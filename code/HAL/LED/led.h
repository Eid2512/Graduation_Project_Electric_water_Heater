/*
 * led.h
 *
 *  Created on: Dec 13, 2023
 *      Author: Eid Elsayed Okda
 */

#ifndef HAL_LED_LED_H_
#define HAL_LED_LED_H_

#include "dio.h"




#define LED_PORT DIO_PORTB
#define LED_PIN  PIN5

void Led_Init(void);
void Led_On(void);
void Led_Off(void);
void Led_Toggle(void);

#endif /* HAL_LED_LED_H_ */
