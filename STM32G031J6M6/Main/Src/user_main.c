#include "../Inc/user_main.h"

#include "../Inc/flash.h"
#include "../Inc/SPI.h"
#include "../Inc/led.h"
#include "../Inc/tim.h"

USER_HANDLE_TYPEDEF_STRUCT uHandle;
LED_HANDLE_TYPEDEF_STRUCT hledUSRM;
TIME_HANDLE_TYPEDEF_STRUCT htime;
extern SPI_HandleTypeDef hspi1;
extern TIM_HandleTypeDef htim17;

uint8_t inv = 0;
float delay = 50;

CBOOL CS_EN()  {return HAL_GPIO_ReadPin(SPI1_CS_GPIO_Port, SPI1_CS_Pin)==GPIO_PIN_RESET ? CTRUE : CFALSE;}
#define segment_num 1

void mainTask()
{
    
    sprintf((char*)htime.arr, "%2d:%2d", htime.minute, htime.second);
    LED_showSegment_invert(htime.arr, 1, hledUSRM.color_r, hledUSRM.color_g, hledUSRM.color_b, hledUSRM.bright);
    HAL_Delay(1000);

    htime.second++;
    if (htime.second >= 60)
    {
        htime.second = 0;
        htime.minute++;
    }
    if (htime.minute >= 60)
    {
        htime.minute = 0;
        htime.hour++;
    }
    if (htime.hour >= 24)
    {
        htime.hour = 0;
    }
    //LED_rainbow();
    if (CS_EN() == CTRUE)
    {
        uHandle.rx_data_flag = CFALSE;
    }
    if (uHandle.rx_data_flag == CFALSE)
    {
        HAL_SPI_Receive_IT(&hspi1, uHandle.rxData, sizeof(uint8_t)*segment_num);
    }
    else
    {
        if (uHandle.tx_led_flag == CFALSE)
        {
            uHandle.tx_led_flag = CTRUE;
            //show_segment(uHandle.rxData, segment_num);
        }
        else
        {
            HAL_Delay(1);
        }
    }
    uHandle.taskTick = HAL_GetTick() - uHandle.taskTick_p;
    uHandle.taskTick_p = HAL_GetTick();
    uHandle.runTime = uHandle.taskTick_p;
}

void initTask(void)
{
    
    set_module();
    switch (uHandle.nowModule)
    {
        case LED_WS2812:
            //setTimARR(0, 76-1);
            break;
        
        case LED_SK6812:
            //setTimARR(0, 79-1);
            break;
        
        default:
            break;
    }

    //time_t t;
    //srand((unsigned) time(&t)); //이거 있으면 디버거 없이 부팅안됨.

    LED_allOff();
    hledUSRM.color_r = 200;//200
    hledUSRM.color_g = 120;//120
    hledUSRM.color_b = 30;//30
    hledUSRM.bright = 30;//30
    htime.hour = 12;
    htime.minute = 30;
    HAL_Delay(100);
}

void set_module(void)
{
    #ifdef WS2812
    uHandle.nowModule = LED_WS2812;
    #elif SK6812
    uHandle.nowModule = LED_SK6812;
    #endif
}

void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim)
{
    HAL_TIM_PWM_Stop_DMA(htim, TIM_CHANNEL_1);
    hledUSRM.dataSendFlag = 0;
}
void HAL_SPI_RxCpltCallback(SPI_HandleTypeDef *hspi)
{
    if (hspi->Instance == SPI1)
    {
        uHandle.rx_data_flag = CTRUE;
        uHandle.tx_led_flag = CFALSE;
    }
}

void dataSendFlag(uint8_t flag)
{
    hledUSRM.dataSendFlag = flag;
}

uint8_t getDataSendFlag(void)
{
    return hledUSRM.dataSendFlag;
}