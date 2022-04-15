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
    if (_##val == 0) {                                                         \
      _##val = 1;                                                              \
    } else {                                                                   \
      _##val = 0;                                                              \
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

#define _RESET_VALUE_STMT(val) _##val = 0;

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
  _IS_EQUAL_10X_EXPR(1)                                                        \
  _IS_EQUAL_10X_EXPR(2)                                                        \
  _IS_EQUAL_10X_EXPR(3)                                                        \
  _IS_EQUAL_10X_EXPR(4)                                                        \
  _IS_EQUAL_10X_EXPR(5)                                                        \
  _IS_EQUAL_10X_EXPR(6)                                                        \
  _IS_EQUAL_10X_EXPR(7)                                                        \
  _IS_EQUAL_10X_EXPR(8)                                                        \
  _IS_EQUAL_10X_EXPR(9)

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

bool bigx::bigint_cell::has_left() { return left != nullptr; }

bool bigx::bigint_cell::has_right() { return right != nullptr; }

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
    if (_511 == 0) {
      _511 = 1;
    } else {
      _511 = 0;
      if (left == nullptr) {
        extend_left();
      }
      left->increment_at(0);
    }
    break;
  }
  default: {
    throw exceptions::IndexOutOfRange();
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
  if (left == nullptr) {
    if (other.left != nullptr) {
      leftVal = false;
    } else {
      leftVal = true;
    }
  } else {
    if (other.left == nullptr) {
      leftVal = false;
    } else {
      leftVal = ((*left).operator==(other.left));
    }
  }
  if (leftVal) {
    bool rightVal = false;
    if (right == nullptr) {
      if (other.right != nullptr) {
        rightVal = false;
      } else {
        rightVal = true;
      }
    } else {
      if (other.right == nullptr) {
        rightVal = false;
      } else {
        rightVal = ((*right).operator==(other.right));
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