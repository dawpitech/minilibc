/*
** EPITECH PROJECT, 2025
** asm
** File description:
** test_strcasecmp.c
*/

#include <strings.h>

#include "test.h"

TestSharedLibrary(strcasecmp, normal) {
    char str1[] = "HELLO World!";
    char str2[] = "hello World!";

    cr_assert_eq(strcasecmp(str1, str2), func(str1, str2));
}

TestSharedLibrary(strcasecmp, not_equals) {
    char str1[] = "Hello Shere!";
    char str2[] = "Hello World!";

    cr_assert_eq(strcasecmp(str1, str2), func(str1, str2));
}

TestSharedLibrary(strcasecmp, not_equals2) {
    char str1[] = "Goofy string";
    char str2[] = "ding dong\n";

    cr_assert_eq(strcasecmp(str1, str2), func(str1, str2));
}
