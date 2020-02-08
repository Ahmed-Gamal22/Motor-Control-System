/*
 * motorSpeed.c
 *
 *  Created on: Jan 7, 2020
 *      Author: ahmed
 */
#include "adc.h"
#include "lcd.h"
#include "Interrupt_AVR.h"
#include "pwm.h"
int main()
{
	/*initialization*/
	/*Enable Global bit*/
	sei();
	/*motor output pins*/
	DDRB|=(1<<PB1)|(1<<PB7);
	/*motor stop initially*/
	PORTB&=~(1<<PB1);
	PORTB&=~(1<<PB7);
	ADC_interInit();
	LCD_init();
	INT1_Init();
	LCD_displayString("ADC Value = ");
	/*super loop*/
	while(1)
	{
		ADC_interReadChannel(0);
		LCD_goToRowColoumn(0,12);
		LCD_integerToString(g_adc);
		PWM_SetDuty(g_adc);
		if(flag == 1)
		{
			PORTB|=(1<<PB7);
			PORTB&=~(1<<PB1);
		}
		else
		{
			PORTB&=~(1<<PB7);
			PORTB|=(1<<PB1);
		}
	}
}
