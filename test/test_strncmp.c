/*
** EPITECH PROJECT, 2025
** asm
** File description:
** test_strncmp.c
*/

#include <string.h>

#include "test.h"

TestSharedLibrary(strncmp, normal) {
    char str1[] = "Hello World!";
    char str2[] = "Hello Warld!";

    cr_assert_eq(strncmp(str1, str2, 5), func(str1, str2, 5));
}

TestSharedLibrary(strncmp, not_equals) {

    char str1[] = "Hello Shere!";
    char str2[] = "Hello World!";

    cr_assert_eq(strncmp(str1, str2, 11), func(str1, str2, 11));
}

TestSharedLibrary(strncmp, not_equals2) {
    char str1[] = "Goofy string";
    char str2[] = "ding dong\n";

    cr_assert_eq(strncmp(str1, str2, 11), func(str1, str2, 11));
}

TestSharedLibrary(strncmp, compare_after_str_end) {
    char str1[] = "Goofy string";
    char str2[] = "Goofy string";

    cr_assert_eq(strncmp(str1, str2, 30), func(str1, str2, 30));
}
