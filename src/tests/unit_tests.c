#include "unit_tests.h"

// Unit test memchr

START_TEST(test_fake_memchr) {
    char str[] = "Searches for the first occurrence of the character c.";
    char *res_fake_memchr = fake_memchr(str, 'c', 10);
    char *res_memchr = memchr(str, 'c', 10);

    ck_assert_str_eq(res_fake_memchr, res_memchr);
}
END_TEST

// Unit test memcmp

START_TEST(test_fake_memcmp) {
    const char str1[] = "Compares the first n bytes of str1 and str2.";
    const char str2[] = "Compares the first n bytes of str1 and str2.";
    int res_fake_memcmp = fake_memcmp(str1, str2, 20);
    int res_memcmp = memcmp(str1, str2, 20);

    ck_assert_int_eq(res_fake_memcmp, res_memcmp);
}
END_TEST

// Unit test memcpy

START_TEST(test_fake_memcpy) {
    char dest[] = "Main test text.";
    const char src[] = "Copies up";
    char *res_fake_memcpy = fake_memcpy(dest, src, sizeof(src) - 1);
    char *res_memcpy = memcpy(dest, src, sizeof(src) - 1);

    ck_assert_str_eq(res_fake_memcpy, res_memcpy);
}
END_TEST

// Unit test memset

START_TEST(test_fake_memset) {
    char str[] = "Test 1";
    char c = 'x';
    char *res_fake_memset = fake_memset(str, c, 4);
    char *res_memset = memset(str, c, 4);

    ck_assert_str_eq(res_fake_memset, res_memset);
}
END_TEST

// Unit test strncat

START_TEST(test_fake_strncat) {
    char dest1[15] = "Hello, ";
    char dest2[15] = "Hello, ";
    char src[7] = "World!";
    char *res_fake_strncat = fake_strncat(dest2, src, 6);
    char *res_strncat = strncat(dest1, src, 6);

    ck_assert_str_eq(res_fake_strncat, res_strncat);
}
END_TEST

// Unit test strchr

START_TEST(test_fake_strchr) {
    const char str[] = "Searches for the first occurrence of the character c.";
    char c = 'f';
    char *res_fake_strchr = fake_strchr(str, c);
    char *res_strchr = strchr(str, c);

    ck_assert_ptr_eq(res_fake_strchr, res_strchr);
}
END_TEST

// Unit test strncmp

START_TEST(test_fake_strncmp) {
    const char str1[] = "Compares at most the first n bytes of str1 and str2.";
    const char str2[] = "Compares at most the first n bytes of str1 and str2.";
    int res_fake_strncmp = fake_strncmp(str1, str2, 10);
    int res_strncmp = strncmp(str1, str2, 10);

    ck_assert_int_eq(res_fake_strncmp, res_strncmp);
}
END_TEST

// Unit test strncpy

START_TEST(test_fake_strncpy) {
    char dest[] = "Main test text.";
    const char src[] = "Copies up";
    char *res_fake_strncpy = fake_strncpy(dest, src, sizeof(src) - 1);
    char *res_strncpy = strncpy(dest, src, sizeof(src) - 1);

    ck_assert_str_eq(res_fake_strncpy, res_strncpy);
}
END_TEST

// Unit test strcspn

START_TEST(test_fake_strcspn) {
    const char str1[] = "I'm 24 years old.";
    const char str2[] = "0123456789";
    fake_size_t res_fake_strcspn = fake_strcspn(str1, str2);
    fake_size_t res_strcspn = strcspn(str1, str2);

    ck_assert_int_eq(res_fake_strcspn, res_strcspn);
}
END_TEST

// Unit test strlen

START_TEST(test_fake_strlen) {
    const char *user_input = "How many letters do I have?";
    int res_fake_strlen = fake_strlen(user_input);
    int res_strlen = strlen(user_input);

    ck_assert_int_eq(res_fake_strlen, res_strlen);
}
END_TEST

// Unit test strpbrk

START_TEST(test_fake_strpbrk) {
    const char str1[] = "04.03.2024 Saint-Petersburg";
    const char str2[] = "Ss";
    char *res_fake_strpbrk = fake_strpbrk(str1, str2);
    char *res_strpbrk = strpbrk(str1, str2);

    ck_assert_str_eq(res_fake_strpbrk, res_strpbrk);
}
END_TEST

// Unit test strrchr

START_TEST(test_fake_strrchr) {
    const char str[] = "Searches for the last occurrence @f the character c";
    int c = '@';
    char *res_fake_strrchr = fake_strrchr(str, c);
    char *res_strrchr = strrchr(str, c);

    ck_assert_str_eq(res_fake_strrchr, res_strrchr);
}
END_TEST

// Unit test strstr

START_TEST(test_fake_strstr) {
    const char haystack[] = "Finds the first occurrence of the entire string needle";
    const char needle[] = "entire";
    char *res_fake_strstr = fake_strstr(haystack, needle);
    char *res_strstr = strstr(haystack, needle);

    ck_assert_str_eq(res_fake_strstr, res_strstr);
}
END_TEST

// Unit test strtok

START_TEST(test_fake_strtok) {
    char str[] = "Breaks string str into a series of tokens separated by delim.";
    const char delim[] = " ";
    char *res_fake_strtok = fake_strtok(str, delim);
    char *res_strtok = strtok(str, delim);

    ck_assert_str_eq(res_fake_strtok, res_strtok);
}
END_TEST

Suite *test_fake_str(void) {
    Suite *s = suite_create("fake_string");
    TCase *tc = tcase_create("Core");

    tcase_add_test(tc, test_fake_memchr);
    tcase_add_test(tc, test_fake_memcmp);
    tcase_add_test(tc, test_fake_memcpy);
    tcase_add_test(tc, test_fake_memset);
    tcase_add_test(tc, test_fake_strncat);
    tcase_add_test(tc, test_fake_strchr);
    tcase_add_test(tc, test_fake_strncmp);
    tcase_add_test(tc, test_fake_strncpy);
    tcase_add_test(tc, test_fake_strcspn);
    tcase_add_test(tc, test_fake_strlen);
    tcase_add_test(tc, test_fake_strpbrk);
    tcase_add_test(tc, test_fake_strrchr);
    tcase_add_test(tc, test_fake_strstr);
    tcase_add_test(tc, test_fake_strtok);

    suite_add_tcase(s, tc);
    return s;
}

int main(void) {
    Suite *test_fake_string = test_fake_str();
    SRunner *runner = srunner_create(suite);

    srunner_run_all(runner, CK_NORMAL);
    int number_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
