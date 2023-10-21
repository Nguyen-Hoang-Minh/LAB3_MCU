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
int timer_flag1 = 0;
int timer_flag2 = 0;
int timer_flag3 = 0;
void set_Timer1(int duration, int interrupt_cycle){
	timer1_counter = duration/interrupt_cycle;
	timer_flag1 = 0;
}

void set_Timer2(int duration){
	timer2_counter = duration;
	timer_flag2 = 0;
}

void set_Timer3(int duration){
	timer3_counter = duration;
	timer_flag3 = 0;
}

void timerRun(){
	timer1_counter--;

	if(timer1_counter <= 0){
		timer_flag1 = 1;
	}
}