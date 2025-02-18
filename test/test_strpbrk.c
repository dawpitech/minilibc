/*
** EPITECH PROJECT, 2025
** asm
** File description:
** test_strpbrk.c
*/

#include <stdio.h>
#include <string.h>

#include "test.h"

TestSharedLibrary(strpbrk, normal) {
    char s[] = "Hello bob, how are you?";
    char accept[] = "bh";

    cr_assert_eq(strpbrk(s, accept), func(s, accept));
}

TestSharedLibrary(strpbrk, normal2) {
    char s[] = "Hello bob, how are you?";
    char accept[] = "hb";

    cr_assert_eq(strpbrk(s, accept), func(s, accept));
}

TestSharedLibrary(strpbrk, not_found) {
    char s[] = "Hello bob, how are you?";
    char accept[] = "john";

    cr_assert_eq(strpbrk(s, accept), func(s, accept));
}

TestSharedLibrary(strpbrk, empty) {
    char s[] = "Hello bob, how are you?";
    char accept[] = "";

    cr_assert_eq(strpbrk(s, accept), func(s, accept));
}
