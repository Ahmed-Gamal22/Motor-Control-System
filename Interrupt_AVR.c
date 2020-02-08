/*
 * Interrupt_AVR.c
 *
 * Created: 18-Dec-19 1:31:08 PM
 *  Author: ahmed
 */ 
#include "Interrupt_AVR.h"
volatile uint8 flag = 0;
void INT1_Init(void)
{
	/*INT1 input*/
	DDRD&=~(1<<PD3);
	/*Rising Edge*/
	MCUCR=(1<<ISC11)|(1<<ISC10);
	/*interrupt enable*/
	GICR=(1<<INT1);
}
ISR(INT1_vect)
{
	flag ^= 1;
}
