#include <stdio.h>

#include "c_tests.h"

int main() {

  EXPECT(1 + 2 == 3);

  printf("first test passed\n");

  EXPECT(1 + 1 == 3);

  printf("second test passed");

  return 0;
}