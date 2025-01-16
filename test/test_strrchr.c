#include "test.h"

TestSharedLibrary(strrchr, normal) {
    char *str = "Hello World!";
    char searched = 'o';
    cr_assert_eq(strrchr(str, searched), func(str, searched));
}

TestSharedLibrary(strrchr, not_in_str) {
    char *str = "Hello World!";
    char searched = 'j';
    cr_assert_eq(strrchr(str, searched), func(str, searched));
}
