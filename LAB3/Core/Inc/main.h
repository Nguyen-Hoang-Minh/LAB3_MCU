/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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
#include "stm32f1xx_hal.h"

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
#define LED_RED_VER_Pin GPIO_PIN_1
#define LED_RED_VER_GPIO_Port GPIOA
#define LED_YELLOW_VER_Pin GPIO_PIN_2
#define LED_YELLOW_VER_GPIO_Port GPIOA
#define LED_GREEN_VER_Pin GPIO_PIN_3
#define LED_GREEN_VER_GPIO_Port GPIOA
#define LED_RED_HOR_Pin GPIO_PIN_4
#define LED_RED_HOR_GPIO_Port GPIOA
#define LED_YELLOW_HOR_Pin GPIO_PIN_5
#define LED_YELLOW_HOR_GPIO_Port GPIOA
#define LED_GREEN_HOR_Pin GPIO_PIN_6
#define LED_GREEN_HOR_GPIO_Port GPIOA
#define EN_VER_1_Pin GPIO_PIN_7
#define EN_VER_1_GPIO_Port GPIOA
#define BTN1_Pin GPIO_PIN_0
#define BTN1_GPIO_Port GPIOB
#define BTN2_Pin GPIO_PIN_1
#define BTN2_GPIO_Port GPIOB
#define BTN3_Pin GPIO_PIN_2
#define BTN3_GPIO_Port GPIOB
#define EN_SEG_VER1_Pin GPIO_PIN_10
#define EN_SEG_VER1_GPIO_Port GPIOB
#define EN_SEG_VER2_Pin GPIO_PIN_11
#define EN_SEG_VER2_GPIO_Port GPIOB
#define EN_SEG_HOR1_Pin GPIO_PIN_12
#define EN_SEG_HOR1_GPIO_Port GPIOB
#define EN_SEG_HOR2_Pin GPIO_PIN_13
#define EN_SEG_HOR2_GPIO_Port GPIOB
#define EN_VER_2_Pin GPIO_PIN_8
#define EN_VER_2_GPIO_Port GPIOA
#define EN_HOR_1_Pin GPIO_PIN_9
#define EN_HOR_1_GPIO_Port GPIOA
#define EN_HOR_2_Pin GPIO_PIN_10
#define EN_HOR_2_GPIO_Port GPIOA
#define LED_TEST_Pin GPIO_PIN_11
#define LED_TEST_GPIO_Port GPIOA
#define seg7_a_Pin GPIO_PIN_3
#define seg7_a_GPIO_Port GPIOB
#define seg7_b_Pin GPIO_PIN_4
#define seg7_b_GPIO_Port GPIOB
#define seg7_c_Pin GPIO_PIN_5
#define seg7_c_GPIO_Port GPIOB
#define seg7_d_Pin GPIO_PIN_6
#define seg7_d_GPIO_Port GPIOB
#define seg7_e_Pin GPIO_PIN_7
#define seg7_e_GPIO_Port GPIOB
#define seg7_f_Pin GPIO_PIN_8
#define seg7_f_GPIO_Port GPIOB
#define seg7_g_Pin GPIO_PIN_9
#define seg7_g_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */
int get_interrupt_cycle();
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
