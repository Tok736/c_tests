#ifndef C_TESTS_VECTOR_H
#define C_TESTS_VECTOR_H

#include <stdbool.h>
#include <stdlib.h>

#include "config.h"
#include "error_message.h"

#define C_TESTS_DEFAULT_CAPACITY 8
#define C_TESTS_GROW_FACTOR 2

typedef struct c_tests_node {
    void (*test_func)(c_tests_error_message *);
    char group_name[GROUP_TEST_NAME_MAX_LEN];
    char name[TEST_NAME_MAX_LEN];
} c_tests_node;

typedef struct c_tests_vector {
    c_tests_node *tests;
    size_t capacity;
    size_t size;
} c_tests_vector;

void c_tests_vector_init(c_tests_vector *tests);
void c_tests_vector_clear(c_tests_vector *tests);
void c_tests_vector_grow(c_tests_vector *tests);
void c_tests_vector_add(c_tests_vector *tests, const c_tests_node *test);

#endif  // C_TESTS_VECTOR_H