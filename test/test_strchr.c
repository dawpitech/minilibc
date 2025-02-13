#include "test.h"

TestSharedLibrary(strchr, normal) {
    char *str = "Hello World!";
    char searched = 'o';
    cr_assert_eq(strchr(str, searched), func(str, searched));
}

TestSharedLibrary(strchr, not_in_str) {
    char *str = "Hello World!";
    char searched = 'o';
    cr_assert_eq(strchr(str, searched), func(str, searched));
}

TestSharedLibrary(strchr, searching_for_zero) {
    char *str = "Hello World!";
    char searched = '\0';
    cr_assert_eq(strchr(str, searched), func(str, searched));
}
