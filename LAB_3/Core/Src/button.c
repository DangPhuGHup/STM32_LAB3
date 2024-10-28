/*
 * button.c
 *
 *  Created on: Oct 28, 2024
 *      Author: Admin
 */
#include "button.h"

int keyReg0 = NORMAL_STATE; // muc cao
int keyReg1 = NORMAL_STATE; // trung binh thoi gian nhieu cua nut nhan la 10ms
int keyReg2 = NORMAL_STATE;
int keyReg3 = NORMAL_STATE;
int timer_keypress;
int timer1_flag = 0;
void subkey()
{
	timer1_flag = 1;

}
void getKeyInput()
{
	keyReg0 = keyReg1;
	keyReg1 = keyReg2;
	keyReg2 = HAL_GPIO_ReadPin(BUTTON_1_GPIO_Port, BUTTON_1_Pin);
	if((keyReg0 == keyReg1) && (keyReg1 == keyReg2)){  // bước chống nhiễu 20ms, vì hàm này
		                                               // được gọi trong ngắt 10ms.
		if(keyReg3 != keyReg2){  // trạng thái nhấn rồi thả, không phải nhấn đè.
			keyReg3 = keyReg2;   // đưa trạng thái cũ vào trạng thái đang nhấn mới.
			if(keyReg2 == PRESSED_STATE) // cho biết là trong trường hợp đã nhấn
			{
				subkey();              // thực hiện hàm tùy ý.
				timer_keypress = 200;  // nhấn đề 2s mới chuyển sang trạng thái nhấn đè ở dưới.
				                       // thời gian để chuyển trạng thái sang nhấn đè.
			}
		}
	    else{  // trạng thái nhấn đè hoặc lúc không nhấn
		    timer_keypress--;
		    if(timer_keypress <= 0)
		    {
			    if(keyReg2 == PRESSED_STATE) // cho biết rằng đây là lúc nhấn đè chứ không phải
			    	                         // lúc không nhấn.
			    {
				    subkey();
			    }
			    timer_keypress = 50;  // thời gian toogle của led khi trong trạng thái nhấn đè.
		    }
		}
	}
}