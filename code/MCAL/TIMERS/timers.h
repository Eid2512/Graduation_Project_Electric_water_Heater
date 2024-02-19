/*
 * timers.h
 *
 *  Created on: Dec 13, 2023
 *      Author: Eid Elsayed Okda
 */

#ifndef MCAL_TIMERS_TIMERS_H_
#define MCAL_TIMERS_TIMERS_H_

#include "atmega32_registers_map.h"
#include "std_types.h"

#if 0
/*TIMER0*/
typedef enum{
	TIMER0_NORMAL_MODE,
	TIMER0_CTC_MODE,
	TIMER0_PHASECORRECT_MODE,
	TIMER0_FASTPWM_MODE
}Timer0_Mode;
#endif
#define TIMER0_NORMAL_MODE        0
#define TIMER0_CTC_MODE           1
#define TIMER0_PHASECORRECT_MODE  2
#define TIMER0_FASTPWM_MODE       3

typedef enum{
	TIMER0_PRESCALER_1 = 1,
	TIMER0_PRESCALER_8,
	TIMER0_PRESCALER_64,
	TIMER0_PRESCALER_256,
	TIMER0_PRESCALER_1024,
	TIMER0_PRESCALER_EXTCLK_FALLEDGE,
	TIMER0_PRESCALER_EXTCLK_RAISEDGE
}Timer0_prescaler;

typedef enum{
	TIMER0_OC0_DISCONNECTED,
	TIMER0_OC0_TOGGLE,
	TIMER0_OC0_CLEAR,
	TIMER0_OC0_SET
}Timer0_OC0_mode;

/* Timer OC0 Mode PWM */
#define   TIMER0_OC0_PWM_NON_INVERTING   2
#define   TIMER0_OC0_PWM_INVERTING       3

#define TIMER0_OVERFLOW_INT_ID     0
#define TIMER0_COMP_MATCH_INT_ID   1



/*CONFIGURATION*/

#define TIMER_0_PRESCALER     TIMER0_PRESCALER_256
#define TIMER_0_MODE          TIMER0_NORMAL_MODE
#define F_SYS 16000000
#define TIMER_0_OC0_MODE  TIMER0_OC0_PWM_NON_INVERTING


/*FUNCTIONS DECLARATION*/
void Timer0_Init(void);
void Timer0_SetTime(uint32 timeInMS);
void Timer0_Start(void);
void Timer0_Stop(void);
void Timer0_EnableInt(uint8 intId);
void Timer0_DisableInt(uint8 intId);
void Timer0_SetCallBack(uint8 intId, void (* interruptAction)(void));
/***********************************************************************/



#endif /* MCAL_TIMERS_TIMERS_H_ */
