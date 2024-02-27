// Created by @mksmvnv

// Functions fake string.h

#include "fake_string.h"

// Memory character

void* fake_memchr(const void* str, int c, fake_size_t n) {
    const unsigned char* p_str = str;

    for (fake_size_t i = 0; i < n; i++) {
        if (p_str[i] == c) return (void*)(p_str + i);
    }

    return FAKE_NULL;
}

// Memory compare

int fake_memcmp(const void* str1, const void* str2, fake_size_t n) {
    const unsigned char* p_str1 = str1;
    const unsigned char* p_str2 = str2;

    for (fake_size_t i = 0; i < n; i++) {
        if (p_str1[i] != p_str2[i]) return (p_str1[i] < p_str2[i]) ? -1 : 1;
    }

    return 0;
}

// Memory copy

void* fake_memcpy(void* dest, const void* src, fake_size_t n) {
    unsigned char* p_dest = dest;
    const unsigned char* p_src = src;

    for (fake_size_t i = 0; i < n; i++) {
        p_dest[i] = p_src[i];
    }

    return dest;
}

// String length

fake_size_t fake_strlen(const char* str) {
    fake_size_t len = 0;

    while (str[len] != '\0') len++;

    return len;
}