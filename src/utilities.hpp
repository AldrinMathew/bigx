#ifndef BIGX_UTILITIES_HPP
#define BIGX_UTILITIES_HPP

#include "./types.hpp"
#include "limits.h"

namespace bigx {
namespace utilities {
/// u64 is a type definition for "unsigned long long". It is understood to have
/// a size of at least 64 bits. However the exact size according to the
/// implementation of the language is required for the library to function
/// properly
constexpr unsigned char u64BitSize = sizeof(u64) * CHAR_BIT;
} // namespace utilities
} // namespace bigx

#endif