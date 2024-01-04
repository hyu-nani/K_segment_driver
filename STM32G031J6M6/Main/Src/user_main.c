#include "../Inc/user_main.h"

#include "../Inc/flash.h"
#include "../Inc/SPI.h"
#include "../Inc/led.h"
#include "../Inc/tim.h"

USER_HANDLE_TYPEDEF_STRUCT uHandle;
LED_HANDLE_TYPEDEF_STRUCT hled;
extern SPI_HandleTypeDef hspi1;
extern TIM_HandleTypeDef htim17;

uint8_t invert = 0;
uint8_t updown = 0;
float delay = 50;

CBOOL CS_EN()  {return HAL_GPIO_ReadPin(SPI1_CS_GPIO_Port, SPI1_CS_Pin)==GPIO_PIN_RESET ? CTRUE : CFALSE;}
#define segment_num 1

void mainTask()
{
    LED_showSegment('1',1,100,0,0);
    LED_showSegment('2',2,100,0,0);
    LED_showSegment('3',3,100,0,0);
    LED_showSegment('4',4,100,0,0);
    LED_showSegment('5',5,100,0,0);
    HAL_Delay(1000);
    LED_showSegment('A',1,100,0,0);
    LED_showSegment('B',2,100,0,0);
    LED_showSegment('C',3,100,0,0);
    LED_showSegment('D',4,100,0,0);
    LED_showSegment('E',5,100,0,0);
    HAL_Delay(1000);
    LED_showSegment('A',1,100,0,0);
    LED_showSegment('P',2,100,0,0);
    LED_showSegment('P',3,100,0,0);
    LED_showSegment('L',4,100,0,0);
    LED_showSegment('E',5,100,0,0);
    HAL_Delay(1000);
    LED_showSegment('B',1,100,0,0);
    LED_showSegment('A',2,100,0,0);
    LED_showSegment('N',3,100,0,0);
    LED_showSegment('A',4,100,0,0);
    LED_showSegment('E',5,100,0,0);
    HAL_Delay(1000);
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
    for(int i = 0; i < MAX_BRIGHT; i++)
    {
        LED_showSegment('a',1,i,i,i);
        LED_showSegment('a',2,i,i,i);
        LED_showSegment('a',3,i,i,i);
        LED_showSegment('a',4,i,i,i);
        LED_showSegment('a',5,i,i,i);
        HAL_Delay(5);
    }
    for(int i = MAX_BRIGHT; i >= 0; i--)
    {
        LED_showSegment('a',1,i,i,i);
        LED_showSegment('a',2,i,i,i);
        LED_showSegment('a',3,i,i,i);
        LED_showSegment('a',4,i,i,i);
        LED_showSegment('a',5,i,i,i);
        HAL_Delay(5);
    }
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
    hled.dataSendFlag = 0;
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
    hled.dataSendFlag = flag;
}

uint8_t getDataSendFlag(void)
{
    return hled.dataSendFlag;
}