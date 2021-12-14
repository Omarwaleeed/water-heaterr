/*******************************************************************************/
/*******************************************************************************/
/*****************   Author:  omar waleed,abdelhamid		********************/
/*****************   Layer:	  APP							********************/
/*****************   SWC:     SYSTEM						********************/
/*****************	 Version: 1.00							********************/
/*******************************************************************************/
/*******************************************************************************/


#ifndef SYS_H_
#define SYS_H_


// Description
/*
The system is using a modified cooperative scheduler. it has
only one task (ON_TASK) which executes the functionality of
the normally working WATER HEATER. the ON_TASK is also checking
if buttons are pressed so it can switch to the SETTING_MODE, 
which is another function (state) to allow the user to change
the set point - or the desired temperature.
*/

// when Reading the ADC, the value is halved due to some issues
// to the Temperature sensor in Proteus LM35. So, please, configure
// it depending on your sensor.

// Including All Peripherals
# define F_CPU 1000000UL
#include <util/delay.h>
#include "SYS_Config.h"
#include "STD_TYPES.h"
#include "ADC_interface.h"
#include "BUTTON_interface.h"
#include "ELEMENT_interface.h"
#include "LED_interface.h"
#include "SSD_inteface.h"
#include "TIMER_inteface.h"
#include "EEPROM_interface.h"

#define OFF 0
#define ON 1
#define SETTING 2

/**************************************** 
*               Functions               *
****************************************/

void sys_init(void);
void ON_state(void);
void OFF_state(void);
void SET_state(void);

void change_temp(void);
void add_new_temp(uint16 * arr , uint16 new_val);
uint16 calc_avg_temp(uint16 * arr);
void temp_arr_init(void);
void go_to_sleep(void);

/****************************************
*               Variables               *
****************************************/

// will add as needed

uint8 Curr_state;

uint16 temp_arr[NUM_OF_TEMP_MEASURES];
uint16 desired_temp;
uint16 actual_temp;
uint16 avg_temp;

uint8 temp_measure_f;
uint8 temp_measure_counter;
uint8 setting_counter;

uint16 toggle_f;
uint8 arr_counter;

#endif /* SYS_H_ */
