#include "../Inc/user_main.h"


USER_HANDLE_TYPEDEF_STRUCT uHandle;
LED_HANDLE_TYPEDEF_STRUCT hledUSRM;
TIME_HANDLE_TYPEDEF_STRUCT htime;
extern SPI_HandleTypeDef hspi1;
extern TIM_HandleTypeDef htim17;
EXTI_HandleTypeDef hexti0;
uint8_t inv = 0;
float delay = 50;
#define num_protocol 1
#define init_red    254
#define init_green  150
#define init_blue   85
#define init_bright 100
void mainTask()
{
    htime.nowTick = HAL_GetTick();
    if (SPI_PROC() == CTRUE)
    {
        uHandle.mode = (USRM_Mode_TypeDef)SPI_getMode();
        uHandle.arr = SPI_getData();
        switch(uHandle.mode)
        {
            case MODE_OFF:
                LED_allOff();
                break;
            case MODE_PRINT:
                LED_showSegment(uHandle.arr, hledUSRM.color_r, hledUSRM.color_g, hledUSRM.color_b, hledUSRM.bright);
                break;
            case MODE_PRINT_INV:
                LED_showSegment_invert(uHandle.arr, hledUSRM.color_r, hledUSRM.color_g, hledUSRM.color_b, hledUSRM.bright);
                break;
            case MODE_EFFECT:
                break;

            case SET_COLOR:

                break;
            default:
                break;
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
    hledUSRM.color_r = init_red;
    hledUSRM.color_g = init_green;
    hledUSRM.color_b = init_blue;
    hledUSRM.bright = init_bright;
    htime.hour = 12;
    htime.minute = 20;
    htime.indicate_interval = 1000;
    SPI_init();
    LED_setDX(20);
}

void set_module(void)
{
#ifdef WS2812
    uHandle.nowModule = LED_WS2812;
#elif SK6812
    uHandle.nowModule = LED_SK6812;
#endif
}

void set_color(uint8_t red, uint8_t green, uint8_t blue, uint8_t bright)
{
    hledUSRM.color_r = red;
    hledUSRM.color_g = green;
    hledUSRM.color_b = blue;
    hledUSRM.bright = bright;
}

void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim)
{
    HAL_TIM_PWM_Stop_DMA(htim, TIM_CHANNEL_1);
    hledUSRM.dataSendFlag = 0;
}

void HAL_SPI_RxCpltCallback(SPI_HandleTypeDef *hspi)
{
    SPI_Callback_spiRxComplete();
    uHandle.rx_data_flag = CTRUE;
    uHandle.tx_led_flag = CFALSE;
}

void HAL_SPI_ErrorCallback(SPI_HandleTypeDef *hspi)
{
    SPI_Callback_spiError();
}

void dataSendFlag(uint8_t flag)
{
    hledUSRM.dataSendFlag = flag;
}

uint8_t getDataSendFlag(void)
{
    return hledUSRM.dataSendFlag;
}