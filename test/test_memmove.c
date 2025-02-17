/*
** EPITECH PROJECT, 2025
** asm
** File description:
** test_memmove.c
*/

#include <stdio.h>
#include <string.h>

#include "test.h"

TestSharedLibrary(memmove, content) {
    char src1[] = "Hello, World!";
    char dest1[20];
    char src2[] = "Hello, World!";
    char dest2[20];

    memmove(dest1, src1, sizeof(src1));
    void* ret2 = func(dest2, src2, sizeof(src2));

    cr_expect_eq(ret2, dest2);

    cr_assert_eq(memcmp(dest1, dest2, sizeof(src1)), 0);
}

TestSharedLibrary(memmove, overlap_start) {
    char src1[] = "ABCDEFG";
    char dest1[20];
    char src2[] = "ABCDEFG";
    char dest2[20];

    memmove(dest1, src1, 5);
    void* ret2 = func(dest2, src2, 5);

    cr_expect_eq(ret2, dest2);

    cr_assert_eq(memcmp(dest1, dest2, 5), 0);
}

TestSharedLibrary(memmove, overlap_end) {
    char src1[] = "1234567890";
    char *dest1 = src1 + 2;
    char src2[] = "1234567890";
    char *dest2 = src2 + 2;

    memmove(dest1, src1, 8);
    void* ret2 = func(dest2, src2, 8);

    cr_expect_eq(ret2, dest2);
    //printf("%s\n", dest1);
    //printf("%s\n", dest2);
    //printf("%d\n", memcmp(dest1, dest2, 10));
    //for (int i = 0; i < 10; i++)
    //    printf("[%d]: %d-%d (%c-%c)\n", i, dest1[i], dest2[i], dest1[i], dest2[i]);

    cr_assert_eq(memcmp(dest1, dest2, 8), 0);
}
