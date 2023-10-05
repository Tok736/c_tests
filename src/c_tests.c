#include "c_tests.h"

c_tests_vector global_c_tests;

static int handle_test(c_tests_node *test) {
    int error;
    c_tests_error_message message = {.error = TEST_SUCCESS, .error_message = ""};
    test->test_func(&message);
    error = message.error;
    if (error == TEST_SUCCESS) {
        printf(PRINT_GREEN "[ PASS ] ");
        printf(PRINT_DEFAULT "%s\n", test->name);
    } else if (error == TEST_ERROR) {
        printf(PRINT_RED "[ FAIL ] ");
        printf(PRINT_DEFAULT "%s\n", test->name);
        printf(PRINT_RED "    %s\n" PRINT_DEFAULT, message.error_message);
    }
    return error;
}

void print_success_out_of(size_t success_amount, size_t n) {
    printf("\n%zu out of %zu tests passed\n", success_amount, n);
}

int run_not_launched_by_group_name(char *group_name, int *was_launched) {
    printf("%s\n", group_name);

    size_t success_amount = 0, n = global_c_tests.size;
    for (size_t i = 0; i < n; i++) {
        if (!was_launched[i] && strcmp(group_name, global_c_tests.tests[i].group_name) == 0) {
            if (handle_test(&global_c_tests.tests[i]) == TEST_SUCCESS) success_amount++;
            was_launched[i] = true;
        }
    }
    return success_amount;
}

int run_c_test_by_group_name(char *group_name) {
    size_t success_amount, n = 0;

    int *was_launched = malloc(global_c_tests.size * sizeof(int));
    for (size_t i = 0; i < global_c_tests.size; i++) {
        was_launched[i] = false;
        if (strcmp(group_name, global_c_tests.tests[i].group_name) == 0) n++;
    }

    success_amount = run_not_launched_by_group_name(group_name, was_launched);

    print_success_out_of(success_amount, n);

    free(was_launched);

    return success_amount;
}

int run_all_c_tests() {
    size_t success_amount = 0, test_num = 1, n = global_c_tests.size;
    int *was_launched = malloc(global_c_tests.size * sizeof(int));
    for (size_t i = 0; i < n; i++) was_launched[i] = false;

    for (size_t i = 0; i < n; i++) {
        if (!was_launched[i]) {
            printf("(%zu) ", test_num);
            success_amount +=
                run_not_launched_by_group_name(global_c_tests.tests[i].group_name, was_launched);
            test_num++;
        }
    }

    print_success_out_of(success_amount, n);

    free(was_launched);

    return success_amount;
}

void global_c_tests_init() { c_tests_vector_init(&global_c_tests); }

TEST(c_tests_library, success_init) {
    EXPECT(global_c_tests.tests != NULL);
    EXPECT(global_c_tests.size > 0);
    EXPECT(global_c_tests.capacity > 0);
}

void global_c_tests_clear() { c_tests_vector_clear(&global_c_tests); }
