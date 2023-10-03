#ifndef C_TESTS_H
#define C_TESTS_H

#include <stdio.h>

#include "c_tests_vector.h"
#include "config.h"
#include "error_message.h"

extern c_tests_vector global_c_tests;

int run_all_c_tests();
void global_c_tests_init() __attribute__((constructor));

#define TEST(group_test_name, test_name)                                        \
    void test_##group_test_name##_##test_name();                                \
    void start_##group_test_name##_##test_name() __attribute__((constructor));  \
    void start_##group_test_name##_##test_name() {                              \
        c_tests_node test = {.test_func = test_##group_test_name##_##test_name, \
                             .group_name = #group_test_name,                    \
                             .name = #test_name};                               \
        c_tests_vector_add(&global_c_tests, &test);                             \
    }                                                                           \
    void test_##group_test_name##_##test_name()

#define EXPECT(bool_value) \
    if (!(bool_value)) {   \
        return;            \
    }

#endif  // C_TESTS_H