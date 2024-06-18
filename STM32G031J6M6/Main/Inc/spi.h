#ifndef __SPI_H
#define __SPI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../Inc/support.h"

#define BUFF_SIZE               512

#define PROTOCOL_LEN            8
/* /stx/num/cmd/data[5]/cs/ */

typedef struct
{
    u8 buf[BUFF_SIZE];
    u16 head;
    u16 tail;
    u16 max;
    u16 len;
} Buff_TypeDef;

typedef struct
{
    Buff_TypeDef buf_rx;
    u8 rx_pop[PROTOCOL_LEN];
    u8 sub_rx[PROTOCOL_LEN];
    u8 sub_len;
    u8 address;
    u8 mode;
    u8 data[5];
    u16 callback_count;
} SPI_HANDLE_TYPEDEF_STRUCT;

CBOOL SPI_PROC(void);
u8 SPI_getMode(void);
u8* SPI_getData(void);
CBOOL Buff_append(Buff_TypeDef *largeBuf, const u8 *buf, u16 len);
u16 Buff_subArray(Buff_TypeDef *largeBuf, u8 *buf);
CBOOL isCS(const u8 *buf, u16 len);

void SPI_init(void);
void SPI_deinit(void);
void SPI_Callback_spiRxComplete(void);
void SPI_Callback_spiError(void);
void HAL_SPI_ErrorCallback(SPI_HandleTypeDef *hspi);

#ifdef __cplusplus
}
#endif

#endif 