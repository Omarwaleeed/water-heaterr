/*******************************************************************************/
/*******************************************************************************/
/*****************   Author:  omar waleed,abdelhamid		********************/
/*****************   Layer:	  APP							********************/
/*****************   SWC:     SYSTEM						********************/
/*****************	 Version: 1.00							********************/
/*******************************************************************************/
/*******************************************************************************/

/*----------------------------------------------------------------------------*-
sys_init() : we used this function to initialize all modules of the system and 
to set initial temperature tio the EEPROM.
-*----------------------------------------------------------------------------*/

#include "SYS_interface.h"

void sys_init(void)
{
	// hn3ml initialize ll modules kolha
	ADC_init();
	Buttons_init();
	cool_init();
	heat_init();
	led_init();
	SSD_init();
	timer0_init();
	timer1_init();
	timer1_INT_enable();
	
	// hnkhly el ON_OFF_flag fe el OFF mode.
	Curr_state = OFF;
	
	// hn3ml set ll initial temp. and hnmly el array.
	if(EEPROM_read(0x0000) != 0xFF){
		desired_temp = EEPROM_read(0x0000);
	}
	else{
		desired_temp = INIT_DESIRED_TEMP;
	}
	
	temp_arr_init();
	
	// hn3ml save ll desired temp fe el EEPROM.
	
	EEPROM_write(0x0000,(uint8) desired_temp);
	
}

/*----------------------------------------------------------------------------*-
OFF_state() : we used this function to turn off all the output display and the timer.
-*----------------------------------------------------------------------------*/

void OFF_state(void)
{
		SSD_turn_off();
		led_off();
		heat_stop();
		cool_stop();
		go_to_sleep();
}

/*----------------------------------------------------------------------------*-
ON_state : we used this function for two purposes which is:
	- waits for the timer to measure temperature using ADC every 100ms.
	- checks for the UP and DOWN buttons to switch to the SETTING mode.
-*----------------------------------------------------------------------------*/

void ON_state(void)
{
	
	// lw 3ada 100ms w el flag ykon triggered hn measure el temperature mn el sensor w hn7otha fe el array w hn7sb el average.
		
	if (temp_measure_f == 1)
	{
		actual_temp = (ADC_read()*0.5);
		add_new_temp(temp_arr , actual_temp);
		avg_temp = calc_avg_temp(temp_arr);	
		temp_measure_f = 0;
	}
	
	SSD_write(actual_temp);
	
	// hnshghl el cooler aw el heater ON aw OFF 3la hasb el average temp. ely et3mlha emasure mn el array.

	
	change_temp();
	 
	 // hn3ml Check lw el UP oaw el DOWN buttons pressed 3shan n3ml switch ll SETTING_MODE.

	if(UP_pressed()==PRESSED || DOWN_pressed()==PRESSED){

		SSD_disable();
		setting_counter = 0;
		Curr_state = SETTING;
			
	}
}



void SET_state(void)
{
	heat_stop();
	cool_stop();
	led_off();
	
	// 3shan n3ml toggle ll seven segment wehna bnktb el desired temperature.
	
	if(toggle_f == 1){
		SSD_write(desired_temp);
	}
	else{
		SSD_turn_off();
	}
	
	// lw el UP aw el DOWN pressed hnghyr el desired temp tool mahya fe el range.
	
	if((UP_pressed() == PRESSED) && (desired_temp < MAX_TEMP))
	{
		desired_temp = desired_temp + 5;
		setting_counter = 0;
		SSD_write(desired_temp);
	}
	else if ((DOWN_pressed() == PRESSED) && (desired_temp > MIN_TEMP))
	{
		desired_temp = desired_temp - 5;
		setting_counter = 0;
		SSD_write(desired_temp);
	}
	
	EEPROM_write(0x0000,desired_temp);
	
}

/*----------------------------------------------------------------------------*-
change_temp : we used this function to turn on the Heater or the Cooler.
-*----------------------------------------------------------------------------*/

void change_temp(void)
{
	if( (desired_temp < avg_temp + MARGIN_TEMP) && (desired_temp > avg_temp - MARGIN_TEMP) )
	{					
		// lw el Actual Temperature equals Desired Temperature fa malhash lzma el heating aw el cooling.
		heat_stop();
		cool_stop();
		led_off();
	}
	else if(desired_temp < avg_temp + MARGIN_TEMP)
	{
		// lw el Actual Temperature akbr fa sa3etha e7na m7tagen n3ml cooling. 
		
		heat_stop();
		cool_start();
		led_on();
	}
	else if (desired_temp > avg_temp - MARGIN_TEMP)
	{
		// lw el Actual Temperature asghr fa sa3etha e7na m7tagen n3ml heating. 
		heat_start();
		cool_stop();
		if (toggle_f == 1)
		{
			led_on();
		}
		else {
			led_off();
		}
	}
}

/*----------------------------------------------------------------------------*-
temp_array_initialization : we used this function to read the actual temp. and store it in the temp. array.
-*----------------------------------------------------------------------------*/

void temp_arr_init(void)
{
	uint16 first_temp = ADC_read()*0.5;
	
	for (uint8 i = 0; i<NUM_OF_TEMP_MEASURES; i++){
		temp_arr[i]= first_temp;
	}
	
	avg_temp = calc_avg_temp(temp_arr);
	arr_counter = 0;
}

/*----------------------------------------------------------------------------*-
add_new_temp : we used this function to add the new measured temp. to the temp. array and have it's average during the code.
-*----------------------------------------------------------------------------*/

void add_new_temp(uint16 * arr , uint16 new_val)
{
	arr[arr_counter] = new_val;
	arr_counter ++;
	
	if (arr_counter == 10){
		arr_counter = 0;
	}
}

/*----------------------------------------------------------------------------*-
Calculate_Average_Temp.: we used this function to calculate the last 10 measured temperatures.
-*----------------------------------------------------------------------------*/

uint16 calc_avg_temp(uint16 * arr)
{
	uint16 sum = 0;
	uint16 avg;
	
	for(uint8 i=0; i<NUM_OF_TEMP_MEASURES; i++){
		sum = sum + arr[i];
	}
	avg = (uint16) sum / NUM_OF_TEMP_MEASURES;
	return avg;
}

/*----------------------------------------------------------------------------*-
go_to_sleep : we used this function to save more power when it doesn't need to perform any task at the moment.
-*----------------------------------------------------------------------------*/

void go_to_sleep(void)
{
	
	MCUCR&=~(1<<SM0);
	MCUCR&=~(1<<SM1);
	MCUCR&=~(1<<SM2);
	
	MCUCR|=(1<<SE);

}
