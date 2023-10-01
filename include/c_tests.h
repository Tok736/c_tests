#ifndef C_TESTS_H
#define C_TESTS_H

#include "config.h"

// struct c_tests_error_message {
//     int error;
//     char error_message[ERROR_MESSAGE_MAX_LEN];
// };

// #define TEST(group_test_name, test_name)
//     int ##group_test_name_##test_name_test()
//     int ##group_test_name_##test_name_test()

#define EXPECT(bool_value)                                                     \
  if (!(bool_value)) {                                                         \
    return 1;                                                                  \
  }

#endif // C_TESTS_H