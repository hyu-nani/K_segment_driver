#include "../Inc/neopixel.h"
#include "../Inc/support.h"
#include "../Inc/spi.h"

#include "main.h"

extern TIM_HandleTypeDef htim17;
DATA_HANDLE_TYPEDEF_STRUCT led;

void LED_show(uint8_t Red, uint8_t Green, uint8_t Blue)
{
	led.idx = 0;
	//GRB
	for (uint8_t i = 8; i > 0; i--)
	{
		if ((Green >> i) & 0x01)
		{
			led.data[led.idx++] = NEOPIXEL_ONE;
		}
		else
		{
			led.data[led.idx++] = NEOPIXEL_ZERO;
		}
	}
	for (uint8_t i = 8; i > 0; i--)
	{
		if ((Red >> i) & 0x01)
		{
			led.data[led.idx++] = NEOPIXEL_ONE;
		}
		else
		{
			led.data[led.idx++] = NEOPIXEL_ZERO;
		}
	}
	for (uint8_t i = 8; i > 0; i--)
	{
		if ((Blue >> i ) & 0x01)
		{
			led.data[led.idx++] = NEOPIXEL_ONE;
		}
		else
		{
			led.data[led.idx++] = NEOPIXEL_ZERO;
		}
	}
	led.data[led.idx] = 0;
	while(getDataSendFlag());
	HAL_TIM_PWM_Start_DMA(&htim17, TIM_CHANNEL_1, led.data, 25);
	dataSendFlag(1);
}

void show_segment(uint8_t* word, uint8_t numSegment)
{
	uint8_t wordIdx;
	LED_show(0,0,0);// initial dummy data
	for (int num = 0; num < numSegment; num++)
	{
		for (wordIdx = 0; wordIdx < save_word_num; wordIdx++)
		{
			if (*word == led_idx[wordIdx])
				break;
		}
		for (int i = 0; i < 8 ; i++)
		{
			if ((led_side[wordIdx] >> i))
			{
				LED_show(30,10,10);
			}
			else
			{
				LED_show(0,0,0);
			}
		}
		for (int i = 0; i < 29; i++)
		{
			if ((led_segment[wordIdx] >> i) & 0x01)
			{
				LED_show(30,10,10);
			}
			else
			{
				LED_show(0,0,0);
			}
		}
		for (int i = 0; i < 8 ; i++)
		{
			if ((led_side[wordIdx] >> (i + 8)))
			{
				LED_show(30,10,10);
			}
			else
			{
				LED_show(0,0,0);
			}
		}
	}
}
