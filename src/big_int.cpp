#include "./big_int.hpp"

#define _COPY_VALUE_STMT(val, object) _##val = object._##val;

#define _COPY_VALUE_10X_STMT(val, object)                                      \
  _COPY_VALUE_STMT(val##0, object)                                             \
  _COPY_VALUE_STMT(val##1, object)                                             \
  _COPY_VALUE_STMT(val##2, object)                                             \
  _COPY_VALUE_STMT(val##3, object)                                             \
  _COPY_VALUE_STMT(val##4, object)                                             \
  _COPY_VALUE_STMT(val##5, object)                                             \
  _COPY_VALUE_STMT(val##6, object)                                             \
  _COPY_VALUE_STMT(val##7, object)                                             \
  _COPY_VALUE_STMT(val##8, object)                                             \
  _COPY_VALUE_STMT(val##9, object)

#define _COPY_VALUE_100X_STMT(val, object)                                     \
  _COPY_VALUE_10X_STMT(val##0, object)                                         \
  _COPY_VALUE_10X_STMT(val##1, object)                                         \
  _COPY_VALUE_10X_STMT(val##2, object)                                         \
  _COPY_VALUE_10X_STMT(val##3, object)                                         \
  _COPY_VALUE_10X_STMT(val##4, object)                                         \
  _COPY_VALUE_10X_STMT(val##5, object)                                         \
  _COPY_VALUE_10X_STMT(val##6, object)                                         \
  _COPY_VALUE_10X_STMT(val##7, object)                                         \
  _COPY_VALUE_10X_STMT(val##8, object)                                         \
  _COPY_VALUE_10X_STMT(val##9, object)

#define _INC_AT_CASE(val)                                                      \
  case val: {                                                                  \
    if (_##val == 0b0) {                                                       \
      _##val = ~_##val;                                                        \
    } else if (_##val == 0b1) {                                                \
      _##val = ~_##val;                                                        \
      increment_at(index + 1);                                                 \
    }                                                                          \
    break;                                                                     \
  }

#define _INC_AT_10X_CASES(val)                                                 \
  _INC_AT_CASE(val##0)                                                         \
  _INC_AT_CASE(val##1)                                                         \
  _INC_AT_CASE(val##2)                                                         \
  _INC_AT_CASE(val##3)                                                         \
  _INC_AT_CASE(val##4)                                                         \
  _INC_AT_CASE(val##5)                                                         \
  _INC_AT_CASE(val##6)                                                         \
  _INC_AT_CASE(val##7)                                                         \
  _INC_AT_CASE(val##8)                                                         \
  _INC_AT_CASE(val##9)

#define _INC_AT_100X_CASES(val)                                                \
  _INC_AT_10X_CASES(val##0)                                                    \
  _INC_AT_10X_CASES(val##1)                                                    \
  _INC_AT_10X_CASES(val##2)                                                    \
  _INC_AT_10X_CASES(val##3)                                                    \
  _INC_AT_10X_CASES(val##4)                                                    \
  _INC_AT_10X_CASES(val##5)                                                    \
  _INC_AT_10X_CASES(val##6)                                                    \
  _INC_AT_10X_CASES(val##7)                                                    \
  _INC_AT_10X_CASES(val##8)                                                    \
  _INC_AT_10X_CASES(val##9)

#define _RESET_VALUE_STMT(val) _##val = 0b0;

#define _RESET_VALUE_10X_STMT(val)                                             \
  _RESET_VALUE_STMT(val##0)                                                    \
  _RESET_VALUE_STMT(val##1)                                                    \
  _RESET_VALUE_STMT(val##2)                                                    \
  _RESET_VALUE_STMT(val##3)                                                    \
  _RESET_VALUE_STMT(val##4)                                                    \
  _RESET_VALUE_STMT(val##5)                                                    \
  _RESET_VALUE_STMT(val##6)                                                    \
  _RESET_VALUE_STMT(val##7)                                                    \
  _RESET_VALUE_STMT(val##8)                                                    \
  _RESET_VALUE_STMT(val##9)

#define _RESET_VALUE_100X_STMT(val)                                            \
  _RESET_VALUE_10X_STMT(val##0)                                                \
  _RESET_VALUE_10X_STMT(val##1)                                                \
  _RESET_VALUE_10X_STMT(val##2)                                                \
  _RESET_VALUE_10X_STMT(val##3)                                                \
  _RESET_VALUE_10X_STMT(val##4)                                                \
  _RESET_VALUE_10X_STMT(val##5)                                                \
  _RESET_VALUE_10X_STMT(val##6)                                                \
  _RESET_VALUE_10X_STMT(val##7)                                                \
  _RESET_VALUE_10X_STMT(val##8)                                                \
  _RESET_VALUE_10X_STMT(val##9)

#define _IS_EQUAL_EXPR(val) (_##val == other._##val) &&

#define _IS_EQUAL_10X_EXPR(val)                                                \
  _IS_EQUAL_EXPR(val##0)                                                       \
  _IS_EQUAL_EXPR(val##1)                                                       \
  _IS_EQUAL_EXPR(val##2)                                                       \
  _IS_EQUAL_EXPR(val##3)                                                       \
  _IS_EQUAL_EXPR(val##4)                                                       \
  _IS_EQUAL_EXPR(val##5)                                                       \
  _IS_EQUAL_EXPR(val##6)                                                       \
  _IS_EQUAL_EXPR(val##7)                                                       \
  _IS_EQUAL_EXPR(val##8)                                                       \
  _IS_EQUAL_EXPR(val##9)

#define _IS_EQUAL_100X_EXPR(val)                                               \
  _IS_EQUAL_10X_EXPR(val##0)                                                   \
  _IS_EQUAL_10X_EXPR(val##1)                                                   \
  _IS_EQUAL_10X_EXPR(val##2)                                                   \
  _IS_EQUAL_10X_EXPR(val##3)                                                   \
  _IS_EQUAL_10X_EXPR(val##4)                                                   \
  _IS_EQUAL_10X_EXPR(val##5)                                                   \
  _IS_EQUAL_10X_EXPR(val##6)                                                   \
  _IS_EQUAL_10X_EXPR(val##7)                                                   \
  _IS_EQUAL_10X_EXPR(val##8)                                                   \
  _IS_EQUAL_10X_EXPR(val##9)

#define _BITSTRING_STMT(val) bit_to_string(_##val) +

#define _BITSTRING_10X_STMT(val)                                               \
  _BITSTRING_STMT(val##9)                                                      \
  _BITSTRING_STMT(val##8)                                                      \
  _BITSTRING_STMT(val##7)                                                      \
  _BITSTRING_STMT(val##6)                                                      \
  _BITSTRING_STMT(val##5)                                                      \
  _BITSTRING_STMT(val##4)                                                      \
  _BITSTRING_STMT(val##3)                                                      \
  _BITSTRING_STMT(val##2)                                                      \
  _BITSTRING_STMT(val##1)                                                      \
  _BITSTRING_STMT(val##0)

#define _BITSTRING_100X_STMT(val)                                              \
  _BITSTRING_10X_STMT(val##9)                                                  \
  _BITSTRING_10X_STMT(val##8)                                                  \
  _BITSTRING_10X_STMT(val##7)                                                  \
  _BITSTRING_10X_STMT(val##6)                                                  \
  _BITSTRING_10X_STMT(val##5)                                                  \
  _BITSTRING_10X_STMT(val##4)                                                  \
  _BITSTRING_10X_STMT(val##3)                                                  \
  _BITSTRING_10X_STMT(val##2)                                                  \
  _BITSTRING_10X_STMT(val##1)                                                  \
  _BITSTRING_10X_STMT(val##0)

bigx::bigint_cell::bigint_cell() { reset(); }

bigx::bigint_cell::bigint_cell(bigint_cell *_right) {
  reset();
  right = _right;
  if (right != nullptr) {
    /// Linking the right-side cell to this instance
    right->left = this;
  }
}

bigx::bigint_cell::bigint_cell(bigint_cell &&other) {
  copy_values(other);
  other.reset();
}

bool bigx::bigint_cell::has_left() const { return left != nullptr; }

bool bigx::bigint_cell::has_right() const { return right != nullptr; }

void bigx::bigint_cell::extend_left() {
  if (has_left()) {
    left->extend_left();
  } else {
    /// This creates a new cell on the left and link it to this instance
    new bigx::bigint_cell(this);
  }
}

void bigx::bigint_cell::trim_left() {
  if (has_left()) {
    if (left->has_left()) {
      left->trim_left();
    } else {
      delete left;
      left = nullptr;
    }
  }
}

void bigx::bigint_cell::copy_values(bigx::bigint_cell &other) {
  _COPY_VALUE_10X_STMT(, other)
  _COPY_VALUE_10X_STMT(1, other)
  _COPY_VALUE_10X_STMT(2, other)
  _COPY_VALUE_10X_STMT(3, other)
  _COPY_VALUE_10X_STMT(4, other)
  _COPY_VALUE_10X_STMT(5, other)
  _COPY_VALUE_10X_STMT(6, other)
  _COPY_VALUE_10X_STMT(7, other)
  _COPY_VALUE_10X_STMT(8, other)
  _COPY_VALUE_10X_STMT(9, other)
  _COPY_VALUE_100X_STMT(1, other)
  _COPY_VALUE_100X_STMT(2, other)
  _COPY_VALUE_100X_STMT(3, other)
  _COPY_VALUE_100X_STMT(4, other)
  _COPY_VALUE_10X_STMT(50, other)
  _COPY_VALUE_STMT(510, other)
  _COPY_VALUE_STMT(511, other)
  left = other.left;
  right = other.right;
}

bigx::bigint_cell &bigx::bigint_cell::operator=(bigx::bigint_cell &&other) {
  copy_values(other);
  other.reset();
  return *this;
}

void bigx::bigint_cell::increment_at(int index) {
  switch (index) {
    _INC_AT_10X_CASES()
    _INC_AT_10X_CASES(1)
    _INC_AT_10X_CASES(2)
    _INC_AT_10X_CASES(3)
    _INC_AT_10X_CASES(4)
    _INC_AT_10X_CASES(5)
    _INC_AT_10X_CASES(6)
    _INC_AT_10X_CASES(7)
    _INC_AT_10X_CASES(8)
    _INC_AT_10X_CASES(9)
    _INC_AT_100X_CASES(1)
    _INC_AT_100X_CASES(2)
    _INC_AT_100X_CASES(3)
    _INC_AT_100X_CASES(4)
    _INC_AT_10X_CASES(50)
    _INC_AT_CASE(510)
  case 511: {
    if (_511 == 0b0) {
      _511 = 0b1;
    } else if (_511 == 0b1) {
      _511 = 0b0;
      if (!has_left()) {
        extend_left();
      }
      left->increment_at(0);
    }
    break;
  }
  default: {
    if (index < 0) {
      throw exceptions::NegativeIndex();
    }
    if (has_left()) {
      left->increment_at(index - 512);
    } else {
      throw exceptions::IndexOutOfRange();
    }
  }
  }
}

bigx::bigint_cell &bigx::bigint_cell::operator++() {
  increment_at(0);
  return *this;
}

bigx::bigint_cell bigx::bigint_cell::operator++(int) {
  increment_at(0);
  return this;
}

bool bigx::bigint_cell::operator==(const bigx::bigint_cell &other) const {
  bool leftVal = false;
  if (has_left()) {
    if (other.has_left()) {
      leftVal = (left->operator==(*(other.left)));
    } else {
      leftVal = false;
    }
  } else {
    if (other.has_left()) {
      leftVal = false;
    } else {
      leftVal = true;
    }
  }
  if (leftVal) {
    bool rightVal = false;
    if (has_right()) {
      if (other.has_right()) {
        rightVal = (right->operator==(*(other.right)));
      } else {
        rightVal = false;
      }
    } else {
      if (other.has_right()) {
        rightVal = false;
      } else {
        rightVal = true;
      }
    }
    if (rightVal) {
      return (_IS_EQUAL_10X_EXPR() _IS_EQUAL_10X_EXPR(1) _IS_EQUAL_10X_EXPR(
          2) _IS_EQUAL_10X_EXPR(3) _IS_EQUAL_10X_EXPR(4) _IS_EQUAL_10X_EXPR(5)
                  _IS_EQUAL_10X_EXPR(6) _IS_EQUAL_10X_EXPR(7)
                      _IS_EQUAL_10X_EXPR(8) _IS_EQUAL_10X_EXPR(9)
                          _IS_EQUAL_100X_EXPR(1) _IS_EQUAL_100X_EXPR(2)
                              _IS_EQUAL_100X_EXPR(3) _IS_EQUAL_100X_EXPR(4)
                                  _IS_EQUAL_10X_EXPR(50)
                                      _IS_EQUAL_EXPR(510)(_511 == other._511));
    } else {
      return rightVal;
    }
  } else {
    return leftVal;
  }
}

bool bigx::bigint_cell::operator==(bigx::bigint_cell &other) {
  bool leftVal = false;
  if (has_left()) {
    if (other.has_left()) {
      leftVal = (left->operator==(*(other.left)));
    } else {
      leftVal = false;
    }
  } else {
    if (other.has_left()) {
      leftVal = false;
    } else {
      leftVal = true;
    }
  }
  if (leftVal) {
    bool rightVal = false;
    if (has_right()) {
      if (other.has_right()) {
        rightVal = (right->operator==(*(other.right)));
      } else {
        rightVal = false;
      }
    } else {
      if (other.has_right()) {
        rightVal = false;
      } else {
        rightVal = true;
      }
    }
    if (rightVal) {
      return (_IS_EQUAL_10X_EXPR() _IS_EQUAL_10X_EXPR(1) _IS_EQUAL_10X_EXPR(
          2) _IS_EQUAL_10X_EXPR(3) _IS_EQUAL_10X_EXPR(4) _IS_EQUAL_10X_EXPR(5)
                  _IS_EQUAL_10X_EXPR(6) _IS_EQUAL_10X_EXPR(7)
                      _IS_EQUAL_10X_EXPR(8) _IS_EQUAL_10X_EXPR(9)
                          _IS_EQUAL_100X_EXPR(1) _IS_EQUAL_100X_EXPR(2)
                              _IS_EQUAL_100X_EXPR(3) _IS_EQUAL_100X_EXPR(4)
                                  _IS_EQUAL_10X_EXPR(50)
                                      _IS_EQUAL_EXPR(510)(_511 == other._511));
    } else {
      return rightVal;
    }
  } else {
    return leftVal;
  };
}

bool bigx::bigint_cell::operator!=(const bigx::bigint_cell &other) const {
  return !(*this == other);
}

bool bigx::bigint_cell::operator!=(bigx::bigint_cell &other) {
  return !(*this == other);
}

void bigx::bigint_cell::loop(std::function<void()> fn) {
  auto count = bigx::bigint_cell();
  while (operator!=(count)) {
    fn();
    count.increment_at(0);
  }
}

void bigx::bigint_cell::reset() {
  _RESET_VALUE_10X_STMT()
  _RESET_VALUE_10X_STMT(1)
  _RESET_VALUE_10X_STMT(2)
  _RESET_VALUE_10X_STMT(3)
  _RESET_VALUE_10X_STMT(4)
  _RESET_VALUE_10X_STMT(5)
  _RESET_VALUE_10X_STMT(6)
  _RESET_VALUE_10X_STMT(7)
  _RESET_VALUE_10X_STMT(8)
  _RESET_VALUE_10X_STMT(9)
  _RESET_VALUE_100X_STMT(1)
  _RESET_VALUE_100X_STMT(2)
  _RESET_VALUE_100X_STMT(3)
  _RESET_VALUE_100X_STMT(4)
  _RESET_VALUE_10X_STMT(50)
  _RESET_VALUE_STMT(510)
  _RESET_VALUE_STMT(511)
  left = nullptr;
  right = nullptr;
}

void bigx::bigint_cell::assign_at(uint64_t index, bool value) {
  if (index == 0) {
    _0 = value ? 0b1 : 0b0;
  }
  _ASSIGN_VALUE_STMT(1)
  _ASSIGN_VALUE_STMT(2)
  _ASSIGN_VALUE_STMT(3)
  _ASSIGN_VALUE_STMT(4)
  _ASSIGN_VALUE_STMT(5)
  _ASSIGN_VALUE_STMT(6)
  _ASSIGN_VALUE_STMT(7)
  _ASSIGN_VALUE_STMT(8)
  _ASSIGN_VALUE_STMT(9)
  _ASSIGN_VALUE_10X_STMT(1)
  _ASSIGN_VALUE_10X_STMT(2)
  _ASSIGN_VALUE_10X_STMT(3)
  _ASSIGN_VALUE_10X_STMT(4)
  _ASSIGN_VALUE_10X_STMT(5)
  _ASSIGN_VALUE_10X_STMT(6)
  _ASSIGN_VALUE_10X_STMT(7)
  _ASSIGN_VALUE_10X_STMT(8)
  _ASSIGN_VALUE_10X_STMT(9)
  _ASSIGN_VALUE_100X_STMT(1)
  _ASSIGN_VALUE_100X_STMT(2)
  _ASSIGN_VALUE_100X_STMT(3)
  _ASSIGN_VALUE_100X_STMT(4)
  _ASSIGN_VALUE_10X_STMT(50)
  _ASSIGN_VALUE_STMT(510) _ASSIGN_VALUE_STMT(511) else {
    if (has_left()) {
      assign_at(index - 512, value);
    } else {
      throw exceptions::IndexOutOfRange();
    }
  }
}

void bigx::bigint_cell::increment_string(std::string &result, size_t index) {
  if (index == result.length()) {
    result = "1" + result;
  } else if (index < result.length()) {
    auto i = result.length() - index - 1;
    switch (result.at(i)) {
    case '0': {
      result[i] = '1';
      break;
    }
    case '1': {
      result[i] = '2';
      break;
    }
    case '2': {
      result[i] = '3';
      break;
    }
    case '3': {
      result[i] = '4';
      break;
    }
    case '4': {
      result[i] = '5';
      break;
    }
    case '5': {
      result[i] = '6';
      break;
    }
    case '6': {
      result[i] = '7';
      break;
    }
    case '7': {
      result[i] = '8';
      break;
    }
    case '8': {
      result[i] = '9';
      break;
    }
    case '9': {
      result[i] = '0';
      increment_string(result, index + 1);
      break;
    }
    }
  }
}

std::string bigx::bigint_cell::to_string() {
  std::string result = "0";
  auto fn = [&result, this]() { this->increment_string(result, 0); };
  loop(fn);
  return result;
}

std::string bigx::bigint_cell::to_binary_string() {
  std::string result = "";
  if (has_left()) {
    result += left->to_binary_string();
  }
  result +=
      (_BITSTRING_STMT(511) _BITSTRING_STMT(510) _BITSTRING_10X_STMT(50)
           _BITSTRING_100X_STMT(4) _BITSTRING_100X_STMT(3)
               _BITSTRING_100X_STMT(2) _BITSTRING_100X_STMT(1)
                   _BITSTRING_10X_STMT(9) _BITSTRING_10X_STMT(8)
                       _BITSTRING_10X_STMT(7) _BITSTRING_10X_STMT(6)
                           _BITSTRING_10X_STMT(5) _BITSTRING_10X_STMT(4)
                               _BITSTRING_10X_STMT(3) _BITSTRING_10X_STMT(2)
                                   _BITSTRING_10X_STMT(1)
                                       _BITSTRING_10X_STMT() "");
  return result;
}

std::string bigx::bigint_cell::bit_to_string(bool val) {
  if (val) {
    return "1";
  } else {
    return "0";
  }
}