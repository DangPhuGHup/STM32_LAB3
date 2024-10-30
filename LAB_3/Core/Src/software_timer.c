/*
 * software_timer.c
 *
 *  Created on: Oct 28, 2024
 *      Author: Admin
 */
#include "software_timer.h"

int timer_counter = 0;  // moi 2s bat flag 1 lan
int timer_flag = 1;

int timer_EN_GR1_counter = 0;
int timer_EN_GR1_flag = 1;

int timer_EN_GR2_counter = 0;
int timer_EN_GR2_flag = 1;

int timer1_1s_counter = 100;
int timer1_1s_flag = 0;

int timer2_1s_counter = 100;
int timer2_1s_flag = 0;

void setTimer(int duration)
{
	timer_counter = duration;
	timer_flag = 0;
}
void setTimer_EN_GR1(int duration)
{
	timer_EN_GR1_counter = duration;
	timer_EN_GR1_flag = 0;
}
void setTimer_EN_GR2(int duration)
{
	timer_EN_GR2_counter = duration;
	timer_EN_GR2_flag = 0;
}
void setTimer_1s1(int duration)
{
	timer1_1s_counter = duration;
	timer1_1s_flag = 0;
}
void setTimer_1s2(int duration)
{
	timer2_1s_counter = duration;
	timer2_1s_flag = 0;
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
	if(timer_EN_GR1_counter > 0)
	{
	    timer_EN_GR1_counter--;
		if(timer_EN_GR1_counter <= 0)
		{
			timer_EN_GR1_flag = 1;
		}
	}
	if(timer_EN_GR2_counter > 0)
	{
	    timer_EN_GR2_counter--;
		if(timer_EN_GR2_counter <= 0)
		{
			timer_EN_GR2_flag = 1;
		}
	}
    if(timer1_1s_counter > 0)
    {
    	timer1_1s_counter--;
    	if(timer1_1s_counter <= 0)
    	{
    		timer1_1s_flag = 1;
    	}
    }
    if(timer2_1s_counter > 0)
	{
		timer2_1s_counter--;
		if(timer2_1s_counter <= 0)
		{
			timer2_1s_flag = 1;
		}
	}

}
