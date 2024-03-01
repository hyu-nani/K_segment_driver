#ifndef __SPI_H
#define __SPI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../Inc/support.h"

#define BUFF_SIZE               512
#define PROTOCOL_LEN            8

typedef struct
{
    uint8_t buf[BUFF_SIZE];
    uint16_t head;
    uint16_t tail;
    uint16_t max;
    uint16_t len;
} Buff_TypeDef;

typedef struct
{
    Buff_TypeDef buf_rx;
    uint8_t rx_pop[PROTOCOL_LEN];
    uint8_t sub_rx[PROTOCOL_LEN];
    uint8_t sub_len;
    uint8_t address;
    uint8_t mode;
    uint8_t data[5];
    uint16_t callback_count;
} SPI_HANDLE_TYPEDEF_STRUCT;

CBOOL SPI_PROC(void);
uint8_t SPI_getMode(void);
uint8_t* SPI_getData(void);
CBOOL Buff_append(Buff_TypeDef *largeBuf, const uint8_t *buf, uint16_t len);
uint16_t Buff_subArray(Buff_TypeDef *largeBuf, uint8_t *buf);
CBOOL isCS(const uint8_t *buf, uint16_t len);

void SPI_init(void);
void SPI_deinit(void);
void SPI_Callback_spiRxComplete(void);
void SPI_Callback_spiError(void);
void HAL_SPI_ErrorCallback(SPI_HandleTypeDef *hspi);

#ifdef __cplusplus
}
#endif

#endif 