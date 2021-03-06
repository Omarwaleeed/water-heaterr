/*******************************************************************************/
/*******************************************************************************/
/*****************   Author:  omar waleed,abdelhamid		********************/
/*****************   Layer:	  MCAL							********************/
/*****************   SWC:     TIMER							********************/
/*****************	 Version: 1.00							********************/
/*******************************************************************************/
/*******************************************************************************/

#ifndef TIMER_H_
#define TIMER_H_
#include "BIT_MATH.h"
#include "TIMER_reg.h"
#include "STD_TYPES.h"
#include <avr/io.h>

void timer1_init();
void timer0_init();
void timer1_INT_disable();
void timer1_INT_enable();

#endif /* TIMER_H_ */