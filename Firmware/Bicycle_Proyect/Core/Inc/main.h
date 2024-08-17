/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#define TEMPERATURE_SENSOR_Pin GPIO_PIN_2
#define TEMPERATURE_SENSOR_GPIO_Port GPIOA
#define SPEED_SENSOR_ANALOG_PIN_Pin GPIO_PIN_3
#define SPEED_SENSOR_ANALOG_PIN_GPIO_Port GPIOA
#define SPEED_SENSOR_DIGITAL_PIN_Pin GPIO_PIN_4
#define SPEED_SENSOR_DIGITAL_PIN_GPIO_Port GPIOA
#define MESURE_VOLTAGE_IN_Pin GPIO_PIN_6
#define MESURE_VOLTAGE_IN_GPIO_Port GPIOA
#define R_SPEED_LED_Pin GPIO_PIN_7
#define R_SPEED_LED_GPIO_Port GPIOA
#define R_SPEED_LEDB0_Pin GPIO_PIN_0
#define R_SPEED_LEDB0_GPIO_Port GPIOB
#define B_SPEED_LED_Pin GPIO_PIN_1
#define B_SPEED_LED_GPIO_Port GPIOB
#define R_TEMPERATURE_LED_Pin GPIO_PIN_2
#define R_TEMPERATURE_LED_GPIO_Port GPIOB
#define G_TEMPERATURE_LED_Pin GPIO_PIN_10
#define G_TEMPERATURE_LED_GPIO_Port GPIOB
#define B_TEMPERATURE_LED_Pin GPIO_PIN_11
#define B_TEMPERATURE_LED_GPIO_Port GPIOB
#define PB_C_Pin GPIO_PIN_12
#define PB_C_GPIO_Port GPIOB
#define PB_B_Pin GPIO_PIN_13
#define PB_B_GPIO_Port GPIOB
#define PB_A_Pin GPIO_PIN_14
#define PB_A_GPIO_Port GPIOB
#define SETTING_LED_Pin GPIO_PIN_8
#define SETTING_LED_GPIO_Port GPIOA
#define FLASH_CS_Pin GPIO_PIN_15
#define FLASH_CS_GPIO_Port GPIOA
#define FLASH_SCK_Pin GPIO_PIN_3
#define FLASH_SCK_GPIO_Port GPIOB
#define FLASH_MISO_Pin GPIO_PIN_4
#define FLASH_MISO_GPIO_Port GPIOB
#define FLASH_MOSI_Pin GPIO_PIN_5
#define FLASH_MOSI_GPIO_Port GPIOB
#define UART_TX_Pin GPIO_PIN_6
#define UART_TX_GPIO_Port GPIOB
#define UART_RX_Pin GPIO_PIN_7
#define UART_RX_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
