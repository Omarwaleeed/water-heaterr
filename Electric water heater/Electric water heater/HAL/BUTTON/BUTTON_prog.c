/*******************************************************************************/
/*******************************************************************************/
/*****************   Author:  omar waleed,abdelhamid		********************/
/*****************   Layer:	  HAL							********************/
/*****************   SWC:     BUTTON						********************/
/*****************	 Version: 1.00							********************/
/*******************************************************************************/
/*******************************************************************************/


#include "BUTTON_interface.h"

/*----------------------------------------------------------------------------*-
Buttons_init() : we used this function to set the pins to be input pins then enabling the internal pull up resistor 
and enabling the external interrupt for the ON/OFF button. 
-*----------------------------------------------------------------------------*/

void Buttons_init(void)
{
	// hnkhly el pins ykono INPUT pins
	CLR_BIT(B_PORT_DIR,ON_OFF_PIN);
	CLR_BIT(B_PORT_DIR,UP_PIN);
	CLR_BIT(B_PORT_DIR,DOWN_PIN);
	
	// Enable internal Pull-Up Resistor
	
	SET_BIT(B_PORT,ON_OFF_PIN);
	SET_BIT(B_PORT,UP_PIN);
	SET_BIT(B_PORT,DOWN_PIN);
	
	

	
	// Enable Global Interrupt bit
	GIE_voidEnableGlobal();
	
	// Trigger with Rising Edge
	SET_BIT(MCUCSR,MCUCSR_ISC2);
	
	// Enable INT2 (External Interrupt)
	SET_BIT(GICR,GICR_INT2);
}


/*----------------------------------------------------------------------------*-
UP_pressed() : we used this function to check wether the UP button is pressed or not and then
return the result. 
-*----------------------------------------------------------------------------*/

unsigned char UP_pressed(void)
{
	// Check if pressed for the first time
	if(!(read_bit(PINB,UP_PIN))){
		// hnstna 100ms 3shan nt2ked enha pressed
		_delay_ms(DEBOUNCE_INTERVAL);
		
		// hnt2ked kman mara
		if (!(read_bit(PINB,UP_PIN))){
			return PRESSED;
		}
		else return NOT_PRESSED;
	}
	else return NOT_PRESSED;	
}

/*----------------------------------------------------------------------------*-
DOWN_pressed() : we used this function to check wether the DOWN button is pressed or not and then
return the result. 
-*----------------------------------------------------------------------------*/

unsigned char DOWN_pressed(void)
{
	// Check if pressed for the first time
	if(!(read_bit(PINB,DOWN_PIN))){
		// nafs el kalam hnstna 100ms 3shan nt2ked 
		_delay_ms(DEBOUNCE_INTERVAL);
	
		// w hn-ceck kman mara 
		if (!(read_bit(PINB,DOWN_PIN))){
			return PRESSED;
		}
		else return NOT_PRESSED;
	}
	else return NOT_PRESSED;
}
