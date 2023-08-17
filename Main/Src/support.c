
/* Includes ------------------------------------------------------------------*/
#include <main.h>
#include "../Inc/user_main.h"
#include "stm32f0xx_hal.h"

static LED_HANDLE_Struct sHandLED;

/**
 * brief : initialize code about LED
 * note  :
 * param :
 * return:
*/
void initLED(void)
{
    for (uint8_t pin = 0; pin < LED_MAX_NUM; pin++)
    {
        sHandLED.eachState[pin] = GPIO_PIN_RESET;
    }
}

/**
 * brief : indicate LED
 * note  : 
 * param :
 * return:
*/
void showLED(void)
{
    uint8_t pin = 0;
    HAL_GPIO_WritePin(L01_GPIO_Port, L01_Pin, sHandLED.eachState[pin++]);
    HAL_GPIO_WritePin(L02_GPIO_Port, L02_Pin, sHandLED.eachState[pin++]);
    HAL_GPIO_WritePin(L03_GPIO_Port, L03_Pin, sHandLED.eachState[pin++]);
    HAL_GPIO_WritePin(L04_GPIO_Port, L04_Pin, sHandLED.eachState[pin++]);
    HAL_GPIO_WritePin(L05_GPIO_Port, L05_Pin, sHandLED.eachState[pin++]);
    HAL_GPIO_WritePin(L06_GPIO_Port, L06_Pin, sHandLED.eachState[pin++]);
    HAL_GPIO_WritePin(L07_GPIO_Port, L07_Pin, sHandLED.eachState[pin++]);
    HAL_GPIO_WritePin(L08_GPIO_Port, L08_Pin, sHandLED.eachState[pin++]);
    HAL_GPIO_WritePin(L09_GPIO_Port, L09_Pin, sHandLED.eachState[pin++]);
    HAL_GPIO_WritePin(L10_GPIO_Port, L10_Pin, sHandLED.eachState[pin++]);
    HAL_GPIO_WritePin(L11_GPIO_Port, L11_Pin, sHandLED.eachState[pin++]);
    HAL_GPIO_WritePin(L12_GPIO_Port, L12_Pin, sHandLED.eachState[pin++]);
    HAL_GPIO_WritePin(L13_GPIO_Port, L13_Pin, sHandLED.eachState[pin++]);
    HAL_GPIO_WritePin(L14_GPIO_Port, L14_Pin, sHandLED.eachState[pin++]);
    HAL_GPIO_WritePin(L15_GPIO_Port, L15_Pin, sHandLED.eachState[pin++]);
    HAL_GPIO_WritePin(L16_GPIO_Port, L16_Pin, sHandLED.eachState[pin++]);
    HAL_GPIO_WritePin(L17_GPIO_Port, L17_Pin, sHandLED.eachState[pin++]);
    HAL_GPIO_WritePin(L18_GPIO_Port, L18_Pin, sHandLED.eachState[pin++]);
    HAL_GPIO_WritePin(L19_GPIO_Port, L19_Pin, sHandLED.eachState[pin++]);
    HAL_GPIO_WritePin(L20_GPIO_Port, L20_Pin, sHandLED.eachState[pin++]);
    HAL_GPIO_WritePin(L21_GPIO_Port, L21_Pin, sHandLED.eachState[pin++]);
    HAL_GPIO_WritePin(L22_GPIO_Port, L22_Pin, sHandLED.eachState[pin++]);
    HAL_GPIO_WritePin(L23_GPIO_Port, L23_Pin, sHandLED.eachState[pin++]);
    HAL_GPIO_WritePin(L24_GPIO_Port, L24_Pin, sHandLED.eachState[pin++]);
    HAL_GPIO_WritePin(L25_GPIO_Port, L25_Pin, sHandLED.eachState[pin++]);
    HAL_GPIO_WritePin(L26_GPIO_Port, L26_Pin, sHandLED.eachState[pin++]);
    HAL_GPIO_WritePin(L27_GPIO_Port, L27_Pin, sHandLED.eachState[pin++]);
    HAL_GPIO_WritePin(L28_GPIO_Port, L28_Pin, sHandLED.eachState[pin++]);
    HAL_GPIO_WritePin(L29_GPIO_Port, L29_Pin, sHandLED.eachState[pin++]);
    HAL_GPIO_WritePin(L30_GPIO_Port, L30_Pin, sHandLED.eachState[pin++]);
    HAL_GPIO_WritePin(L31_GPIO_Port, L31_Pin, sHandLED.eachState[pin++]);
    HAL_GPIO_WritePin(L32_GPIO_Port, L32_Pin, sHandLED.eachState[pin++]);
    HAL_GPIO_WritePin(L33_GPIO_Port, L33_Pin, sHandLED.eachState[pin++]);
    HAL_GPIO_WritePin(L34_GPIO_Port, L34_Pin, sHandLED.eachState[pin++]);
    HAL_GPIO_WritePin(L35_GPIO_Port, L35_Pin, sHandLED.eachState[pin++]);
    HAL_GPIO_WritePin(L36_GPIO_Port, L36_Pin, sHandLED.eachState[pin++]);
    HAL_GPIO_WritePin(L37_GPIO_Port, L37_Pin, sHandLED.eachState[pin++]);
    HAL_GPIO_WritePin(L38_GPIO_Port, L38_Pin, sHandLED.eachState[pin++]);
    HAL_GPIO_WritePin(L39_GPIO_Port, L39_Pin, sHandLED.eachState[pin++]);
    HAL_GPIO_WritePin(L40_GPIO_Port, L40_Pin, sHandLED.eachState[pin++]);
    HAL_GPIO_WritePin(L41_GPIO_Port, L41_Pin, sHandLED.eachState[pin++]);
    HAL_GPIO_WritePin(L42_GPIO_Port, L42_Pin, sHandLED.eachState[pin++]);
    HAL_GPIO_WritePin(L43_GPIO_Port, L43_Pin, sHandLED.eachState[pin++]);
    HAL_GPIO_WritePin(L44_GPIO_Port, L44_Pin, sHandLED.eachState[pin++]);
}

/**
 * brief : set led
 * note  : state setting on number of led 
 * param : target led num
 * param : pin state
 * return: x
*/
void insertStateLED(uint8_t ledNum, GPIO_PinState state)
{
    sHandLED.eachState[ledNum] = state;
}

/**
 * brief : setup all LED 
 * note  : GPIO_PIN_SET or GPIO_PIN_RESET
 * param : GPIO_PinState
 * return: x
*/
void allStateLED(GPIO_PinState state)
{
    if (state != GPIO_PIN_RESET)
    {
        GPIOA->BSRR = (uint32_t)0x9FFFU;
        GPIOB->BSRR = (uint32_t)0xF33FU;
        GPIOC->BSRR = (uint32_t)0x1FFFU;
        GPIOD->BSRR = (uint32_t)0x0004U;
        GPIOF->BSRR = (uint32_t)0x00F0U;
    }
    else
    {
        GPIOA->BRR = (uint32_t)0x9FFFU;
        GPIOB->BRR = (uint32_t)0xF33FU;
        GPIOC->BRR = (uint32_t)0x1FFFU;
        GPIOD->BRR = (uint32_t)0x0004U;
        GPIOF->BRR = (uint32_t)0x00F0U;
    }
}