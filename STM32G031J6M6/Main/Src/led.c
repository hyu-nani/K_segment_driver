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
	0x30421040, //0011 0000 0100 0010 0001 0000 0100 0,1
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
	0x7C421040, //0111 1100 0100 0010 0001 0000 0100 0,T
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

static float led_segment_mask_r[] = {
	0.9, 0.9, 1.0, 0.7, 0.7, 1.0, 0.9, 0.9,
	0.7, 0.7, 0.9, 0.9, 0.9, 0.7, 0.7,
	0.7, 0.9, 1.0, 0.9, 0.7,
	0.7, 0.9, 0.9, 0.9, 0.7,
	0.7, 0.9, 1.0, 0.9, 0.7,
	0.7, 0.7, 0.9, 0.9, 0.9, 0.7, 0.7,
	0.9, 0.9, 1.0, 0.7, 0.7, 1.0, 0.9, 0.9,
};
static float led_segment_mask_g[] = {
	0.9, 0.9, 1.0, 0.75, 0.75, 1.0, 0.9, 0.9,
	0.75, 0.75, 0.9, 0.9, 0.9, 0.75, 0.75,
	0.75, 0.9, 1.0, 0.9, 0.75,
	0.75, 0.9, 0.9, 0.9, 0.75,
	0.75, 0.9, 1.0, 0.9, 0.75,
	0.75, 0.75, 0.9, 0.9, 0.9, 0.75, 0.75,
	0.9, 0.9, 1.0, 0.75, 0.75, 1.0, 0.9, 0.9,
};
static float led_segment_mask_b[] = {
	0.9, 0.9, 1.0, 0.75, 0.75, 1.0, 0.9, 0.9,
	0.75, 0.75, 0.9, 0.9, 0.9, 0.75, 0.75,
	0.75, 0.9, 1.0, 0.9, 0.75,
	0.75, 0.9, 0.9, 0.9, 0.75,
	0.75, 0.9, 1.0, 0.9, 0.75,
	0.75, 0.75, 0.9, 0.9, 0.9, 0.75, 0.75,
	0.9, 0.9, 1.0, 0.75, 0.75, 1.0, 0.9, 0.9,
};

void LED_show(void)
{
	while(getDataSendFlag());
	HAL_TIM_PWM_Start_DMA(&htim17, TIM_CHANNEL_1, led.dma_buf, DMA_BUFF_SIZE);
	dataSendFlag(1);
	for (uint16_t pixelNum = 0 ; pixelNum < (NUM_PIXELS_PER_UNIT * NUM_UNIT * 3); pixelNum += 3)
	{
		led.idx = 0;
		uint8_t i = 0;
		//GRB
		for (i = 8; i > 0; i--)
		{
			if ((led.Buf[pixelNum + 1] >> i) & 0x01)
			{
				led.dma_buf[led.idx++] = NEOPIXEL_ONE;
			}
			else
			{
				led.dma_buf[led.idx++] = NEOPIXEL_ZERO;
			}
		}
		for (i = 8; i > 0; i--)
		{
			if ((led.Buf[pixelNum + 0] >> i) & 0x01)
			{
				led.dma_buf[led.idx++] = NEOPIXEL_ONE;
			}
			else
			{
				led.dma_buf[led.idx++] = NEOPIXEL_ZERO;
			}
		}
		for (i = 8; i > 0; i--)
		{
			if ((led.Buf[pixelNum + 2] >> i ) & 0x01)
			{
				led.dma_buf[led.idx++] = NEOPIXEL_ONE;
			}
			else
			{
				led.dma_buf[led.idx++] = NEOPIXEL_ZERO;
			}
		}
		led.dma_buf[led.idx] = 0;
		while(getDataSendFlag());
		HAL_TIM_PWM_Start_DMA(&htim17, TIM_CHANNEL_1, led.dma_buf, DMA_BUFF_SIZE);
		dataSendFlag(1);
	}
}

void LED_setColor(uint8_t pixelNum, uint8_t red, uint8_t green, uint8_t blue, uint8_t bright)
{
	if (bright > 100)
	return;
	red = (uint8_t)((float)red * MAX_BRIGHT / 255.0f * (float)bright / 100.0f);
	green = (uint8_t)((float)green * MAX_BRIGHT / 255.0f * (float)bright / 100.0f);
	blue = (uint8_t)((float)blue * MAX_BRIGHT / 255.0f * (float)bright / 100.0f);
	led.Buf[pixelNum * 3 + 0] = red;
	led.Buf[pixelNum * 3 + 1] = green;
	led.Buf[pixelNum * 3 + 2] = blue;
}

void PROC_LED(void)
{
	if (led.head != led.tail)
	{
		while(getDataSendFlag());
		//HAL_TIM_PWM_Start_DMA(&htim17, TIM_CHANNEL_1, led.ringBuf, DMA_BUFF_SIZE);
		dataSendFlag(1);
		led.tail += DMA_BUFF_SIZE;
	}
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
void LED_showSegment(uint8_t* ch, uint8_t num, uint8_t led_R, uint8_t led_G, uint8_t led_B, uint8_t led_bright)
{
	led.r = led_R;
	led.g = led_G;
	led.b = led_B;

	int textIdx;
	uint16_t side;
	uint32_t cent;
	int i;
	for (int num = 0; num < NUM_UNIT; num++)
	{
		for (int idx = 0; idx < MAX_IDX; idx++)
		{
			if (ascii_table_idx[idx] == *(ch + num))
			{
				led.idx_list[num] = idx;
				break;
			}
		}
	}
	for (int num = 0 ; num < NUM_UNIT; num++)
	{
		side = led_side[led.idx_list[num]];
		cent = led_segment[led.idx_list[num]];
		i = 0;
		for (int pixelNum = 0; pixelNum < NUM_PIXELS_PER_UNIT; pixelNum++)
		{
			if (pixelNum >= 8 && pixelNum < 37)
			{
				if (cent & 0x80000000)
				{
					LED_setColor((pixelNum + num * NUM_PIXELS_PER_UNIT), 
								(uint8_t)((float)led.r * led_segment_mask_r[i]), 
								(uint8_t)((float)led.g * led_segment_mask_g[i]), 
								(uint8_t)((float)led.b * led_segment_mask_b[i]), 
								led_bright);
				}
				else
				{
					LED_setColor(pixelNum + num * NUM_PIXELS_PER_UNIT, 0, 0, 0, led_bright);
				}
				cent = (cent << 1);
			}
			else
			{
				if (side & 0x8000)
				{
					LED_setColor((pixelNum + num * NUM_PIXELS_PER_UNIT), 
								(uint8_t)((float)led.r * led_segment_mask_r[i]), 
								(uint8_t)((float)led.g * led_segment_mask_g[i]), 
								(uint8_t)((float)led.b * led_segment_mask_b[i]), 
								led_bright);	
				}
				else
				{
					LED_setColor(pixelNum + num * NUM_PIXELS_PER_UNIT, 0, 0, 0, led_bright);
				}
				side = (side << 1);
			}
			i++;
		}
	}
	LED_show();
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
void LED_showSegment_invert(uint8_t* ch, uint8_t num, uint8_t led_R, uint8_t led_G, uint8_t led_B, uint8_t led_bright)
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
	int i;
	for (int num = 0; num < NUM_UNIT; num++)
	{
		for (int idx = 0; idx < MAX_IDX; idx++)
		{
			if (ascii_table_idx[idx] == *(ch + num))
			{
				led.idx_list[num] = idx;
				break;
			}
		}
	}
	for (int num = 0 ; num < NUM_UNIT; num++)
	{
		side = led_side[led.idx_list[num]];
		cent = led_segment[led.idx_list[num]];
		i = 0;
		for (int pixelNum = 0; pixelNum < 45; pixelNum++)
		{
			if (pixelNum >= 8 && pixelNum < 37)
			{
				if (cent & 0x80000000)
				{
					LED_setColor(pixelNum + num * NUM_PIXELS_PER_UNIT, 0, 0, 0, led_bright);
				}
				else
				{
					LED_setColor(pixelNum + num * NUM_PIXELS_PER_UNIT, 
								(uint8_t)((float)led.r * led_segment_mask_r[i]), 
								(uint8_t)((float)led.g * led_segment_mask_g[i]), 
								(uint8_t)((float)led.b * led_segment_mask_b[i]), 
								led_bright);
				}
				cent = (cent << 1);
			}
			else
			{
				if (side & 0x8000)
				{
					LED_setColor(pixelNum + num * NUM_PIXELS_PER_UNIT, 0, 0, 0, led_bright);
				}
				else
				{
					LED_setColor((pixelNum + num * NUM_PIXELS_PER_UNIT), 
								(uint8_t)((float)led.r * led_segment_mask_r[i]), 
								(uint8_t)((float)led.g * led_segment_mask_g[i]), 
								(uint8_t)((float)led.b * led_segment_mask_b[i]), 
								led_bright);
				}
				side = (side << 1);
			}
			i++;
		}
	}
	LED_show();
}

void LED_allOff(void)
{
	for (int i = 0; i < (NUM_UNIT * NUM_PIXELS_PER_UNIT)+1; i++)
	{
		LED_setColor(i, 0, 0, 0, 0);
	}
        LED_show();
	HAL_Delay(1);
}

void LED_rainbow(void)
{
	int fadeVal=0, fadeMax=100;
	int wait = 3, rainbowLoops = 10;
	// Hue of first pixel runs 'rainbowLoops' complete loops through the color
	// wheel. Color wheel has a range of 65536 but it's OK if we roll over, so
	// just count from 0 to rainbowLoops*65536, using steps of 256 so we
	// advance around the wheel at a decent clip.
	for(uint32_t firstPixelHue = 0; firstPixelHue < rainbowLoops*65536; firstPixelHue += 256) 
	{
		for(int i=0; i<NUM_PIXELS_PER_UNIT * NUM_UNIT; i++) 
		{ // For each pixel in strip...

			// Offset pixel hue by an amount to make one full revolution of the
			// color wheel (range of 65536) along the length of the strip
			// (strip.numPixels() steps):
			uint32_t pixelHue = firstPixelHue + (i * 65536L / NUM_PIXELS_PER_UNIT * NUM_UNIT);

			// strip.ColorHSV() can take 1 or 3 arguments: a hue (0 to 65535) or
			// optionally add saturation and value (brightness) (each 0 to 255).
			// Here we're using just the three-argument variant, though the
			// second value (saturation) is a constant 255.
			//pixels.setPixelColor(i, pixels.gamma32(pixels.ColorHSV(pixelHue, 255, 255 * fadeVal / fadeMax)));
		}

		HAL_Delay(100);
		if (firstPixelHue < 65536) 
		{                              // First loop,
			if(fadeVal < fadeMax) fadeVal++;                       // fade in
		} 
		else if (firstPixelHue >= ((rainbowLoops-1) * 65536)) 
		{ // Last loop,
			if(fadeVal > 0) fadeVal--;                             // fade out
		} 
		else 
		{
			fadeVal = fadeMax; // Interim loop, make sure fade is at max
		}
	}
	HAL_Delay(500); // Pause 1/2 second
}