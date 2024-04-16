/*
 * Seven_Segmant_config.c
 *
 *  Created on: Mar 15, 2024
 *      Author: aboam
 */
#include"STD_TYPES.h"
#include"DIO_ErrorState.h"
#include "DIO_Interface.h"
#include "SevSeg_Priv.h"
#include "SevSeg_Config.h"

SEVSEG_t SEVSEG_AstrConfig [SEG_NUMBER]=
{
		{
			  DIO_u8PORTA,DIO_u8Pin0
			 ,DIO_u8PORTA,DIO_u8Pin1
			 ,DIO_u8PORTB,DIO_u8Pin2
			 ,DIO_u8PORTB,DIO_u8Pin3
			 ,DIO_u8PORTC,DIO_u8Pin4
			 ,DIO_u8PORTC,DIO_u8Pin5
			 ,DIO_u8PORTD,DIO_u8Pin6
			 ,NOT_CONNECTED,NOT_CONNECTED
			 ,NOT_CONNECTED,NOT_CONNECTED
			 ,COMMAN_CATHODE
		},//SEVSEG 1
		{
			  DIO_u8PORTA,DIO_u8Pin2
			 ,DIO_u8PORTA,DIO_u8Pin3
			 ,DIO_u8PORTB,DIO_u8Pin4
			 ,DIO_u8PORTB,DIO_u8Pin5
			 ,DIO_u8PORTC,DIO_u8Pin6
			 ,DIO_u8PORTC,DIO_u8Pin7
			 ,DIO_u8PORTD,DIO_u8Pin1
			 ,NOT_CONNECTED,NOT_CONNECTED
			 ,NOT_CONNECTED,NOT_CONNECTED
			 ,COMMAN_CATHODE
		}//SEVSEG 2

};

