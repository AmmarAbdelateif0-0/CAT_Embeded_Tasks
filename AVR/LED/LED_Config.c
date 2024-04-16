/*
 * LED_Config.c
 *
 *  Created on: Mar 8, 2024
 *      Author: aboam
 */
#include"STD_TYPES.h"
#include"DIO_ErrorState.h"

#include"Led_Config.h"
#include"LED_priv.h"
#include"Switch_Config.h"
#include"Switch_Interface.h"
#include"DIO_Interface.h"


LED_t LED_AstrLedConfig[LED_NUM]=
{
		{DIO_u8PORTA, DIO_u8Pin0, LED_SOURCE, LED_OFF}
	   ,{DIO_u8PORTB, DIO_u8Pin1, LED_SOURCE, LED_OFF}
	   ,{DIO_u8PORTC, DIO_u8Pin2, LED_SINK  , LED_ON}
};




