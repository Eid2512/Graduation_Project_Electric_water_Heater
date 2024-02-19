/*
 * main.c
 *
 *  Created on: Dec 13, 2023
 *  Author: Eid Elsayed Okda
 */
#include "api.h"
static uint8 temp_change = 5;

void system_toggle(void);
void increase_temp(void);
void decrease_temp(void);


int main(void){

	system_init();
	while(1){
		/*
		 * It is a switch case to change the state
		 * if any button of the three buttons has been pressed
		 * */

	switch (current_state){
		case OFF: system_off();
		    break;
		case ON:
			system_on();
		    break;
		case UP: up_state();
		    break;
		case DOWN: down_state();
		    break;
		default:
			break;
		}
	}


	return 0;
}
void timer_counters(void){

	millisec_counter++;

	if(millisec_counter % 100){
		temp_sensor_counter++;
	}
	else{
		temp_sensor_counter=0;
	}

	/*to make delay for 1 second*/
	if(	millisec_counter % 1000 ==0){
		disp_toggle_counter++;
	}

	/*to make delay for 5 seconds*/
	if(millisec_counter % 5000 == 0){
		exit_mode_counter++;
	}

}


void increase_temp(void){
	/*to increase the temperature by 5 degrees if the system is on*/
	if(toggle_system == 1){
		current_state = UP;
		exit_mode_counter=0;
		millisec_counter=0;
		if( (set_temp < 75)  ){
			set_temp += temp_change ;
			stored_temp = (uint8) set_temp;
			EEPROM_writeByte(0,stored_temp);
			eeprom_counter++;
		}
	}


}


void decrease_temp(){
	/*to increase the temperature by 5 degrees if the system is on*/
	if(toggle_system == 1){
		current_state = DOWN;
		exit_mode_counter=0;
		millisec_counter=0;
		if( set_temp > 35  ){
			set_temp -= temp_change ;
			stored_temp = (uint8) set_temp;
			EEPROM_writeByte(0,stored_temp);
			eeprom_counter++;
		}
	}

}


void system_toggle(void){
	/*if the system was off turned it on and the opposite right*/
	if(current_state == OFF &&  Button_GetState(ONBTN2)==PRESSED/*flag_toggle==1*/){
		current_state = ON;
	}
	else if(current_state == ON && Button_GetState(ONBTN2)==PRESSED/*flag_toggle==2*/){
		current_state = OFF;
	}
}



