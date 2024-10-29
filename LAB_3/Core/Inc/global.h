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

#include "software_timer.h"
#include "button.h"
#include "led7_segment.h"
#include "traffic_light.h"
#include "main.h"

extern int status;

#endif /* INC_GLOBAL_H_ */
