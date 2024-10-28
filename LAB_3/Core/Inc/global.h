/*
 * global.h
 *
 *  Created on: Oct 28, 2024
 *      Author: Admin
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#define INIT        1
#define AUTO_RED    2
#define AUTO_GREEN  3
#define AUTO_YELLOW 4

#define MAN_RED     12
#define MAN_GREEN   13
#define MAN_YELLOW  14

#include "software_timer.h"
#include "button.h"
#include "led7_segment.h"
#include "traffic_light.h"
#include "main.h"

extern int status;

#endif /* INC_GLOBAL_H_ */
