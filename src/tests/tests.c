// Created by @mksmvnv

// Test file

#include "tests.h"

int main() {
    printf("%-20s | %-20s | %-20s | %-10s\n", "Test name", "Original result", "Fake result", "Status");
    test_memchr();
    test_memcmp();
    test_memcpy();
    test_memset();
    test_strncat();
    test_strchr();
    test_strncmp();
    test_strncpy();
    test_strlen();
    return 0;
}

// Test memory character

void test_memchr() {
    char str[] = "Searches for the first occurrence of the character c.";
    char* res_memchr = memchr(str, 'c', 10);
    char* res_fmemchr = fake_memchr(str, 'c', 10);
    printf("%-20s | %-20c | %-20c | %-10s\n", "Memory character", *res_memchr, *res_fmemchr,
           res_memchr == res_fmemchr ? "YES" : "NO");
}

// Test memory compare

void test_memcmp() {
    const char str1[] = "Compares the first n bytes of str1 and str2.";
    const char str2[] = "Compares the first n bytes of str1 and str2.";
    int res_cmp = memcmp(str1, str2, 20);
    int res_fcmp = fake_memcmp(str1, str2, 20);
    printf("%-20s | %-20d | %-20d | %-10s\n", "Memory compare", res_cmp, res_fcmp,
           res_cmp == 0 && res_fcmp == 0 ? "YES" : "NO");
}

// Test memory copy

void test_memcpy() {
    char dest[] = "Main test text.";
    const char src[] = "Copies up";
    char* res_cpy = memcpy(dest, src, sizeof(src) - 1);
    char* res_fcpy = fake_memcpy(dest, src, sizeof(src) - 1);
    printf("%-20s | %-20s | %-20s | %-10s\n", "Memory copy", res_cpy, res_fcpy,
           res_cpy == res_fcpy ? "YES" : "NO");
}

// Test memory set

void test_memset() {
    char str[] = "Test 1";
    char* c = "x";
    char* res_set = memset(str, *c, 4);
    char* res_fset = fake_memset(str, *c, 4);
    printf("%-20s | %-20s | %-20s | %-10s\n", "Memory set", res_set, res_fset,
           res_set == res_fset ? "YES" : "NO");
}

// Test string concatenate

void test_strncat() {
    char dest1[15] = "Hello, ";
    char dest2[15] = "Hello, ";
    char src[7] = "World!";
    char* res_cat = strncat(dest1, src, 6);
    char* res_fcat = fake_strncat(dest2, src, 6);
    printf("%-20s | %-20s | %-20s | %-10s\n", "String concatenate", res_cat, res_fcat,
           *res_cat == *res_fcat ? "YES" : "NO");
}

// Test string character

void test_strchr() {
    const char str[] = "Searches for the first occurrence of the character c.";
    char* c = "f";
    char* res_strchr = strchr(str, *c);
    printf("%-20s | %-20p | %-20p | %-10s\n", "String character", res_strchr, res_strchr,
           res_strchr == res_strchr ? "YES" : "NO");
}

// Test string compare

void test_strncmp() {
    const char str1[] = "Compares at most the first n bytes of str1 and str2.";
    const char str2[] = "Compares at most the first n bytes of str1 and str2.";
    int res_strncmp = strncmp(str1, str2, 10);
    int res_fstrncmp = fake_strncmp(str1, str2, 10);
    printf("%-20s | %-20d | %-20d | %-10s\n", "String compare", res_strncmp, res_fstrncmp,
           res_strncmp == 0 && res_fstrncmp == 0 ? "YES" : "NO");
}

// Test string copy

void test_strncpy() {
    char dest[] = "Main test text.";
    const char src[] = "Copies up";
    char* res_strncpy = strncpy(dest, src, sizeof(src) - 1);
    char* res_fstrncpy = fake_strncpy(dest, src, sizeof(src) - 1);
    printf("%-20s | %-20s | %-20s | %-10s\n", "String copy", res_strncpy, res_fstrncpy,
           res_strncpy == res_fstrncpy ? "YES" : "NO");
}

// Test string length

void test_strlen() {
    const char* user_input = "How many letters do I have?";
    int res_strlen = strlen(user_input);
    int res_fstrlen = fake_strlen(user_input);
    printf("%-20s | %-20d | %-20d | %-10s\n", "String length", res_strlen, res_fstrlen,
           res_strlen == res_fstrlen ? "YES" : "NO");
}
