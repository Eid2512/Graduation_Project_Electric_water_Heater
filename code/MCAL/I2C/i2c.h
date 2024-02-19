/*
 * i2c.h
 *
 *  Created on: Feb 6, 2024
 *      Author: Eid Elsayed
 */

#ifndef MCAL_I2C_I2C_H_
#define MCAL_I2C_I2C_H_

#include "atmega32_registers_map.h"
#include "std_types.h"


/*CONFIGURATION*/
typedef enum{
	I2C_PRESCALER_1,
	I2C_PRESCALER_4,
	I2C_PRESCALER_16,
	I2C_PRESCALER_64
}I2C_Prescaler;

#define I2C_PRESCALER                    I2C_PRESCALER_1
#define TWI_STATUS_VLAUE                 (TWSR&0xF8)
#define TWI_START_CONDITION_ACK          0x08
#define TWI_REP_START_CONDITION_ACK      0x10
#define TWI_SLAVE_ADDRESS_WRITE_ACK      0x18
#define TWI_SLAVE_ADDRESS_READ_ACK       0x40
#define TWI_MASTER_DATA_TRANSMIT_ACK     0x28
#define TWI_MASTER_DATA_RECEIVE_ACK      0x50
#define TWI_MASTER_DATA_RECEIVE_NACK     0X58

/*FUNCTIONS DECLARATION*/
void TWI_initMaster();
void TWI_initSlave();
void TWI_sendStartCondition();
void TWI_sendRepStartCondition();
void TWI_sendStopCondition();
void TWI_sendSlaveAddWithWrite(uint8 slave_address);
void TWI_sendSlaveAddWithRead(uint8 slave_address);
void TWI_sendMasterDataByte(uint8 Data_packed);
void TWI_receiveMasterDataByte(uint8* Data_packed);



#endif /* MCAL_I2C_I2C_H_ */
