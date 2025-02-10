/*
** EPITECH PROJECT, 2025
** asm
** File description:
** test_strcmp.c
*/

#include <string.h>

#include "test.h"

TestSharedLibrary(strcmp, normal) {
    char str1[] = "Hello World!";
    char str2[] = "Hello World!";

    cr_assert_eq(strcmp(str1, str2), func(str1, str2));
}

TestSharedLibrary(strcmp, not_equals) {
    char str1[] = "Hello Shere!";
    char str2[] = "Hello World!";

    cr_assert_eq(strcmp(str1, str2), func(str1, str2));
}

TestSharedLibrary(strcmp, not_equals2) {
    char str1[] = "Goofy string";
    char str2[] = "ding dong\n";

    cr_assert_eq(strcmp(str1, str2), func(str1, str2));
}
