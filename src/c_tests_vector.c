#include "c_tests_vector.h"

void c_tests_vector_init(c_tests_vector *tests) {
    tests->capacity = C_TESTS_DEFAULT_CAPACITY;
    tests->tests = (c_tests_node *)malloc(tests->capacity * sizeof(c_tests_node));
    tests->size = 0;
}

void c_tests_vector_clear(c_tests_vector *tests) {
    free(tests->tests);
    tests->capacity = 0;
    tests->size = 0;
}

void c_tests_vector_grow(c_tests_vector *tests) {
    tests->capacity *= C_TESTS_GROW_FACTOR;
    tests->tests = (c_tests_node *)realloc(tests->tests, tests->capacity * sizeof(c_tests_node));
}

void c_tests_vector_add(c_tests_vector *tests, const c_tests_node *test) {
    if (tests->size == tests->capacity) c_tests_vector_grow(tests);
    tests->tests[(tests->size)++] = *test;
}
