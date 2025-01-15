#include <criterion/criterion.h>
#include <dlfcn.h>

typedef char * (*strchr_t)(char *str, int searchedChar);

Test(strchr, normal) {
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    if (!handle)
        cr_skip("Failed to open shared library: %s", dlerror());
    strchr_t func = dlsym(handle, "strchr");
    if (!func)
        cr_skip("Failed to get function pointer: %s", dlerror());

    char *str = "Hello World!";
    char searched = 'o';
    cr_assert_eq(strchr(str, searched), func(str, searched));

    dlclose(handle);
}

Test(strchr, not_in_str) {
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    if (!handle)
        cr_skip("Failed to open shared library: %s", dlerror());
    strchr_t func = dlsym(handle, "strchr");
    if (!func)
        cr_skip("Failed to get function pointer: %s", dlerror());

    char *str = "Hello World!";
    char searched = 'o';
    printf("%s", func(str, searched));
    printf("%s", strchr(str, searched));
    cr_assert_eq(strchr(str, searched), func(str, searched));

    dlclose(handle);
}
