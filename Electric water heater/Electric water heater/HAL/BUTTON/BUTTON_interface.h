/*******************************************************************************/
/*******************************************************************************/
/*****************   Author:  omar waleed,abdelhamid		********************/
/*****************   Layer:	  HAL							********************/
/*****************   SWC:     BUTTON						********************/
/*****************	 Version: 1.00							********************/
/*******************************************************************************/
/*******************************************************************************/


#ifndef BUTTON_INTERFACE_H_
#define BUTTON_INTERFACE_H_

#define F_CPU 1000000UL
#include "BUTTON_reg.h"
#include <util/delay.h>
#include "GIE_interface.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "PORT_reg.h"
#include "DIO_reg.h"
#include "GIE_interface.h"
#include "GIE_reg.h"
#include "EXTI_reg.h"

// Buttons Reading Functions
void Buttons_init(void);
void ON_OFF_EXTI(void);

unsigned char UP_pressed(void);
unsigned char DOWN_pressed(void);


#endif /* BUTTON_H_ */
