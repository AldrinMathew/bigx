#ifndef BIGX_EXCEPTIONS_HPP
#define BIGX_EXCEPTIONS_HPP

#include <exception>

namespace bigx {
namespace exceptions {
class IndexOutOfRange : public std::exception {
  const char *what();
};

class NegativeIndex : public std::exception {
  const char *what();
};
} // namespace exceptions
} // namespace bigx

#endif