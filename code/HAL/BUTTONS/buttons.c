/*
 * buttons.c
 *
 *  Created on: Dec 13, 2023
 *      Author: Eid Elsayed Okda
 */
#include "buttons.h"
#include <util/delay.h>



void Button_Init(uint8 btn)
{
	switch (btn)
	{
		case UPBTN0:
			Dio_SetPinDirection(UPBTN0_PORT, UPBTN0_PIN, INPUT);
			break;
		case DOWNBTN1:
			Dio_SetPinDirection(DOWNBTN1_PORT, DOWNBTN1_PIN, INPUT);
			break;
		case ONBTN2:
			Dio_SetPinDirection(ONBTN2_PORT, ONBTN2_PIN, INPUT);
			break;
	}
}

Dio_PinStateType Button_GetState(uint8 btn)
{
	uint8 btnState = RELEASED;
	switch (btn)
	{
		case UPBTN0:
			if (Dio_ReadPin(UPBTN0_PORT, UPBTN0_PIN) == PRESSED)
			{
				_delay_ms(30);
				if (Dio_ReadPin(UPBTN0_PORT, UPBTN0_PIN) == PRESSED)
				{
					btnState = PRESSED;
					while(Dio_ReadPin(UPBTN0_PORT, UPBTN0_PIN) == PRESSED);
				}
			}
			break;
		case DOWNBTN1:
			if (Dio_ReadPin(DOWNBTN1_PORT, DOWNBTN1_PIN) == PRESSED)
			{
				_delay_ms(30);
				if (Dio_ReadPin(DOWNBTN1_PORT, DOWNBTN1_PIN) == PRESSED)
				{
					btnState = PRESSED;
					while(Dio_ReadPin(DOWNBTN1_PORT, DOWNBTN1_PIN) == PRESSED);
				}
			}
			break;
		case ONBTN2:
			if (Dio_ReadPin(ONBTN2_PORT, ONBTN2_PIN) == PRESSED)
			{
				_delay_ms(30);
				if (Dio_ReadPin(ONBTN2_PORT, ONBTN2_PIN) == PRESSED)
				{
					btnState = PRESSED;
					while(Dio_ReadPin(ONBTN2_PORT, ONBTN2_PIN) == PRESSED);
				}
			}
			break;
	}
	return btnState;
}
