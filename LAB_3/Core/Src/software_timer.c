/*
 * software_timer.c
 *
 *  Created on: Oct 28, 2024
 *      Author: Admin
 */
#include "software_timer.h"

int timer_counter = 0;  // moi 2s bat flag 1 lan
int timer_flag = 1;

int timer_led7_counter = 0;
int timer_led7_flag = 1;

void setTimer(int duration)
{
	timer_counter = duration;
	timer_flag = 0;
}
void setTimer_led7(int duration)
{
	timer_led7_counter = duration;
	timer_led7_flag = 1;
}
void timerRun()
{
	if(timer_counter > 0)
	{
		timer_counter--;
		if(timer_counter <= 0)
		{
			timer_flag = 1;
		}
	}
	if(timer_led7_counter > 0)
		{
			timer_led7_counter--;
			if(timer_led7_counter <= 0)
			{
				timer_led7_flag = 1;
			}
		}

}
