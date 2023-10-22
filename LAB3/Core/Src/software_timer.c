/*
 * software_timer.c
 *
 *  Created on: Oct 21, 2023
 *      Author: ADMIN
 */

#include "software_timer.h"

int timer1_counter = 0;
int timer2_counter = 0;
int timer3_counter = 0;
int timer4_counter = 0;
int timer_flag1 = 0;
int timer_flag2 = 0;
int timer_flag3 = 0;
int timer_flag4 = 0;
void set_Timer1(int duration, int interrupt_cycle){
	timer1_counter = duration/interrupt_cycle;
	timer_flag1 = 0;
}

void set_Timer2(int duration, int interrupt_cycle){
	timer2_counter = duration/interrupt_cycle;
	timer_flag2 = 0;
}

void set_Timer3(int duration, int interrupt_cycle){
	timer3_counter = duration/interrupt_cycle;
	timer_flag3 = 0;
}

void set_Timer4(int duration, int interrupt_cycle){
	timer4_counter = duration/interrupt_cycle;
	timer_flag4 = 0;
}

int get_timer1(){
	return timer1_counter;
}

int get_timer3(){
	return timer3_counter;
}
void timerRun(){
	timer1_counter--;//counter for main flow, used for led cycle in vertical
	timer3_counter--;//counter for main flow, used for led cycle in horizontal
	timer2_counter--;//counter for scan led
	timer4_counter--;//counter for scan 7segment leds
	if(timer1_counter <= 0){
		timer_flag1 = 1;
	}
	if(timer2_counter <= 0){
		timer_flag2 = 1;
	}
	if(timer3_counter <= 0){
		timer_flag3 = 1;
	}
	if(timer4_counter <= 0){
		timer_flag4 = 1;
		}
}
