/*
 * interrupts.c
 *
 *  Created on: Dec 13, 2023
 *      Author: Eid Elsayed Okda
 */

#include "interrupts.h"
#include "bit_math.h"
#include "atmega32_registers_map.h"




/**********GIE INTERRUPT********************/
void GIE_Enable(void)
{
	/* To enable the global interrupt */
	SET_BIT(SREG,I_BIT);
}

void GIE_Disable(void)
{
	/* To disable the global interrupt */
	CLEAR_BIT(SREG,I_BIT);
}

/*******EXT INTERRUPTS***************/
static void (*Ext_Int_CallBack[3])(void)={NULL};

void Ext_Int_Init(uint8 interruptChannel)
{
	switch(interruptChannel)
	{
		case EXT_INT0:
	#if EXT_INT0_SENSE_CONTROL == FALLING_EDGE
			SET_BIT(MCUCR,ISC01_BIT);
			CLEAR_BIT(MCUCR,ISC00_BIT);
	#elif EXT_INT0_SENSE_CONTROL == RISING_EDGE
			SET_BIT(MCUCR,ISC01_BIT);
			SET_BIT(MCUCR,ISC00_BIT);
	#elif EXT_INT0_SENSE_CONTROL == LOW_LEVEL
			CLEAR_BIT(MCUCR,ISC01_BIT);
			CLEAR_BIT(MCUCR,ISC00_BIT);
	#elif EXT_INT0_SENSE_CONTROL == LOGICAL_CHANGE
			CLEAR_BIT(MCUCR,ISC01_BIT);
			SET_BIT(MCUCR,ISC00_BIT);
	#endif
			break;
		case EXT_INT1:
	#if EXT_INT1_SENSE_CONTROL == FALLING_EDGE
			SET_BIT(MCUCR,ISC11_BIT);
			CLEAR_BIT(MCUCR,ISC10_BIT);
	#elif EXT_INT1_SENSE_CONTROL == RISING_EDGE
			SET_BIT(MCUCR,ISC11_BIT);
			SET_BIT(MCUCR,ISC10_BIT);
	#elif EXT_INT1_SENSE_CONTROL == LOW_LEVEL
			CLEAR_BIT(MCUCR,ISC11_BIT);
			CLEAR_BIT(MCUCR,ISC10_BIT);
	#elif EXT_INT1_SENSE_CONTROL == LOGICAL_CHANGE
			CLEAR_BIT(MCUCR,ISC11_BIT);
			CLEAR_BIT(MCUCR,ISC10_BIT);
	#endif
			break;
		case EXT_INT2:
	#if EXT_INT2_SENSE_CONTROL == FALLING_EDGE
			CLEAR_BIT(MCUCR,ISC2_BIT);
	#elif EXT_INT2_SENSE_CONTROL == RISING_EDGE
			SET_BIT(MCUCSR,ISC2_BIT);
	#endif
			break;
		default:
			break;
	}
}
void Ext_Int_Enable(uint8 interruptChannel)
{
	switch(interruptChannel)
	{
		case EXT_INT0:
			SET_BIT(GICR, INT0_BIT);
			break;
		case EXT_INT1:
			SET_BIT(GICR, INT1_BIT);
			break;
		case EXT_INT2:
			SET_BIT(GICR, INT2_BIT);
			break;
	}
}

void Ext_Int_Disable(uint8 interruptChannel)
{
	switch(interruptChannel)
	{
		case EXT_INT0:
			CLEAR_BIT(GICR, INT0_BIT);
			break;
		case EXT_INT1:
			CLEAR_BIT(GICR, INT1_BIT);
			break;
		case EXT_INT2:
			CLEAR_BIT(GICR, INT2_BIT);
			break;
	}
}

void Ext_Int_SetCallBack(uint8 interruptChannel, void (*interruptAction)(void))
{
	Ext_Int_CallBack[interruptChannel] = interruptAction;
}
/*UP BUTTON*/
ISR(INT0_VECT)
{
	Ext_Int_CallBack[EXT_INT0]();
}
/*DOWN BUTTON*/
ISR(INT1_VECT)
{
	Ext_Int_CallBack[EXT_INT1]();
}
/*ON/OFF BUTTON*/
ISR(INT2_VECT)
{
	Ext_Int_CallBack[EXT_INT2]();
}
