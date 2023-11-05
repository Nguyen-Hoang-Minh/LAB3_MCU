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
int return_flag = 0;
void fsm_for_input_processing(void){
	//init_traffic_light();
	switch(system_state){
	case MODE1:
	{
		if(return_flag == 1){
			init_traffic_light();
			return_flag = 0;
		}
		traffic_light();
		if(is_button_pressed(0) == 1){
			system_state = MODE2;
			//INCREASE VALUE OF PORT A BY ONE UNIT
		}
		break;
	}
	case MODE2:
	{
		if(is_button_pressed(1) == 1){
			int tmp = get_red_cycle()/1000;
			tmp++;
			if(tmp > 99) tmp = 0;
			set_red_cycle(tmp*1000);
		}
		update_7seg_buffer(get_red_cycle()/1000, 2);
		scan_4leds();
		display_red_light();
		if(is_button_pressed(2) == 1){
			if(get_red_cycle() != (get_yellow_cycle() + get_green_cycle()) ){
				set_green_cycle(get_red_cycle() - get_yellow_cycle());
			}
		}
		if(is_button_pressed(0) == 1){
			system_state = MODE3;
		}
		break;
	}
	case MODE3:
	{
		if(is_button_pressed(1) == 1){
			int tmp = get_yellow_cycle()/1000;
			tmp++;
			if(tmp > 99) tmp = 0;
			set_yellow_cycle(tmp*1000);
		}
		update_7seg_buffer(get_yellow_cycle()/1000, 3);
		scan_4leds();
		display_yellow_light();
		if(is_button_pressed(2) == 1){
			if(get_red_cycle() != (get_yellow_cycle() + get_green_cycle()) ){
				set_green_cycle(get_red_cycle() - get_yellow_cycle());
			}
		}
		if(is_button_pressed(0) == 1){
			system_state = MODE4;
		}
		break;
	}
	case MODE4:
	{
		if(is_button_pressed(1) == 1){
			int tmp = get_green_cycle()/1000;
			tmp++;
			if(tmp > 99) tmp = 0;
			set_green_cycle(tmp*1000);
		}
		update_7seg_buffer(get_green_cycle()/1000, 4);
		scan_4leds();
		display_green_light();
		if(is_button_pressed(2) == 1){
			if(get_red_cycle() != (get_yellow_cycle() + get_green_cycle()) ){
				set_red_cycle(get_green_cycle() + get_yellow_cycle());
			}
		}
		if(is_button_pressed(0) == 1){
			system_state = MODE1;
			return_flag = 1;
		}
		break;
	}
	default:
		break;
	}
}

