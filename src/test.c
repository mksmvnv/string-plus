// Created by @mksmvnv

// Test file

#include "fake_string.h"

int main() {
    const char* user_input = "1942, late evening, Bletchley Park, Alan Turing's desk.";
    int user_input_len = strlen(user_input);
    printf("String length test: strlen [%d] | fake_strlen [%d]", user_input_len, fake_strlen(user_input));
    return 0;
}
