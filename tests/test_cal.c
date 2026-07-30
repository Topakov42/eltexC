#include <check.h>  // подключаем библеотеку для тестов
#include "../include/math_ops.h"
#include <math.h>       //  для nan

START_TEST(test_sum_positive) {
    // начало функции
    ck_assert_double_eq_tol(sum(2.0, 3.0), 5.0, 1e-6);
    // првоерка чисел дабл до 1е-6, так как через == сравнивать нельзя. жалко что нет equals как в джаве((
}

END_TEST

START_TEST(test_sum_negative) {
    ck_assert_double_eq_tol(sum(-2.0, -3.0), -5.0, 1e-6);
}

END_TEST

START_TEST(test_sub_normal) {
    ck_assert_double_eq_tol(sub(10.0, 3.0), 7.0, 1e-6);
}

END_TEST

START_TEST(test_sub_negative_result) {
    ck_assert_double_eq_tol(sub(3.0, 10.0), -7.0, 1e-6);
}

END_TEST

START_TEST(test_mul_normal) {
    ck_assert_double_eq_tol(mul(4.0, 2.5), 10.0, 1e-6);
}

END_TEST

START_TEST(test_mul_zero) {
    ck_assert_double_eq_tol(mul(5.0, 0.0), 0.0, 1e-6);
}

END_TEST


START_TEST(test_divv_normal) {
    ck_assert_double_eq_tol(divv(10.0, 2.0), 5.0, 1e-6);
}

END_TEST

START_TEST(test_divv_zero) {
    double result = divv(10.0, 0.0);
    ck_assert(isnan(result)); // должен быть nan , неопред поведение
}

END_TEST


int main(void) {
    Suite *s = suite_create("MathOps"); //
    TCase *tc = tcase_create("Core");

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

    return (number_failed == 0) ? 0 : 1;
}
