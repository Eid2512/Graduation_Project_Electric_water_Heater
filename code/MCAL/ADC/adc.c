/*
 * adc.c
 *
 *  Created on: Dec 13, 2023
 *      Author: Eid Elsayed Okda
 */
#include "atmega32_registers_map.h"
#include "adc.h"
#include "bit_math.h"
#include "dio.h"
void ADC_Init(void){
	//Dio_SetPinDirection(PORTA,PIN0,INPUT);
#if ADC_V_REF  ==  AVCC
	SET_BIT(ADMUX,REFS0_BIT);
	CLEAR_BIT(ADMUX,REFS1_BIT);
#elif ADC_V_REF  ==  AREF_PIN
	CLEAR_BIT(ADMUX,REFS0_BIT);
	CLEAR_BIT(ADMUX,REFS1_BIT);
#elif ADC_V_REF ==   _2V56
	SET_BIT(ADMUX,REFS0_BIT);
	SET_BIT(ADMUX,REFS1_BIT);
#endif

	/* to select right adjustment */
	CLEAR_BIT(ADMUX,ADLAR_BIT);

	/* to select an ADC channel*/
	ADMUX = (ADMUX & 0b11100000) | ADC_CHANNEL;

	/* to select the ADC frequency*/
	ADCSRA = (ADCSRA & 0b11111000) | ADC_PRESCALER;

	/* to enable ADC circuit*/
	SET_BIT(ADCSRA,ADEN_BIT);

}

uint16 ADC_Read(void){

	uint16 read_value;
	/* to start conversion*/
	SET_BIT(ADCSRA,ADSC_BIT);
	while(IS_BIT_CLEARED(ADCSRA,ADIF_BIT));
	read_value=ADC_VALUE;
	/*clear the flag*/
	SET_BIT(ADCSRA,ADIF_BIT);
	return read_value;
}
void ADC_AutoEnable(void){
	ADCSRA = (ADCSRA & 0xDF) | (1<<ADATE_BIT);
	CLEAR_BIT(SFIOR, ADTS0_BIT );
	CLEAR_BIT(SFIOR, ADTS0_BIT );
	CLEAR_BIT(SFIOR, ADTS0_BIT );
}

