//*******************************************************************************/
/*******************************************************************************/
/*****************   Author:  omar waleed,abdelhamid		********************/
/*****************   Layer:	  HAL							********************/
/*****************   SWC:     SSD							********************/
/*****************	 Version: 1.00							********************/
/*******************************************************************************/
/*******************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SSD_inteface.h"
#include "SSD_reg.h"



/*----------------------------------------------------------------------------*-
SSD_Init. : we used this function to set the port of seven segments to be output.
-*----------------------------------------------------------------------------*/

// Array for Numbers' Values
uint8 Nums[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

void SSD_init(void)
{
	
	// bnkhly pins el seven segments output pins.
	SSD_PORT_DIR = 0xFF;
	SET_BIT(SSD_ENABLE_PORT_DIR,SSD1_ENABLE_PIN);
	SET_BIT(SSD_ENABLE_PORT_DIR,SSD2_ENABLE_PIN);
	
	// bnkhalehom off.
	SSD_disable();
	
}
	
/*----------------------------------------------------------------------------*-
SSD_Send. : we used this function to upload the numbers to the seven segments.
-*----------------------------------------------------------------------------*/
	
void SSD_send(uint16 N)
{
	SSD_DATA = Nums[N];
}

/*----------------------------------------------------------------------------*-
SSD_enable() : we used this function to enable one of the seven segments and disable the other. 
-*----------------------------------------------------------------------------*/

void SSD_enable(uint8_t disp)
{
	if(disp == 1){
		SET_BIT(SSD_ENABLE_PORT,SSD1_ENABLE_PIN);
		CLR_BIT(SSD_ENABLE_PORT,SSD2_ENABLE_PIN);
	}
	else if (disp == 2){
		SET_BIT(SSD_ENABLE_PORT,SSD2_ENABLE_PIN);
		CLR_BIT(SSD_ENABLE_PORT,SSD1_ENABLE_PIN);
	}
}

/*----------------------------------------------------------------------------*-
SSD_disable() : we used this function to disable both seven segments but only for special cases.
-*----------------------------------------------------------------------------*/

void SSD_disable(void)
{
	CLR_BIT(SSD_ENABLE_PORT,SSD1_ENABLE_PIN);
	CLR_BIT(SSD_ENABLE_PORT,SSD2_ENABLE_PIN);
}

/*----------------------------------------------------------------------------*-
SSD_turn_off() : we used this function to turn off the seven segments.
-*----------------------------------------------------------------------------*/

void SSD_turn_off(void)
{
	SSD_DATA = 0x00;
}

/*----------------------------------------------------------------------------*-
SSD_write() : we used this function to calculate what to write on each of the two SSDs.
-*----------------------------------------------------------------------------*/

void SSD_write(uint16 N)
{
	uint8 units;
	uint8 tens;
	
	units = N % 10;
	tens = (int) N / 10;
	
	SSD_enable(DISP1);
	SSD_send(units);
	_delay_ms(5);
	
	SSD_enable(DISP2);
	SSD_send(tens);
	_delay_ms(5);
}
