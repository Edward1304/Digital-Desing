#include "state_machine.h"

state_machine_enum state_machine;
extern TIM_HandleTypeDef htim3;

extern flag_enum button_flag;
extern flag_enum timer_switch_flag;
uint8_t tiempo_maximo;
uint8_t tiempo_actual;
uint8_t time_250ms;
uint8_t time_250ms_for_seconds;
uint8_t time_led_on_in_250ms;
uint8_t time_led_off_in_250ms;
LED_state_enum LED_state;

void initialize_state_machine( void ){
	state_machine = cruce_carros;
	config_times_and_cariables_cruce_carros();
	LED_state = LED_OFF;
}

void config_times_and_cariables_cruce_carros ( void ){
	tiempo_maximo = TIEMPO_CRUCE_CARROS;
	time_led_on_in_250ms = TIEMPO_PATRON_LED_ON_CARROS_MS;
	time_led_on_in_250ms = TIEMPO_PATRON_LED_OFF_CARROS_MS;
	tiempo_actual = 0;
	time_250ms = 0;
	button_flag = FLAG_RELEASED;
}

void config_times_and_variables_cruce_peatones ( void ){
	tiempo_maximo = TIEMPO_CRUCE_PEATONES;
	time_led_on_in_250ms = TIEMPO_PATRON_LED_ON_PEATONES_MS;
	time_led_on_in_250ms = TIEMPO_PATRON_LED_OFF_PEATONES_MS;
	tiempo_actual = 0;
	time_250ms = 0;
}

void patron_luz ( void ){
	//Patrón de luz
	if( LED_state == LED_ON ){
		if( time_250ms % time_led_on_in_250ms == 0 ){
			LED_state = LED_OFF;
			HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);
			time_250ms = 0;
		}
	}else if( LED_state == LED_OFF ){
		if( time_250ms % time_led_on_in_250ms == 0 ){
			LED_state = LED_ON;
			HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);
			time_250ms = 0;
		}
	}
}

void check_state_machine( void ){
	switch( state_machine ){
		case cruce_carros:
			cruce_carro_state_function();
			break;
		case cruce_peatones:
			cruce_peaton_state_function();
			break;
		default:
			break;
	}
}

void cruce_carro_state_function( void ){

	if( button_flag == FLAG_SET ){
		button_flag = FLAG_RELEASED;
		if( tiempo_actual + 2 < tiempo_maximo){
			tiempo_actual = tiempo_maximo - 2;
			time_250ms_for_seconds = 0;
		}
	}

	if( timer_switch_flag == FLAG_SET ){
		timer_switch_flag = FLAG_RELEASED;

		if( time_250ms_for_seconds % 4 == 0 ){
			tiempo_actual++;
			time_250ms_for_seconds = 0;
		}


		patron_luz();

		//Revisión de cambio de estados
		if( tiempo_actual == tiempo_maximo ){
			state_machine = cruce_peatones;
			config_times_and_variables_cruce_peatones();
			LED_state = LED_OFF;
			HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);
		}
	}

}

void cruce_peaton_state_function(void){

	if( timer_switch_flag == FLAG_SET ){
		timer_switch_flag = FLAG_RELEASED;

		if( time_250ms_for_seconds % 4 == 0 ){
			tiempo_actual++;
			time_250ms_for_seconds = 0;
		}


		patron_luz();

		//Revisión de cambio de estados
		if( tiempo_actual == tiempo_maximo ){
			state_machine = cruce_carros;
			config_times_and_cariables_cruce_carros();
			LED_state = LED_OFF;
			HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);
		}
	}

}


