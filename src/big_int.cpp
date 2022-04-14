#include "./big_int.hpp"

bigx::bigint_cell::bigint_cell(bigint_cell *_right)
    : right(_right), left(nullptr), _0(0), _1(0), _2(0), _3(0), _4(0), _5(0),
      _6(0), _7(0) {
  /// Linking the right-side cell to this instance
  this->right->left = this;
}

bigx::bigint_cell::bigint_cell(bigint_cell &&other) {
  this->_0 = other._0;
  this->_1 = other._1;
  this->_2 = other._2;
  this->_3 = other._3;
  this->_4 = other._4;
  this->_5 = other._5;
  this->_6 = other._6;
  this->_7 = other._7;
  this->left = other.left;
  this->right = other.right;
  other._0 = 0;
  other._1 = 0;
  other._2 = 0;
  other._3 = 0;
  other._4 = 0;
  other._5 = 0;
  other._6 = 0;
  other._7 = 0;
  other.left = nullptr;
  other.right = nullptr;
}

bool bigx::bigint_cell::has_left() { return this->left != nullptr; }

bool bigx::bigint_cell::has_right() { return this->right != nullptr; }

void bigx::bigint_cell::extend_left() {
  if (this->has_left()) {
    this->left->extend_left();
  } else {
    /// This creates a new cell on the left and link it to this instance
    new bigx::bigint_cell(this);
  }
}

void bigx::bigint_cell::trim_left() {
  if (this->has_left()) {
    if (this->left->has_left()) {
      this->left->trim_left();
    } else {
      delete this->left;
      this->left = nullptr;
    }
  }
}

bigx::bigint_cell &bigx::bigint_cell::operator=(bigx::bigint_cell &&other) {
  this->_0 = other._0;
  this->_1 = other._1;
  this->_2 = other._2;
  this->_3 = other._3;
  this->_4 = other._4;
  this->_5 = other._5;
  this->_6 = other._6;
  this->_7 = other._7;
  this->left = other.left;
  this->right = other.right;
  other._0 = 0;
  other._1 = 0;
  other._2 = 0;
  other._3 = 0;
  other._4 = 0;
  other._5 = 0;
  other._6 = 0;
  other._7 = 0;
  other.left = nullptr;
  other.right = nullptr;
  return *this;
}