/*
 * seven_segments.c
 *
 *  Created on: Dec 13, 2023
 *      Author: Eid Elsayed Okda
 */


#include "dio.h"
#include "seven_segments.h"
#include "util/delay.h"
#include "atmega32_registers_map.h"


#define SEVEN_SEGMENT_MASK  0b10000000


void SevenSeg_Init(void)
{
	Dio_SetPortDirection(SEVENSEG_DISPLAY_PORT, (DDRA & SEVEN_SEGMENT_MASK) | 0x7F ); // DDRA --> PORTA
	Dio_SetPinDirection(SEVENSEG1_EN_PORT, SEVENSEG1_EN_PIN, OUTPUT);
	Dio_SetPinDirection(SEVENSEG2_EN_PORT, SEVENSEG2_EN_PIN, OUTPUT);

}

void SevenSeg_Display(uint8 num)
{
	/*array contains numbers from 0 to 9 in binary */
	uint8 arr[10]={ 0b1000000,0b1111001,0b0100100,0b0110000,0b0011001,0b0010010,0b0000010,0b1111000,0b0000000,0b0010000};
	uint8 units = num % 10;
	uint8 tens = num / 10;
	//uint16 counter;
	Dio_WritePin(SEVENSEG1_EN_PORT, SEVENSEG1_EN_PIN, LOW);
	Dio_WritePin(SEVENSEG2_EN_PORT, SEVENSEG2_EN_PIN, LOW);

		Dio_WritePort(SEVENSEG_DISPLAY_PORT, (DDRA & SEVEN_SEGMENT_MASK) | arr[units] );
		Dio_WritePin(SEVENSEG1_EN_PORT, SEVENSEG1_EN_PIN, HIGH);
		_delay_ms(10);
		Dio_WritePin(SEVENSEG1_EN_PORT, SEVENSEG1_EN_PIN, LOW);

		Dio_WritePort(SEVENSEG_DISPLAY_PORT, (DDRA & SEVEN_SEGMENT_MASK) | arr[tens] );
		Dio_WritePin(SEVENSEG2_EN_PORT, SEVENSEG2_EN_PIN, HIGH);
		_delay_ms(10);
		Dio_WritePin(SEVENSEG2_EN_PORT, SEVENSEG2_EN_PIN, LOW);

}

void SevenSeg_Off(void){
	Dio_WritePort(SEVENSEG_DISPLAY_PORT, (DDRA & SEVEN_SEGMENT_MASK) | 0b0000000);
	Dio_WritePin(SEVENSEG1_EN_PORT, SEVENSEG1_EN_PIN, LOW);
	Dio_WritePin(SEVENSEG2_EN_PORT, SEVENSEG2_EN_PIN, LOW);
}
