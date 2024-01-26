#ifndef __SPI_H
#define __SPI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"
#include "../Inc/support.h"
#define BUFF_MAX_SMALL                      32
#define BUFF_MAX_LARGE                      1024


typedef struct
{
    uint8_t buf[BUFF_MAX_SMALL];
    uint16_t len;
} Buff_Small_TypeDef;

typedef struct
{
    uint8_t buf[BUFF_MAX_LARGE];
    uint16_t head;
    uint16_t tail;
    uint16_t max;
    uint16_t len;
} Buff_Large_TypeDef;

typedef struct
{
    Buff_Large_TypeDef buffLarge_rx;
    Buff_Small_TypeDef buffSmall_rx;
} SPI_HANDLE_TYPEDEF_STRUCT;


CBOOL Buff_appendLarge(Buff_Large_TypeDef *largeBuf, const uint8_t *smallBuf, uint16_t len);
uint16_t Buff_subArrayLarge(Buff_Large_TypeDef *largeBuf, uint8_t *smallBuf);
void SPI_init(void);

#ifdef __cplusplus
}
#endif

#endif 