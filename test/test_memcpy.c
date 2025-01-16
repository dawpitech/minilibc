#include "test.h"

TestSharedLibrary(memcpy, normal) {
    char str[] = "Hello World!";
    const size_t size = sizeof(str);

    char buff[size];
    cr_assert_eq(func(buff, str, size), buff);

    char expected[size];
    memcpy(expected, str, size);
    cr_assert_arr_eq(buff, expected, size);
}
