/*******************************************************************************/
/*******************************************************************************/
/*****************   Author:  omar waleed,abdelhamid		********************/
/*****************   Layer:	  HAL							********************/
/*****************   SWC:     LED							********************/
/*****************	 Version: 1.00							********************/
/*******************************************************************************/
/*******************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "LED_interface.h"
#include "LED_reg.h"
#include "DIO_reg.h"
#include "PORT_reg.h"


/*----------------------------------------------------------------------------*-
led_init() : we used this function to initialize the heating element indication LED by making it an output pin.
-*----------------------------------------------------------------------------*/

void led_init(void)
{
	
	// hnkhly pin0 fe el port tkon output pin w el led pin htkon initially off.
	
	SET_BIT(LED_PORT_DIR,LED_PIN);
	CLR_BIT(LED_PORT,LED_PIN);

}

/*----------------------------------------------------------------------------*-
LED control : we used this function to control on/off button of the led.
-*----------------------------------------------------------------------------*/

void led_on(void)
{
	SET_BIT(LED_PORT,LED_PIN);
}

void led_off(void)
{
	CLR_BIT(LED_PORT,LED_PIN);
}
