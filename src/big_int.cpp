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

bigx::bigint_cell bigx::bigint_cell::operator++() { increment_at(0); }

void bigx::bigint_cell::reset() {
  _0 = 0, _1 = 0, _2 = 0, _3 = 0, _4 = 0, _5 = 0, _6 = 0, _7 = 0, _8 = 0,
  _9 = 0, _10 = 0, _11 = 0, _12 = 0, _13 = 0, _14 = 0, _15 = 0, _16 = 0,
  _17 = 0, _18 = 0, _19 = 0, _20 = 0, _21 = 0, _22 = 0, _23 = 0, _24 = 0,
  _25 = 0, _26 = 0, _27 = 0, _28 = 0, _29 = 0, _30 = 0, _31 = 0, _32 = 0,
  _33 = 0, _34 = 0, _35 = 0, _36 = 0, _37 = 0, _38 = 0, _39 = 0, _40 = 0,
  _41 = 0, _42 = 0, _43 = 0, _44 = 0, _45 = 0, _46 = 0, _47 = 0, _48 = 0,
  _49 = 0, _50 = 0, _51 = 0, _52 = 0, _53 = 0, _54 = 0, _55 = 0, _56 = 0,
  _57 = 0, _58 = 0, _59 = 0, _60 = 0, _61 = 0, _62 = 0, _63 = 0, _64 = 0,
  _65 = 0, _66 = 0, _67 = 0, _68 = 0, _69 = 0, _70 = 0, _71 = 0, _72 = 0,
  _73 = 0, _74 = 0, _75 = 0, _76 = 0, _77 = 0, _78 = 0, _79 = 0, _80 = 0,
  _81 = 0, _82 = 0, _83 = 0, _84 = 0, _85 = 0, _86 = 0, _87 = 0, _88 = 0,
  _89 = 0, _90 = 0, _91 = 0, _92 = 0, _93 = 0, _94 = 0, _95 = 0, _96 = 0,
  _97 = 0, _98 = 0, _99 = 0, _100 = 0, _101 = 0, _102 = 0, _103 = 0, _104 = 0,
  _105 = 0, _106 = 0, _107 = 0, _108 = 0, _109 = 0, _110 = 0, _111 = 0,
  _112 = 0, _113 = 0, _114 = 0, _115 = 0, _116 = 0, _117 = 0, _118 = 0,
  _119 = 0, _120 = 0, _121 = 0, _122 = 0, _123 = 0, _124 = 0, _125 = 0,
  _126 = 0, _127 = 0, _128 = 0, _129 = 0, _130 = 0, _131 = 0, _132 = 0,
  _133 = 0, _134 = 0, _135 = 0, _136 = 0, _137 = 0, _138 = 0, _139 = 0,
  _140 = 0, _141 = 0, _142 = 0, _143 = 0, _144 = 0, _145 = 0, _146 = 0,
  _147 = 0, _148 = 0, _149 = 0, _150 = 0, _151 = 0, _152 = 0, _153 = 0,
  _154 = 0, _155 = 0, _156 = 0, _157 = 0, _158 = 0, _159 = 0, _160 = 0,
  _161 = 0, _162 = 0, _163 = 0, _164 = 0, _165 = 0, _166 = 0, _167 = 0,
  _168 = 0, _169 = 0, _170 = 0, _171 = 0, _172 = 0, _173 = 0, _174 = 0,
  _175 = 0, _176 = 0, _177 = 0, _178 = 0, _179 = 0, _180 = 0, _181 = 0,
  _182 = 0, _183 = 0, _184 = 0, _185 = 0, _186 = 0, _187 = 0, _188 = 0,
  _189 = 0, _190 = 0, _191 = 0, _192 = 0, _193 = 0, _194 = 0, _195 = 0,
  _196 = 0, _197 = 0, _198 = 0, _199 = 0, _200 = 0, _201 = 0, _202 = 0,
  _203 = 0, _204 = 0, _205 = 0, _206 = 0, _207 = 0, _208 = 0, _209 = 0,
  _210 = 0, _211 = 0, _212 = 0, _213 = 0, _214 = 0, _215 = 0, _216 = 0,
  _217 = 0, _218 = 0, _219 = 0, _220 = 0, _221 = 0, _222 = 0, _223 = 0,
  _224 = 0, _225 = 0, _226 = 0, _227 = 0, _228 = 0, _229 = 0, _230 = 0,
  _231 = 0, _232 = 0, _233 = 0, _234 = 0, _235 = 0, _236 = 0, _237 = 0,
  _238 = 0, _239 = 0, _240 = 0, _241 = 0, _242 = 0, _243 = 0, _244 = 0,
  _245 = 0, _246 = 0, _247 = 0, _248 = 0, _249 = 0, _250 = 0, _251 = 0,
  _252 = 0, _253 = 0, _254 = 0, _255 = 0, _256 = 0, _257 = 0, _258 = 0,
  _259 = 0, _260 = 0, _261 = 0, _262 = 0, _263 = 0, _264 = 0, _265 = 0,
  _266 = 0, _267 = 0, _268 = 0, _269 = 0, _270 = 0, _271 = 0, _272 = 0,
  _273 = 0, _274 = 0, _275 = 0, _276 = 0, _277 = 0, _278 = 0, _279 = 0,
  _280 = 0, _281 = 0, _282 = 0, _283 = 0, _284 = 0, _285 = 0, _286 = 0,
  _287 = 0, _288 = 0, _289 = 0, _290 = 0, _291 = 0, _292 = 0, _293 = 0,
  _294 = 0, _295 = 0, _296 = 0, _297 = 0, _298 = 0, _299 = 0, _300 = 0,
  _301 = 0, _302 = 0, _303 = 0, _304 = 0, _305 = 0, _306 = 0, _307 = 0,
  _308 = 0, _309 = 0, _310 = 0, _311 = 0, _312 = 0, _313 = 0, _314 = 0,
  _315 = 0, _316 = 0, _317 = 0, _318 = 0, _319 = 0, _320 = 0, _321 = 0,
  _322 = 0, _323 = 0, _324 = 0, _325 = 0, _326 = 0, _327 = 0, _328 = 0,
  _329 = 0, _330 = 0, _331 = 0, _332 = 0, _333 = 0, _334 = 0, _335 = 0,
  _336 = 0, _337 = 0, _338 = 0, _339 = 0, _340 = 0, _341 = 0, _342 = 0,
  _343 = 0, _344 = 0, _345 = 0, _346 = 0, _347 = 0, _348 = 0, _349 = 0,
  _350 = 0, _351 = 0, _352 = 0, _353 = 0, _354 = 0, _355 = 0, _356 = 0,
  _357 = 0, _358 = 0, _359 = 0, _360 = 0, _361 = 0, _362 = 0, _363 = 0,
  _364 = 0, _365 = 0, _366 = 0, _367 = 0, _368 = 0, _369 = 0, _370 = 0,
  _371 = 0, _372 = 0, _373 = 0, _374 = 0, _375 = 0, _376 = 0, _377 = 0,
  _378 = 0, _379 = 0, _380 = 0, _381 = 0, _382 = 0, _383 = 0, _384 = 0,
  _385 = 0, _386 = 0, _387 = 0, _388 = 0, _389 = 0, _390 = 0, _391 = 0,
  _392 = 0, _393 = 0, _394 = 0, _395 = 0, _396 = 0, _397 = 0, _398 = 0,
  _399 = 0, _400 = 0, _401 = 0, _402 = 0, _403 = 0, _404 = 0, _405 = 0,
  _406 = 0, _407 = 0, _408 = 0, _409 = 0, _410 = 0, _411 = 0, _412 = 0,
  _413 = 0, _414 = 0, _415 = 0, _416 = 0, _417 = 0, _418 = 0, _419 = 0,
  _420 = 0, _421 = 0, _422 = 0, _423 = 0, _424 = 0, _425 = 0, _426 = 0,
  _427 = 0, _428 = 0, _429 = 0, _430 = 0, _431 = 0, _432 = 0, _433 = 0,
  _434 = 0, _435 = 0, _436 = 0, _437 = 0, _438 = 0, _439 = 0, _440 = 0,
  _441 = 0, _442 = 0, _443 = 0, _444 = 0, _445 = 0, _446 = 0, _447 = 0,
  _448 = 0, _449 = 0, _450 = 0, _451 = 0, _452 = 0, _453 = 0, _454 = 0,
  _455 = 0, _456 = 0, _457 = 0, _458 = 0, _459 = 0, _460 = 0, _461 = 0,
  _462 = 0, _463 = 0, _464 = 0, _465 = 0, _466 = 0, _467 = 0, _468 = 0,
  _469 = 0, _470 = 0, _471 = 0, _472 = 0, _473 = 0, _474 = 0, _475 = 0,
  _476 = 0, _477 = 0, _478 = 0, _479 = 0, _480 = 0, _481 = 0, _482 = 0,
  _483 = 0, _484 = 0, _485 = 0, _486 = 0, _487 = 0, _488 = 0, _489 = 0,
  _490 = 0, _491 = 0, _492 = 0, _493 = 0, _494 = 0, _495 = 0, _496 = 0,
  _497 = 0, _498 = 0, _499 = 0, _500 = 0, _501 = 0, _502 = 0, _503 = 0,
  _504 = 0, _505 = 0, _506 = 0, _507 = 0, _508 = 0, _509 = 0, _510 = 0,
  _511 = 0;
  left = nullptr;
  right = nullptr;
}