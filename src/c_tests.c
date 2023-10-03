#include "c_tests.h"

c_tests_vector global_c_tests;

typedef enum printf_color { PRINTF_COLOR_RED, PRINTF_COLOR_GREEN, PRINTF_COLOR_DEFAULT } printf_color;

static void set_printf_color(printf_color color) {
    if (color == PRINTF_COLOR_RED)
        printf("\033[0;31m");
    else if (color == PRINTF_COLOR_GREEN)
        printf("\033[0;32m");
    else if (color == PRINTF_COLOR_DEFAULT)
        printf("\033[0m");
}

static int handle_test(c_tests_node *test) {
    int error;
    c_tests_error_message message = {.error = TEST_SUCCESS, .error_message = ""};
    test->test_func(&message);
    error = message.error;
    if (error == TEST_SUCCESS) {
        set_printf_color(PRINTF_COLOR_GREEN);
        printf("[ PASS ] ");
        set_printf_color(PRINTF_COLOR_DEFAULT);
        printf("%s\n", test->name);
    } else if (error == TEST_ERROR) {
        set_printf_color(PRINTF_COLOR_RED);
        printf("[ FAIL ] ");
        set_printf_color(PRINTF_COLOR_DEFAULT);
        printf("%s:", test->name);
        set_printf_color(PRINTF_COLOR_RED);
        printf("\n    %s\n", message.error_message);
        set_printf_color(PRINTF_COLOR_DEFAULT);
    }
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
