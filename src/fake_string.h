#ifndef FAKE_STRING_H
#define FAKE_STRING_H

#include <stdio.h>
#include <string.h>

#define FAKE_NULL ((void*)0)
typedef unsigned long fake_size_t;

void* fake_memchr(const void* str, int c, fake_size_t n);
int fake_memcmp(const void* str1, const void* str2, fake_size_t n);
void* fake_memcpy(void* dest, const void* src, fake_size_t n);
void* fake_memset(void* str, int c, fake_size_t n);
char* fake_strncat(char* dest, const char* src, fake_size_t n);
char* fake_strchr(const char* str, int c);
int fake_strncmp(const char* str1, const char* str2, fake_size_t n);
char* fake_strncpy(char* dest, const char* src, fake_size_t n);
fake_size_t fake_strlen(const char* str);

#endif  // FAKE_STRING_H
