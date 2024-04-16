/*

  * Switch_Config.c
 *
 *  Created on: Mar 8, 2024
 *      Author: aboam
 */

#include"STD_TYPES.h"
#include"DIO_ErrorState.h"

#include"Switch_Priv.h"
#include"Switch_Config.h"

#include"DIO_Interface.h"

SW_t Switch_AstrSwitchStates[SW_NUM]={
		{DIO_u8PORTA,DIO_u8Pin7,DIO_u8PULL_UP}
	   ,{DIO_u8PORTB,DIO_u8Pin7,DIO_u8FLOAT}
	   ,{DIO_u8PORTD,DIO_u8Pin7,DIO_u8PULL_UP}
};


