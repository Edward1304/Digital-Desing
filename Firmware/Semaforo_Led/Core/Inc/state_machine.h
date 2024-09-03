#ifndef __STATE_MACHINE__
#define __STATE_MACHINE__

#include "main.h"

#define TIEMPO_CRUCE_CARROS 				10 //en segundios
#define TIEMPO_CRUCE_PEATONES 				3 //en segundios
#define TIEMPO_PATRON_LED_ON_CARROS_MS 		6 //en 250 ms
#define TIEMPO_PATRON_LED_OFF_CARROS_MS 	2 //en 250 ms
#define TIEMPO_PATRON_LED_ON_PEATONES_MS 	1 //en 250 ms
#define TIEMPO_PATRON_LED_OFF_PEATONES_MS 	1 //en 250 ms

typedef enum{
	cruce_carros,
	cruce_peatones,
}state_machine_enum;

typedef enum{
	LED_ON,
	LED_OFF,
}LED_state_enum;

void initialize_state_machine ( void );
void check_state_machine ( void );
void patron_luz ( void );
void cruce_carro_state_function ( void );
void cruce_peaton_state_function ( void );
void config_times_and_cariables_cruce_carros ( void );
void config_times_and_cariables_cruce_peatones ( void );

#endif
