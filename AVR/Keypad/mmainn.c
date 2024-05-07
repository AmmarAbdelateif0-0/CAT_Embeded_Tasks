/*
 * main.c
 *
 *  Created on: May 1, 2024
 *      Author: aboam
 */

#include "STD_TYPES.h"

#include"DIO_ErrorState.h"
#include "DIO_Interface.h"

//#include "CLCD_Interface.h"

#include"Keypad_Interface.h"
void main(void){
	u8 Local_u8Key=0xff;
	DIO_EnuInit();
//	CLCD_EnuInit();
	while(1){
		do{
		Local_u8Key=KPD_u8GetPressedKey();

		}while(Local_u8Key==0XFF);
		DIO_EnuSetPinortValue(DIO_u8PORTD,DIO_u8Pin0,DIO_u8HIGH);

	}

}
