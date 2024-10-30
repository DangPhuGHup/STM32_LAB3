/*
 * software_timer.h
 *
 *  Created on: Oct 28, 2024
 *      Author: Admin
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer_flag;
extern int timer_EN_GR1_flag; // bat tat cho cum 2 7seg thu nhat
extern int timer_EN_GR2_flag;
extern int timer1_1s_flag;
extern int timer2_1s_flag;
void setTimer(int duration);
void setTimer_EN_GR1(int duration);
void setTimer_EN_GR2(int duration);
void setTimer_1s1(int duration);
void setTimer_1s2(int duration);
void timerRun();

#endif /* INC_SOFTWARE_TIMER_H_ */
