#ifndef __LED_H
#define __LED_H

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"
#include "support.h"

/* private define ------------------------------------ */
typedef struct 
{
    uint8_t idx;/* data */
    uint32_t data[DMA_BUFF_SIZE];
} DATA_HANDLE_TYPEDEF_STRUCT;

/* data */
static char ascii_table_idx[];
static uint32_t led_segment[];
static uint16_t led_side[];

void LED_sendData(uint8_t Red, uint8_t Green, uint8_t Blue);
void LED_showSegment(char ch, uint8_t num, uint8_t led_R, uint8_t led_G, uint8_t led_B);
void LED_allOff(void);

#ifdef __cplusplus
}
#endif

#endif