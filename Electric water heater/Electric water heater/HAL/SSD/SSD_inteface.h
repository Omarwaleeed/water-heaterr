/*******************************************************************************/
/*******************************************************************************/
/*****************   Author:  omar waleed,abdelhamid		********************/
/*****************   Layer:	  HAL							********************/
/*****************   SWC:     SSD							********************/
/*****************	 Version: 1.00							********************/
/*******************************************************************************/
/*******************************************************************************/

#ifndef SSD_H_
#define SSD_H_


#define F_CPU 1000000UL
#include <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SSD_reg.h"
#include "DIO_reg.h"
#include "PORT_reg.h"


// SSD Control Functions
void SSD_init(void);
void SSD_send(uint16 N);
void SSD_enable(uint8 disp);
void SSD_disable(void);
void SSD_turn_off(void);
void SSD_write(uint16 N);


#endif /* SSD_H_ */
