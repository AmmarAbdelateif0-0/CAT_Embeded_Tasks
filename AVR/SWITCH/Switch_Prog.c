/*
 * Switch_Prog.c
 *
 *  Created on: Mar 8, 2024
 *      Author: aboam
 */
#include"STD_TYPES.h"
#include"DIO_ErrorState.h"

#include"Switch_Priv.h"
#include"Switch_Config.h"

#include"DIO_Interface.h"


ES_t Switch_enuInit(SW_t * Copy_AstrSwitchs){
	u8 Local_u8ErrorStatus=ES_NOK;


	if(Copy_AstrSwitchs!=NULL)
	{
		u8 Local_u8Iterator=0;
		for(Local_u8Iterator=0; Local_u8Iterator<SW_NUM; Local_u8Iterator++)
		{
			//DDR(SW_PinID)->PIN(SW_PinID)->DIO_u8INPUT
			Local_u8ErrorStatus=DIO_EnuSetPinDirection(Copy_AstrSwitchs[Local_u8Iterator].SW_PortID,Copy_AstrSwitchs[Local_u8Iterator].SW_PinID,DIO_u8INPUT);

			//PORT(SW_PinID)->PIN(SW_PinID)->SW_Status
			Local_u8ErrorStatus=DIO_EnuSetPinValue(Copy_AstrSwitchs[Local_u8Iterator].SW_PortID,Copy_AstrSwitchs[Local_u8Iterator].SW_PinID,Copy_AstrSwitchs[Local_u8Iterator].SW_Status);
		}
	}

	else
	{
		Local_u8ErrorStatus=ES_PNULL;
	}
		return Local_u8ErrorStatus;
}

ES_t Switch_enuGetState(SW_t * Copy_AstrSwitchs,u8 * Copy_pu8SwState){
	u8 Local_u8ErrorStatus=ES_NOK;

	if( (Copy_AstrSwitchs!=NULL) && (Copy_pu8SwState!=NULL) )
	{
			Local_u8ErrorStatus = DIO_EnuGetPinValue(Copy_AstrSwitchs->SW_PortID , Copy_AstrSwitchs->SW_PinID , Copy_pu8SwState);
	}

	else
	{
		Local_u8ErrorStatus=ES_PNULL;
	}
	return Local_u8ErrorStatus;
}
