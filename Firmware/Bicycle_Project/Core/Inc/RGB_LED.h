#ifndef INC_RGB_LED_H_
#define INC_RGB_LED_H_

#include "stm32f0xx_hal.h"

//Enumeration that contain the identifiers of the RGB LEDs
typedef enum{
	NONE,
	SPEED,
	TEMPERATURE
}ID_LED;

//Structure for set the ports and pins of the LEDs
typedef struct RGB_LEDS_struct_{
	GPIO_TypeDef*	RED_Speed_Port;
	uint16_t		RED_Speed_Pin;
	GPIO_TypeDef*	GREEN_Speed_Port;
	uint16_t		GREEN_Speed_Pin;
	GPIO_TypeDef*	BLUE_Speed_Port;
	uint16_t		BLUE_Speed_Pin;
	GPIO_TypeDef*	RED_Temperature_Port;
	uint16_t		RED_Temperature_Pin;
	GPIO_TypeDef*	GREEN_Temperature_Port;
	uint16_t		GREEN_Temperature_Pin;
	GPIO_TypeDef*	BLUE_Temperature_Port;
	uint16_t		BLUE_Temperature_Pin;
}RGB_LEDS_struct_t;

//Functions prototype
void RGB_Init(RGB_LEDS_struct_t parameters);
void RGB_RED_ON(ID_LED ID);
void RGB_GREEN_ON(ID_LED ID);
void RGB_BLUE_ON(ID_LED ID);
void RGB_ALL_OFF(ID_LED ID);

#endif /* INC_RGB_LED_H_ */
