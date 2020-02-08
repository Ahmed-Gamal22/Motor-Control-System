/*
 * pwm.c
 *
 *  Created on: Jan 7, 2020
 *      Author: ahmed
 */
#include "pwm.h"
void PWM_SetDuty(uint16 duty)
{
	TCNT0 = 0;
	OCR0 = (uint8)(((float)duty/1023)*255);
	/*PWM output pin*/
	DDRB|=(1<<PB3);
	/* fast PWM -- non inverting mode -- clock/8 */
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
}

