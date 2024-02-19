/*
 * adc.h
 *
 *  Created on: Dec 13, 2023
 *      Author: Eid Elsayed Okda
 */

#ifndef MCAL_ADC_ADC_H_
#define MCAL_ADC_ADC_H_

#include "std_types.h"

typedef enum{
	ADC0,
	ADC1,
	ADC2,
	ADC3,
	ADC4,
	ADC5,
	ADC6,
	ADC7
}ADC_NUM;

typedef enum{
	_2_DIVISION_FACTOR = 1,
	_4_DIVISION_FACTOR,
	_8_DIVISION_FACTOR,
	_16_DIVISION_FACTOR,
	_32_DIVISION_FACTOR,
	_64_DIVISION_FACTOR,
	_128_DIVISION_FACTOR,
}Division_Factor;

#define AVCC      1
#define AREF_PIN  2
#define _2V56     3


/* SELECT AREF MODE: AVCC, AREF_PIN,_2V56 */
#define ADC_V_REF AVCC

/* SELECT ADC_CHANNEL: ADC0 -> ADC7 */
#define ADC_CHANNEL ADC7

/* SELECT ADC_PRESCALER: _2_DIVISION_FACTOR -> _128_DIVISION_FACTOR */
#define ADC_PRESCALER _128_DIVISION_FACTOR


/* functions prototype */
void ADC_Init(void);
uint16 ADC_Read(void);
void ADC_AutoEnable(void);


#endif /* MCAL_ADC_ADC_H_ */
