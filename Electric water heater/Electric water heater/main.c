/*******************************************************************************/
/*******************************************************************************/
/*****************   Author:  omar waleed,abdelhamid		********************/
/*****************   SWC:     MAIN							********************/
/*****************	 Version: 1.00							********************/
/*******************************************************************************/
/*******************************************************************************/

# define F_CPU 1000000UL
#include <util/delay.h>
#include "STD_TYPES.h"
#include "SYS_interface.h"
#include "BIT_MATH.h"
#include <avr/interrupt.h>


/*----------------------------------------------------------------------------*-
ON/OFF_Button_ISR : we used this function to control ON/OFF state.
-*----------------------------------------------------------------------------*/

ISR(INT2_vect)
{
	if(Curr_state==OFF)
	{
		Curr_state = ON;
		desired_temp = EEPROM_read(0x0000);
	}
	else if (Curr_state==ON || Curr_state==SETTING)
	{
		Curr_state = OFF;
	}
}

/*----------------------------------------------------------------------------*-
TIMER1_ISR (A) : we used this function to trigger the ISR every 100ms. So, it makes the temperature
measure flag equals one to enable the ADC.
-*----------------------------------------------------------------------------*/

ISR(TIMER1_COMPA_vect)
{
	temp_measure_f = 1;
}

/*----------------------------------------------------------------------------*-
TIMER1_ISR (B) : we used this function to trigger the ISR every 1 second. So, it toggles the
toggle flag for the LED and the Seven Segment. and counts to keep it in

-*----------------------------------------------------------------------------*/

ISR(TIMER0_COMP_vect)
{
	if ((Curr_state==SETTING) || (Curr_state==ON))
	{
		setting_counter++;
		if(setting_counter % 4 == 0){
			toggle_f ^= 1;
		}
		if (setting_counter > 20){
			
			// hnktb el tempreature ely 3yznha fe el EEPROM
			Curr_state = ON;
		}
	}
}

/*----------------------------------------------------------------------------*-
Main_Function : this function is used to allow the program to choose which function will be executed according to the variable Curr_state 
that changes with ISRs. 
-*----------------------------------------------------------------------------*/


int main(void)
{
	
	sys_init();
	
	while(1){
		switch (Curr_state){
			case ON:{
				ON_state();
				break;
			}
			case OFF:{
				OFF_state();
				break;
			}
			case SETTING:{
				SET_state();
				break;
			}
		}
	}
}
