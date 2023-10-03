#include "c_tests.h"

c_tests_vector global_c_tests;

int run_all_c_tests() {
    printf("Test running\n");
    for (size_t i = 0; i < global_c_tests.size; i++) {
        global_c_tests.tests[i].test_func();
    }
    c_tests_vector_clear(&global_c_tests);
    return 0;
}

void global_c_tests_init() { c_tests_vector_init(&global_c_tests); }
