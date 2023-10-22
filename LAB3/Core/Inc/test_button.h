/*
 * test_button.h
 *
 *  Created on: Oct 22, 2023
 *      Author: ADMIN
 */

#ifndef INC_TEST_BUTTON_H_
#define INC_TEST_BUTTON_H_

#include "input_reading.h"
#include "main.h"
#include "traffic_light.h"

void toogle(){
	if(is_button_pressed(0) == 1 ){
		HAL_GPIO_TogglePin(GPIOA, LED_RED_VER_Pin);
	}
	//scan_2leds(EN_VER_1_Pin, EN_VER_2_Pin);
}

#endif /* INC_TEST_BUTTON_H_ */