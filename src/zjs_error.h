// Copyright (c) 2017, Intel Corporation.

#ifndef __zjs_error_h__
#define __zjs_error_h__

#include "jerry-api.h"

typedef enum zjs_error_type {
    AssertionError,
    NetworkError,
    NotSupportedError,
    RangeError,
    SecurityError,
    SyntaxError,
    SystemError,
    TimeoutError,
    TypeError,
    Error
} zjs_error_type_t;

/** Initialize the error module, or reinitialize after cleanup. */
void zjs_error_init();

/** Release resources held by the error module. */
void zjs_error_cleanup();

/**
 * Create an error object to return from an API.
 *
 * @param type An error type from zjs_error_type enum.
 * @param message String for additional detail about the error.
 *
 * @return A new Error or subclass object.
 */
jerry_value_t zjs_standard_error(zjs_error_type_t type, const char *message);

#define zjs_error(msg)          (zjs_standard_error(Error, (msg)))

#define ASSERTION_ERROR(msg)    (zjs_standard_error(AssertionError, (msg)))
#define SECURITY_ERROR(msg)     (zjs_standard_error(SecurityError, (msg)))
#define NOTSUPPORTED_ERROR(msg) (zjs_standard_error(NotSupportedError, (msg)))
#define SYNTAX_ERROR(msg)       (zjs_standard_error(SyntaxError, (msg)))
#define TYPE_ERROR(msg)         (zjs_standard_error(TypeError, (msg)))
#define RANGE_ERROR(msg)        (zjs_standard_error(RangeError, (msg)))
#define TIMEOUT_ERROR(msg)      (zjs_standard_error(TimeoutError, (msg)))
#define NETWORK_ERROR(msg)      (zjs_standard_error(NetworkError, (msg)))
#define SYSTEM_ERROR(msg)       (zjs_standard_error(SystemError, (msg)))

#endif  // __zjs_error_h__
