/*
 * input_processing.c
 *
 *  Created on: Oct 22, 2023
 *      Author: ADMIN
 */


#include "main.h"
#include "input_reading.h"
#include "traffic_light.h"
#include "Seven_segment_led.h"


enum SystemState{
	MODE1,
	MODE2,
	MODE3,
	MODE4
};

enum SystemState system_state = MODE1;

void fsm_for_input_processing(void){
	switch(system_state){
	case MODE1:
	{
		traffic_light();
		if(is_button_pressed(0)){
			system_state = MODE2;
			//INCREASE VALUE OF PORT A BY ONE UNIT
		}
		break;
	}
	case MODE2:
	{
		update_7seg_buffer(get_red_cycle(), 2);
		scan_4leds();
		display_red_light();
		if(is_button_pressed(0)){
			system_state = MODE3;
		}
		break;
	}
	case MODE3:
	{
		update_7seg_buffer(get_yellow_cycle(), 3);
		scan_4leds();
		display_yellow_light();
		if(is_button_pressed(0)){
			system_state = MODE4;
		}
		break;
	}
	case MODE4:
	{
		update_7seg_buffer(get_green_cycle(), 4);
		display_green_light();
		if(is_button_pressed(0)){
			system_state = MODE1;
		}
		break;
	}
	default:
		break;
	}
}