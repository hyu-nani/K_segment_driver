#ifndef __SPI_H
#define __SPI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"
#include "../Inc/support.h"
#define BUFF_MAX_SMALL                      8
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
    Buff_Small_TypeDef pop_rx;
    uint8_t address;
    uint8_t mode;
    uint8_t data[5];
} SPI_HANDLE_TYPEDEF_STRUCT;

CBOOL SPI_PROC(void);
uint8_t SPI_getMode(void);
uint8_t* SPI_getData(void);
CBOOL Buff_appendLarge(Buff_Large_TypeDef *largeBuf, const uint8_t *smallBuf, uint16_t len);
uint16_t Buff_subArrayLarge(Buff_Large_TypeDef *largeBuf, uint8_t *smallBuf);
void SPI_init(void);
void SPI_deinit(void);
#ifdef __cplusplus
}
#endif

#endif 