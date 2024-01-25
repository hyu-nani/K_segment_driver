#ifndef __LED_H
#define __LED_H

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"
#include "support.h"

#define NUM_PIXELS_PER_UNIT     45
#define NUM_UNIT                5
#define MAX_BRIGHT              180.0f
#define MIN_BRIGHT              4
#define MAX_IDX                 50
#define ALL_LED                 NUM_PIXELS_PER_UNIT*NUM_UNIT
  
/* LED MODULE */
#define WS2812

#ifdef WS2812
#define NEOPIXEL_ZERO           26      /* (ARR+1)*0.32 */
#define NEOPIXEL_ONE            51      /* (ARR+1)*0.64 */
#define DMA_BUFF_SIZE           24 + 1
#endif

#ifdef SK6812
#define NEOPIXEL_ZERO           19      /* (ARR+1)*0.25 */
#define NEOPIXEL_ONE            39      /* (ARR+1)*0.5 */
#define DMA_BUFF_SIZE           32 + 1
#endif

#define RING_BUF_SIZE           ALL_LED * 3

/* private define ------------------------------------ */
typedef struct 
{
    uint16_t    idx;/* data */
    uint8_t     r;
    uint8_t     g;
    uint8_t     b;
    uint8_t     idx_list[NUM_UNIT];     
    uint32_t    dma_buf[DMA_BUFF_SIZE]; //chort buf 

    uint8_t     buf[RING_BUF_SIZE];     //all buf
    uint8_t     red_now[ALL_LED];       //current
    uint8_t     green_now[ALL_LED];     //current
    uint8_t     blue_now[ALL_LED];      //current

    uint8_t     red_dest[ALL_LED];      //red destination 
    uint8_t     red_orig[ALL_LED];      //red origin 
    uint8_t     green_dest[ALL_LED];    //green destination
    uint8_t     green_orig[ALL_LED];    //green origin
    uint8_t     blue_dest[ALL_LED];     //blue destination
    uint8_t     blue_orig[ALL_LED];     //blue origin

    CBOOL       compare;           
    float       dx;
} DATA_HANDLE_TYPEDEF_STRUCT;



/* data */
static uint8_t  ascii_table_idx[MAX_IDX];
static uint32_t led_segment[MAX_IDX];  
static uint16_t led_side[MAX_IDX];
static float    led_segment_mask_r[NUM_PIXELS_PER_UNIT];
static float    led_segment_mask_g[NUM_PIXELS_PER_UNIT];
static float    led_segment_mask_b[NUM_PIXELS_PER_UNIT];

void append_buf(void);
void LED_show(void);
void LED_showSegment(uint8_t* ch, uint8_t num, uint8_t led_R, uint8_t led_G, uint8_t led_B, uint8_t led_bright);
void LED_showSegment_invert(uint8_t* ch, uint8_t num, uint8_t led_R, uint8_t led_G, uint8_t led_B, uint8_t led_bright);
void LED_allOff(void);
void set_idx(void);
void send_DMA(void);
void LED_setDX(float val);
void LED_rainbow(void);

#ifdef __cplusplus
}
#endif

#endif