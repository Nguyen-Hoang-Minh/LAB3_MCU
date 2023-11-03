/*
 * traffic_light.c
 *
 *  Created on: Oct 21, 2023
 *      Author: ADMIN
 */

#include "traffic_light.h"
#include "main.h"
#include "software_timer.h"
#include "Seven_segment_led.h"
enum traffic_light_state{
	RED,
	YELLOW,
	GREEN
};
int red_cycle = 0, yellow_cycle = 0, green_cycle = 0;
enum traffic_light_state vertical = RED;
enum traffic_light_state horizontal = GREEN;
int display_flag;
void set_red_cycle(int duration){
	red_cycle = duration;
}

void set_yellow_cycle(int duration){
	yellow_cycle = duration;
}

void set_green_cycle(int duration){
	green_cycle = duration;
}

int get_red_cycle(){
	return red_cycle;
}

int get_yellow_cycle(){
	return yellow_cycle;
}

int get_green_cycle(){
	return green_cycle;
}
void  scan_2leds(uint16_t led1, uint16_t led2){
	if(timer_flag2 == 1){
		set_Timer2(100, get_interrupt_cycle());
		HAL_GPIO_TogglePin(GPIOA, led1|led2);
	}
}

void scan_4leds(){
	if(timer_flag4 == 1){
		set_Timer4(100, get_interrupt_cycle());
		update_display(&display_flag);
	}
}
void init_traffic_light(){
	HAL_GPIO_WritePin(GPIOA, LED_RED_VER_Pin, GPIO_PIN_RESET);//at beginning, the red light of vertical ON
	HAL_GPIO_WritePin(GPIOA, LED_YELLOW_VER_Pin|LED_GREEN_VER_Pin, GPIO_PIN_SET);//at the beginning, the yellow and green light of vertical OFF
	HAL_GPIO_WritePin(GPIOA, LED_GREEN_HOR_Pin, GPIO_PIN_RESET);//at beginning, the green light of horizontal ON
	HAL_GPIO_WritePin(GPIOA, LED_YELLOW_HOR_Pin|LED_RED_HOR_Pin, GPIO_PIN_SET);//at the beginning, the red and yellow light of horizontal OFF
	HAL_GPIO_WritePin(GPIOA, EN_HOR_1_Pin|EN_VER_1_Pin, GPIO_PIN_RESET);//initial for scan traffic led
	HAL_GPIO_WritePin(GPIOA, EN_HOR_2_Pin|EN_VER_2_Pin, GPIO_PIN_SET);//initial for scan traffic led
	set_red_cycle(INIT_RED);//initial value for red cycle
	set_yellow_cycle(INIT_YELLOW);//initial value for yellow cycle
	set_green_cycle(INIT_GREEN);//initial value for green cycle
	set_Timer1(red_cycle, get_interrupt_cycle());
	set_Timer3(green_cycle, get_interrupt_cycle());
	set_Timer2(100, get_interrupt_cycle());//100 indicates for time scan(for traffic light)
	set_Timer4(100, get_interrupt_cycle());//100 indicates for time scan(for 7segment led)
	init_7seg();//turn on the first 7segment led, purpose for scan led
	display_flag = 0;//turn on the first 7segment led, purpose for scan led
}
void traffic_light(){
		update_7seg_buffer(get_timer1()*get_interrupt_cycle()/1000, get_timer3()*get_interrupt_cycle()/1000);
		scan_4leds();
	 	  switch (vertical){
	 	  	  case RED:{
	 	  		  HAL_GPIO_WritePin(GPIOA, LED_RED_VER_Pin, GPIO_PIN_RESET);
	 	  		  scan_2leds(EN_VER_1_Pin, EN_VER_2_Pin);
	 	  		  HAL_GPIO_WritePin(GPIOA, LED_YELLOW_VER_Pin|LED_GREEN_VER_Pin, GPIO_PIN_SET);
	 	  		  if(timer_flag1 == 1){
	 	  			  vertical = GREEN;
	 	  			  set_Timer1(green_cycle, get_interrupt_cycle());
	 	  		  }
	 	  		  break;
	 	  	  }
	 	  	  case YELLOW:{
	 	  		  HAL_GPIO_WritePin(GPIOA, LED_YELLOW_VER_Pin, GPIO_PIN_RESET);
	 	  		  scan_2leds(EN_VER_1_Pin, EN_VER_2_Pin);
	 	  		  HAL_GPIO_WritePin(GPIOA, LED_RED_VER_Pin|LED_GREEN_VER_Pin, GPIO_PIN_SET);
	 	  		  if(timer_flag1 == 1){
	 	  			  vertical = RED;
	 	  			  set_Timer1(red_cycle, get_interrupt_cycle());
	 	  		  }
	 	  		  break;
	 	  	  }
	 	  	  case GREEN:{
	 	  		  HAL_GPIO_WritePin(GPIOA, LED_GREEN_VER_Pin, GPIO_PIN_RESET);
	 	  		  scan_2leds(EN_VER_1_Pin, EN_VER_2_Pin);
	 	  		  HAL_GPIO_WritePin(GPIOA, LED_RED_VER_Pin|LED_YELLOW_VER_Pin, GPIO_PIN_SET);
	 	  		  if(timer_flag1 == 1){
	 	  			  vertical = YELLOW;
	 	  			  set_Timer1(yellow_cycle, get_interrupt_cycle());
	 	  		  }
	 	  		  break;
	 	  	  }
	 	  	  default:{
	 	  		  break;
	 	  	  }
	 	  }
	 	  switch (horizontal){
	 	  	  	  case RED:{
	 	  	  		  HAL_GPIO_WritePin(GPIOA, LED_RED_HOR_Pin, GPIO_PIN_RESET);
	 	  	  		  scan_2leds(EN_HOR_1_Pin, EN_HOR_2_Pin);
	 	  	  		  HAL_GPIO_WritePin(GPIOA, LED_YELLOW_HOR_Pin|LED_GREEN_HOR_Pin, GPIO_PIN_SET);
	 	  	  		  if(timer_flag3 == 1){
	 	  	  			  horizontal = GREEN;
	 	  	  			  set_Timer3(green_cycle, get_interrupt_cycle());
	 	  	  		  }
	 	  	  		  break;
	 	  	  	  }
	 	  	  	  case YELLOW:{
	 	  	  		  HAL_GPIO_WritePin(GPIOA, LED_YELLOW_HOR_Pin, GPIO_PIN_RESET);
	 	  	  		  scan_2leds(EN_HOR_1_Pin, EN_HOR_2_Pin);
	 	  	  		  HAL_GPIO_WritePin(GPIOA, LED_RED_HOR_Pin|LED_GREEN_HOR_Pin, GPIO_PIN_SET);
	 	  	  		  if(timer_flag3 == 1){
	 	  	  			  horizontal = RED;
	 	  	  			  set_Timer3(red_cycle, get_interrupt_cycle());
	 	  	  		  }
	 	  	  		  break;
	 	  	  	  }
	 	  	  	  case GREEN:{
	 	  	  		  HAL_GPIO_WritePin(GPIOA, LED_GREEN_HOR_Pin, GPIO_PIN_RESET);
	 	  	  		  scan_2leds(EN_HOR_1_Pin, EN_HOR_2_Pin);
	 	  	  		  HAL_GPIO_WritePin(GPIOA, LED_RED_HOR_Pin|LED_YELLOW_HOR_Pin, GPIO_PIN_SET);
	 	  	  		  if(timer_flag3 == 1){
	 	  	  			  horizontal = YELLOW;
	 	  	  			  set_Timer3(yellow_cycle, get_interrupt_cycle());
	 	  	  		  }
	 	  	  		  break;
	 	  	  	  }
	 	  	  	  default:{
	 	  	  		  break;
	 	  	  	  }
	 	  	  }

}

void display_red_light(){
	HAL_GPIO_WritePin(GPIOA, LED_RED_HOR_Pin|LED_RED_VER_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, LED_YELLOW_HOR_Pin|LED_YELLOW_VER_Pin|LED_GREEN_HOR_Pin|LED_GREEN_VER_Pin, GPIO_PIN_SET);
	if(timer_flag2 == 1){
		set_Timer2(100, get_interrupt_cycle());
		HAL_GPIO_TogglePin(GPIOA, EN_HOR_1_Pin|EN_HOR_2_Pin|EN_VER_1_Pin|EN_VER_2_Pin);
	}
}

void display_yellow_light(){
	HAL_GPIO_WritePin(GPIOA, LED_YELLOW_HOR_Pin|LED_YELLOW_VER_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, LED_RED_HOR_Pin|LED_RED_VER_Pin|LED_GREEN_HOR_Pin|LED_GREEN_VER_Pin, GPIO_PIN_SET);
	if(timer_flag2 == 1){
		set_Timer2(100, get_interrupt_cycle());
		HAL_GPIO_TogglePin(GPIOA, EN_HOR_1_Pin|EN_HOR_2_Pin|EN_VER_1_Pin|EN_VER_2_Pin);
	}
}

void display_green_light(){
	HAL_GPIO_WritePin(GPIOA, LED_GREEN_HOR_Pin|LED_GREEN_VER_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, LED_YELLOW_HOR_Pin|LED_YELLOW_VER_Pin|LED_RED_HOR_Pin|LED_RED_VER_Pin, GPIO_PIN_SET);
	if(timer_flag2 == 1){
		set_Timer2(100, get_interrupt_cycle());
		HAL_GPIO_TogglePin(GPIOA, EN_HOR_1_Pin|EN_HOR_2_Pin|EN_VER_1_Pin|EN_VER_2_Pin);
	}
}
