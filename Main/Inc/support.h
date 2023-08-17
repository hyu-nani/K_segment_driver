#ifndef __SUPPORT_H
#define __SUPPORT_H

#ifdef __cplusplus
extern "C" {
#endif

/* Private defines -----------------------------------------------------------*/
#define LED_MAX_NUM             44


/* Private enums -------------------------------------------------------------*/
typedef enum
{
    CFALSE = 0x00,
    CTRUE,
} CBOOL;

/* Private structures --------------------------------------------------------*/
typedef struct
{
    GPIO_PinState eachState[LED_MAX_NUM];
} LED_HANDLE_Struct;

/* Exported functions prototypes ---------------------------------------------*/
void showLED(void);
void insertStateLED(uint8_t ledNum, GPIO_PinState state);
void allStateLED(GPIO_PinState state);
#ifdef __cplusplus
}
#endif
#endif /* __SUPPORT_H */