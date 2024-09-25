#ifndef IRSPEED_H
#define IRSPEED_H

#include "stm32f0xx_hal.h"

// Define the pins for the IR Speed Sensor
#define IRSPEED_AO_PIN GPIO_PIN_3
#define IRSPEED_AO_PORT GPIOA
#define IRSPEED_DO_PIN GPIO_PIN_4
#define IRSPEED_DO_PORT GPIOA

// Function prototypes
void IRSPEED_Init(void);
uint16_t IRSPEED_ReadAnalog(void);
uint8_t IRSPEED_ReadDigital(void);

#endif // IRSPEED_H