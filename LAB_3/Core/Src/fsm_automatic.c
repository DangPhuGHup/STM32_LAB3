/*
 * fsm_automatic.c
 *
 *  Created on: Oct 28, 2024
 *      Author: Admin
 */
#include "fsm_automatic.h"
int time_red_copy = 0;
int time_green_copy = 0; // chi lam vay de khai bao thoi
int time_yellow_copy = 0;
void fsm_automatic_Run(){
	switch(status){
		    case INIT:
		    	light_1(black);
		    	light_2(black);
		    	status = AUTO_RED_GREEN;
		    	setTimer(time_green * 100);    // set 3s cho trang thai red_green

		    	time_green_copy = time_green;
		    	setTimer_led7(100);
		    	break;
		    case AUTO_RED_GREEN:
		    	light_1(red);
		    	light_2(green);
		    	if(timer_flag == 1)
		    	{
		    		setTimer(time_yellow * 100); // set 2s cho trang thai red_yellow
		    		status = AUTO_RED_YELLOW;

		    		time_yellow_copy = time_yellow;
		    		setTimer_led7(100);
		    	}
		    	if(button_flag[0] == 1)
		    	{
		    		button_flag[0] = 0;
//		    		setTimer(800);      // neu khong nhan gi nua, 8s sau quay ve trang thai auto.
		    		status = MAN_RED;   // moi truong hop, khi nhan button_1 thi deu ve man_red
		    	}
		    	if(timer_led7_flag == 1)
		    	{
		    		setTimer_led7(100);
		    		display_1(time_green_copy--);
		    	}
		    	break;
		    case AUTO_RED_YELLOW:
		    	light_1(red);
		    	light_2(yellow);
		    	if(timer_flag == 1)
		    	{
		    		setTimer(time_green * 100);
		    		status = AUTO_GREEN_RED;

		    		time_green_copy = time_green;
		    		setTimer_led7(100);
		    	}
		    	if(button_flag[0] == 1)
				{
		    		button_flag[0] = 0;
					status = MAN_RED;  // moi truong hop, khi nhan button_1 thi deu ve man_red
				}
		    	if(timer_led7_flag == 1)
				{
					setTimer_led7(100);
					display_1(time_yellow_copy--);
				}
		    	break;
		    case AUTO_GREEN_RED:
		    	light_1(green);
		    	light_2(red);
		        if(timer_flag == 1)
		        {
		    		setTimer(time_yellow * 100);
		    		status = AUTO_YELLOW_RED;

		    		time_yellow_copy = time_yellow;
					setTimer_led7(100);
		    	}
		        if(button_flag[0] == 1)
				{
		        	button_flag[0] = 0;
					status = MAN_RED;  // moi truong hop, khi nhan button_1 thi deu ve man_red
				}
		        if(timer_led7_flag == 1)
				{
					setTimer_led7(100);
					display_1(time_green_copy--);
				}
		    	break;
		    case AUTO_YELLOW_RED:
				light_1(yellow);
				light_2(red);
				if(timer_flag == 1)
				{
					setTimer(time_green * 100);
					status = AUTO_RED_GREEN;

					time_green_copy = time_green;
					setTimer_led7(100);
				}
				if(button_flag[0] == 1)
				{
					button_flag[0] = 0;
					status = MAN_RED;  // moi truong hop, khi nhan button_1 thi deu ve man_red
				}
				break;
		    default:
		    	break;
		}
}
