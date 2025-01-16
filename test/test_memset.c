#include <string.h>
#include "test.h"

TestSharedLibrary(memset, five_zero_bytes) {
    const size_t size = 5;
    const char value = 0;

    char buff[size];
    cr_assert_eq(func(buff, value, size), buff);

    char expected[size];
    memset(expected, value, size);
    cr_assert_arr_eq(buff, expected, size);
}

TestSharedLibrary(memset, ten_chr_bytes) {
    const size_t size = 10;
    const char value = 'b';

    char buff[size];
    cr_assert_eq(func(buff, value, size), buff);

    char expected[size];
    memset(expected, value, size);
    cr_assert_arr_eq(buff, expected, size);
}
