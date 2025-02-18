/*
** EPITECH PROJECT, 2025
** asm
** File description:
** test_strcspn.c
*/

#include <string.h>

#include "test.h"

TestSharedLibrary(strcspn, reject) {
    char s[] = "Hello bob, how are you?";
    char accept[] = "bh";

    cr_assert_eq(strcspn(s, accept), func(s, accept));
}

TestSharedLibrary(strcspn, reject2) {
    char s[] = "Hello bob, how are you?";
    char accept[] = "hb";

    cr_assert_eq(strcspn(s, accept), func(s, accept));
}

TestSharedLibrary(strcspn, no_reject) {
    char s[] = "Hello bob, how are you?";
    char accept[] = "john";

    cr_assert_eq(strcspn(s, accept), func(s, accept));
}

TestSharedLibrary(strcspn, empty_rejects) {
    char s[] = "Hello bob, how are you?";
    char accept[] = "";

    cr_assert_eq(strcspn(s, accept), func(s, accept));
}
