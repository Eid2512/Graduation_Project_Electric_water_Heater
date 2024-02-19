/*
 * api.h
 *
 *  Created on: Dec 13, 2023
 *      Author: Eid Elsayed Okda
 */





#ifndef API_API_H_
#define API_API_H_

#include "dio.h"
#include "interrupts.h"
#include "timers.h"
#include "std_types.h"
#include "eeprom.h"
#include "adc.h"
#include "led.h"
#include "heater_cooler.h"
#include "seven_segments.h"
#include "buttons.h"
#include "eeprom.h"
#include "i2c.h"

typedef enum{
	OFF,
	ON,
	UP,
	DOWN
}state;

extern uint8 current_state  ;
extern uint16 millisec_counter ;
extern uint8 temp_sensor_counter ;
extern uint16 exit_mode_counter ;
extern uint16 set_temp  ;
extern uint8 disp_toggle_counter;
extern uint8 toggle_system;
extern uint8 eeprom_counter;
extern uint8 stored_temp;


void system_init(void);
void system_toggle(void);
void increase_temp(void);
void decrease_temp(void);
void system_off(void);
void system_on(void);
void timer_counters(void);
void down_state(void);
void up_state(void);


#endif /* API_API_H_ */









