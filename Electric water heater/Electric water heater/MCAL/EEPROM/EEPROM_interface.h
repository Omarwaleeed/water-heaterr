/*******************************************************************************/
/*******************************************************************************/
/*****************   Author:  omar waleed,abdelhamid		********************/
/*****************   Layer:	  MCAL							********************/
/*****************   SWC:     EEPROM						********************/
/*****************	 Version: 1.00							********************/
/*******************************************************************************/
/*******************************************************************************/




#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

#include <avr/io.h>
#include "BIT_MATH.h"

void EEPROM_write(const unsigned short addr, unsigned char data);
unsigned char EEPROM_read(const unsigned short addr);

#endif /* EEPROM_H_ */
