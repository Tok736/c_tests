#include "c_tests.h"

c_tests_vector global_c_tests;

int run_all_c_tests() {
    for (size_t i = 0; i < global_c_tests.size; i++) {
        c_tests_error_message message = {.error = TEST_SUCCESS, .error_message = ""};
        global_c_tests.tests[i].test_func(&message);
        if (message.error == TEST_SUCCESS) {
            printf("[ PASS ] %s\n", global_c_tests.tests[i].name);
        } else if (message.error == TEST_ERROR) {
            printf("[ FAIL ] %s: %s\n", global_c_tests.tests[i].name, message.error_message);
        }
    }
    c_tests_vector_clear(&global_c_tests);
    return 0;
}

void global_c_tests_init() { c_tests_vector_init(&global_c_tests); }
