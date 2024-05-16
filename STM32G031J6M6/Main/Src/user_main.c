#include "../Inc/user_main.h"


USER_HANDLE_TYPEDEF_STRUCT uHandle;
LED_HANDLE_TYPEDEF_STRUCT hledUSRM;
TIME_HANDLE_TYPEDEF_STRUCT htime;
extern SPI_HandleTypeDef hspi1;
extern TIM_HandleTypeDef htim17;
COLOR_TYPEDEF_STRUCT color;

#define num_protocol 1
#define init_red    254
#define init_green  150
#define init_blue   85
#define init_bright 100

#define init_bg_red    254
#define init_bg_green  150
#define init_bg_blue   85
#define init_bg_bright 100
#define init_dx     20

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
                color.ch_red = hledUSRM.color_r;
                color.ch_green = hledUSRM.color_g;
                color.ch_blue = hledUSRM.color_b;
                color.ch_bright = hledUSRM.bright;
                color.bg_red = hledUSRM.bgColor_r;
                color.bg_green = hledUSRM.bgColor_g;
                color.bg_blue = hledUSRM.bgColor_b;
                color.bg_bright = hledUSRM.bgBright;
                LED_showSegment(uHandle.arr, &color);
                break;

            case MODE_PRINT_INV:
                color.ch_red = hledUSRM.color_r;
                color.ch_green = hledUSRM.color_g;
                color.ch_blue = hledUSRM.color_b;
                color.ch_bright = hledUSRM.bright;
                color.bg_red = hledUSRM.bgColor_r;
                color.bg_green = hledUSRM.bgColor_g;
                color.bg_blue = hledUSRM.bgColor_b;
                color.bg_bright = hledUSRM.bgBright;
                LED_showSegment_invert(uHandle.arr, &color);
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
    SPI_init();
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
    hledUSRM.color_r = init_red;
    hledUSRM.color_g = init_green;
    hledUSRM.color_b = init_blue;
    hledUSRM.bright = init_bright;
    htime.hour = 12;
    htime.minute = 20;
    htime.indicate_interval = 1000;
    LED_setDX(init_dx);
}

void set_module(void)
{
#ifdef WS2812
    uHandle.nowModule = LED_WS2812;
#elif SK6812
    uHandle.nowModule = LED_SK6812;
#endif
}

void set_ch_color(uint8_t red, uint8_t green, uint8_t blue, uint8_t bright)
{
    hledUSRM.color_r = red;
    hledUSRM.color_g = green;
    hledUSRM.color_b = blue;
    hledUSRM.bright = bright;
}

void set_bg_color(uint8_t red, uint8_t green, uint8_t blue, uint8_t bright)
{
    hledUSRM.bgColor_r = red;
    hledUSRM.bgColor_g = green;
    hledUSRM.bgColor_b = blue;
    hledUSRM.bgBright = bright;
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