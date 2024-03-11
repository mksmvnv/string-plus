// Created by @mksmvnv

// Functions fake string.h

#include "fake_string.h"

#include "fake_strerror.h"

// Memory character

void* fake_memchr(const void* str, int c, fake_size_t n) {
    const unsigned char* p_str = str;

    for (fake_size_t i = 0; i < n; i++)
        if (p_str[i] == c) return (void*)(p_str + i);

    return FAKE_NULL;
}

// Memory compare

int fake_memcmp(const void* str1, const void* str2, fake_size_t n) {
    const unsigned char* p_str1 = str1;
    const unsigned char* p_str2 = str2;

    for (fake_size_t i = 0; i < n; i++)
        if (p_str1[i] != p_str2[i]) return (p_str1[i] < p_str2[i]) ? -1 : 1;

    return 0;
}

// Memory copy

void* fake_memcpy(void* dest, const void* src, fake_size_t n) {
    unsigned char* p_dest = dest;
    const unsigned char* p_src = src;

    for (fake_size_t i = 0; i < n; i++) p_dest[i] = p_src[i];

    return dest;
}

// Memory set

void* fake_memset(void* str, int c, fake_size_t n) {
    unsigned char* p_str = str;

    for (fake_size_t i = 0; i < n; i++) p_str[i] = (unsigned char)c;

    return str;
}

// String concatenate

char* fake_strncat(char* dest, const char* src, fake_size_t n) {
    unsigned char* p_dest = dest;

    while (*dest != '\0') dest++;

    while (*src != '\0' && n > 0) {
        *dest = *src;
        dest++;
        src++;
        n--;
    }

    *dest = '\0';

    return p_dest;
}

// String character

char* fake_strchr(const char* str, int c) {
    while (*str != '\0') {
        if (*str == c) return (char*)str;
        str++;
    }
    return FAKE_NULL;
}

// String compare

int fake_strncmp(const char* str1, const char* str2, fake_size_t n) {
    for (fake_size_t i = 0; i < n; i++)
        if (str1[i] != str2[i] || str1[i] == '\0' || str2[i] == '\0') return (str1[i] < str2[i]) ? -1 : 1;

    return 0;
}

// String copy

char* fake_strncpy(char* dest, const char* src, fake_size_t n) {
    fake_size_t i;

    for (i = 0; i < n && src[i] != '\0'; i++) dest[i] = src[i];

    for (; i < n; i++) dest[i] = '\0';

    return dest;
}

// String complement span

fake_size_t fake_strcspn(const char* str1, const char* str2) {
    fake_size_t num = 0;

    while (str1[num] != '\0') {
        size_t i = 0;
        while (str2[i] != '\0') {
            if (str1[num] == str2[i]) {
                return num;
            }
            i++;
        }
        num++;
    }

    return num;
}

// String error

char* fake_strerror(int errnum) {
    static char result[512] = {'\0'};

    if (errnum <= MIN_ERRLIST || errnum >= MAX_ERRLIST) {
        sprintf(result, "Unknown error: %d", errnum);
    } else {
        fake_strcpy(result, ((char*)error_list[errnum]));
    }

    return result;
}

// String length

fake_size_t fake_strlen(const char* str) {
    fake_size_t len = 0;

    while (str[len] != '\0') len++;

    return len;
}

// String pointer break

char* fake_strpbrk(const char* str1, const char* str2) {
    while (*str1) {
        const char* ptr = str2;
        while (*ptr) {
            if (*str1 == *ptr) {
                return (char*)str1;
            }
            ptr++;
        }
        str1++;
    }
    return NULL;
}

// String reverse character

char* fake_strrchr(const char* str, int c) {
    const char* last_occurrence = FAKE_NULL;
    while (*str) {
        if (*str == c) {
            last_occurrence = str;
        }
        str++;
    }
    return (char*)last_occurrence;
}

// String string

char* fake_strstr(const char* haystack, const char* needle) {
    if (*needle == '\0') {
        return (char*)haystack;
    }

    while (*haystack) {
        const char* h = haystack;
        const char* n = needle;

        while (*n && *h == *n) {
            h++;
            n++;
        }

        if (*n == '\0') {
            return (char*)haystack;
        }

        haystack++;
    }

    return FAKE_NULL;
}

// String token

char* fake_strtok(char* str, const char* delim) {
    static char* last_token = FAKE_NULL;
    if (str != NULL) {
        last_token = str;
    } else {
        if (last_token == FAKE_NULL) {
            return FAKE_NULL;
        }
        str = last_token;
    }

    while (*str && fake_strchr(delim, *str)) {
        str++;
    }

    if (*str == '\0') {
        last_token = FAKE_NULL;
        return FAKE_NULL;
    }

    char* token_start = str;
    while (*str && !fake_strchr(delim, *str)) {
        str++;
    }

    if (*str) {
        *str = '\0';
        last_token = str + 1;
    } else {
        last_token = FAKE_NULL;
    }

    return token_start;
}

// Extra func for strerror

void fake_strcpy(char* dest, const char* src) {
    while (*src) {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}
