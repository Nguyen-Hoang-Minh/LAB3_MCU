/*
 * Seven_segment_led.h
 *
 *  Created on: Oct 21, 2023
 *      Author: ADMIN
 */

#ifndef INC_SEVEN_SEGMENT_LED_H_
#define INC_SEVEN_SEGMENT_LED_H_

int led_buffer[4];
void update_7seg_buffer(int vertical, int horizontal);
void init_7seg();
void display7SEG(int number);
void update_display(int* display_flag);

#endif /* INC_SEVEN_SEGMENT_LED_H_ */