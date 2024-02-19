/*
 * heater_cooler.c
 *
 *  Created on: Dec 13, 2023
 *      Author: Eid Elsayed Okda
 */

#include "heater_cooler.h"
#include "dio.h"


void Conversion_Init(heat_type element){
	switch(element)
	{
		case HEATER:
			Dio_SetPinDirection(HEATER_PORT, HEATER_PIN, OUTPUT);
			break;
		case COOLER:
			Dio_SetPinDirection(COOLER_PORT, COOLER_PIN, OUTPUT);
			break;
	}
}
void Conversion_On(heat_type element){
	switch(element)
	{
		case HEATER:
			Dio_WritePin(HEATER_PORT, HEATER_PIN, HIGH);
			break;
		case COOLER:
			Dio_WritePin(COOLER_PORT, COOLER_PIN, HIGH);
			break;
		default:
			break;
	}
}
void Conversion_Off(heat_type element){
	switch(element)
	{
		case HEATER:
			Dio_WritePin(HEATER_PORT, HEATER_PIN, LOW);
			break;
		case COOLER:
			Dio_WritePin(COOLER_PORT, COOLER_PIN, LOW);
			break;
		default:
			break;
	}
}
