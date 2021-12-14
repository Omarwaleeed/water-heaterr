/*******************************************************************************/
/*******************************************************************************/
/*****************   Author:  omar waleed,abdelhamid		********************/
/*****************   Layer:	  MCAL							********************/
/*****************   SWC:     ADC							********************/
/*****************	 Version: 1.00							********************/
/*******************************************************************************/
/*******************************************************************************/


#include "ADC_interface.h"
#include "ADC_reg.h"
#include "BIT_MATH.h"

/*----------------------------------------------------------------------------*-
ADC_init() : we used this function to begin the ADC to sense the tempreature coming from the sensor. 
-*----------------------------------------------------------------------------*/

void ADC_init()
{
	
	
	// the AVCC pin with a capacitor at the AREF pin.
	SET_BIT(ADMUX,ADMUX_REFS0);
	
	// bnkhtar Channel One 3nd A0 pin.
	CLR_BIT(ADMUX,ADMUX_MUX0);
	CLR_BIT(ADMUX,ADMUX_MUX1);
	CLR_BIT(ADMUX,ADMUX_MUX2);
	CLR_BIT(ADMUX,ADMUX_MUX3);
	CLR_BIT(ADMUX,ADMUX_MUX4);
	
	// bnkhaly el Data tkon Right Adjusted fe el Data Register
	CLR_BIT(ADMUX,ADMUX_ADLAR);
	
	// bnkhtar el Prescaler ll ADC clock.
	// b3deha bnkhtar (2) enha el Prescaler.
	SET_BIT(ADCSRA,ADCSRA_ADPS0);
	CLR_BIT(ADCSRA,ADCSRA_ADPS1);
	CLR_BIT(ADCSRA,ADCSRA_ADPS2);
	
	// Enable the ADC
	SET_BIT(ADCSRA,ADCSRA_ADEN);
	
}

/*----------------------------------------------------------------------------*-
ADC_read() : when we call this function we can read data of tempreature sensor.
-*----------------------------------------------------------------------------*/

uint16 ADC_read()
{
	
	uint16 data;
	
	// Start Conversion
	SET_BIT(ADCSRA,ADCSRA_ADSC);
	
	
	// Indication of finished conversion
	while(is_bit_clr(ADCSRA,ADCSRA_ADIF));
	
	// bn2ra el Data mn el ADC Data Register.
	// hn2ra el awl el low register.
	data = ADCL;
	data |= (ADCH<<8);
	
	// Clear Flag (3shan msh bnstkhdm el interrupt w msh byt3mlha clear lwhdha). 
	
	SET_BIT(ADCSRA,ADCSRA_ADIF);
	
	return data;	
}
