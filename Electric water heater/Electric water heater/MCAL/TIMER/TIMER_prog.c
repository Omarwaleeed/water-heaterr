/*******************************************************************************/
/*******************************************************************************/
/*****************   Author:  omar waleed,abdelhamid		********************/
/*****************   Layer:	  MCAL							********************/
/*****************   SWC:     TIMER						********************/
/*****************	 Version: 1.00							********************/
/*******************************************************************************/
/*******************************************************************************/

#include "TIMER_inteface.h"
#include "GIE_interface.h"

/*----------------------------------------------------------------------------*-
timer1_init() : we used this function to initialize timer(1) so it could measure time between tasks every 1ms.
-*----------------------------------------------------------------------------*/

void timer1_init()
{
	

	
	
	// hnkhtar CTC Mode
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	
	
	// hn3ml ll value Load fe OCR1A
	OCR1AH = 0b00000000;
	OCR1AL = 0b01100010;
	
	// hnkhtar el Clock Prescaler (F_CPU / 1024)
	SET_BIT(TCCR1B,TCCR1B_CS10);
	CLR_BIT(TCCR1B,TCCR1B_CS11);
	SET_BIT(TCCR1B,TCCR1B_CS12);
	
	// hn3ml Enable ll Global Interrupt bit
	GIE_voidEnableGlobal();

}

/*----------------------------------------------------------------------------*-
timer0_init() : we used this function to initialize timer(0) so it could trigger INT every 100ms to get Temp.
-*----------------------------------------------------------------------------*/

void timer0_init()
{
	
	// hnkhtar el mode
	SET_BIT(TCCR0,TCCR0_WGM01);
	
	// hn3ml Load ll Value fe OCR0
	OCR0 = 250;
	
	// hnkhtar el Prescaler
	SET_BIT(TCCR0,TCCR0_CS00);
	SET_BIT(TCCR0,TCCR0_CS02);
	
	//hn3ml Enable ll Timer INT
	GIE_voidEnableGlobal();
	SET_BIT(TIMSK,TIMSK_OCIE0);
	
}

/*----------------------------------------------------------------------------*-
timer1_INT_disable() :we used this function to stop timer(1) from triggering INTERRUPTS.
-*----------------------------------------------------------------------------*/

void timer1_INT_disable()
{
	
	// hn3ml Disable ll Interrupts we7na bn3ml compare m3 values A.
	CLR_BIT(TIMSK,OCIE1A);
	
}

/*----------------------------------------------------------------------------*-
timer1_INT_enable() : we used this function start timer(1).
-*----------------------------------------------------------------------------*/

void timer1_INT_enable()
{
	
	// hn3ml Enable ll Interrupts we7na bn3ml compre m3 values A.
	SET_BIT(TIMSK,OCIE1A);
	
}