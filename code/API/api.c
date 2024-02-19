/*
 * api.c
 *
 *  Created on: Dec 13, 2023
 *      Author: Eid Elsayed Okda
 */

#include "api.h"


/*Variables used in the program*/
static float32 measured_temp;
static uint16 temp_arr[10];
static uint8 temp_arr_index =0;
static uint16 avg_temp = 0;
static uint16 sum_temp = 0;
uint16 millisec_counter = 0;
uint8 temp_sensor_counter=0;
uint16 exit_mode_counter=0;
uint8 disp_toggle_counter=0;
uint16 set_temp = 60;
uint8 current_state ;
uint8 toggle_system = 0;
uint8 eeprom_counter;
uint8 stored_temp =0;

/*
 * system_init is a function to initialize all the program
 * */

void system_init(){


    /*Interrupt Initialization*/
	Ext_Int_Init(EXT_INT0);
	Ext_Int_SetCallBack(EXT_INT0,  increase_temp);
	Ext_Int_Enable(EXT_INT0);

	Ext_Int_Init(EXT_INT1);
	Ext_Int_SetCallBack(EXT_INT1, decrease_temp);
	Ext_Int_Enable(EXT_INT1);

	Ext_Int_Init(EXT_INT2);
	Ext_Int_SetCallBack(EXT_INT2, system_toggle);
	Ext_Int_Enable(EXT_INT2);



	/*Timer0 Initialization*/

	Timer0_Init();
	Timer0_SetCallBack(TIMER0_OVERFLOW_INT_ID , timer_counters);
	Timer0_SetTime(1);
	Timer0_Start();
	Timer0_EnableInt(TIMER0_OVERFLOW_INT_ID );

	Conversion_Init(HEATER);
	Conversion_Init(COOLER);

	Led_Init();

	SevenSeg_Init();

	Button_Init(UPBTN0);
	Button_Init(DOWNBTN1);
	Button_Init(ONBTN2);

	ADC_Init();

/*
	// I2C initialization in the eeprom initialization
	TWI_initMaster();
*/

	EEPROM_init();

	GIE_Enable();



	millisec_counter = 0;
	temp_sensor_counter=0;
	exit_mode_counter=0;
	disp_toggle_counter=0;
	set_temp = 60;
	eeprom_counter = 0;
	current_state = OFF;

}








void system_on(void){
	current_state = ON ;
	toggle_system=1;

	/*to check on the stored temperature*/
	if(eeprom_counter == 0){
		stored_temp =(uint8) set_temp;
	}
	else{
		EEPROM_readByte(02,&stored_temp);
	}

	/*ADC will measure the temperature every 100 millisecond */
	if(temp_sensor_counter != 0 ){
	   temp_sensor_counter=0;
	   measured_temp = ((ADC_Read())*0.5)-1;
	   temp_arr[temp_arr_index ] = (uint16)measured_temp;
	   temp_arr_index ++;
	}

	/*to get the average of the last 10 reads from ADC  */

	if(temp_arr_index  == 9){
		temp_sensor_counter=0;
		sum_temp = 0;
		avg_temp = 0;
		for(temp_arr_index = 0; temp_arr_index <= 9 ;temp_arr_index++){
			sum_temp += temp_arr[temp_arr_index];
		}
		avg_temp = sum_temp / 10 ;
		temp_arr_index =0;
	}
	SevenSeg_Display(measured_temp);


	/*Turn on Heater*/
	if((set_temp > avg_temp ) && (set_temp >= (measured_temp + 5))){

		if(disp_toggle_counter % 2 ==0){
			Led_On();
		}
		else{
			Led_Off();
		}
		Conversion_Off(COOLER);
		Conversion_On(HEATER);

		SevenSeg_Display(measured_temp);
	}

	/*Turn on Cooler*/
	else if((set_temp < avg_temp) && (set_temp <= (measured_temp + 5))){
		Led_On();
		Conversion_Off(HEATER);
		Conversion_On(COOLER);
		SevenSeg_Display(measured_temp);
	}

	/*Idle state*/
	else{
		Conversion_Off(HEATER);
		Conversion_Off(COOLER);
		Led_Off();
		SevenSeg_Display(measured_temp);
	}


}


void system_off(void){
	/*close the system*/
	current_state =OFF ;
	toggle_system = 0;
	SevenSeg_Off();
	Conversion_Off(HEATER);
	Conversion_Off(COOLER);
	Led_Off();
}



void up_state(void){
	current_state = UP;
	/*delay for 5 seconds before exit this mode
	 * unless up button has been pressed*/
	if(exit_mode_counter == 1){
			current_state = ON;
			 exit_mode_counter =0;
		}
	else {
		current_state = UP;
	    }

	/*delay for 1 second to blink the seven segment display*/
	if(disp_toggle_counter % 2 ==0){
			SevenSeg_Display(set_temp);
	  }
	else{
			SevenSeg_Off();
	  }

}





void down_state(void){
	current_state = DOWN;

	/*delay for 5 seconds before exit this mode
	 * unless up button has been pressed*/
	if(exit_mode_counter == 1){

			current_state = ON;
			 exit_mode_counter =0;
		}

	/*delay for 1 second to blink the seven segment display*/
	if(disp_toggle_counter % 2 ==0){
			SevenSeg_Display(set_temp);
		}
	else{
			SevenSeg_Off();
		}

}










