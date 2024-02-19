/*
 * eeprom.h
 *
 *  Created on: Feb 8, 2024
 *      Author: Eid Elsayed
 */

#ifndef HAL_EEPROM_EEPROM_H_
#define HAL_EEPROM_EEPROM_H_
#include "std_types.h"


#define EEPROM_FIXED_ADRESS 0X50 //0b01010000

void EEPROM_init(void);
void EEPROM_writeByte(uint16 wordAddress, uint8 data);
void EEPROM_readByte(uint16 wordAddress, uint8* data);

#endif /* HAL_EEPROM_EEPROM_H_ */
