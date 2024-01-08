#include "../Inc/led.h"

extern TIM_HandleTypeDef htim17;
DATA_HANDLE_TYPEDEF_STRUCT led;

static uint8_t ascii_table_idx[] = {
	' ',
	'0',
	'1',
	'2',
	'3',
	'4',
	'5',
	'6',
	'7',
	'8',
	'9',
	'A',
	'B',
	'C',
	'D',
	'E',
	'F',
	'G',
	'H',
	'I',
	'J',
	'K',
	'L',
	'M',
	'N',
	'O',
	'P',
	'Q',
	'R',
	'S',
	'T',
	'U',
	'V',
	'W',
	'X',
	'Y',
	'Z',
	':',
	'-',
	'.',
	'$', //heart imotion
	'[',
	']',
	'a', //all on
};

//total 29 led
static uint32_t led_segment[] = {
	0x00000000, 
	0x38A528E0, //0011 1000 1010 0101 0010 1000 1110 0,
	0x10421040, //0001 0000 0100 0010 0001 0000 0100 0,1
	0x382221F0, //0011 1000 0010 0010 0010 0001 1111 0,2
	0x382208E0, //0011 1000 0010 0010 0000 1000 1110 0,3
	0x6CA70830, //0110 1100 1010 0111 0000 1000 0011 0,4
	0x7C8608E0, //0111 1100 1000 0110 0000 1000 1110 0,5
	0x388728E0, //0011 1000 1000 0111 0010 1000 1110 0,6
	0x7C210830, //0111 1100 0010 0001 0000 1000 0011 0,7
	0x38A228E0, //0011 1000 1010 0010 0010 1000 1110 0,8
	0x38A708E0, //0011 1000 1010 0111 0000 1000 1110 0,9
	0x38A729B0, //0011 1000 1010 0111 0010 1001 1011 0,A
	0x78A629E0, //0111 1000 1010 0110 0010 1001 1110 0,B
	0x388420E0, //0011 1000 1000 0100 0010 0000 1110 0,C
	0x78A529E0, //0111 1000 1010 0101 0010 1001 1110 0,D
	0x708621C0, //0111 0000 1000 0110 0010 0001 1100 0,E
	0x1C230830, //0001 1100 0010 0011 0000 1000 0011 0,F
	0x390BC4E0, //0011 1001 0000 1011 1100 0100 1110 0,G
	0x6CA729B0, //0110 1100 1010 0111 0010 1001 1011 0,H
	0x10421040, //0001 0000 0100 0010 0001 0000 0100 0,I
	0x0C2108E0, //0000 1100 0010 0001 0000 1000 1110 0,J
	0x6CC431B0, //0110 1100 1100 0100 0011 0001 1011 0,K
	0x608421C0, //0110 0000 1000 0100 0010 0001 1100 0,L
	0x6D5AC718, //0110 1101 0101 1010 1100 0111 0001 1,M
	0xE79ACF38, //1110 0111 1001 1010 1100 1111 0011 1,N
	0x38A528E0, //0011 1000 1010 0101 0010 1000 1110 0,O
	0x78A62180, //0111 1000 1010 0110 0010 0001 1000 0,P
	0x38A528F8, //0011 1000 1010 0101 0010 1000 1111 1,Q
	0x78A629B0, //0111 1000 1010 0110 0010 1001 1011 0,R
	0x388208E0, //0011 1000 1000 0010 0000 1000 1110 0,S
	0x7C421940, //0111 1100 0100 0010 0001 0000 0100 0,T
	0x6CA528E0, //0110 1100 1010 0101 0010 1000 1110 0,U
	0x6CA53840, //0110 1100 1010 0101 0011 1000 0100 0,V
	0xC71AD7B8, //1100 0111 0001 1010 1101 0111 1011 1,W
	0x6CA229B0, //0110 1100 1010 0010 0010 1001 1011 0,X
	0x6CA21040, //0110 1100 1010 0010 0001 0000 0100 0,Y
	0x7C2221F0, //0111 1100 0010 0010 0010 0001 1111 0,Z
	0x00401000, //0000 0000 0100 0000 0001 0000 0000 0,:
	0x00070000, //0000 0000 0000 0111 0000 0000 0000 0,-
	0x00000000, //0000 0000 0000 0000 0000 0000 0000 0,.
	0xEFFFFCE0, //1110 1111 1111 1111 1111 1100 1110 0,heart
	0x708421C0, //0111 0000 1000 0100 0010 0001 1100 0,[
	0x1C210870, //0001 1100 0010 0001 0000 1000 0111 0,]
	0xFFFFFFF8, //1111 1111 1111 1111 1111 1111 1111 1,all on
};

//up side led 8, down side led 8
static uint16_t led_side[] = {
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0010, // 0000 0000 0001 0000
	0x0010, // 0000 0000 0001 0000
	0x0000,
	0x0000,
	0xFFFF,
};
static float led_segment_mask[] = {
	10, 10, 0, 20, 20, 0, 10, 10,
	20, 20, 10, 10, 10, 20, 20,
	20, 10, 0, 10, 20,
	20, 10, 10, 10, 20,
	20, 10, 0, 10, 20,
	20, 20, 10, 10, 10, 20, 20,
	10, 10, 0, 20, 20, 0, 10, 10,
};
/*
static float led_segment_mask[] = {
	0.9, 0.9, 1.0, 0.8, 0.8, 1.0, 0.9, 0.9,
	0.8, 0.8, 0.9, 0.9, 0.9, 0.8, 0.8,
	0.8, 0.9, 1.0, 0.9, 0.8,
	0.8, 0.9, 0.9, 0.9, 0.8,
	0.8, 0.9, 1.0, 0.9, 0.8,
	0.8, 0.8, 0.9, 0.9, 0.9, 0.8, 0.8,
	0.9, 0.9, 1.0, 0.8, 0.8, 1.0, 0.9, 0.9,
};
*/

void LED_sendData(uint8_t Red, uint8_t Green, uint8_t Blue)
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
	HAL_TIM_PWM_Start_DMA(&htim17, TIM_CHANNEL_1, led.data, DMA_BUFF_SIZE);
	dataSendFlag(1);
}

void PROC_LED(void)
{
	if (led.head != led.tail)
	{
		while(getDataSendFlag());
		HAL_TIM_PWM_Start_DMA(&htim17, TIM_CHANNEL_1, led.ringBuf, DMA_BUFF_SIZE);
		dataSendFlag(1);
		led.tail += DMA_BUFF_SIZE;
	}
}

void append_buf(void)
{
	
}

/* @brief led show segment
 * @note 
 * @param ch a ascii textIdx
 * @param num number unit of segment
 * @param led_R 0 - 255
 * @param led_G 0 - 255
 * @param led_B 0 - 255
 * @param led_bright 0 - 100 [%]
 */
void LED_showSegment(char ch[5], uint8_t num, uint8_t led_R, uint8_t led_G, uint8_t led_B, uint8_t led_bright)
{
	led_bright = (led_bright > 100) ? 100 : led_bright;
	led_R = (uint8_t)((float)led_R * MAX_BRIGHT / 255.0f * (float)led_bright / 100.0f);
	led_G = (uint8_t)((float)led_G * MAX_BRIGHT / 255.0f * (float)led_bright / 100.0f);
	led_B = (uint8_t)((float)led_B * MAX_BRIGHT / 255.0f * (float)led_bright / 100.0f);
	led.r = led_R;
	led.g = led_G;
	led.b = led_B;

	int textIdx;
	uint16_t side;
	uint32_t cent;
	int i=0;
	for (int num = 0; num < NUM_UNIT; num++)
	{
		for (int idx = 0; idx < MAX_IDX; idx++)
		{
			if (ascii_table_idx[idx] == ch[num])
			{
				led.idx_list[num] = idx;
				break;
			}
		}
	}
	LED_sendData(0, 0, 0);
	for (int num = 0 ; num < NUM_UNIT; num++)
	{
		side = led_side[led.idx_list[num]];
		cent = led_segment[led.idx_list[num]];
		for (int pixelNum = 0; pixelNum < 45; pixelNum++)
		{
			if (pixelNum >= 8 && pixelNum < 37)
			{
				if (cent & 0x80000000)
				{
					LED_sendData(led.r,led.g,led.b);
					//LED_sendData((led_R * led_segment_mask[i]), (led_G * led_segment_mask[i]), (led_B * led_segment_mask[i]));
				}
				else
				{
					LED_sendData(0, 0, 0);
				}
				cent = (cent << 1);
			}
			else
			{
				if (side & 0x8000)
				{
					LED_sendData(led.r,led.g,led.b);
					//LED_sendData((led_R * led_segment_mask[i]), (led_G * led_segment_mask[i]), (led_B * led_segment_mask[i]));
				}
				else
				{
					LED_sendData(0, 0, 0);
				}
				side = (side << 1);
			}
			i++;
		}
	}
}

/* @brief led show segment(invert)
 * @note 
 * @param ch a ascii textIdx
 * @param num number unit of segment
 * @param led_R 0 - 255
 * @param led_G 0 - 255
 * @param led_B 0 - 255
 * @param led_bright 0 - 100 [%]
 */
void LED_showSegment_invert(char ch[5], uint8_t num, uint8_t led_R, uint8_t led_G, uint8_t led_B, uint8_t led_bright)
{
	led_bright = (led_bright > 100) ? 100 : led_bright;
	led_R = (uint8_t)((float)led_R * MAX_BRIGHT / 255.0f * (float)led_bright / 100.0f);
	led_G = (uint8_t)((float)led_G * MAX_BRIGHT / 255.0f * (float)led_bright / 100.0f);
	led_B = (uint8_t)((float)led_B * MAX_BRIGHT / 255.0f * (float)led_bright / 100.0f);
	led.r = led_R;
	led.g = led_G;
	led.b = led_B;

	int textIdx;
	uint16_t side;
	uint32_t cent;
	int i=0;
	for (int num = 0; num < NUM_UNIT; num++)
	{
		for (int idx = 0; idx < MAX_IDX; idx++)
		{
			if (ascii_table_idx[idx] == ch[num])
			{
				led.idx_list[num] = idx;
				break;
			}
		}
	}
	LED_sendData(0, 0, 0);
	for (int num = 0 ; num < NUM_UNIT; num++)
	{
		side = led_side[led.idx_list[num]];
		cent = led_segment[led.idx_list[num]];
		for (int pixelNum = 0; pixelNum < 45; pixelNum++)
		{
			if (pixelNum >= 8 && pixelNum < 37)
			{
				if (cent & 0x80000000)
				{
					LED_sendData(0, 0, 0);
				}
				else
				{
					LED_sendData(led.r,led.g,led.b);
				}
				cent = (cent << 1);
			}
			else
			{
				if (side & 0x8000)
				{
					LED_sendData(0, 0, 0);
				}
				else
				{
					LED_sendData(led.r,led.g,led.b);
				}
				side = (side << 1);
			}
			i++;
		}
	}
}

void LED_allOff(void)
{
	for (int i = 0; i < (NUM_UNIT * NUM_PIXELS_PER_UNIT)+1; i++)
	{
		LED_sendData(0, 0, 0);
	}
	HAL_Delay(1);
}
