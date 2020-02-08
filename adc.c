/*
 * adc.c
 *
 *  Created on: Dec 30, 2019
 *      Author: ahmed
 */
#include "adc.h"
volatile uint16 g_adc;
void ADC_init(void)
{
	/*AREF = 5V, ADLAR Left Adjust Result*/
	ADC_ADMUX.data=0;
	/*ADC Enable*/
	ADC_ADCCSRA.BITS.BIT0 = 1;
	/*(/8) Division factor*/
	ADC_ADCCSRA.BITS.BIT1 = 1;
	ADC_ADCCSRA.BITS.BIT7 = 1;
}
void ADC_interInit(void)
{
	/*ADC Enable*/
	ADC_ADCCSRA.BITS.BIT7 = 1;
	/*(/8) Division factor*/
	ADC_ADCCSRA.BITS.BIT0 = 1;
	ADC_ADCCSRA.BITS.BIT1 = 1;
	/*ADC interrupt enable*/
	ADC_ADCCSRA.BITS.BIT3 = 1;
}
void ADC_interReadChannel(uint8 channel)
{
	/*AREF = 5V, ADLAR Left Adjust Result*/
	ADC_ADMUX.data = (ADC_ADMUX.data & 0xE0)|(channel&0x07);
	/*start conversion*/
	ADC_ADCCSRA.BITS.BIT6 = 1;
}
uint16 ADC_readChannel(uint8 channel)
{
	ADC_ADMUX.data = (ADC_ADMUX.data & 0xE0)|(channel&0x07);
	/*start conversion*/
	ADC_ADCCSRA.BITS.BIT6 = 1;
	/*wait till ADC flag = 1*/
	while(ADC_ADCCSRA.BITS.BIT4 == 0);
	/*clear flag*/
	ADC_ADCCSRA.BITS.BIT4 = 1;
	/*return data*/
	return ADCHL;
}
ISR(ADC_vect)
{
	g_adc = ADCHL;
}
