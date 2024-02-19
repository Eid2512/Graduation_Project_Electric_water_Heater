/*
 * heater_cooler.h
 *
 *  Created on: Dec 13, 2023
 *      Author: Eid Elsayed Okda
 */

#ifndef HAL_HEATER_COOLER_HEATER_COOLER_H_
#define HAL_HEATER_COOLER_HEATER_COOLER_H_

#include "dio.h"


typedef enum{
	HEATER,
	COOLER
}heat_type;

#define HEATER_PORT DIO_PORTD
#define COOLER_PORT DIO_PORTB

#define HEATER_PIN PIN7
#define COOLER_PIN PIN4

void Conversion_Init(heat_type element);
void Conversion_On(heat_type element);
void Conversion_Off(heat_type element);



#endif /* HAL_HEATER_COOLER_HEATER_COOLER_H_ */
