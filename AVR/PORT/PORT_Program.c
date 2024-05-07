/*
 * PORT_Program.c
 *
 *  Created on: Apr 30, 2024
 *      Author: aboam
 */
#include "STD_TYPES.h"
#include"DIO_ErrorState.h"
#include "PORT_Config.h"
#include "PORT_Interface.h"
#include "PORT_Private.h"
#include "PORT_Register.h"

void PORT_voidInit(void){
	DDRA=PORTA_DIR;
	DDRB=PORTB_DIR;
	DDRD=PORTD_DIR;
	DDRC=PORTC_DIR;

	PORTA=PORTA_INTIAL_VALUE;
	PORTB=PORTB_INTIAL_VALUE;
	PORTC=PORTC_INTIAL_VALUE;
	PORTD=PORTD_INTIAL_VALUE;

}
