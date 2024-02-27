// Created by @mksmvnv

// Functions fake string.h

#include "fake_string.h"

// String length

int fake_strlen(const char* str) {
    int i;
    for (i = 0; *str != '\0'; i++, str++)
        ;
    return i;
}