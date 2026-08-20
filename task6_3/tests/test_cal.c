#include <check.h>
#include <math.h>

#include "../include/loader.h"

#define LIBS_DIR "./libs"
#define MAX_FUNCTIONS 10

static LoadedFunction functions[MAX_FUNCTIONS];
static int function_count;

static math_func find_function(char operation)
{
    for (int i = 0; i < function_count; i++) {
        if (functions[i].operation == operation) {
            return functions[i].function;
        }
    }

    return NULL;
}

static void setup(void)
{
    function_count = load_functions(
        LIBS_DIR,
        functions,
        MAX_FUNCTIONS
    );
}

static void teardown(void)
{
    unload_functions(functions, function_count);
    function_count = 0;
}

START_TEST(test_sum_positive)
{
    math_func function = find_function('+');

    ck_assert_ptr_nonnull(function);
    ck_assert_double_eq_tol(function(2.0, 3.0), 5.0, 1e-6);
}
END_TEST

START_TEST(test_sum_negative)
{
    math_func function = find_function('+');

    ck_assert_ptr_nonnull(function);
    ck_assert_double_eq_tol(function(-2.0, -3.0), -5.0, 1e-6);
}
END_TEST

START_TEST(test_sub_normal)
{
    math_func function = find_function('-');

    ck_assert_ptr_nonnull(function);
    ck_assert_double_eq_tol(function(10.0, 3.0), 7.0, 1e-6);
}
END_TEST

START_TEST(test_sub_negative_result)
{
    math_func function = find_function('-');

    ck_assert_ptr_nonnull(function);
    ck_assert_double_eq_tol(function(3.0, 10.0), -7.0, 1e-6);
}
END_TEST

START_TEST(test_mul_normal)
{
    math_func function = find_function('*');

    ck_assert_ptr_nonnull(function);
    ck_assert_double_eq_tol(function(4.0, 2.5), 10.0, 1e-6);
}
END_TEST

START_TEST(test_mul_zero)
{
    math_func function = find_function('*');

    ck_assert_ptr_nonnull(function);
    ck_assert_double_eq_tol(function(5.0, 0.0), 0.0, 1e-6);
}
END_TEST

START_TEST(test_divv_normal)
{
    math_func function = find_function('/');

    ck_assert_ptr_nonnull(function);
    ck_assert_double_eq_tol(function(10.0, 2.0), 5.0, 1e-6);
}
END_TEST

START_TEST(test_divv_zero)
{
    math_func function = find_function('/');

    ck_assert_ptr_nonnull(function);

    double result = function(10.0, 0.0);

    ck_assert(isnan(result));
}
END_TEST

int main(void)
{
    Suite *s = suite_create("DynamicMathOps");
    TCase *tc = tcase_create("Core");

    tcase_add_checked_fixture(tc, setup, teardown);

    tcase_add_test(tc, test_sum_positive);
    tcase_add_test(tc, test_sum_negative);
    tcase_add_test(tc, test_sub_normal);
    tcase_add_test(tc, test_sub_negative_result);
    tcase_add_test(tc, test_mul_normal);
    tcase_add_test(tc, test_mul_zero);
    tcase_add_test(tc, test_divv_normal);
    tcase_add_test(tc, test_divv_zero);

    suite_add_tcase(s, tc);

    SRunner *sr = srunner_create(s);
    srunner_run_all(sr, CK_NORMAL);

    int number_failed = srunner_ntests_failed(sr);

    srunner_free(sr);

    return number_failed == 0 ? 0 : 1;
}