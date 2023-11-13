#ifndef __NEOPIXEL_H
#define __NEOPIXEL_H

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"
#include "../Inc/support.h"
/* private define ------------------------------------ */

typedef struct 
{
    uint8_t idx;/* data */
    uint32_t data[DMA_BUFF_SIZE];
} DATA_HANDLE_TYPEDEF_STRUCT;


void LED_show(uint8_t Red, uint8_t Green, uint8_t Blue);
void show_segment(uint8_t* word, uint8_t num);

#ifdef __cplusplus
}
#endif

#endif