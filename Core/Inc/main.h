/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define CS_Pin GPIO_PIN_13
#define CS_GPIO_Port GPIOC
#define L27_Pin GPIO_PIN_0
#define L27_GPIO_Port GPIOC
#define L28_Pin GPIO_PIN_1
#define L28_GPIO_Port GPIOC
#define L29_Pin GPIO_PIN_2
#define L29_GPIO_Port GPIOC
#define L30_Pin GPIO_PIN_3
#define L30_GPIO_Port GPIOC
#define L01_Pin GPIO_PIN_0
#define L01_GPIO_Port GPIOA
#define L02_Pin GPIO_PIN_1
#define L02_GPIO_Port GPIOA
#define L03_Pin GPIO_PIN_2
#define L03_GPIO_Port GPIOA
#define L04_Pin GPIO_PIN_3
#define L04_GPIO_Port GPIOA
#define L41_Pin GPIO_PIN_4
#define L41_GPIO_Port GPIOF
#define L42_Pin GPIO_PIN_5
#define L42_GPIO_Port GPIOF
#define L05_Pin GPIO_PIN_4
#define L05_GPIO_Port GPIOA
#define L06_Pin GPIO_PIN_5
#define L06_GPIO_Port GPIOA
#define L07_Pin GPIO_PIN_6
#define L07_GPIO_Port GPIOA
#define L08_Pin GPIO_PIN_7
#define L08_GPIO_Port GPIOA
#define L31_Pin GPIO_PIN_4
#define L31_GPIO_Port GPIOC
#define L32_Pin GPIO_PIN_5
#define L32_GPIO_Port GPIOC
#define L15_Pin GPIO_PIN_0
#define L15_GPIO_Port GPIOB
#define L16_Pin GPIO_PIN_1
#define L16_GPIO_Port GPIOB
#define L17_Pin GPIO_PIN_2
#define L17_GPIO_Port GPIOB
#define L23_Pin GPIO_PIN_12
#define L23_GPIO_Port GPIOB
#define L24_Pin GPIO_PIN_13
#define L24_GPIO_Port GPIOB
#define L25_Pin GPIO_PIN_14
#define L25_GPIO_Port GPIOB
#define L26_Pin GPIO_PIN_15
#define L26_GPIO_Port GPIOB
#define L33_Pin GPIO_PIN_6
#define L33_GPIO_Port GPIOC
#define L34_Pin GPIO_PIN_7
#define L34_GPIO_Port GPIOC
#define L35_Pin GPIO_PIN_8
#define L35_GPIO_Port GPIOC
#define L36_Pin GPIO_PIN_9
#define L36_GPIO_Port GPIOC
#define L09_Pin GPIO_PIN_8
#define L09_GPIO_Port GPIOA
#define L10_Pin GPIO_PIN_9
#define L10_GPIO_Port GPIOA
#define L11_Pin GPIO_PIN_10
#define L11_GPIO_Port GPIOA
#define L12_Pin GPIO_PIN_11
#define L12_GPIO_Port GPIOA
#define L13_Pin GPIO_PIN_12
#define L13_GPIO_Port GPIOA
#define L43_Pin GPIO_PIN_6
#define L43_GPIO_Port GPIOF
#define L44_Pin GPIO_PIN_7
#define L44_GPIO_Port GPIOF
#define L14_Pin GPIO_PIN_15
#define L14_GPIO_Port GPIOA
#define L37_Pin GPIO_PIN_10
#define L37_GPIO_Port GPIOC
#define L38_Pin GPIO_PIN_11
#define L38_GPIO_Port GPIOC
#define L39_Pin GPIO_PIN_12
#define L39_GPIO_Port GPIOC
#define L40_Pin GPIO_PIN_2
#define L40_GPIO_Port GPIOD
#define L18_Pin GPIO_PIN_3
#define L18_GPIO_Port GPIOB
#define L19_Pin GPIO_PIN_4
#define L19_GPIO_Port GPIOB
#define L20_Pin GPIO_PIN_5
#define L20_GPIO_Port GPIOB
#define L21_Pin GPIO_PIN_8
#define L21_GPIO_Port GPIOB
#define L22_Pin GPIO_PIN_9
#define L22_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
