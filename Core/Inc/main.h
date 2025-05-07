/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
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

#define NUM_COLS 14
#define NUM_ROWS 5
#define NUM_KEYS 64

#define COL_PORT GPIOB
#define COL1 COL1_Pin
#define COL2 COL2_Pin
#define COL3 COL3_Pin
#define COL4 COL4_Pin
#define COL5 COL5_Pin
#define COL6 COL6_Pin
#define COL7 COL7_Pin
#define COL8 COL8_Pin
#define COL9 COL9_Pin
#define COL10 COL10_Pin
#define COL11 COL11_Pin
#define COL12 COL12_Pin
#define COL13 COL13_Pin
#define COL14 COL14_Pin

#define ROW_PORT GPIOA
#define ROW1 ROW1_Pin
#define ROW2 ROW2_Pin
#define ROW3 ROW3_Pin
#define ROW4 ROW4_Pin
#define ROW5 ROW5_Pin

#define DEBOUNCE_TIME_MS 5


/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define ROW1_Pin GPIO_PIN_0
#define ROW1_GPIO_Port GPIOA
#define ROW2_Pin GPIO_PIN_1
#define ROW2_GPIO_Port GPIOA
#define ROW3_Pin GPIO_PIN_2
#define ROW3_GPIO_Port GPIOA
#define ROW4_Pin GPIO_PIN_3
#define ROW4_GPIO_Port GPIOA
#define ROW5_Pin GPIO_PIN_4
#define ROW5_GPIO_Port GPIOA
#define LEDS_STAT_Pin GPIO_PIN_6
#define LEDS_STAT_GPIO_Port GPIOA
#define OS1_Pin GPIO_PIN_7
#define OS1_GPIO_Port GPIOA
#define COL1_Pin GPIO_PIN_0
#define COL1_GPIO_Port GPIOB
#define COL2_Pin GPIO_PIN_1
#define COL2_GPIO_Port GPIOB
#define COL3_Pin GPIO_PIN_2
#define COL3_GPIO_Port GPIOB
#define COL11_Pin GPIO_PIN_10
#define COL11_GPIO_Port GPIOB
#define COL12_Pin GPIO_PIN_11
#define COL12_GPIO_Port GPIOB
#define COL13_Pin GPIO_PIN_12
#define COL13_GPIO_Port GPIOB
#define COL14_Pin GPIO_PIN_13
#define COL14_GPIO_Port GPIOB
#define OS2_Pin GPIO_PIN_8
#define OS2_GPIO_Port GPIOA
#define OS3_Pin GPIO_PIN_9
#define OS3_GPIO_Port GPIOA
#define LEDS_OUT_Pin GPIO_PIN_15
#define LEDS_OUT_GPIO_Port GPIOA
#define COL4_Pin GPIO_PIN_3
#define COL4_GPIO_Port GPIOB
#define COL5_Pin GPIO_PIN_4
#define COL5_GPIO_Port GPIOB
#define COL6_Pin GPIO_PIN_5
#define COL6_GPIO_Port GPIOB
#define COL7_Pin GPIO_PIN_6
#define COL7_GPIO_Port GPIOB
#define COL8_Pin GPIO_PIN_7
#define COL8_GPIO_Port GPIOB
#define COL9_Pin GPIO_PIN_8
#define COL9_GPIO_Port GPIOB
#define COL10_Pin GPIO_PIN_9
#define COL10_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
