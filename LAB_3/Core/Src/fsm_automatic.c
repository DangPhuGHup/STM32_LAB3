/*
 * fsm_automatic.c
 *
 *  Created on: Oct 28, 2024
 *      Author: Admin
 */
#include "fsm_automatic.h"


#include "fsm_automatic.h"
int led_auto_buffer[3] = {5, 3, 2};
int time_red_copy = 0;
int time_green_copy = 0; // chi lam vay de khai bao thoi
int time_yellow_copy = 0;
int led7_1 = 0;          // 2 bien nay de switch giua 2 con led7
int led7_2 = 0;

void display7seg()
{
	if(status == AUTO_RED_GREEN)
	{
		switch(led7_1){
			case 0:
				HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, GPIO_PIN_SET);

				display_2(time_red_copy / 10);
				display_1(time_green_copy / 10);
				led7_1 = 1;
				break;
			case 1:
				HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, GPIO_PIN_RESET);

				display_2(time_red_copy % 10);
				display_1(time_green_copy % 10);
				led7_1 = 0;
				break;

		}
	}
	else if(status == AUTO_RED_YELLOW)
	{
		switch(led7_1){
			case 0:
				HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, GPIO_PIN_SET);

				display_2(time_red_copy / 10);
				display_1(time_yellow_copy / 10);
				led7_1 = 1;
				break;
			case 1:
				HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, GPIO_PIN_RESET);

				display_2(time_red_copy % 10);
				display_1(time_yellow_copy % 10);
				led7_1 = 0;
				break;

		}
	}
	else if(status == AUTO_GREEN_RED)
	{
		switch(led7_1){
			case 0:
				HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, GPIO_PIN_SET);

				display_2(time_green_copy / 10);
				display_1(time_red_copy / 10);
				led7_1 = 1;
				break;
			case 1:
				HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, GPIO_PIN_RESET);

				display_2(time_green_copy % 10);
				display_1(time_red_copy % 10);
				led7_1 = 0;
				break;

		}
	}
	else
	{
		switch(led7_1){
			case 0:
				HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, GPIO_PIN_SET);

				display_2(time_yellow_copy / 10);
				display_1(time_red_copy / 10);
				led7_1 = 1;
				break;
			case 1:
				HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, GPIO_PIN_RESET);

				display_2(time_yellow_copy % 10);
				display_1(time_red_copy % 10);
				led7_1 = 0;
				break;

		}
	}
}

void fsm_automatic_Run(){
	switch(status){
		    case INIT:
		    	light_1(black);
		    	light_2(black);
		    	time_red_copy = led_auto_buffer[0];
		    	time_green_copy = led_auto_buffer[1];
		    	time_yellow_copy =led_auto_buffer[2];
		    	status = AUTO_RED_GREEN;
		    	setTimer_1s1(100);             // timer 1s
		    	setTimer_EN_GR1(freq1_led7);   // timer freg giua 2 con led7 cua 1 cum

		    	break;
		    case AUTO_RED_GREEN:
		    	light_1(red);
		    	light_2(green);

                if(timer_EN_GR1_flag == 1)
                {
                	setTimer_EN_GR1(freq1_led7);
                	display7seg();
                }

				if(timer1_1s_flag == 1)
				{
					setTimer_1s1(100);
					time_red_copy--;
					time_green_copy--;
					if(time_green_copy <= 0)
					{
						status = AUTO_RED_YELLOW;
						time_green_copy = led_auto_buffer[1];
					}
				}
		    	break;
		    case AUTO_RED_YELLOW:
		    	light_1(red);
		    	light_2(yellow);
		    	if(timer_EN_GR1_flag == 1)
				{
					setTimer_EN_GR1(freq1_led7);
					display7seg();
				}


		    	if(timer1_1s_flag == 1)
				{
					setTimer_1s1(100);
					time_red_copy--;
					time_yellow_copy--;
					if(time_red_copy == 0 || time_yellow_copy == 0)
					{
						status = AUTO_GREEN_RED;
						time_red_copy = led_auto_buffer[0];
						time_yellow_copy = led_auto_buffer[2];
					}
				}
		    	break;
		    case AUTO_GREEN_RED:
		    	light_1(green);
		    	light_2(red);
		    	if(timer_EN_GR1_flag == 1)
				{
					setTimer_EN_GR1(freq1_led7);
					display7seg();
				}
		    	if(timer1_1s_flag == 1)
				{
					setTimer_1s1(100);
					time_green_copy--;
					time_red_copy--;
					if(time_green_copy == 0)
					{
						status = AUTO_YELLOW_RED;
						time_green_copy = led_auto_buffer[1];
					}
				}
		    	break;
		    case AUTO_YELLOW_RED:
				light_1(yellow);
				light_2(red);
				if(timer_EN_GR1_flag == 1)
				{
					setTimer_EN_GR1(freq1_led7);
					display7seg();
				}
				if(timer1_1s_flag == 1)
				{
					setTimer_1s1(100);
					time_yellow_copy--;
					time_red_copy--;
					if(time_yellow_copy == 0 || time_red_copy == 0)
					{
						status = AUTO_RED_GREEN;
						time_yellow_copy = led_auto_buffer[2];
						time_red_copy = led_auto_buffer[0];
					}
				}
				break;
		    default:
		    	break;
		}
}





