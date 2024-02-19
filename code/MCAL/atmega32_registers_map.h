/*
 * atmega32_registers_map.h
 *
 *  Created on: Dec 13, 2023
 *      Author: Eid Elsayed Okda
 */

#ifndef MCAL_ATMEGA32_REGISTERS_MAP_H_
#define MCAL_ATMEGA32_REGISTERS_MAP_H_

#include "std_types.h"

/**********************    DIO     **********************/
#define PORTA     (*((volatile uint8* const)0x3B))
#define DDRA      (*((volatile uint8* const)0x3A))
#define PINA      (*((volatile uint8* const)0x39))

#define PORTB     (*((volatile uint8* const)0x38))
#define DDRB      (*((volatile uint8* const)0x37))
#define PINB      (*((volatile uint8* const)0x36))

#define PORTC     (*((volatile uint8* const)0x35))
#define DDRC      (*((volatile uint8* const)0x34))
#define PINC      (*((volatile uint8* const)0x33))

#define PORTD     (*((volatile uint8* const)0x32))
#define DDRD      (*((volatile uint8* const)0x31))
#define PIND      (*((volatile uint8* const)0x30))

/**********************  Interrupt  **********************/
#define SREG      (*((volatile uint8* const)0x5F))

/* SREG BITS */
#define I_BIT     7

#define MCUCR 	  (*((volatile uint8* const)0x55))
#define MCUCSR    (*((volatile uint8* const)0x54))
#define GICR  	  (*((volatile uint8* const)0x5B))

/* MCUCR BITS */
#define ISC00_BIT 0
#define ISC01_BIT 1
#define ISC10_BIT 2
#define ISC11_BIT 3

/* MCUCSR BITS */
#define ISC2_BIT  6

/* GICR BITS */
#define INT0_BIT  6
#define INT1_BIT  7
#define INT2_BIT  5

/**********************  ADC  **********************/
#define ADMUX			(*((volatile uint8* const)0x27))
#define ADCSRA			(*((volatile uint8* const)0x26))
#define ADC_VALUE		(*((volatile uint16* const)0x24))
#define SFIOR		    (*((volatile uint16* const)0x50))
/* ADMUX BITS */
#define REFS1_BIT			7
#define REFS0_BIT			6
#define ADLAR_BIT			5

/* ADSRA bits */
#define ADEN_BIT			7
#define ADSC_BIT			6
#define ADIF_BIT			4

/*ADCSRA BIT*/
#define ADATE_BIT		    5

/*SFIOR BITS*/
#define    ADTS0_BIT        5
#define    ADTS1_BIT        6
#define    ADTS2_BIT        7

/**********************  Timer0  **********************/
#define TCCR0     (*((volatile uint8* const)0x53))
#define TIMSK     (*((volatile uint8* const)0x59))
#define TCNT0     (*((volatile uint8* const)0x52))
#define OCR0      (*((volatile uint8* const)0x5C))

/* TCCR0 BITS */
#define WGM00_BIT          6
#define WGM01_BIT          3
#define CS02_BIT           2
#define CS01_BIT           1
#define CS00_BIT           0

/* TIMSK BITS */
#define OCIE0_BIT          1
#define TOIE0_BIT          0



/**********EEPROM REGISTERS****************/

#define EEARH     (*((volatile uint8* const)0x3F))
#define EEARL     (*((volatile uint8* const)0x3E))
#define EEAR     (*((volatile uint16* const)0x3E))
#define EEDR     (*((volatile uint8* const)0x3D))
#define EECR     (*((volatile uint8* const)0x3C))

/*EECR BITS*/
typedef enum{
	EERE,
	EEWE,
	EEMWE,
	EERIE
}EECR_BITS;


/**********I2C REGISTERS****************/

#define  TWBR (*((volatile uint8* const)0x20)) // TWI BIT Rate Register
#define  TWDR (*((volatile uint8* const)0x23)) // TWI Data Register
#define  TWAR (*((volatile uint8* const)0x22)) // TWI (Slave) Address Register
#define  TWSR (*((volatile uint8* const)0x21)) // TWI Status Register
#define  TWCR (*((volatile uint8* const)0x23)) // TWI Control Register

/*TWBR BITS*/
typedef enum{
	TWBR0,
	TWBR1,
	TWBR2,
	TWBR3,
	TWBR4,
	TWBR5,
	TWBR6,
	TWBR7
}TWBR_BITS;


/*TWCR_BITS*/
typedef enum{
	TWIE,
	TWEN=2,
	TWWC,
	TWSTO,
	TWSTA,
	TWEA,
	TWINT
}TWCR_BITS;

/*TWDR_BITS*/
typedef enum{
	TWD0,
	TWD1,
	TWD2,
	TWD3,
	TWD4,
	TWD5,
	TWD6,
	TWD7
}TWDR_BITS;

/*TWAR_BITS*/
typedef enum{
	TWGCE,
	TWA0,
	TWA1,
	TWA2,
	TWA3,
	TWA4,
	TWA5,
	TWA6
}TWAR_BITS;

/*TWSR_BITS*/
typedef enum{
	TWPS0,  //PRESCALER
	TWPS1,  //PRESCALER
	TWS3=3,
	TWS4,
	TWS5,
	TWS6,
	TWS7
}TWSR_BITS;



#endif /* MCAL_ATMEGA32_REGISTERS_MAP_H_ */
