/*
 * dio.h
 *
 *  Created on: Dec 13, 2023
 *      Author: Eid Elsayed Okda
 */

#ifndef MCAL_DIO_DIO_H_
#define MCAL_DIO_DIO_H_


#include "std_types.h"


typedef enum{
	LOW,
	HIGH
}Dio_PinStateType;

typedef enum{
	INPUT,
	OUTPUT
}Dio_PinDirType;

typedef enum{
	DIO_PORTA,
	DIO_PORTB,
	DIO_PORTC,
	DIO_PORTD
}Dio_PortType;

typedef enum{
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7
}Dio_PinType;


void Dio_SetPinDirection(Dio_PortType port, Dio_PinType pin,Dio_PinDirType mode);
void Dio_SetPortDirection(Dio_PortType port, uint8 mode);
void Dio_WritePin(Dio_PortType port, Dio_PinType pin, Dio_PinStateType state);
void Dio_WritePort(Dio_PortType port, uint8 state);
Dio_PinStateType Dio_ReadPin(Dio_PortType port, Dio_PinType pin);
uint8 Dio_ReadPort(Dio_PortType port);
void Dio_TogglePin(Dio_PortType Port, Dio_PinType pin);


#endif /* MCAL_DIO_DIO_H_ */
