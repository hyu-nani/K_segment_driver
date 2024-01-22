#ifndef __USER_MAIN_H
#define __USER_MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../Inc/support.h"
#include "main.h"

typedef struct 
{
    uint32_t runTime;
    uint32_t LEDSendInterval;
    uint32_t taskTick_p;
    uint32_t taskTick;

    uint8_t* rxData;
    CBOOL rx_data_flag;
    CBOOL tx_led_flag;

    LED_moduleList nowModule;
} USER_HANDLE_TYPEDEF_STRUCT;

typedef struct {
    uint8_t dataSendFlag;
    uint8_t LEDbit;
    uint8_t color_r;
    uint8_t color_g;
    uint8_t color_b;
    uint8_t bright;
    uint16_t LEDcount;
} LED_HANDLE_TYPEDEF_STRUCT;



void mainTask(void);
void initTask(void);
void set_module(void);
void LED_sendEnd(void);
void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim);
void dataSendFlag(uint8_t flag);
uint8_t getDataSendFlag(void);

#ifdef __cplusplus
}
#endif

#endif