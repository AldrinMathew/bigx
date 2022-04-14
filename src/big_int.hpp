#ifndef BIGX_INT_HPP
#define BIGX_INT_HPP

#include "./exceptions.hpp"
#include "./types.hpp"

namespace bigx {
/**
 * @brief A bigint_cell is a unit that is connected to other bigint_cell
 * instances. All these connected instances make up the big integer number.
 *
 * Efficiency as provided below is in the sense of how much of the struct's
 * allocation space is used to store the actual number. These values are
 * according to the understanding that the size of "unsigned long long" is at
 * least 64-bit
 *  _______________________________
 * |                |              |
 * |  Architecture  |  Efficiency  |
 * |________________|______________|
 * |                |              |
 * |     64-bit     |      80%     |
 * |________________|______________|
 * |                |              |
 * |     32-bit     |    88.89%    |
 * |________________|______________|
 *
 */
struct bigint_cell {
  /**
   * @brief Construct a new bigint_cell object
   *
   * @param _right The right-side cell to link the new instance to
   */
  bigint_cell(bigint_cell *_right);

  /**
   * @brief Move constructor of bigint_cell
   *
   * @param other The rvalue of the other instance
   */
  bigint_cell(bigint_cell &&other);

  /**
   * @brief These variables hold the actual bit-data associated with the big
   * integer.
   */
  u64 _0, _1, _2, _3, _4, _5, _6, _7;
  /// The left-side bigint_cell this instance is linked to.
  bigint_cell *left;
  /// The right-side bigint_cell this instance is linked to.
  bigint_cell *right;

  /// Whether this cell is linked to another cell on the left side
  bool has_left();
  /// Whether this cell is linked to another cell on the right side
  bool has_right();
  /// Add another cell to the left end of the sequence of cells
  void extend_left();
  /// Trim the extreme left cell in the linked sequence
  void trim_left();
  /// Move assignment operator for bigint_cell
  bigint_cell &operator=(bigint_cell &&cell);
};
} // namespace bigx

#endif

  /**
   * @brief Construct a new bigint_cell object
   *
   * @param _right The right-side cell to link the new instance to
   */
  bigint_cell(bigint_cell *_right);
};
} // namespace bigx

#endif