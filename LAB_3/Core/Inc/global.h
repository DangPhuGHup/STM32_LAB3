/*
 * global.h
 *
 *  Created on: Oct 28, 2024
 *      Author: Admin
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#define INIT              0
#define AUTO_RED_GREEN    1
#define AUTO_RED_YELLOW   2
#define AUTO_GREEN_RED    3
#define AUTO_YELLOW_RED   4

#define MAN_RED           11
#define MAN_GREEN         12
#define MAN_YELLOW        13

#define SETTING_RED       21
#define SETTING_GREEN     22
#define SETTING_YELLOW    23

#define freq1_led7        10
#define freq2_led7        10
#include "software_timer.h"
#include "button.h"
#include "led7_segment.h"
#include "traffic_light.h"
#include "main.h"

extern int status;

extern int time_red;
extern int time_green;
extern int time_yellow;

extern int led_auto_buffer[3];
void display7seg();
#endif /* INC_GLOBAL_H_ */
