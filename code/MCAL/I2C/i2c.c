/*
 * i2c.c
 *
 *  Created on: Feb 6, 2024
 *      Author: Eid Elsayed
 */
#include "atmega32_registers_map.h"
#include "std_types.h"
#include "bit_math.h"
#include "dio.h"
#include "i2c.h"

#define I2C_Prescaler_Mask 11111100


void TWI_initMaster(){
	TWSR = (TWSR & I2C_Prescaler_Mask ) | I2C_PRESCALER ;  //set prescaler 1
	TWBR = 12; // frequency = 400KHZ
	SET_BIT(TWCR,TWEA); // Enable ACK
	SET_BIT(TWCR,TWEN); // Enable TWI Peripheral

}


void TWI_sendStartCondition(){
	SET_BIT(TWCR,TWSTA); // Request Start Condition
	SET_BIT(TWCR,TWINT); // Clear Flag To Start Current Job
	while(0 == (GET_BIT(TWCR,TWINT))); // Busy Wait for the flag
	while((TWSR&0xF8) != TWI_START_CONDITION_ACK  ); // Check ACK = SC ACK
}


void TWI_sendRepStartCondition(){
	SET_BIT(TWCR,TWSTA); // Request Start Condition
	SET_BIT(TWCR,TWINT); // Clear Flag To Start Current Job
	while(0 == (GET_BIT(TWCR,TWINT))); // Busy Wait for the flag
	while(TWI_STATUS_VLAUE != TWI_REP_START_CONDITION_ACK); // Check ACK = SC ACK
}


void TWI_sendStopCondition(){
	SET_BIT(TWCR,TWSTO); // Request Stop Condition
	SET_BIT(TWCR,TWINT); // Clear flag to start current job
}


void TWI_sendSlaveAddWithWrite(uint8 slave_address){
	if(slave_address < 128){
		TWDR = slave_address << 1; // the address put in the 7 bits most
		CLEAR_BIT(TWDR,TWD0);  // clear to choose write option
		CLEAR_BIT(TWCR,TWSTA); //CLEAR START CONDITION BIT
		SET_BIT(TWCR,TWINT); // Clear Flag To Start Current Job
		while(0 == (GET_BIT(TWCR,TWINT))); // Busy Wait for the flag
		while(TWI_STATUS_VLAUE != TWI_SLAVE_ADDRESS_WRITE_ACK  ); // Check ACK = Master transmit(slave address + write request)
	}
}


void TWI_sendSlaveAddWithRead(uint8 slave_address){
	if(slave_address < 128){
		TWDR = slave_address << 1; // the address put in the 7 bits most
		SET_BIT(TWDR,TWD0);  // clear to choose read option
		CLEAR_BIT(TWCR,TWSTA); //CLEAR START CONDITION BIT
		SET_BIT(TWCR,TWINT); // Clear Flag To Start Current Job
		while(0 == (GET_BIT(TWCR,TWINT))); // Busy Wait for the flag
		while(TWI_STATUS_VLAUE != TWI_SLAVE_ADDRESS_READ_ACK  ); // Check ACK = Master transmit(slave address + write request) ACK
	}
}


void TWI_sendMasterDataByte(uint8 Data_packed){
	TWDR = Data_packed;
	SET_BIT(TWCR,TWINT); // Clear Flag To Start Current Job
	while(0 == (GET_BIT(TWCR,TWINT))); // Busy Wait for the flag
	while(TWI_STATUS_VLAUE != TWI_MASTER_DATA_TRANSMIT_ACK); // check ACK = Master transmit data ACK

}


void TWI_receiveMasterDataByte(uint8* Data_packed){
	if(Data_packed != NULL){
		SET_BIT(TWCR,TWINT); // Clear Flag To Start Current Job
		CLEAR_BIT(TWCR,TWEA); // Disable ACK
		while(0 == (GET_BIT(TWCR,TWINT))); // Busy Wait for the flag
		while(TWI_STATUS_VLAUE != TWI_MASTER_DATA_RECEIVE_NACK); // check ACK = Master received data ACK
		*Data_packed = TWDR;     // Read Data from data register
	}
}















