/*
 * led.c
 *
 *  Created on: Dec 13, 2023
 *      Author: Eid Elsayed Okda
 */

#include "led.h"
#include "dio.h"


void Led_Init(void){
	Dio_SetPinDirection(LED_PORT, LED_PIN, OUTPUT);
}

void Led_On(void){
	Dio_WritePin(LED_PORT, LED_PIN, HIGH);
}

void Led_Off(void){
	Dio_WritePin(LED_PORT, LED_PIN, LOW);
}

void Led_Toggle(void){
	Dio_TogglePin(LED_PORT, LED_PIN);


}
