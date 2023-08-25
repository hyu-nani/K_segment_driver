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
#include <cmsis_os.h>
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
#define B1_Pin GPIO_PIN_13
#define B1_GPIO_Port GPIOC
#define B1_EXTI_IRQn EXTI4_15_IRQn
#define B0_Pin GPIO_PIN_0
#define B0_GPIO_Port GPIOC
#define B1C1_Pin GPIO_PIN_1
#define B1C1_GPIO_Port GPIOC
#define B2_Pin GPIO_PIN_2
#define B2_GPIO_Port GPIOC
#define B3_Pin GPIO_PIN_3
#define B3_GPIO_Port GPIOC
#define USART_TX_Pin GPIO_PIN_2
#define USART_TX_GPIO_Port GPIOA
#define USART_RX_Pin GPIO_PIN_3
#define USART_RX_GPIO_Port GPIOA
#define LD2_Pin GPIO_PIN_5
#define LD2_GPIO_Port GPIOA
#define B4_Pin GPIO_PIN_4
#define B4_GPIO_Port GPIOC
#define B5_Pin GPIO_PIN_5
#define B5_GPIO_Port GPIOC
#define A3_Pin GPIO_PIN_10
#define A3_GPIO_Port GPIOB
#define A4_Pin GPIO_PIN_11
#define A4_GPIO_Port GPIOB
#define A5_Pin GPIO_PIN_12
#define A5_GPIO_Port GPIOB
#define A6_Pin GPIO_PIN_13
#define A6_GPIO_Port GPIOB
#define A7_Pin GPIO_PIN_14
#define A7_GPIO_Port GPIOB
#define A8_Pin GPIO_PIN_15
#define A8_GPIO_Port GPIOB
#define B6_Pin GPIO_PIN_6
#define B6_GPIO_Port GPIOC
#define B7_Pin GPIO_PIN_7
#define B7_GPIO_Port GPIOC
#define B8_Pin GPIO_PIN_8
#define B8_GPIO_Port GPIOC
#define B9_Pin GPIO_PIN_9
#define B9_GPIO_Port GPIOC
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define B10_Pin GPIO_PIN_10
#define B10_GPIO_Port GPIOC
#define A0_Pin GPIO_PIN_7
#define A0_GPIO_Port GPIOB
#define A1_Pin GPIO_PIN_8
#define A1_GPIO_Port GPIOB
#define A2_Pin GPIO_PIN_9
#define A2_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
