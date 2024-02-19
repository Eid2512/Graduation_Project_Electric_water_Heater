/*
 * buttons.h
 *
 *  Created on: Dec 13, 2023
 *      Author: Eid Elsayed Okda
 */

#ifndef HAL_BUTTONS_BUTTONS_H_
#define HAL_BUTTONS_BUTTONS_H_

#include "dio.h"

#define ACTIVE_HIGH 1
#define ACTIVE_LOW  0


/*CONFIGURATION***/
#define BUTTON_SCHEME ACTIVE_HIGH

#define UPBTN0_PORT DIO_PORTD
#define UPBTN0_PIN  PIN2

#define DOWNBTN1_PORT DIO_PORTD
#define DOWNBTN1_PIN PIN3

#define ONBTN2_PORT DIO_PORTB
#define ONBTN2_PIN PIN2

/**INTERFACING***/

#if (BUTTON_SCHEME == ACTIVE_HIGH)

#define PRESSED HIGH
#define RELEASED LOW

#else

#define PRESSED LOW
#define RELEASED HIGH

#endif

typedef enum{
	UPBTN0,
	DOWNBTN1,
	ONBTN2
}BTN_type;

void Button_Init(uint8 btn);
Dio_PinStateType Button_GetState(uint8 btn);




#endif /* HAL_BUTTONS_BUTTONS_H_ */
