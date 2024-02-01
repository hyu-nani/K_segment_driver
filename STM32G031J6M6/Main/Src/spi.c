
#include <main.h>
#include "../Inc/user_main.h"
#include <string.h>
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

#define SPI_HANDLE          &hspi1 
#define SPI_IRQn            SPI1_IRQn
#define SPI_RX_CNT          (SPI_HANDLE)->RxXferCount
#define SPI_RX_LEN          PROTOCOL_LEN

SPI_HANDLE_TYPEDEF_STRUCT sHandSPI;
extern SPI_HandleTypeDef hspi1;

CBOOL SPI_PROC(void)
{

    sHandSPI.sub_len = Buff_subArray(&sHandSPI.buf_rx, sHandSPI.sub_rx);

    if (sHandSPI.sub_len != 0)
    {
        sHandSPI.mode = sHandSPI.sub_rx[0];
        switch (sHandSPI.mode)
        {
            case MODE_PRINT:
            case MODE_PRINT_INV:
                sHandSPI.data[0] = sHandSPI.sub_rx[1];
                sHandSPI.data[1] = sHandSPI.sub_rx[2];
                sHandSPI.data[2] = sHandSPI.sub_rx[3];
                sHandSPI.data[3] = sHandSPI.sub_rx[4];
                sHandSPI.data[4] = sHandSPI.sub_rx[5];
                break;
            case SET_COLOR:
                set_color(sHandSPI.sub_rx[1], sHandSPI.sub_rx[2], sHandSPI.sub_rx[3], sHandSPI.sub_rx[4]);
                break;
                
            default:
                break;
        }
        return CTRUE;
    }
    return CFALSE;
}
uint8_t SPI_getMode(void)
{
    return sHandSPI.mode;
}

uint8_t* SPI_getData(void)
{
    return &sHandSPI.data[0];
}

CBOOL Buff_append(Buff_TypeDef *largeBuf, const uint8_t *buf, uint16_t len)
{
    if (largeBuf->head + len >= BUFF_SIZE)
    {
        return CFALSE;
    }

    largeBuf->buf[largeBuf->head++] = len & 0xFF;

    memcpy(&largeBuf->buf[largeBuf->head], buf, len);

    largeBuf->head += len;

    if (largeBuf->max < len)
    {
        largeBuf->max = len;
    }

    return CTRUE;
}

uint16_t Buff_subArray(Buff_TypeDef *largeBuf, uint8_t *buf)
{
    uint16_t pop_len = 0;

    isEQUA_RET_USER(largeBuf->head, largeBuf->tail, 0);

    pop_len = largeBuf->buf[largeBuf->tail];

    memcpy(buf, &largeBuf->buf[largeBuf->tail + 1], pop_len);

    largeBuf->tail += (pop_len + 1);

    if (largeBuf->head == largeBuf->tail)
    {
        largeBuf->head = largeBuf->tail = 0;
    }

    return pop_len;
}

void SPI_Callback_spiRxComplete(void)
{
    Buff_append(&sHandSPI.buf_rx, sHandSPI.rx_pop, SPI_RX_LEN);
}

void SPI_Callback_spiError(void)
{
    HAL_SPI_Abort_IT(SPI_HANDLE);
	HAL_SPI_Receive_DMA(SPI_HANDLE, sHandSPI.rx_pop, SPI_RX_LEN);
}

void SPI_init(void)
{
	HAL_SPI_Receive_DMA(SPI_HANDLE, sHandSPI.rx_pop, SPI_RX_LEN);
}

void SPI_deinit(void)
{
	HAL_SPI_DMAStop(SPI_HANDLE);
	__HAL_SPI_DISABLE_IT(SPI_HANDLE, SPI_IT_RXNE);
}