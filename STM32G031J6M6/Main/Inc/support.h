#ifndef __SUPPORT_H
#define __SUPPORT_H

#ifdef __cplusplus
extern "C" {
#endif


/* LED MODULE */
#define WS2812

#ifdef WS2812
#define NEOPIXEL_ZERO   26      /* (ARR+1)*0.32 */
#define NEOPIXEL_ONE    51      /* (ARR+1)*0.64 */
#define DMA_BUFF_SIZE   24 + 1
#endif

#ifdef SK6812
#define NEOPIXEL_ZERO   19      /* (ARR+1)*0.25 */
#define NEOPIXEL_ONE    39      /* (ARR+1)*0.5 */
#define DMA_BUFF_SIZE   32 + 1
#endif

#define NUM_PIXELS_PER_UNIT  45
#define NUM_UNIT 5
#define MAX_BRIGHT 180
typedef enum {
    CFALSE = 0,
    CTRUE,
} CBOOL;

typedef enum {
    NONE = 0,
    LED_WS2812,
    LED_SK6812,
    MODULE_MAX,
} LED_moduleList;

//void set_module(void);

#ifdef __cplusplus
}
#endif

#endif