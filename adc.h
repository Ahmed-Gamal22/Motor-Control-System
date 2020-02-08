/*
 * adc.h
 *
 *  Created on: Dec 30, 2019
 *      Author: ahmed
 */

#ifndef ADC_H_
#define ADC_H_
#include "std_Types.h"
#include "micro_config.h"
#include "common_macros.h"
extern volatile uint16 g_adc;
/*ADC Registers*/
typedef union{
	uint8 data;
	struct{
	uint8 BIT0:1;
	uint8 BIT1:1;
	uint8 BIT2:1;
	uint8 BIT3:1;
	uint8 BIT4:1;
	uint8 BIT5:1;
	uint8 BIT6:1;
	uint8 BIT7:1;
	}BITS;
}REG;

#define ADC_ADMUX 		(*((volatile REG*)0x27))
#define ADC_ADCCSRA 	(*((volatile REG*)0x26))
#define ADCHL  			(*((volatile uint16*)0x24))
#define StatusREG  		(*((volatile REG*)0x5f))

/*Functions Prototypes*/
void ADC_init(void);
uint16 ADC_readChannel(uint8 channel);
void ADC_interReadChannel(uint8 channel);
void ADC_interInit(void);

#endif /* ADC_H_ */
