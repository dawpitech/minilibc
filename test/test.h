/*
** EPITECH PROJECT, 2025
** minilibc
** File description:
** test template
*/

#include <criterion/criterion.h>
#include <dlfcn.h>

#define TestSharedLibrary(func_name, test_name)                           \
    void generated_test_##func_name##_##test_name(func_name##_t func);    \
                                                                          \
    Test(func_name, test_name) {                                          \
        void *handle = dlopen("./libasm.so", RTLD_LAZY);                  \
        if (!handle)                                                      \
            cr_skip("Failed to open shared library: %s", dlerror());      \
        func_name##_t func = dlsym(handle, #func_name);                   \
        if (!func)                                                        \
            cr_skip("Failed to get function pointer: %s", dlerror());     \
        generated_test_##func_name##_##test_name(func);                   \
        dlclose(handle);                                                  \
    }                                                                     \
                                                                          \
    void generated_test_##func_name##_##test_name(func_name##_t func)

typedef char *(*strchr_t)(char *str, int searchedChar);
typedef void *(*memset_t)(void *dest, int chr, size_t count);
typedef char *(*strrchr_t)(char *str, int searchedChar);
typedef void *(*memcpy_t)(void *dest, void *src, size_t n);
typedef int (*strcmp_t)(const char* s1, const char* s2);
typedef int (*strncmp_t)(const char* s1, const char* s2, size_t n);
typedef int (*strcasecmp_t)(const char *s1, const char *s2);
typedef void *(*memmove_t)(void *dest, void *src, size_t n);
typedef char *(*strstr_t)(char *haystack, char *needle);
typedef char *(*strpbrk_t)(char *s, char *accept);
typedef int (*strcspn_t)(char *s, char *reject);
