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
    test_strcspn();
    test_strlen();
    test_strpbrk();
    test_strrchr();
    test_strstr();
    test_strtok();
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
    char c = 'x';
    char* res_set = memset(str, c, 4);
    char* res_fset = fake_memset(str, c, 4);
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
    char c = 'f';
    char* res_strchr = strchr(str, c);
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

// String complement span

void test_strcspn() {
    const char str1[] = "I'm 24 years old.";
    const char str2[] = "0123456789";
    fake_size_t res_strcspn = strcspn(str1, str2);
    fake_size_t res_fstrcspn = fake_strcspn(str1, str2);
    printf("%-20s | %-20zu | %-20zu | %-10s\n", "String comp. span", res_strcspn, res_fstrcspn,
           res_strcspn == res_fstrcspn ? "YES" : "NO");
}

// Test string length

void test_strlen() {
    const char* user_input = "How many letters do I have?";
    int res_strlen = strlen(user_input);
    int res_fstrlen = fake_strlen(user_input);
    printf("%-20s | %-20d | %-20d | %-10s\n", "String length", res_strlen, res_fstrlen,
           res_strlen == res_fstrlen ? "YES" : "NO");
}

// String pointer break

void test_strpbrk() {
    const char str1[] = "04.03.2024 Saint-Petersburg";
    const char str2[] = "Ss";
    char* res_strpbrk = strpbrk(str1, str2);
    char* res_fstrpbrk = fake_strpbrk(str1, str2);
    printf("%-20s | %-20s | %-20s | %-10s\n", "String pointer break", res_strpbrk, res_fstrpbrk,
           res_strpbrk == res_fstrpbrk ? "YES" : "NO");
};

// String reverse character

void test_strrchr() {
    const char str[] = "Searches for the last occurrence @f the character c";
    int c = '@';
    char* res_strrchr = strrchr(str, c);
    char* res_fstrrchr = fake_strrchr(str, c);
    printf("%-20s | %-20s | %-20s | %-10s\n", "String reverse char.", res_strrchr, res_fstrrchr,
           res_strrchr == res_fstrrchr ? "YES" : "NO");
};

// String string

void test_strstr() {
    const char haystack[] = "Finds the first occurrence of the entire string needle";
    const char needle[] = "entire";
    char* res_strstr = strstr(haystack, needle);
    char* res_fstrstr = fake_strstr(haystack, needle);
    printf("%-20s | %-20s | %-20s | %-10s\n", "String string", res_strstr, res_fstrstr,
           res_strstr == res_fstrstr ? "YES" : "NO");
};

// String token

void test_strtok() {
    char str[] = "Breaks string str into a series of tokens separated by delim.";
    const char delim[] = " ";
    char* res_strtok = strtok(str, delim);
    char* res_fstrtok = fake_strtok(str, delim);
    printf("%-20s | %-20s | %-20s | %-10s\n", "String token", res_strtok, res_fstrtok,
           res_strtok == res_fstrtok ? "YES" : "NO");
};
