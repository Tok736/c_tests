#include <stdio.h>

#include "c_tests.h"

TEST(arithmetic, test_plus) {
    int a = 1, b = 1;
    EXPECT(a + b == 2);
}

TEST(arithmetic, test_minus_fail) {
    int a = 4, b = 2;
    EXPECT(a - b == 1);
}

TEST(many_expects, increment_test) {
    int a = 0;
    a++;
    EXPECT(a == 1);
    a++;
    EXPECT(a == 2);
    a++;
    EXPECT(a == 3);
}

TEST(debug_expect, debug_expect_example) {
    int a = 1;
    a++;
    DEBUG_EXPECT(a == 3) {
        printf("It's a debug expect. When a condition is false this code will be executed\n");
        printf("a = %d\n", a);
    }
}

int main() {
    // Running all the tests
    run_all_c_tests();

    printf("\n=====\n\n");

    // Running only one group of tests
    run_c_test_by_group_name("arithmetic");

    return 0;
}