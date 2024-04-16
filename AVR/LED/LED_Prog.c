/*
 * LED_Prog.c
 *
 *  Created on: Mar 8, 2024
 *      Author: aboam
 */
#include"STD_TYPES.h"
#include"DIO_ErrorState.h"

#include"LED_priv.h"
#include"Led_Config.h"

#include"DIO_Interface.h"


ES_t LED_enuInit(LED_t * Copy_pstrLedConfig)
{
	u8 Local_u8ErrorState=ES_NOK;
	if(Copy_pstrLedConfig!=NULL)
	{
		u8 Local_u8Iterator=0;
		for(Local_u8Iterator=0;Local_u8Iterator<LED_NUM;Local_u8Iterator++)
		{
			Local_u8ErrorState=DIO_EnuSetPinDirection(Copy_pstrLedConfig[Local_u8Iterator].LED_u8PortID,Copy_pstrLedConfig[Local_u8Iterator].LED_u8PinID,DIO_u8OUTPUT);
			if(Copy_pstrLedConfig[Local_u8Iterator].LED_u8Connection==LED_SINK)
			{
				if(Copy_pstrLedConfig[Local_u8Iterator].LED_u8InitState==LED_ON)
				{
					Local_u8ErrorState=DIO_EnuSetPinValue(Copy_pstrLedConfig[Local_u8Iterator].LED_u8PortID,Copy_pstrLedConfig[Local_u8Iterator].LED_u8PinID,DIO_u8LOW);
				}
				else if(Copy_pstrLedConfig[Local_u8Iterator].LED_u8InitState==LED_OFF)
				{
					Local_u8ErrorState=DIO_EnuSetPinValue(Copy_pstrLedConfig[Local_u8Iterator].LED_u8PortID,Copy_pstrLedConfig[Local_u8Iterator].LED_u8PinID,DIO_u8HIGH);
				}
				else
				{
					return ES_OUT_OF_RANGE;
				}
			}
			else if(Copy_pstrLedConfig[Local_u8Iterator].LED_u8Connection==LED_SOURCE)
			{
				if(Copy_pstrLedConfig[Local_u8Iterator].LED_u8InitState==LED_ON)
				{
					Local_u8ErrorState=DIO_EnuSetPinValue(Copy_pstrLedConfig[Local_u8Iterator].LED_u8PortID,Copy_pstrLedConfig[Local_u8Iterator].LED_u8PinID,DIO_u8HIGH);
				}
				else if(Copy_pstrLedConfig[Local_u8Iterator].LED_u8InitState==LED_OFF)
				{
					Local_u8ErrorState=DIO_EnuSetPinValue(Copy_pstrLedConfig[Local_u8Iterator].LED_u8PortID,Copy_pstrLedConfig[Local_u8Iterator].LED_u8PinID,DIO_u8LOW);
				}
				else
				{
					return ES_OUT_OF_RANGE;
				}
			}
			else
			{
				return ES_OUT_OF_RANGE;

			}

		}
	}
	else
	{
		Local_u8ErrorState=ES_PNULL;
	}


	return Local_u8ErrorState;
}

ES_t LED_enuTurnON(LED_t * Copy_pstrLedID)
{
	u8 Local_u8ErrorState=ES_NOK;
	if(Copy_pstrLedID!=NULL)
	{

		if(Copy_pstrLedID->LED_u8Connection==LED_SINK)
		{
			Local_u8ErrorState=DIO_EnuSetPinValue(Copy_pstrLedID->LED_u8PortID,Copy_pstrLedID->LED_u8PinID,DIO_u8LOW);
		}
		else if(Copy_pstrLedID->LED_u8Connection==LED_SOURCE)
		{
			Local_u8ErrorState=DIO_EnuSetPinValue(Copy_pstrLedID->LED_u8PortID,Copy_pstrLedID->LED_u8PinID,DIO_u8HIGH);
		}
		else
		{
			return ES_OUT_OF_RANGE;
		}
	}
	else
	{
		return ES_PNULL;
	}

	return Local_u8ErrorState;
}

ES_t LED_enuTurnOFF(LED_t * Copy_pstrLedID)
{
	u8 Local_u8ErrorState=ES_NOK;
	if(Copy_pstrLedID!=NULL)
	{

		if(Copy_pstrLedID->LED_u8Connection==LED_SINK)
		{
			Local_u8ErrorState=DIO_EnuSetPinValue(Copy_pstrLedID->LED_u8PortID,Copy_pstrLedID->LED_u8PinID,DIO_u8HIGH);
		}
		else if(Copy_pstrLedID->LED_u8Connection==LED_SOURCE)
		{
			Local_u8ErrorState=DIO_EnuSetPinValue(Copy_pstrLedID->LED_u8PortID,Copy_pstrLedID->LED_u8PinID,DIO_u8LOW);
		}
		else
		{
			return ES_OUT_OF_RANGE;
		}
	}
	else
	{
		return ES_PNULL;
	}

	return Local_u8ErrorState;
}
