/*
** EPITECH PROJECT, 2025
** asm
** File description:
** test_strstr.c
*/

#include <stdio.h>
#include <string.h>

#include "test.h"

TestSharedLibrary(strstr, normal) {
    char haystack[] = "Hello bob, how are you?";
    char needle[] = "bob";

    cr_assert_eq(strstr(haystack, needle), func(haystack, needle));
}

TestSharedLibrary(strstr, not_found) {
    char haystack[] = "Hello bob, how are you?";
    char needle[] = "john";

    cr_assert_eq(strstr(haystack, needle), func(haystack, needle));
}

TestSharedLibrary(strstr, empyu) {
    char haystack[] = "Hello bob, how are you?";
    char needle[] = "";

    cr_assert_eq(strstr(haystack, needle), func(haystack, needle));
}
