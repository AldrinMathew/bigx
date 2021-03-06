#ifndef BIGX_INT_HPP
#define BIGX_INT_HPP

#include "./exceptions.hpp"
#include "limits.h"
#include <cstdint>
#include <functional>
#include <iostream>
#include <string>

namespace bigx {

/**
 * @brief A bigint_cell is a unit that is connected to other bigint_cell
 * instances. All these connected instances make up the big integer number.
 *
 * Efficiency as provided below is in the sense of how much of the struct's
 * allocation space is used to store the actual number.
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
   * @brief Default constructor
   *
   */
  bigint_cell();

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
   * @brief Construct a new bigint_cell from an int
   *
   * @param value is the integer to be converted to bigint_cell
   */
  bigint_cell(int value);
  /**
   * @brief Construct a new bigint_cell from a uint64_t
   *
   * @param value is the 64-bit integer to be converted to bigint_cell
   */
  bigint_cell(uint64_t value);
  /**
   * @brief Construct a new bigint_cell from a "unsigned long long"
   *
   * @param value is the "unsigned long long" integer to be converted to
   * bigint_cell
   */
  bigint_cell(unsigned long long value);

  /**
   * @brief These variables hold the actual bit-data associated with the big
   * integer.
   */
  std::uint64_t _0 : 1, _1 : 1, _2 : 1, _3 : 1, _4 : 1, _5 : 1, _6 : 1, _7 : 1,
      _8 : 1, _9 : 1, _10 : 1, _11 : 1, _12 : 1, _13 : 1, _14 : 1, _15 : 1,
      _16 : 1, _17 : 1, _18 : 1, _19 : 1, _20 : 1, _21 : 1, _22 : 1, _23 : 1,
      _24 : 1, _25 : 1, _26 : 1, _27 : 1, _28 : 1, _29 : 1, _30 : 1, _31 : 1,
      _32 : 1, _33 : 1, _34 : 1, _35 : 1, _36 : 1, _37 : 1, _38 : 1, _39 : 1,
      _40 : 1, _41 : 1, _42 : 1, _43 : 1, _44 : 1, _45 : 1, _46 : 1, _47 : 1,
      _48 : 1, _49 : 1, _50 : 1, _51 : 1, _52 : 1, _53 : 1, _54 : 1, _55 : 1,
      _56 : 1, _57 : 1, _58 : 1, _59 : 1, _60 : 1, _61 : 1, _62 : 1, _63 : 1,
      _64 : 1, _65 : 1, _66 : 1, _67 : 1, _68 : 1, _69 : 1, _70 : 1, _71 : 1,
      _72 : 1, _73 : 1, _74 : 1, _75 : 1, _76 : 1, _77 : 1, _78 : 1, _79 : 1,
      _80 : 1, _81 : 1, _82 : 1, _83 : 1, _84 : 1, _85 : 1, _86 : 1, _87 : 1,
      _88 : 1, _89 : 1, _90 : 1, _91 : 1, _92 : 1, _93 : 1, _94 : 1, _95 : 1,
      _96 : 1, _97 : 1, _98 : 1, _99 : 1, _100 : 1, _101 : 1, _102 : 1,
      _103 : 1, _104 : 1, _105 : 1, _106 : 1, _107 : 1, _108 : 1, _109 : 1,
      _110 : 1, _111 : 1, _112 : 1, _113 : 1, _114 : 1, _115 : 1, _116 : 1,
      _117 : 1, _118 : 1, _119 : 1, _120 : 1, _121 : 1, _122 : 1, _123 : 1,
      _124 : 1, _125 : 1, _126 : 1, _127 : 1, _128 : 1, _129 : 1, _130 : 1,
      _131 : 1, _132 : 1, _133 : 1, _134 : 1, _135 : 1, _136 : 1, _137 : 1,
      _138 : 1, _139 : 1, _140 : 1, _141 : 1, _142 : 1, _143 : 1, _144 : 1,
      _145 : 1, _146 : 1, _147 : 1, _148 : 1, _149 : 1, _150 : 1, _151 : 1,
      _152 : 1, _153 : 1, _154 : 1, _155 : 1, _156 : 1, _157 : 1, _158 : 1,
      _159 : 1, _160 : 1, _161 : 1, _162 : 1, _163 : 1, _164 : 1, _165 : 1,
      _166 : 1, _167 : 1, _168 : 1, _169 : 1, _170 : 1, _171 : 1, _172 : 1,
      _173 : 1, _174 : 1, _175 : 1, _176 : 1, _177 : 1, _178 : 1, _179 : 1,
      _180 : 1, _181 : 1, _182 : 1, _183 : 1, _184 : 1, _185 : 1, _186 : 1,
      _187 : 1, _188 : 1, _189 : 1, _190 : 1, _191 : 1, _192 : 1, _193 : 1,
      _194 : 1, _195 : 1, _196 : 1, _197 : 1, _198 : 1, _199 : 1, _200 : 1,
      _201 : 1, _202 : 1, _203 : 1, _204 : 1, _205 : 1, _206 : 1, _207 : 1,
      _208 : 1, _209 : 1, _210 : 1, _211 : 1, _212 : 1, _213 : 1, _214 : 1,
      _215 : 1, _216 : 1, _217 : 1, _218 : 1, _219 : 1, _220 : 1, _221 : 1,
      _222 : 1, _223 : 1, _224 : 1, _225 : 1, _226 : 1, _227 : 1, _228 : 1,
      _229 : 1, _230 : 1, _231 : 1, _232 : 1, _233 : 1, _234 : 1, _235 : 1,
      _236 : 1, _237 : 1, _238 : 1, _239 : 1, _240 : 1, _241 : 1, _242 : 1,
      _243 : 1, _244 : 1, _245 : 1, _246 : 1, _247 : 1, _248 : 1, _249 : 1,
      _250 : 1, _251 : 1, _252 : 1, _253 : 1, _254 : 1, _255 : 1, _256 : 1,
      _257 : 1, _258 : 1, _259 : 1, _260 : 1, _261 : 1, _262 : 1, _263 : 1,
      _264 : 1, _265 : 1, _266 : 1, _267 : 1, _268 : 1, _269 : 1, _270 : 1,
      _271 : 1, _272 : 1, _273 : 1, _274 : 1, _275 : 1, _276 : 1, _277 : 1,
      _278 : 1, _279 : 1, _280 : 1, _281 : 1, _282 : 1, _283 : 1, _284 : 1,
      _285 : 1, _286 : 1, _287 : 1, _288 : 1, _289 : 1, _290 : 1, _291 : 1,
      _292 : 1, _293 : 1, _294 : 1, _295 : 1, _296 : 1, _297 : 1, _298 : 1,
      _299 : 1, _300 : 1, _301 : 1, _302 : 1, _303 : 1, _304 : 1, _305 : 1,
      _306 : 1, _307 : 1, _308 : 1, _309 : 1, _310 : 1, _311 : 1, _312 : 1,
      _313 : 1, _314 : 1, _315 : 1, _316 : 1, _317 : 1, _318 : 1, _319 : 1,
      _320 : 1, _321 : 1, _322 : 1, _323 : 1, _324 : 1, _325 : 1, _326 : 1,
      _327 : 1, _328 : 1, _329 : 1, _330 : 1, _331 : 1, _332 : 1, _333 : 1,
      _334 : 1, _335 : 1, _336 : 1, _337 : 1, _338 : 1, _339 : 1, _340 : 1,
      _341 : 1, _342 : 1, _343 : 1, _344 : 1, _345 : 1, _346 : 1, _347 : 1,
      _348 : 1, _349 : 1, _350 : 1, _351 : 1, _352 : 1, _353 : 1, _354 : 1,
      _355 : 1, _356 : 1, _357 : 1, _358 : 1, _359 : 1, _360 : 1, _361 : 1,
      _362 : 1, _363 : 1, _364 : 1, _365 : 1, _366 : 1, _367 : 1, _368 : 1,
      _369 : 1, _370 : 1, _371 : 1, _372 : 1, _373 : 1, _374 : 1, _375 : 1,
      _376 : 1, _377 : 1, _378 : 1, _379 : 1, _380 : 1, _381 : 1, _382 : 1,
      _383 : 1, _384 : 1, _385 : 1, _386 : 1, _387 : 1, _388 : 1, _389 : 1,
      _390 : 1, _391 : 1, _392 : 1, _393 : 1, _394 : 1, _395 : 1, _396 : 1,
      _397 : 1, _398 : 1, _399 : 1, _400 : 1, _401 : 1, _402 : 1, _403 : 1,
      _404 : 1, _405 : 1, _406 : 1, _407 : 1, _408 : 1, _409 : 1, _410 : 1,
      _411 : 1, _412 : 1, _413 : 1, _414 : 1, _415 : 1, _416 : 1, _417 : 1,
      _418 : 1, _419 : 1, _420 : 1, _421 : 1, _422 : 1, _423 : 1, _424 : 1,
      _425 : 1, _426 : 1, _427 : 1, _428 : 1, _429 : 1, _430 : 1, _431 : 1,
      _432 : 1, _433 : 1, _434 : 1, _435 : 1, _436 : 1, _437 : 1, _438 : 1,
      _439 : 1, _440 : 1, _441 : 1, _442 : 1, _443 : 1, _444 : 1, _445 : 1,
      _446 : 1, _447 : 1, _448 : 1, _449 : 1, _450 : 1, _451 : 1, _452 : 1,
      _453 : 1, _454 : 1, _455 : 1, _456 : 1, _457 : 1, _458 : 1, _459 : 1,
      _460 : 1, _461 : 1, _462 : 1, _463 : 1, _464 : 1, _465 : 1, _466 : 1,
      _467 : 1, _468 : 1, _469 : 1, _470 : 1, _471 : 1, _472 : 1, _473 : 1,
      _474 : 1, _475 : 1, _476 : 1, _477 : 1, _478 : 1, _479 : 1, _480 : 1,
      _481 : 1, _482 : 1, _483 : 1, _484 : 1, _485 : 1, _486 : 1, _487 : 1,
      _488 : 1, _489 : 1, _490 : 1, _491 : 1, _492 : 1, _493 : 1, _494 : 1,
      _495 : 1, _496 : 1, _497 : 1, _498 : 1, _499 : 1, _500 : 1, _501 : 1,
      _502 : 1, _503 : 1, _504 : 1, _505 : 1, _506 : 1, _507 : 1, _508 : 1,
      _509 : 1, _510 : 1, _511 : 1;
  /// The left-side bigint_cell this instance is linked to.
  bigint_cell *left;
  /// The right-side bigint_cell this instance is linked to.
  bigint_cell *right;

  /// Whether this cell is linked to another cell on the left side
  bool has_left() const;
  /// Whether this cell is linked to another cell on the right side
  bool has_right() const;
  /// Add another cell to the left end of the sequence of cells
  void extend_left();
  /// Trim the extreme left cell in the linked sequence
  void trim_left();
  /// Reset all values and set all pointers to null
  void reset();
  /// Move assignment operator for bigint_cell
  bigint_cell &operator=(bigint_cell &&cell);
  /// Increment Operator - Prefix
  bigint_cell &operator++();
  /// Increment Operator - Postfix
  bigint_cell operator++(int);
  /// Equality Operator
  bool operator==(const bigx::bigint_cell &other) const;
  bool operator==(bigx::bigint_cell &other);
  /// Inequality Operator
  bool operator!=(const bigx::bigint_cell &other) const;
  bool operator!=(bigx::bigint_cell &other);
  /**
   * @brief Loops as many times as is represented by this bigint_cell number and
   * calls the provided function
   *
   * @param fn Function to be called in each and every iteration
   */
  void loop(std::function<void()> fn);
  /// Convert this number to a binary string
  std::string to_binary_string();
  /// Convert this number to a string
  std::string to_string();
  /// This function increments the value at a particular bit position
  void increment_at(int index);

private:
  /// Copy values from other bigint_cell instance
  void copy_values(bigint_cell &other);

  void assign_at(uint64_t index, bool val);

  void increment_string(std::string &result, size_t index);

  inline static std::string bit_to_string(bool val);
};
} // namespace bigx

#endif