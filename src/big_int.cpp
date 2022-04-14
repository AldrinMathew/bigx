#include "./big_int.hpp"

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
  _0 = other._0, _1 = other._1, _2 = other._2, _3 = other._3, _4 = other._4,
  _5 = other._5, _6 = other._6, _7 = other._7, _8 = other._8, _9 = other._9,
  _10 = other._10, _11 = other._11, _12 = other._12, _13 = other._13,
  _14 = other._14, _15 = other._15, _16 = other._16, _17 = other._17,
  _18 = other._18, _19 = other._19, _20 = other._20, _21 = other._21,
  _22 = other._22, _23 = other._23, _24 = other._24, _25 = other._25,
  _26 = other._26, _27 = other._27, _28 = other._28, _29 = other._29,
  _30 = other._30, _31 = other._31, _32 = other._32, _33 = other._33,
  _34 = other._34, _35 = other._35, _36 = other._36, _37 = other._37,
  _38 = other._38, _39 = other._39, _40 = other._40, _41 = other._41,
  _42 = other._42, _43 = other._43, _44 = other._44, _45 = other._45,
  _46 = other._46, _47 = other._47, _48 = other._48, _49 = other._49,
  _50 = other._50, _51 = other._51, _52 = other._52, _53 = other._53,
  _54 = other._54, _55 = other._55, _56 = other._56, _57 = other._57,
  _58 = other._58, _59 = other._59, _60 = other._60, _61 = other._61,
  _62 = other._62, _63 = other._63, _64 = other._64, _65 = other._65,
  _66 = other._66, _67 = other._67, _68 = other._68, _69 = other._69,
  _70 = other._70, _71 = other._71, _72 = other._72, _73 = other._73,
  _74 = other._74, _75 = other._75, _76 = other._76, _77 = other._77,
  _78 = other._78, _79 = other._79, _80 = other._80, _81 = other._81,
  _82 = other._82, _83 = other._83, _84 = other._84, _85 = other._85,
  _86 = other._86, _87 = other._87, _88 = other._88, _89 = other._89,
  _90 = other._90, _91 = other._91, _92 = other._92, _93 = other._93,
  _94 = other._94, _95 = other._95, _96 = other._96, _97 = other._97,
  _98 = other._98, _99 = other._99, _100 = other._100, _101 = other._101,
  _102 = other._102, _103 = other._103, _104 = other._104, _105 = other._105,
  _106 = other._106, _107 = other._107, _108 = other._108, _109 = other._109,
  _110 = other._110, _111 = other._111, _112 = other._112, _113 = other._113,
  _114 = other._114, _115 = other._115, _116 = other._116, _117 = other._117,
  _118 = other._118, _119 = other._119, _120 = other._120, _121 = other._121,
  _122 = other._122, _123 = other._123, _124 = other._124, _125 = other._125,
  _126 = other._126, _127 = other._127, _128 = other._128, _129 = other._129,
  _130 = other._130, _131 = other._131, _132 = other._132, _133 = other._133,
  _134 = other._134, _135 = other._135, _136 = other._136, _137 = other._137,
  _138 = other._138, _139 = other._139, _140 = other._140, _141 = other._141,
  _142 = other._142, _143 = other._143, _144 = other._144, _145 = other._145,
  _146 = other._146, _147 = other._147, _148 = other._148, _149 = other._149,
  _150 = other._150, _151 = other._151, _152 = other._152, _153 = other._153,
  _154 = other._154, _155 = other._155, _156 = other._156, _157 = other._157,
  _158 = other._158, _159 = other._159, _160 = other._160, _161 = other._161,
  _162 = other._162, _163 = other._163, _164 = other._164, _165 = other._165,
  _166 = other._166, _167 = other._167, _168 = other._168, _169 = other._169,
  _170 = other._170, _171 = other._171, _172 = other._172, _173 = other._173,
  _174 = other._174, _175 = other._175, _176 = other._176, _177 = other._177,
  _178 = other._178, _179 = other._179, _180 = other._180, _181 = other._181,
  _182 = other._182, _183 = other._183, _184 = other._184, _185 = other._185,
  _186 = other._186, _187 = other._187, _188 = other._188, _189 = other._189,
  _190 = other._190, _191 = other._191, _192 = other._192, _193 = other._193,
  _194 = other._194, _195 = other._195, _196 = other._196, _197 = other._197,
  _198 = other._198, _199 = other._199, _200 = other._200, _201 = other._201,
  _202 = other._202, _203 = other._203, _204 = other._204, _205 = other._205,
  _206 = other._206, _207 = other._207, _208 = other._208, _209 = other._209,
  _210 = other._210, _211 = other._211, _212 = other._212, _213 = other._213,
  _214 = other._214, _215 = other._215, _216 = other._216, _217 = other._217,
  _218 = other._218, _219 = other._219, _220 = other._220, _221 = other._221,
  _222 = other._222, _223 = other._223, _224 = other._224, _225 = other._225,
  _226 = other._226, _227 = other._227, _228 = other._228, _229 = other._229,
  _230 = other._230, _231 = other._231, _232 = other._232, _233 = other._233,
  _234 = other._234, _235 = other._235, _236 = other._236, _237 = other._237,
  _238 = other._238, _239 = other._239, _240 = other._240, _241 = other._241,
  _242 = other._242, _243 = other._243, _244 = other._244, _245 = other._245,
  _246 = other._246, _247 = other._247, _248 = other._248, _249 = other._249,
  _250 = other._250, _251 = other._251, _252 = other._252, _253 = other._253,
  _254 = other._254, _255 = other._255, _256 = other._256, _257 = other._257,
  _258 = other._258, _259 = other._259, _260 = other._260, _261 = other._261,
  _262 = other._262, _263 = other._263, _264 = other._264, _265 = other._265,
  _266 = other._266, _267 = other._267, _268 = other._268, _269 = other._269,
  _270 = other._270, _271 = other._271, _272 = other._272, _273 = other._273,
  _274 = other._274, _275 = other._275, _276 = other._276, _277 = other._277,
  _278 = other._278, _279 = other._279, _280 = other._280, _281 = other._281,
  _282 = other._282, _283 = other._283, _284 = other._284, _285 = other._285,
  _286 = other._286, _287 = other._287, _288 = other._288, _289 = other._289,
  _290 = other._290, _291 = other._291, _292 = other._292, _293 = other._293,
  _294 = other._294, _295 = other._295, _296 = other._296, _297 = other._297,
  _298 = other._298, _299 = other._299, _300 = other._300, _301 = other._301,
  _302 = other._302, _303 = other._303, _304 = other._304, _305 = other._305,
  _306 = other._306, _307 = other._307, _308 = other._308, _309 = other._309,
  _310 = other._310, _311 = other._311, _312 = other._312, _313 = other._313,
  _314 = other._314, _315 = other._315, _316 = other._316, _317 = other._317,
  _318 = other._318, _319 = other._319, _320 = other._320, _321 = other._321,
  _322 = other._322, _323 = other._323, _324 = other._324, _325 = other._325,
  _326 = other._326, _327 = other._327, _328 = other._328, _329 = other._329,
  _330 = other._330, _331 = other._331, _332 = other._332, _333 = other._333,
  _334 = other._334, _335 = other._335, _336 = other._336, _337 = other._337,
  _338 = other._338, _339 = other._339, _340 = other._340, _341 = other._341,
  _342 = other._342, _343 = other._343, _344 = other._344, _345 = other._345,
  _346 = other._346, _347 = other._347, _348 = other._348, _349 = other._349,
  _350 = other._350, _351 = other._351, _352 = other._352, _353 = other._353,
  _354 = other._354, _355 = other._355, _356 = other._356, _357 = other._357,
  _358 = other._358, _359 = other._359, _360 = other._360, _361 = other._361,
  _362 = other._362, _363 = other._363, _364 = other._364, _365 = other._365,
  _366 = other._366, _367 = other._367, _368 = other._368, _369 = other._369,
  _370 = other._370, _371 = other._371, _372 = other._372, _373 = other._373,
  _374 = other._374, _375 = other._375, _376 = other._376, _377 = other._377,
  _378 = other._378, _379 = other._379, _380 = other._380, _381 = other._381,
  _382 = other._382, _383 = other._383, _384 = other._384, _385 = other._385,
  _386 = other._386, _387 = other._387, _388 = other._388, _389 = other._389,
  _390 = other._390, _391 = other._391, _392 = other._392, _393 = other._393,
  _394 = other._394, _395 = other._395, _396 = other._396, _397 = other._397,
  _398 = other._398, _399 = other._399, _400 = other._400, _401 = other._401,
  _402 = other._402, _403 = other._403, _404 = other._404, _405 = other._405,
  _406 = other._406, _407 = other._407, _408 = other._408, _409 = other._409,
  _410 = other._410, _411 = other._411, _412 = other._412, _413 = other._413,
  _414 = other._414, _415 = other._415, _416 = other._416, _417 = other._417,
  _418 = other._418, _419 = other._419, _420 = other._420, _421 = other._421,
  _422 = other._422, _423 = other._423, _424 = other._424, _425 = other._425,
  _426 = other._426, _427 = other._427, _428 = other._428, _429 = other._429,
  _430 = other._430, _431 = other._431, _432 = other._432, _433 = other._433,
  _434 = other._434, _435 = other._435, _436 = other._436, _437 = other._437,
  _438 = other._438, _439 = other._439, _440 = other._440, _441 = other._441,
  _442 = other._442, _443 = other._443, _444 = other._444, _445 = other._445,
  _446 = other._446, _447 = other._447, _448 = other._448, _449 = other._449,
  _450 = other._450, _451 = other._451, _452 = other._452, _453 = other._453,
  _454 = other._454, _455 = other._455, _456 = other._456, _457 = other._457,
  _458 = other._458, _459 = other._459, _460 = other._460, _461 = other._461,
  _462 = other._462, _463 = other._463, _464 = other._464, _465 = other._465,
  _466 = other._466, _467 = other._467, _468 = other._468, _469 = other._469,
  _470 = other._470, _471 = other._471, _472 = other._472, _473 = other._473,
  _474 = other._474, _475 = other._475, _476 = other._476, _477 = other._477,
  _478 = other._478, _479 = other._479, _480 = other._480, _481 = other._481,
  _482 = other._482, _483 = other._483, _484 = other._484, _485 = other._485,
  _486 = other._486, _487 = other._487, _488 = other._488, _489 = other._489,
  _490 = other._490, _491 = other._491, _492 = other._492, _493 = other._493,
  _494 = other._494, _495 = other._495, _496 = other._496, _497 = other._497,
  _498 = other._498, _499 = other._499, _500 = other._500, _501 = other._501,
  _502 = other._502, _503 = other._503, _504 = other._504, _505 = other._505,
  _506 = other._506, _507 = other._507, _508 = other._508, _509 = other._509,
  _510 = other._510, _511 = other._511;
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