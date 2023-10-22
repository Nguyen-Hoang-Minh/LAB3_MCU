/*
 * traffic_light.h
 *
 *  Created on: Oct 21, 2023
 *      Author: ADMIN
 */

#ifndef INC_TRAFFIC_LIGHT_H_
#define INC_TRAFFIC_LIGHT_H_

#define INIT_RED 	5000	//initial cycle of red light
#define INIT_YELLOW	2000	//initial cycle of yellow light
#define INIT_GREEN 	3000	//initial cycle of green light

#include "main.h"
void set_red_cycle(int duration);
void set_yellow_cycle(int duration);
void set_green_cycle(int duration);

int get_red_cycle();
int get_yellow_cycle();
int get_green_cycle();

void traffic_light();
void init_traffic_light();

void display_red_light();
void display_yellow_light();
void display_green_light();
void scan_4leds();
void  scan_2leds(uint16_t led1, uint16_t led2);
#endif /* INC_TRAFFIC_LIGHT_H_ */
