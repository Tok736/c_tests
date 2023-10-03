#include "c_tests.h"

c_tests_vector global_c_tests;

static int handle_test(c_tests_node *test) {
    int error;
    c_tests_error_message message = {.error = TEST_SUCCESS, .error_message = ""};
    test->test_func(&message);
    error = message.error;
    if (error == TEST_SUCCESS)
        printf("[ PASS ] %s\n", test->name);
    else if (error == TEST_ERROR)
        printf("[ FAIL ] %s: %s\n", test->name, message.error_message);
    return error;
}

int run_all_c_tests() {
    size_t success_amount = 0;
    for (size_t i = 0; i < global_c_tests.size; i++) {
        int error;
        error = handle_test(&global_c_tests.tests[i]);
        if (error == TEST_SUCCESS) success_amount++;
    }
    printf("\n%zu out of %zu tests passed\n", success_amount, global_c_tests.size);
    c_tests_vector_clear(&global_c_tests);
    return success_amount;
}

void global_c_tests_init() { c_tests_vector_init(&global_c_tests); }
