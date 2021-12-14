/*******************************************************************************/
/*******************************************************************************/
/*****************   Author:  omar waleed,abdelhamid		********************/
/*****************   Layer:	  HAL							********************/
/*****************   SWC:     ELEMENT						********************/
/*****************	 Version: 1.00							********************/
/*******************************************************************************/
/*******************************************************************************/


/*----------------------------------------------------------------------------*-
Heater/Cooler Init. : we used this function to set the cooler and heater pins to be OUTPUT pins.
-*----------------------------------------------------------------------------*/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_reg.h"
#include "ELEMENT_interface.h"
#include "ELEMENT_reg.h"
#include "PORT_reg.h"
void heat_init(void)
{
	SET_BIT(HEAT_PORT_DIR,HEAT_PIN);
}

void cool_init(void)
{
	SET_BIT(COOL_PORT_DIR,COOL_PIN);
}


/*----------------------------------------------------------------------------*-
Heater/Cooler Start : we used this function to start the heater and cooler.
-*----------------------------------------------------------------------------*/

void heat_start(void)
{
	SET_BIT(HEAT_PORT,HEAT_PIN);
}

void cool_start(void)
{
	SET_BIT(COOL_PORT,COOL_PIN);
}


/*----------------------------------------------------------------------------*-
Heater/Cooler Stop : we used thus function to stop them from working.
-*----------------------------------------------------------------------------*/

void heat_stop(void)
{
	CLR_BIT(HEAT_PORT,HEAT_PIN);
}

void cool_stop(void)
{
	CLR_BIT(COOL_PORT,COOL_PIN);
}
