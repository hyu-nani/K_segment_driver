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
#define B10_Pin GPIO_PIN_0
#define B10_GPIO_Port GPIOF
#define B11_Pin GPIO_PIN_1
#define B11_GPIO_Port GPIOF
#define A1_Pin GPIO_PIN_0
#define A1_GPIO_Port GPIOA
#define A2_Pin GPIO_PIN_1
#define A2_GPIO_Port GPIOA
#define B1_Pin GPIO_PIN_4
#define B1_GPIO_Port GPIOA
#define B2_Pin GPIO_PIN_5
#define B2_GPIO_Port GPIOA
#define B3_Pin GPIO_PIN_6
#define B3_GPIO_Port GPIOA
#define B4_Pin GPIO_PIN_7
#define B4_GPIO_Port GPIOA
#define A3_Pin GPIO_PIN_0
#define A3_GPIO_Port GPIOB
#define A4_Pin GPIO_PIN_1
#define A4_GPIO_Port GPIOB
#define PWM_IN_Pin GPIO_PIN_8
#define PWM_IN_GPIO_Port GPIOA
#define B5_Pin GPIO_PIN_9
#define B5_GPIO_Port GPIOA
#define B6_Pin GPIO_PIN_10
#define B6_GPIO_Port GPIOA
#define B7_Pin GPIO_PIN_11
#define B7_GPIO_Port GPIOA
#define B8_Pin GPIO_PIN_12
#define B8_GPIO_Port GPIOA
#define B9_Pin GPIO_PIN_15
#define B9_GPIO_Port GPIOA
#define A5_Pin GPIO_PIN_3
#define A5_GPIO_Port GPIOB
#define A6_Pin GPIO_PIN_4
#define A6_GPIO_Port GPIOB
#define A7_Pin GPIO_PIN_5
#define A7_GPIO_Port GPIOB
#define A8_Pin GPIO_PIN_6
#define A8_GPIO_Port GPIOB
#define A9_Pin GPIO_PIN_7
#define A9_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
