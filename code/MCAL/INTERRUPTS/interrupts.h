/*
 * interrupts.h
 *
 *  Created on: Dec 13, 2023
 *      Author: Eid Elsayed Okda
 */

#ifndef MCAL_INTERRUPTS_INTERRUPTS_H_
#define MCAL_INTERRUPTS_INTERRUPTS_H_

#include "std_types.h"


/*******GIE INTERRUPT***********/
#define INT0_VECT        __vector_1
#define INT1_VECT        __vector_2
#define INT2_VECT        __vector_3
#define TIMER1_CAPT_VCET __vector_6
#define TIMER0_COMP_VECT __vector_10
#define TIMER0_OVF_VECT  __vector_11

#define ISR(VECT) void VECT(void)__attribute__((signal));\
				  void VECT(void)

void GIE_Enable(void);
void GIE_Disable(void);


/**********EXT INTERRUPTS**********************/
#define FALLING_EDGE	 1
#define RISING_EDGE		 2
#define LOW_LEVEL        3
#define LOGICAL_CHANGE   4

#define EXT_INT0_SENSE_CONTROL RISING_EDGE
#define EXT_INT1_SENSE_CONTROL RISING_EDGE
#define EXT_INT2_SENSE_CONTROL RISING_EDGE

#define EXT_INT0 	0
#define EXT_INT1 	1
#define EXT_INT2	2

void Ext_Int_Init(uint8 interruptChannel);
void Ext_Int_Enable(uint8 interruptChannel);
void Ext_Int_Disable(uint8 interruptChannel);
void Ext_Int_SetCallBack(uint8 interruptChannel, void (*interruptAction)(void));



#endif /* MCAL_INTERRUPTS_INTERRUPTS_H_ */
