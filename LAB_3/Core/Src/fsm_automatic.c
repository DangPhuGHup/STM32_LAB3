/*
 * fsm_automatic.c
 *
 *  Created on: Oct 28, 2024
 *      Author: Admin
 */
#include "fsm_automatic.h"
//int time_red_copy = 0;
//int time_green_copy = 0; // chi lam vay de khai bao thoi
//int time_yellow_copy = 0;




//int timer_counter_led = 0;
//int timer_counter_led2 = 0;
//int led7_1 = 0;          // 2 bien nay de switch giua 2 con led7
//int led7_2 = 0;
//int is_initialized = 0;  // Biến kiểm tra khởi tạo
//int is_initialized2 = 0;
//void fsm_automatic_Run(){
//	switch(status){
//		    case INIT:
//		    	light_1(black);
//		    	light_2(black);
//		    	status = AUTO_RED_GREEN;
//		    	setTimer(time_green * 100);    // set 3s cho trang thai red_green
//		    	is_initialized = 0; // Đảm bảo lần sau vào AUTO_RED_GREEN, sẽ khởi tạo lại biến
//		    	is_initialized2 = 0;
//		    	break;
//
//		    case AUTO_RED_GREEN:
//		    	if (is_initialized == 0) {  // Chỉ khởi tạo lại một lần khi vào trạng thái AUTO_RED_GREEN
//					timer_counter_led = time_red;
//					is_initialized = 1;
//				}
//		    	if (is_initialized2 == 0){
//		    		timer_counter_led2 = time_green;
//		    		is_initialized2 = 1;
//		    	}
//		    	light_1(red);
//		    	light_2(green);
//
//                if(timer_EN_GR1_flag == 1)
//                {
//                	setTimer_EN_GR1(freq1_led7);
//                	switch(led7_1){
//                		case 0:
//                			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
//                			HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, GPIO_PIN_RESET);
//                			display_2(timer_counter_led / 10);
//                			led7_1 = 1;
//                			break;
//                		case 1:
//                			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_RESET);
//                			HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, GPIO_PIN_SET);
//                			display_2(timer_counter_led % 10);
//                			led7_1 = 0;
//                			break;
//                	}
//                }
//                if(timer_EN_GR2_flag == 1)
//                {
//                	setTimer_EN_GR2(freq2_led7);
//                	switch(led7_2){
//                		case 0:
//                			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
//                			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);
//                			display_1(timer_counter_led2 / 10);
//                			led7_2 = 1;
//                			break;
//                		case 1:
//                			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
//                			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
//                			display_1(timer_counter_led2 % 10);
//                			led7_2 = 0;
//                			break;
//                	}
//                }
//                if(timer1_1s_flag == 1)
//                {
//                	setTimer_1s1(100);
//                	timer_counter_led--;
//                	timer_counter_led2--;
//                }
//
//		    	if(timer_flag == 1)
//		    	{
//					setTimer(time_yellow * 100);
//					status = AUTO_RED_YELLOW;
//					is_initialized = 0;
//					is_initialized2 = 0;
//		    	}
//		    	if(button_flag[0] == 1)
//		    	{
//		    		button_flag[0] = 0;
////		    		setTimer(800);      // neu khong nhan gi nua, 8s sau quay ve trang thai auto.
//		    		status = MAN_RED;   // moi truong hop, khi nhan button_1 thi deu ve man_red
//		    	}
//		    	break;
//
//		    case AUTO_RED_YELLOW:
////		    	if (is_initialized == 0) {  // Chỉ khởi tạo lại một lần khi vào trạng thái AUTO_RED_GREEN
////					timer_counter_led = time_red - time_green;
////					is_initialized = 1;
////				}
////				if (is_initialized2 == 0){
////					timer_counter_led2 = time_yellow;
////					is_initialized2 = 1;
////				}
//		    	light_1(red);
//		    	light_2(yellow);
////		    	if(timer_EN_GR1_flag == 1)
////				{
////					setTimer_EN_GR1(freq1_led7);
////					switch(led7_1){
////						case 0:
////							HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
////							HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, GPIO_PIN_RESET);
////							display_2(timer_counter_led / 10);
////							led7_1 = 1;
////							break;
////						case 1:
////							HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_RESET);
////							HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, GPIO_PIN_SET);
////							display_2(timer_counter_led % 10);
////							led7_1 = 0;
////							break;
////					}
////				}
////		    	if(timer_EN_GR2_flag == 1)
////				{
////					setTimer_EN_GR2(freq2_led7);
////					switch(led7_2){
////						case 0:
////							HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
////							HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);
////							display_1(timer_counter_led2 / 10);
////							led7_2 = 1;
////							break;
////						case 1:
////							HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
////							HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
////							display_1(timer_counter_led2 % 10);
////							led7_2 = 0;
////							break;
////					}
////				}
////		    	if(timer1_1s_flag == 1)
////				{
////					setTimer_1s1(100);
////					timer_counter_led--;
////					timer_counter_led2--;
////				}
//		    	if(timer_flag == 1)
//		    	{
//		    		setTimer(time_green * 100);
//		    		status = AUTO_GREEN_RED;
////		    		is_initialized = 0;
////		    		is_initialized2 = 0;
//		    	}
//		    	if(button_flag[0] == 1)
//				{
//		    		button_flag[0] = 0;
//					status = MAN_RED;  // moi truong hop, khi nhan button_1 thi deu ve man_red
//				}
//		    	break;
//
//		    case AUTO_GREEN_RED:
//		    	light_1(green);
//		    	light_2(red);
//		        if(timer_flag == 1)
//		        {
//		    		setTimer(time_yellow * 100);
//		    		status = AUTO_YELLOW_RED;
//		    	}
//		        if(button_flag[0] == 1)
//				{
//		        	button_flag[0] = 0;
//					status = MAN_RED;  // moi truong hop, khi nhan button_1 thi deu ve man_red
//				}
//		    	break;
//		    case AUTO_YELLOW_RED:
//				light_1(yellow);
//				light_2(red);
//				if(timer_flag == 1)
//				{
//					setTimer(time_green * 100);
//					status = AUTO_RED_GREEN;
//				}
//				if(button_flag[0] == 1)
//				{
//					button_flag[0] = 0;
//					status = MAN_RED;  // moi truong hop, khi nhan button_1 thi deu ve man_red
//				}
//				break;
//		    default:
//		    	break;
//		}
//}




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
				HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, GPIO_PIN_RESET);

				display_2(time_red_copy / 10);
				display_1(time_green_copy / 10);
				led7_1 = 1;
				break;
			case 1:
				HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, GPIO_PIN_SET);
				display_2(time_red_copy % 10);
				display_1(time_green_copy % 10);
				//display_2(time_red_copy % 10);
				//display_2(8);
				led7_1 = 0;
				break;
			default:
				break;
		}
	}
	else if(status == AUTO_RED_YELLOW)
	{
		switch(led7_1){
			case 0:
				HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, GPIO_PIN_RESET);

				display_2(time_red_copy / 10);
				display_1(time_yellow_copy / 10);
				//display_2(9);
				led7_1 = 1;
				break;
			case 1:
				HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, GPIO_PIN_SET);
				display_2(time_red_copy % 10);
				display_1(time_yellow_copy % 10);
				//display_2(time_red_copy % 10);
				//display_2(8);
				led7_1 = 0;
				break;
			default:
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
//		    	setTimer(time_green * 100);    // set 3s cho trang thai red_green
		    	setTimer_1s1(100);             // timer 1s
//		    	setTimer_EN_GR1(freq1_led7);   // timer freg giua 2 con led7 cua 1 cum
//		    	setTimer_EN_GR2(freq2_led7);
		    	break;
		    case AUTO_RED_GREEN:
		    	light_1(red);
		    	light_2(green);

		    	if(timer_EN_GR1_flag == 1)
				{
					setTimer_EN_GR1(freq1_led7);
					display7seg();
//					switch(led7_2){
//						case 0:
//							HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
//							HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);
//							//display_1(time_green_copy / 10);
//							//display_1(1);
//							led7_2 = 1;
//							break;
//						case 1:
//							HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
//							HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
//							//display_1(time_green_copy % 10);
//							//display_1(-1 % 10);
//							led7_2 = 0;
//							break;
//					}
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
//		    	if(timer_flag == 1)
//		    	{
//		    		setTimer(time_yellow * 100); // set 2s cho trang thai red_yellow
//		    		status = AUTO_RED_YELLOW;
//					time_green_copy = led_auto_buffer[1];
////		    		setTimer_1s1(100);             // timer 1s
////					setTimer_EN_GR1(freq1_led7);   // timer freg giua 2 con led7 cua 1 cum
////					setTimer_EN_GR2(freq2_led7);
//
//		    	}
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
//		    	if(timer_EN_GR1_flag == 1)
//				{
//					setTimer_EN_GR1(freq1_led7);
//					switch(led7_1){
//						case 0:
//							HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
//							HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, GPIO_PIN_RESET);
//							display_2(time_red_copy / 10);
//							led7_1 = 1;
//							break;
//						case 1:
//							HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_RESET);
//							HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, GPIO_PIN_SET);
//							display_2(time_red_copy % 10);
//							led7_1 = 0;
//							break;
//					}
//				}
//				if(timer_EN_GR2_flag == 1)
//				{
//					setTimer_EN_GR2(freq2_led7);
//					switch(led7_2){
//						case 0:
//							HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
//							HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);
//							display_1(time_yellow_copy / 10);
//							led7_2 = 1;
//							break;
//						case 1:
//							HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
//							HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
//							display_1(time_yellow_copy % 10);
//							led7_2 = 0;
//							break;
//					}
//				}
//		    	if(timer_flag == 1)
//		    	{
//		    		setTimer(time_green * 100);
//		    		status = AUTO_GREEN_RED;
//		    		time_red_copy = led_auto_buffer[0];
//		    		time_yellow_copy = led_auto_buffer[2];
//		    	}
		    	if(button_flag[0] == 1)
				{
		    		button_flag[0] = 0;
//		    		setTimer(800);      // neu khong nhan gi nua, 8s sau quay ve trang thai auto.
					status = MAN_RED;  // moi truong hop, khi nhan button_1 thi deu ve man_red
				}
		    	break;
		    case AUTO_GREEN_RED:
		    	light_1(green);
		    	light_2(red);
		        if(timer_flag == 1)
		        {
		    		setTimer(time_yellow * 100);
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
					setTimer(time_green * 100);
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





