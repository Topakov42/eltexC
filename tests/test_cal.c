#include <check.h>
#include "math_ops.h"
#include <math.h> // Для isnan()

// --- ТЕСТЫ СЛОЖЕНИЯ ---
START_TEST(test_sum_positive) {
    ck_assert_double_eq_tol(sum(2.0, 3.0), 5.0, 1e-6);
}
END_TEST

START_TEST(test_sum_negative) {
    ck_assert_double_eq_tol(sum(-2.0, -3.0), -5.0, 1e-6);
}
END_TEST

// --- ТЕСТЫ ВЫЧИТАНИЯ ---
START_TEST(test_sub_normal) {
    ck_assert_double_eq_tol(sub(10.0, 3.0), 7.0, 1e-6);
}
END_TEST

START_TEST(test_sub_negative_result) {
    ck_assert_double_eq_tol(sub(3.0, 10.0), -7.0, 1e-6);
}
END_TEST

// --- ТЕСТЫ УМНОЖЕНИЯ ---
START_TEST(test_mul_normal) {
    ck_assert_double_eq_tol(mul(4.0, 2.5), 10.0, 1e-6);
}
END_TEST

START_TEST(test_mul_zero) {
    ck_assert_double_eq_tol(mul(5.0, 0.0), 0.0, 1e-6); // 5 * 0 должно быть 0!
}
END_TEST

// --- ТЕСТЫ ДЕЛЕНИЯ ---
START_TEST(test_divv_normal) {
    ck_assert_double_eq_tol(divv(10.0, 2.0), 5.0, 1e-6);
}
END_TEST

START_TEST(test_divv_zero) {
    double result = divv(10.0, 0.0);
    ck_assert(isnan(result)); // Проверяем, что вернулся NAN при делении на ноль!
}
END_TEST


// --- МАГИЯ ЗАПУСКА (main) ---
int main(void) {
    Suite *s = suite_create("MathOps");
    TCase *tc = tcase_create("Core");

    // Добавляем ВСЕ тесты в контейнер
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