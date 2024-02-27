// Created by @mksmvnv

// Test file

#include "tests.h"

int main() {
    printf("%-20s | %-10s | %-10s | %-10s\n", "Test name", "Result 1", "Result 2", "Status");
    test_memchr();
    test_memcmp();
    test_memcpy();
    test_strlen();
    return 0;
}

void test_memchr() {
    char classes[] = {'a', 'b', 'c', 'd'};
    char* res_chr = memchr(classes, 'b', 4);
    char* res_fchr = fake_memchr(classes, 'b', 4);
    printf("%-20s | %-10c | %-10c | %-10s\n", "Memory character", *res_chr, *res_fchr,
           res_chr == res_fchr ? "YES" : "NO");
}

void test_memcmp() {
    const char* user_input_1 = "1942, late evening, Bletchley Park, Alan Turing's desk";
    const char* user_input_2 = "1942, late evening, Bletchley Park, Alan Turing's desk";
    int res_cmp = memcmp(user_input_1, user_input_2, 40);
    int res_fcmp = fake_memcmp(user_input_1, user_input_2, 40);
    printf("%-20s | %-10d | %-10d | %-10s\n", "Memory compare", res_cmp, res_fcmp,
           res_cmp == 0 && res_fcmp == 0 ? "YES" : "NO");
}

void test_memcpy() {
    char memcpy_user_input_1[SIZE] = "Guinea pig";
    const char memcpy_user_input_2[SIZE] = "Changer";
    char* res_cpy = memcpy(memcpy_user_input_1, memcpy_user_input_2, sizeof(memcpy_user_input_1));
    char* res_fcpy = fake_memcpy(memcpy_user_input_1, memcpy_user_input_2, sizeof(memcpy_user_input_1));
    printf("%-20s | %-10s | %-10s | %-10s\n", "Memory copy", res_cpy, res_fcpy,
           res_cpy == res_fcpy ? "YES" : "NO");
}

void test_strlen() {
    const char* user_input = "How many letters do I have?";
    int res_strlen = strlen(user_input);
    int res_fstrlen = fake_strlen(user_input);
    printf("%-20s | %-10d | %-10d | %-10s\n", "String length", res_strlen, res_fstrlen,
           res_strlen == res_fstrlen ? "YES" : "NO");
}
