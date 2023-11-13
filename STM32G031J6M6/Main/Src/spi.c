#include "../Inc/spi.h"
//static SPI_HANDLE_TYPEDEF_STRUCT sHandleSPI;
/*
Dec  Char                           Dec  Char     Dec  Char     Dec  Char
---------                           ---------     ---------     ----------
  0  NUL (null)                      32  SPACE     64  @         96  `
  1  SOH (start of heading)          33  !         65  A         97  a
  2  STX (start of text)             34  "         66  B         98  b
  3  ETX (end of text)               35  #         67  C         99  c
  4  EOT (end of transmission)       36  $         68  D        100  d
  5  ENQ (enquiry)                   37  %         69  E        101  e
  6  ACK (acknowledge)               38  &         70  F        102  f
  7  BEL (bell)                      39  '         71  G        103  g
  8  BS  (backspace)                 40  (         72  H        104  h
  9  TAB (horizontal tab)            41  )         73  I        105  i
 10  LF  (NL line feed, new line)    42  *         74  J        106  j
 11  VT  (vertical tab)              43  +         75  K        107  k
 12  FF  (NP form feed, new page)    44  ,         76  L        108  l
 13  CR  (carriage return)           45  -         77  M        109  m
 14  SO  (shift out)                 46  .         78  N        110  n
 15  SI  (shift in)                  47  /         79  O        111  o
 16  DLE (data link escape)          48  0         80  P        112  p
 17  DC1 (device control 1)          49  1         81  Q        113  q
 18  DC2 (device control 2)          50  2         82  R        114  r
 19  DC3 (device control 3)          51  3         83  S        115  s
 20  DC4 (device control 4)          52  4         84  T        116  t
 21  NAK (negative acknowledge)      53  5         85  U        117  u
 22  SYN (synchronous idle)          54  6         86  V        118  v
 23  ETB (end of trans. block)       55  7         87  W        119  w
 24  CAN (cancel)                    56  8         88  X        120  x
 25  EM  (end of medium)             57  9         89  Y        121  y
 26  SUB (substitute)                58  :         90  Z        122  z
 27  ESC (escape)                    59  ;         91  [        123  {
 28  FS  (file separator)            60  <         92  \        124  |
 29  GS  (group separator)           61  =         93  ]        125  }
 30  RS  (record separator)          62  >         94  ^        126  ~
 31  US  (unit separator)            63  ?         95  _        127  DEL
*/

#define NUL 0
#define SOH 1
#define STX 2
#define ETX 3
#define EOT 4
#define ACK 5

uint8_t led_idx[] = {
    0,  // NULL
    32, // SPACE
    33, // !
    40, // (
    41, // )
    43, // +
    45, // - 
    46, // .
    48, // 0
    49, // 1
    50, // 2
    51, // 3
    52, // 4
    53, // 5
    54, // 6
    55, // 7
    56, // 8
    57, // 9
    58, // :
    65, // A
    66, // B
    67, // C
    68, // D
    69, // E
    70, // F
    71, // G
    72, // H
    73, // I
    74, // J
    75, // K
    76, // L
    77, // M
    78, // N
    79, // O
    80, // P
    81, // Q
    82, // R
    83, // S
    84, // T
    85, // U
    86, // V
    87, // W
    88, // X
    89, // Y
    90, // Z
};

//total 29 led
uint32_t led_segment[] = {
    0x00000001, // NULL
    0x00000002, // SPACE
    0x00000003, // !
    0x00000004, // (
    0x00000005, // )
    0x00000006, // +
    0x00000007, // - 
    0x00000008, // .
    0x00000009, // 0
    0x00000000, // 1
    0x00000000, // 2
    0x00000000, // 3
    0x00000000, // 4
    0x00000000, // 5
    0x00000000, // 6
    0x00000000, // 7
    0x00000000, // 8
    0x00000000, // 9
    0x00000000, // :
    0x00000000, // A
    0x00000000, // B
    0x00000000, // C
    0x00000000, // D
    0x00000000, // E
    0x00000000, // F
    0x00000000, // G
    0x00000000, // H
    0x00000000, // I
    0x00000000, // J
    0x00000000, // K
    0x00000000, // L
    0x00000000, // M
    0x00000000, // N
    0x00000000, // O
    0x00000000, // P
    0x00000000, // Q
    0x00000000, // R
    0x00000000, // S
    0x00000000, // T
    0x00000000, // U
    0x00000000, // V
    0x00000000, // W
    0x00000000, // X
    0x00000000, // Y
    0x00000000, // Z  
};

// down side led 8bit , up side led 8bit
uint16_t led_side[] = {
    0x0101, // NULL
    0x0202, // SPACE
    0x0303, // !
    0x0404, // (
    0x0505, // )
    0x0606, // +
    0x0707, // - 
    0x0808, // .
    0x0909, // 0
    0x0000, // 1
    0x0000, // 2
    0x0000, // 3
    0x0000, // 4
    0x0000, // 5
    0x0000, // 6
    0x0000, // 7
    0x0000, // 8
    0x0000, // 9
    0x0000, // :
    0x0000, // A
    0x0000, // B
    0x0000, // C
    0x0000, // D
    0x0000, // E
    0x0000, // F
    0x0000, // G
    0x0000, // H
    0x0000, // I
    0x0000, // J
    0x0000, // K
    0x0000, // L
    0x0000, // M
    0x0000, // N
    0x0000, // O
    0x0000, // P
    0x0000, // Q
    0x0000, // R
    0x0000, // S
    0x0000, // T
    0x0000, // U
    0x0000, // V
    0x0000, // W
    0x0000, // X
    0x0000, // Y
    0x0000, // Z  
};