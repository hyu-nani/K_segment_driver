#ifndef __SPI_H
#define __SPI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"

#define save_word_num 45


/* data */
extern uint8_t led_idx[save_word_num];
extern uint32_t led_segment[save_word_num];
extern uint16_t led_side[save_word_num];

#ifdef __cplusplus
}
#endif

#endif 