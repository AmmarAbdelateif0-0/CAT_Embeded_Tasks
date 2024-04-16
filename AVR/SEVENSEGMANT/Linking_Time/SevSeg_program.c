/*
 * SevSeg_program.c
 *
 *  Created on: Mar 16, 2024
 *      Author: aboam
 */
#include"DIO_ErrorState.h"
#include"STD_TYPES.h"
#include "DIO_Interface.h"
#include "SevSeg_Config.h"
#include "SevSeg_Priv.h"

extern SEVSEG_t SEVSEG_AstrConfig [SEG_NUMBER];

ES_t SevenSegmant_enuInit(SEVSEG_t *Copy_PstrSegConfig) {
	u8 local_u8ErrorState=ES_NOK;
	u8 Local_u8Iterator=0;
	if(Copy_PstrSegConfig !=NULL)
	{
		for(Local_u8Iterator=0 ;Local_u8Iterator<SEG_NUMBER;Local_u8Iterator++)
		{
			DIO_EnuSetPinDirection(Copy_PstrSegConfig[Local_u8Iterator].SEG_APort,Copy_PstrSegConfig[Local_u8Iterator].SEG_APin,DIO_u8OUTPUT);
			DIO_EnuSetPinDirection(Copy_PstrSegConfig[Local_u8Iterator].SEG_BPort,Copy_PstrSegConfig[Local_u8Iterator].SEG_BPin,DIO_u8OUTPUT);
			DIO_EnuSetPinDirection(Copy_PstrSegConfig[Local_u8Iterator].SEG_CPort,Copy_PstrSegConfig[Local_u8Iterator].SEG_CPin,DIO_u8OUTPUT);
			DIO_EnuSetPinDirection(Copy_PstrSegConfig[Local_u8Iterator].SEG_DPort,Copy_PstrSegConfig[Local_u8Iterator].SEG_DPin,DIO_u8OUTPUT);
			DIO_EnuSetPinDirection(Copy_PstrSegConfig[Local_u8Iterator].SEG_EPort,Copy_PstrSegConfig[Local_u8Iterator].SEG_EPin,DIO_u8OUTPUT);
			DIO_EnuSetPinDirection(Copy_PstrSegConfig[Local_u8Iterator].SEG_FPort,Copy_PstrSegConfig[Local_u8Iterator].SEG_FPin,DIO_u8OUTPUT);
			DIO_EnuSetPinDirection(Copy_PstrSegConfig[Local_u8Iterator].SEG_GPort,Copy_PstrSegConfig[Local_u8Iterator].SEG_GPin,DIO_u8OUTPUT);

			if( Copy_PstrSegConfig[Local_u8Iterator].SEG_CMN      !=NOT_CONNECTED
					&& Copy_PstrSegConfig[Local_u8Iterator].SEG_CMN_Port !=NOT_CONNECTED )
			{
				DIO_EnuSetPinDirection(Copy_PstrSegConfig[Local_u8Iterator].SEG_CMN_Port,Copy_PstrSegConfig[Local_u8Iterator].SEG_CMN,DIO_u8OUTPUT);
			}

			if( Copy_PstrSegConfig[Local_u8Iterator].SEG_DOT      !=NOT_CONNECTED
					&& Copy_PstrSegConfig[Local_u8Iterator].SEG_DOT_Port !=NOT_CONNECTED )
			{
				DIO_EnuSetPinDirection(Copy_PstrSegConfig[Local_u8Iterator].SEG_DOT_Port,Copy_PstrSegConfig[Local_u8Iterator].SEG_DOT,DIO_u8OUTPUT);
			}

		}
	}
	else
	{
		local_u8ErrorState=ES_PNULL;
	}
	return local_u8ErrorState;

}


ES_t SevenSegmant_enuDisplayNum(u8 Copy_u8SegID,u8 Copy_u8Num){
	u8 local_u8ErrorState=ES_NOK;

	if(Copy_u8SegID<SEG_NUMBER && Copy_u8Num<10)
	{
		if(SEVSEG_AstrConfig[Copy_u8SegID].SEG_TYPE==COMMAN_CATHODE)
		{
			DIO_EnuSetPinValue(SEVSEG_AstrConfig[Copy_u8SegID].SEG_APort,SEVSEG_AstrConfig[Copy_u8SegID].SEG_APin,( (SEG_Au8DisplayNum[Copy_u8Num]>>0 ) &1 ));
			DIO_EnuSetPinValue(SEVSEG_AstrConfig[Copy_u8SegID].SEG_BPort,SEVSEG_AstrConfig[Copy_u8SegID].SEG_BPin,( (SEG_Au8DisplayNum[Copy_u8Num]>>1 ) &1 ));
			DIO_EnuSetPinValue(SEVSEG_AstrConfig[Copy_u8SegID].SEG_CPort,SEVSEG_AstrConfig[Copy_u8SegID].SEG_CPin,( (SEG_Au8DisplayNum[Copy_u8Num]>>2 ) &1 ));
			DIO_EnuSetPinValue(SEVSEG_AstrConfig[Copy_u8SegID].SEG_DPort,SEVSEG_AstrConfig[Copy_u8SegID].SEG_DPin,( (SEG_Au8DisplayNum[Copy_u8Num]>>3 ) &1 ));
			DIO_EnuSetPinValue(SEVSEG_AstrConfig[Copy_u8SegID].SEG_EPort,SEVSEG_AstrConfig[Copy_u8SegID].SEG_EPin,( (SEG_Au8DisplayNum[Copy_u8Num]>>4 ) &1 ));
			DIO_EnuSetPinValue(SEVSEG_AstrConfig[Copy_u8SegID].SEG_FPort,SEVSEG_AstrConfig[Copy_u8SegID].SEG_FPin,( (SEG_Au8DisplayNum[Copy_u8Num]>>5 ) &1 ));
			DIO_EnuSetPinValue(SEVSEG_AstrConfig[Copy_u8SegID].SEG_GPort,SEVSEG_AstrConfig[Copy_u8SegID].SEG_GPin,( (SEG_Au8DisplayNum[Copy_u8Num]>>6 ) &1 ));


		}
		else if(SEVSEG_AstrConfig[Copy_u8SegID].SEG_TYPE==COMMAN_ANODE)
		{
			DIO_EnuSetPinValue(SEVSEG_AstrConfig[Copy_u8SegID].SEG_APort,SEVSEG_AstrConfig[Copy_u8SegID].SEG_APin, !( (SEG_Au8DisplayNum[Copy_u8Num]>>0 ) &1 ));
			DIO_EnuSetPinValue(SEVSEG_AstrConfig[Copy_u8SegID].SEG_BPort,SEVSEG_AstrConfig[Copy_u8SegID].SEG_BPin, !( (SEG_Au8DisplayNum[Copy_u8Num]>>1 ) &1 ));
			DIO_EnuSetPinValue(SEVSEG_AstrConfig[Copy_u8SegID].SEG_CPort,SEVSEG_AstrConfig[Copy_u8SegID].SEG_CPin, !( (SEG_Au8DisplayNum[Copy_u8Num]>>2 ) &1 ));
			DIO_EnuSetPinValue(SEVSEG_AstrConfig[Copy_u8SegID].SEG_DPort,SEVSEG_AstrConfig[Copy_u8SegID].SEG_DPin, !( (SEG_Au8DisplayNum[Copy_u8Num]>>3 ) &1 ));
			DIO_EnuSetPinValue(SEVSEG_AstrConfig[Copy_u8SegID].SEG_EPort,SEVSEG_AstrConfig[Copy_u8SegID].SEG_EPin, !( (SEG_Au8DisplayNum[Copy_u8Num]>>4 ) &1 ));
			DIO_EnuSetPinValue(SEVSEG_AstrConfig[Copy_u8SegID].SEG_FPort,SEVSEG_AstrConfig[Copy_u8SegID].SEG_FPin, !( (SEG_Au8DisplayNum[Copy_u8Num]>>5 ) &1 ));
			DIO_EnuSetPinValue(SEVSEG_AstrConfig[Copy_u8SegID].SEG_GPort,SEVSEG_AstrConfig[Copy_u8SegID].SEG_GPin, !( (SEG_Au8DisplayNum[Copy_u8Num]>>6 ) &1 ));

		}
		else
		{
			local_u8ErrorState=ES_OUT_OF_RANGE;
		}
	}
	else
	{
		local_u8ErrorState=ES_OUT_OF_RANGE;
	}


	return local_u8ErrorState;
}

ES_t SevenSegmant_enuClearDisplay(u8 Copy_u8SegID){
	u8 local_u8ErrorState=ES_NOK;

	if(Copy_u8SegID<SEG_NUMBER)
	{
		if(SEVSEG_AstrConfig[Copy_u8SegID].SEG_TYPE==COMMAN_CATHODE)
		{
			DIO_EnuSetPinValue(SEVSEG_AstrConfig[Copy_u8SegID].SEG_APort,SEVSEG_AstrConfig[Copy_u8SegID].SEG_APin,DIO_u8LOW);
			DIO_EnuSetPinValue(SEVSEG_AstrConfig[Copy_u8SegID].SEG_BPort,SEVSEG_AstrConfig[Copy_u8SegID].SEG_BPin,DIO_u8LOW);
			DIO_EnuSetPinValue(SEVSEG_AstrConfig[Copy_u8SegID].SEG_CPort,SEVSEG_AstrConfig[Copy_u8SegID].SEG_CPin,DIO_u8LOW);
			DIO_EnuSetPinValue(SEVSEG_AstrConfig[Copy_u8SegID].SEG_DPort,SEVSEG_AstrConfig[Copy_u8SegID].SEG_DPin,DIO_u8LOW);
			DIO_EnuSetPinValue(SEVSEG_AstrConfig[Copy_u8SegID].SEG_EPort,SEVSEG_AstrConfig[Copy_u8SegID].SEG_EPin,DIO_u8LOW);
			DIO_EnuSetPinValue(SEVSEG_AstrConfig[Copy_u8SegID].SEG_FPort,SEVSEG_AstrConfig[Copy_u8SegID].SEG_FPin,DIO_u8LOW);
			DIO_EnuSetPinValue(SEVSEG_AstrConfig[Copy_u8SegID].SEG_GPort,SEVSEG_AstrConfig[Copy_u8SegID].SEG_GPin,DIO_u8LOW);

			if( SEVSEG_AstrConfig[Copy_u8SegID].SEG_CMN      !=NOT_CONNECTED
					&& SEVSEG_AstrConfig[Copy_u8SegID].SEG_CMN_Port !=NOT_CONNECTED )
			{
				DIO_EnuSetPinDirection(SEVSEG_AstrConfig[Copy_u8SegID].SEG_CMN_Port,SEVSEG_AstrConfig[Copy_u8SegID].SEG_CMN,DIO_u8LOW);
			}

			if( SEVSEG_AstrConfig[Copy_u8SegID].SEG_DOT      !=NOT_CONNECTED
					&& SEVSEG_AstrConfig[Copy_u8SegID].SEG_DOT_Port !=NOT_CONNECTED )
			{
				DIO_EnuSetPinDirection(SEVSEG_AstrConfig[Copy_u8SegID].SEG_DOT_Port,SEVSEG_AstrConfig[Copy_u8SegID].SEG_DOT,DIO_u8LOW);
			}

		}
		else if(SEVSEG_AstrConfig[Copy_u8SegID].SEG_TYPE==COMMAN_ANODE)
		{
			DIO_EnuSetPinValue(SEVSEG_AstrConfig[Copy_u8SegID].SEG_APort,SEVSEG_AstrConfig[Copy_u8SegID].SEG_APin, DIO_u8HIGH);
			DIO_EnuSetPinValue(SEVSEG_AstrConfig[Copy_u8SegID].SEG_BPort,SEVSEG_AstrConfig[Copy_u8SegID].SEG_BPin, DIO_u8HIGH);
			DIO_EnuSetPinValue(SEVSEG_AstrConfig[Copy_u8SegID].SEG_CPort,SEVSEG_AstrConfig[Copy_u8SegID].SEG_CPin, DIO_u8HIGH);
			DIO_EnuSetPinValue(SEVSEG_AstrConfig[Copy_u8SegID].SEG_DPort,SEVSEG_AstrConfig[Copy_u8SegID].SEG_DPin, DIO_u8HIGH);
			DIO_EnuSetPinValue(SEVSEG_AstrConfig[Copy_u8SegID].SEG_EPort,SEVSEG_AstrConfig[Copy_u8SegID].SEG_EPin, DIO_u8HIGH);
			DIO_EnuSetPinValue(SEVSEG_AstrConfig[Copy_u8SegID].SEG_FPort,SEVSEG_AstrConfig[Copy_u8SegID].SEG_FPin, DIO_u8HIGH);
			DIO_EnuSetPinValue(SEVSEG_AstrConfig[Copy_u8SegID].SEG_GPort,SEVSEG_AstrConfig[Copy_u8SegID].SEG_GPin, DIO_u8HIGH);

			if( SEVSEG_AstrConfig[Copy_u8SegID].SEG_CMN      !=NOT_CONNECTED
					&& SEVSEG_AstrConfig[Copy_u8SegID].SEG_CMN_Port !=NOT_CONNECTED )
			{
				DIO_EnuSetPinDirection(SEVSEG_AstrConfig[Copy_u8SegID].SEG_CMN_Port,SEVSEG_AstrConfig[Copy_u8SegID].SEG_CMN,DIO_u8HIGH);
			}

			if( SEVSEG_AstrConfig[Copy_u8SegID].SEG_DOT      !=NOT_CONNECTED
					&& SEVSEG_AstrConfig[Copy_u8SegID].SEG_DOT_Port !=NOT_CONNECTED )
			{
				DIO_EnuSetPinDirection(SEVSEG_AstrConfig[Copy_u8SegID].SEG_DOT_Port,SEVSEG_AstrConfig[Copy_u8SegID].SEG_DOT,DIO_u8HIGH);
			}

		}
		else
		{
			local_u8ErrorState=ES_OUT_OF_RANGE;
		}
	}
	else
	{
		local_u8ErrorState=ES_OUT_OF_RANGE;
	}
	return local_u8ErrorState;

}

ES_t SevenSegmant_enuEnableCommon(u8 Copy_u8SegID){

	u8 local_u8ErrorState=ES_NOK;

	if(Copy_u8SegID<SEG_NUMBER)
	{
		if( SEVSEG_AstrConfig[Copy_u8SegID].SEG_CMN      !=NOT_CONNECTED
				&& SEVSEG_AstrConfig[Copy_u8SegID].SEG_CMN_Port !=NOT_CONNECTED )
		{
			if(SEVSEG_AstrConfig[Copy_u8SegID].SEG_TYPE==COMMAN_CATHODE)
			{
				DIO_EnuSetPinDirection(SEVSEG_AstrConfig[Copy_u8SegID].SEG_CMN_Port,SEVSEG_AstrConfig[Copy_u8SegID].SEG_CMN,DIO_u8HIGH);
			}
			else if(SEVSEG_AstrConfig[Copy_u8SegID].SEG_TYPE==COMMAN_ANODE)
			{
				DIO_EnuSetPinDirection(SEVSEG_AstrConfig[Copy_u8SegID].SEG_CMN_Port,SEVSEG_AstrConfig[Copy_u8SegID].SEG_CMN,DIO_u8LOW);
			}
		}

	}



	return local_u8ErrorState;
}
ES_t SevenSegmant_enuDisableCommon(u8 Copy_u8SegID){
	u8 local_u8ErrorState=ES_NOK;
	if( Copy_u8SegID<SEG_NUMBER )
	{
		if( SEVSEG_AstrConfig[Copy_u8SegID].SEG_CMN      !=NOT_CONNECTED
				&& SEVSEG_AstrConfig[Copy_u8SegID].SEG_CMN_Port !=NOT_CONNECTED )
		{
			if(SEVSEG_AstrConfig[Copy_u8SegID].SEG_TYPE==COMMAN_CATHODE)
			{
				DIO_EnuSetPinDirection(SEVSEG_AstrConfig[Copy_u8SegID].SEG_CMN_Port,SEVSEG_AstrConfig[Copy_u8SegID].SEG_CMN,DIO_u8LOW);
			}
			else if(SEVSEG_AstrConfig[Copy_u8SegID].SEG_TYPE==COMMAN_ANODE)
			{
				DIO_EnuSetPinDirection(SEVSEG_AstrConfig[Copy_u8SegID].SEG_CMN_Port,SEVSEG_AstrConfig[Copy_u8SegID].SEG_CMN,DIO_u8HIGH);
			}
		}

	}

	return local_u8ErrorState;
}


ES_t SevenSegmant_enuEnableDot(u8 Copy_u8SegID){
	u8 local_u8ErrorState=ES_NOK;
	if(Copy_u8SegID<SEG_NUMBER)
	{
		if( SEVSEG_AstrConfig[Copy_u8SegID].SEG_DOT      !=NOT_CONNECTED
				&& SEVSEG_AstrConfig[Copy_u8SegID].SEG_DOT_Port !=NOT_CONNECTED )
		{
			if(SEVSEG_AstrConfig[Copy_u8SegID].SEG_TYPE==COMMAN_CATHODE)
			{
				DIO_EnuSetPinDirection(SEVSEG_AstrConfig[Copy_u8SegID].SEG_DOT_Port,SEVSEG_AstrConfig[Copy_u8SegID].SEG_DOT,DIO_u8HIGH);
			}
			else if(SEVSEG_AstrConfig[Copy_u8SegID].SEG_TYPE==COMMAN_ANODE)
			{
				DIO_EnuSetPinDirection(SEVSEG_AstrConfig[Copy_u8SegID].SEG_DOT_Port,SEVSEG_AstrConfig[Copy_u8SegID].SEG_DOT,DIO_u8LOW);
			}
		}

	}


	return local_u8ErrorState;
}

ES_t SevenSegmant_enuDisableDot(u8 Copy_u8SegID){
	u8 local_u8ErrorState=ES_NOK;
	if(Copy_u8SegID<SEG_NUMBER)
	{
		if( SEVSEG_AstrConfig[Copy_u8SegID].SEG_DOT      !=NOT_CONNECTED
				&& SEVSEG_AstrConfig[Copy_u8SegID].SEG_DOT_Port !=NOT_CONNECTED )
		{
			if(SEVSEG_AstrConfig[Copy_u8SegID].SEG_TYPE==COMMAN_CATHODE)
			{
				DIO_EnuSetPinDirection(SEVSEG_AstrConfig[Copy_u8SegID].SEG_DOT_Port,SEVSEG_AstrConfig[Copy_u8SegID].SEG_DOT,DIO_u8LOW);
			}
			else if(SEVSEG_AstrConfig[Copy_u8SegID].SEG_TYPE==COMMAN_ANODE)
			{
				DIO_EnuSetPinDirection(SEVSEG_AstrConfig[Copy_u8SegID].SEG_DOT_Port,SEVSEG_AstrConfig[Copy_u8SegID].SEG_DOT,DIO_u8HIGH);
			}
		}
	}
	return local_u8ErrorState;
}

