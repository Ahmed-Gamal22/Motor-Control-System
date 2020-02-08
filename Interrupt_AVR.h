/*
 * Interrupt_AVR.h
 *
 * Created: 18-Dec-19 1:31:26 PM
 *  Author: ahmed
 */ 


#ifndef INTERRUPT_AVR_H_
#define INTERRUPT_AVR_H_
#include "std_Types.h"
#include "micro_config.h"
#include "common_macros.h"

extern volatile uint8 flag;
void INT1_Init(void);
#endif /* INTERRUPT_AVR_H_ */
