/*
 * eeprom.c
 *
 *  Created on: Feb 8, 2024
 *      Author: Eid Elsayed
 */

#include <util/delay.h>
#include "std_types.h"
#include "bit_math.h"
#include "eeprom.h"
#include "i2c.h"
#include "atmega32_registers_map.h"

void EEPROM_init(void){
	TWI_initMaster();
}
void EEPROM_writeByte(uint16 wordAddress, uint8 data){
	uint8 address = (wordAddress >> 8) | EEPROM_FIXED_ADRESS;
	TWI_sendStartCondition(); // Send start condition
	TWI_sendSlaveAddWithWrite(address); // Send slave address with write operation
	TWI_sendMasterDataByte((uint8)wordAddress); // send word address
	TWI_sendMasterDataByte(data); // send byte data
	TWI_sendStopCondition();// send stop condition
	_delay_ms(5); // self-timed write cycle delay
}


void EEPROM_readByte(uint16 wordAddress, uint8* data){
	if(data != NULL){
		uint8 address = (wordAddress >> 8) | EEPROM_FIXED_ADRESS;
		TWI_sendStartCondition(); // Send start condition
		TWI_sendSlaveAddWithWrite(address); // Send slave address with write operation
		TWI_sendMasterDataByte((uint8)wordAddress); // send word address
		TWI_sendRepStartCondition();
		TWI_sendSlaveAddWithRead(address); // send slave address with read operation
		TWI_receiveMasterDataByte(data); // &*data   read byte data
		TWI_sendStopCondition();// send stop condition
		_delay_ms(5); // self-timed write cycle delay




	}
}
