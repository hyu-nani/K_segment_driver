#ifndef __USER_MAIN_H
#define __USER_MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"
#include "../Inc/support.h"

#include "../Inc/flash.h"
#include "../Inc/SPI.h"
#include "../Inc/led.h"
#include "../Inc/tim.h"

typedef enum
{
    MODE_OFF = 0x00,
    
    MODE_PRINT,
    MODE_PRINT_INV,
    MODE_EFFECT,
    SET_DX,
    SET_COLOR,
    SET_BG_COLOR,
    COMMAND_MAX,
} USRM_Mode_TypeDef;

typedef struct 
{
    u32 runTime;
    u32 LEDSendInterval;
    u32 taskTick_p;
    u32 taskTick;

    u8* arr;
    CBOOL rx_data_flag;
    CBOOL tx_led_flag;
    USRM_Mode_TypeDef mode;
} USER_HANDLE_TYPEDEF_STRUCT;

typedef struct {
    u8 dataSendFlag;
    u8 LEDbit;
    u8 color_r;
    u8 color_g;
    u8 color_b;
    u8 bright;
    u8 bgColor_r;
    u8 bgColor_g;
    u8 bgColor_b;
    u8 bgBright;
    u16 LEDcount;
} LED_HANDLE_TYPEDEF_STRUCT;

typedef struct {
    u8 hour;
    u8 minute;
    u8 second;
    u32 indicate_tick;
    u32 indicate_interval;
    u32 nowTick;
    u32 preTick;
    u8 arr[5];
} TIME_HANDLE_TYPEDEF_STRUCT;

void mainTask(void);
void initTask(void);
void set_module(void);
void set_ch_color(u8 red, u8 green, u8 blue, u8 bright);
void set_bg_color(u8 red, u8 green, u8 blue, u8 bright);
void LED_sendEnd(void);
void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim);
void dataSendFlag(u8 flag);
u8 getDataSendFlag(void);

void HAL_GPIO_EXTI_Falling_Callback(u16 GPIO_Pin);
void HAL_GPIO_EXTI_Rising_Callback(u16 GPIO_Pin);

#ifdef __cplusplus
}
#endif

#endif