/*
 * EEPROM.c
 *
 * Created: 3/22/2021 6:27:21 PM
 *  Author: PC
 */ 

#include "EEPROM_interface.h"

/*----------------------------------------------------------------------------*-
EEPROM_read() : this function is used to read data of EEPROM with given adresss and then return the data.
-*----------------------------------------------------------------------------*/

unsigned char EEPROM_read(const unsigned short addr)
{
	// hn3ml Setup ll Address Register
	EEARL = (char)addr;
	EEARH = (char)(addr>>8);
	
	// Start Reading
	SET_BIT(EECR,EERE);
	
	
	return EEDR;
}

/*----------------------------------------------------------------------------*-
EEPROM_write() : we used this function to write the data inside the EEPROM with a known adress 
and known data.
-*----------------------------------------------------------------------------*/

void EEPROM_write(const unsigned short addr, unsigned char data)
{
	unsigned char INT_EN=0;
		
	// hn3ml Setup ll Address Register
	EEARL = (char)addr;
	EEARH = (char)(addr>>8);
	
	// hn7ot el Data fe el Data Register
	EEDR = data;
	
	// hn3ml Disable ll Interrupts 3shan my7slsh moshkela
	if(((SREG&(1<<7))>>7)==1){
		INT_EN = 1;
		CLR_BIT(SREG,7);
	}
	
	// Start Writing
	SET_BIT(EECR,EEMWE);
	SET_BIT(EECR,EEWE);
	while(((EECR&(1<<EEWE))>>EEWE)==1);
	
	// Back
	if (INT_EN==1)
	{
		SET_BIT(SREG,7);
	}
	
}
