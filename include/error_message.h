#ifndef C_TESTS_ERROR_MESSAGE_H
#define C_TESTS_ERROR_MESSAGE_H

#include "config.h"

typedef struct c_tests_error_message {
    int error;
    char error_message[ERROR_MESSAGE_MAX_LEN];
} c_tests_error_message;

#endif  // C_TESTS_ERROR_MESSAGE_H