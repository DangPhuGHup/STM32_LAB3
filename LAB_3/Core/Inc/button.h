/*
 * button.h
 *
 *  Created on: Oct 28, 2024
 *      Author: Admin
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"
#define NORMAL_STATE GPIO_PIN_SET  // Khi khong nhan, chan nay o muc cao.
#define PRESSED_STATE GPIO_PIN_RESET
#define NUMBER_of_BUTTONS 3
//extern int button1_flag;
//extern int button2_flag;
//extern int button3_flag;
extern int button_flag[NUMBER_of_BUTTONS];
void getKeyInput();
void subkey();


#endif /* INC_BUTTON_H_ */
