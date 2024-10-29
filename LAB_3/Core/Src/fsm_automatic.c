/*
 * fsm_automatic.c
 *
 *  Created on: Oct 28, 2024
 *      Author: Admin
 */
#include "fsm_automatic.h"

void fsm_automatic_Run(){
	switch(status){
		    case INIT:
		    	light_1(black);
		    	light_2(black);
		    	status = AUTO_RED_GREEN;
		    	setTimer(300);    // set 3s cho trang thai red_green
		    	break;
		    case AUTO_RED_GREEN:
		    	light_1(red);
		    	light_2(green);
		    	if(timer_flag == 1)
		    	{
		    		setTimer(200); // set 2s cho trang thai red_yellow
		    		status = AUTO_RED_YELLOW;
		    	}
		    	if(button_flag[0] == 1)
		    	{
		    		button_flag[0] = 0;
//		    		setTimer(800);      // neu khong nhan gi nua, 8s sau quay ve trang thai auto.
		    		status = MAN_RED;   // moi truong hop, khi nhan button_1 thi deu ve man_red
		    	}
		    	break;
		    case AUTO_RED_YELLOW:
		    	light_1(red);
		    	light_2(yellow);
		    	if(timer_flag == 1)
		    	{
		    		setTimer(300);
		    		status = AUTO_GREEN_RED;
		    	}
		    	if(button_flag[0] == 1)
				{
		    		button_flag[0] = 0;
					status = MAN_RED;  // moi truong hop, khi nhan button_1 thi deu ve man_red
				}
		    	break;
		    case AUTO_GREEN_RED:
		    	light_1(green);
		    	light_2(red);
		        if(timer_flag == 1)
		        {
		    		setTimer(200);
		    		status = AUTO_YELLOW_RED;
		    	}
		        if(button_flag[0] == 1)
				{
		        	button_flag[0] = 0;
					status = MAN_RED;  // moi truong hop, khi nhan button_1 thi deu ve man_red
				}
		    	break;
		    case AUTO_YELLOW_RED:
				light_1(yellow);
				light_2(red);
				if(timer_flag == 1)
				{
					setTimer(300);
					status = AUTO_RED_GREEN;
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
