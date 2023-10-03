#include <stdio.h>

#include "c_tests.h"

TEST(first_group, test_a) {
    printf("Hello from test a\n");
    EXPECT(1 + 1 == 2);
    printf("success\n");
}

TEST(second_group, test_b) {
    printf("Hello from test b\n");
    EXPECT(1 + 1 == 3);
    printf("success\n");
}

int main() {
    printf("Main\n");
    run_all_c_tests();

    return 0;
}