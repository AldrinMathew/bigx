#include "exceptions.hpp"

const char *bigx::exceptions::IndexOutOfRange::what() {
  return "The provided index is out of range";
}

const char *bigx::exceptions::NegativeIndex::what() {
  return "The provided index is negative and hence is invalid";
}