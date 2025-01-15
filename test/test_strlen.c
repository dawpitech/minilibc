#include <criterion/criterion.h>
#include <dlfcn.h>

typedef size_t (*strlen_t)(char *str);

Test(strlen, normal) {
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    if (!handle)
        cr_skip("Failed to open shared library: %s", dlerror());
    strlen_t func = dlsym(handle, "strlen");
    if (!func)
        cr_skip("Failed to get function pointer: %s", dlerror());

    char *str = "Hello World!";
    cr_assert_eq(strlen(str), func(str));

    dlclose(handle);
}

Test(strlen, empty) {
    void *handle = dlopen("./libasm.so", RTLD_LAZY);
    if (!handle)
        cr_skip("Failed to open shared library: %s", dlerror());
    strlen_t func = dlsym(handle, "strlen");
    if (!func)
        cr_skip("Failed to get function pointer: %s", dlerror());

    char *str = "";
    cr_assert_eq(strlen(str), func(str));

    dlclose(handle);
}
