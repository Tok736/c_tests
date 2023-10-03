#include <stdio.h>

#include "c_tests.h"

TEST(first_group, test_a) {
    int a = 1, b = 1;
    EXPECT(a + b == 2);
}

TEST(second_group, test_b) {
    int a = 2, b = 2;
    EXPECT(a + b == 3);
}

int main() {
    run_all_c_tests();

    return 0;
}