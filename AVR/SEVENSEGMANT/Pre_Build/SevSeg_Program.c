/*
 * SevSeg_Program.c
 *
 *  Created on: Mar 9, 2024
 *      Author: aboam
 */
#include"STD_TYPES.h"
#include"DIO_ErrorState.h"
#include "DIO_Interface.h"
#include "SevSeg_Priv.h"
#include "SevSeg_Config.h"




ES_t   SevenSegmant_enuInit(void){
	u8  Local_u8ErrorState=ES_NOK;
	u32 Local_u32Check=0;

	/*************************************************************************************/

	Local_u32Check  =(DIO_EnuSetPinDirection(SEG_APort,SEG_APin,DIO_u8OUTPUT));
	Local_u32Check |=( DIO_EnuSetPinDirection(SEG_BPort,SEG_BPin,DIO_u8OUTPUT) << 3  );
	Local_u32Check |=( DIO_EnuSetPinDirection(SEG_CPort,SEG_CPin,DIO_u8OUTPUT) << 6  );
	Local_u32Check |=( DIO_EnuSetPinDirection(SEG_DPort,SEG_DPin,DIO_u8OUTPUT) << 9  );
	Local_u32Check |=( DIO_EnuSetPinDirection(SEG_EPort,SEG_EPin,DIO_u8OUTPUT) << 12 );
	Local_u32Check |=( DIO_EnuSetPinDirection(SEG_FPort,SEG_FPin,DIO_u8OUTPUT) << 15 );
	( DIO_EnuSetPinDirection(SEG_GPort,SEG_GPin,DIO_u8OUTPUT)  );

	/*************************************************************************************/


#if   SEG_CMN<=DIO_u8Pin7 && SEG_CMN_Port<=DIO_u8PORTD
	Local_u8ErrorState=(DIO_EnuSetPinDirection(SEG_CMN_Port , SEG_CMN, DIO_u8OUTPUT));
#elif SEG_CMN==NOT_CONNECTED || SEG_CMN_Port==NOT_CONNECTED
#else
#error "OUT_OF_RANGE"
#endif

	/*************************************************************************************/

#if   SEG_DOT<=DIO_u8Pin7 && SEG_DOT_Port<=DIO_u8PORTD
	Local_u8ErrorState=(DIO_EnuSetPinDirection(SEG_DOT_Port, SEG_DOT,DIO_u8OUTPUT));
#elif SEG_DOT==NOT_CONNECTED || SEG_DOT_Port==NOT_CONNECTED
#else
#error "OUT_OF_RANGE"
#endif

	/*************************************************************************************/

	u8 Local_u8Iter=0;

	for(Local_u8Iter=0;(Local_u8Iter<( sizeof(Local_u32Check) * 8 )-8 ) ;Local_u8Iter+=3)
	{
		if( ( ( Local_u32Check >> Local_u8Iter ) & 7) != ES_OK )
		{
			Local_u8ErrorState=( ( Local_u32Check >> Local_u8Iter ) & 7);
			return Local_u8ErrorState;
		}
	}
	return Local_u8ErrorState;
}

ES_t   SevenSegmant_enuDisplayNum(u8 Copy_u8Num){

	u8 Local_u8ErrorState=ES_NOK;
	u32 Local_u32Check=0;


	/*************************************************************************************/
	if(Copy_u8Num<10)
	{
#if SEG_TYPE == COMMAN_CATHODE
		Local_u32Check|=(DIO_EnuSetPinValue(SEG_APort , SEG_APin , ((SEG_Au8DisplayNum[Copy_u8Num]>>0) & 1 ))<< 0 );
		Local_u32Check|=(DIO_EnuSetPinValue(SEG_BPort , SEG_BPin , ((SEG_Au8DisplayNum[Copy_u8Num]>>1) & 1 ))<< 3 );
		Local_u32Check|=(DIO_EnuSetPinValue(SEG_CPort , SEG_CPin , ((SEG_Au8DisplayNum[Copy_u8Num]>>2) & 1 ))<< 6 );
		Local_u32Check|=(DIO_EnuSetPinValue(SEG_DPort , SEG_DPin , ((SEG_Au8DisplayNum[Copy_u8Num]>>3) & 1 ))<< 9 );
		Local_u32Check|=(DIO_EnuSetPinValue(SEG_EPort , SEG_EPin , ((SEG_Au8DisplayNum[Copy_u8Num]>>4) & 1 ))<< 12);
		Local_u32Check|=(DIO_EnuSetPinValue(SEG_FPort , SEG_FPin , ((SEG_Au8DisplayNum[Copy_u8Num]>>5) & 1 ))<< 15);
		(DIO_EnuSetPinValue(SEG_GPort , SEG_GPin , ((SEG_Au8DisplayNum[Copy_u8Num]>>6) & 1 )));
#elif SEG_TYPE == COMMAN_ANODE
		Local_u32Check|=(DIO_EnuSetPinValue(SEG_APort , SEG_APin ,!((SEG_Au8DisplayNum[Copy_u8Num]>>0) & 1 ))<< 0  );
		Local_u32Check|=(DIO_EnuSetPinValue(SEG_BPort , SEG_BPin ,!((SEG_Au8DisplayNum[Copy_u8Num]>>1) & 1 ))<< 3  );
		Local_u32Check|=(DIO_EnuSetPinValue(SEG_CPort , SEG_CPin ,!((SEG_Au8DisplayNum[Copy_u8Num]>>2) & 1 ))<< 6  );
		Local_u32Check|=(DIO_EnuSetPinValue(SEG_DPort , SEG_DPin ,!((SEG_Au8DisplayNum[Copy_u8Num]>>3) & 1 ))<< 9  );
		Local_u32Check|=(DIO_EnuSetPinValue(SEG_EPort , SEG_EPin ,!((SEG_Au8DisplayNum[Copy_u8Num]>>4) & 1 ))<< 12 );
		Local_u32Check|=(DIO_EnuSetPinValue(SEG_FPort , SEG_FPin ,!((SEG_Au8DisplayNum[Copy_u8Num]>>5) & 1 ))<< 15 );
		(DIO_EnuSetPinValue(SEG_GPort , SEG_GPin ,!((SEG_Au8DisplayNum[Copy_u8Num]>>6) & 1 )) );
#else
#error "SEG Type has a Wrong Selection"
#endif
		Local_u8ErrorState=ES_OK;

	}
	else
	{
		Local_u8ErrorState=ES_OUT_OF_RANGE;
	}

	/*************************************************************************************/

	u8 Local_u8Iter=0;

	for(Local_u8Iter=0;(Local_u8Iter<( sizeof(Local_u32Check) * 8 )-8 ) ;Local_u8Iter+=3)
	{
		if( ( ( Local_u32Check >> Local_u8Iter ) & 7) != ES_OK )
		{
			Local_u8ErrorState=( ( Local_u32Check >> Local_u8Iter ) & 7);
			return Local_u8ErrorState;
		}
	}
	return Local_u8ErrorState;
}
ES_t   SevenSegmant_enuClearDisplay(void){
	u8 Local_u8ErrorState=ES_NOK;
	u32 Local_u32Check=0;

#if SEG_TYPE == COMMAN_CATHODE
	Local_u32Check|=(DIO_EnuSetPinValue(SEG_APort , SEG_APin , DIO_u8LOW)<< 0  );
	Local_u32Check|=(DIO_EnuSetPinValue(SEG_BPort , SEG_BPin , DIO_u8LOW)<< 3  );
	Local_u32Check|=(DIO_EnuSetPinValue(SEG_CPort , SEG_CPin , DIO_u8LOW)<< 6  );
	Local_u32Check|=(DIO_EnuSetPinValue(SEG_DPort , SEG_DPin , DIO_u8LOW)<< 9  );
	Local_u32Check|=(DIO_EnuSetPinValue(SEG_EPort , SEG_EPin , DIO_u8LOW)<< 12 );
	Local_u32Check|=(DIO_EnuSetPinValue(SEG_FPort , SEG_FPin , DIO_u8LOW)<< 15 );
	(DIO_EnuSetPinValue(SEG_GPort , SEG_GPin , DIO_u8LOW));
#elif SEG_TYPE == COMMAN_ANODE
	Local_u32Check|(DIO_EnuGetPinValue(SEG_APort,SEG_APin,DIO_u8HIGH)<< 0   );
	Local_u32Check|(DIO_EnuGetPinValue(SEG_APort,SEG_APin,DIO_u8HIGH)<< 3   );
	Local_u32Check|(DIO_EnuGetPinValue(SEG_APort,SEG_APin,DIO_u8HIGH)<< 6   );
	Local_u32Check|(DIO_EnuGetPinValue(SEG_APort,SEG_APin,DIO_u8HIGH)<< 9   );
	Local_u32Check|(DIO_EnuGetPinValue(SEG_APort,SEG_APin,DIO_u8HIGH)<< 12  );
	Local_u32Check|(DIO_EnuGetPinValue(SEG_APort,SEG_APin,DIO_u8HIGH)<< 15  );
	(DIO_EnuGetPinValue(SEG_APort,SEG_APin,DIO_u8HIGH) );
#else
#error "SEG Type has a Wrong Selection"
#endif

	/*************************************************************************************/

		u8 Local_u8Iter=0;

	for(Local_u8Iter=0;(Local_u8Iter<( sizeof(Local_u32Check) * 8 )-8) ;Local_u8Iter+=3)
	{
		if( ( ( Local_u32Check >> Local_u8Iter ) & 7) != ES_OK )
		{
			Local_u8ErrorState=( ( Local_u32Check >> Local_u8Iter ) & 7);
			return Local_u8ErrorState;
		}
	}
	return Local_u8ErrorState;


}

ES_t   SevenSegmant_enuEnableCommon(void){
	u8 Local_u8ErrorState=ES_NOK;
#if   SEG_CMN<=DIO_u8Pin7 && SEG_CMN_Port<=DIO_u8PORTD
#if SEG_TYPE==COMMAN_CATHODE
	Local_u8ErrorState=(DIO_EnuSetPinDirection(SEG_CMN_Port , SEG_CMN, DIO_u8HIGH));
#elif SEG_TYPE==COMMAN_ANODE
	Local_u8ErrorState=(DIO_EnuSetPinDirection(SEG_CMN_Port , SEG_CMN, DIO_u8LOW));
#else
#error "SEG Type has a Wrong Selection"
#endif
#elif SEG_CMN==NOT_CONNECTED || SEG_CMN_Port==NOT_CONNECTED
#else
#error "Wrong value in SEG_CMN"
#endif


	return Local_u8ErrorState;
}
ES_t   SevenSegmant_enuDisableCommon(void){
	u8 Local_u8ErrorState=ES_NOK;
#if   SEG_CMN<=DIO_u8Pin7 && SEG_CMN_Port<=DIO_u8PORTD
#if SEG_TYPE==COMMAN_CATHODE
	Local_u8ErrorState=(DIO_EnuSetPinDirection(SEG_CMN_Port , SEG_CMN, DIO_u8LOW));
#elif SEG_TYPE==COMMAN_ANODE
	Local_u8ErrorState=(DIO_EnuSetPinDirection(SEG_CMN_Port , SEG_CMN, DIO_u8HIGH));
#else
#error "SEG Type has a Wrong Selection"
#endif
#elif SEG_CMN==NOT_CONNECTED || SEG_CMN_Port==NOT_CONNECTED
#else
#error "Wrong value in SEG_CMN"
#endif


	return Local_u8ErrorState;
}

ES_t   SevenSegmant_enuEnableDot(void){
	u8 Local_u8ErrorState=ES_NOK;
#if   SEG_DOT<=DIO_u8Pin7 && SEG_DOT_Port<=DIO_u8PORTD
#if SEG_TYPE==COMMAN_CATHODE
	Local_u8ErrorState=(DIO_EnuSetPinDirection(SEG_DOT_Port , SEG_DOT, DIO_u8HIGH));
#elif SEG_TYPE==COMMAN_ANODE
	Local_u8ErrorState=(DIO_EnuSetPinDirection(SEG_DOT_Port , SEG_DOT, DIO_u8LOW));
#else
#error "SEG Type has a Wrong Selection"
#endif
#elif SEG_DOT==NOT_CONNECTED || SEG_DOT_Port==NOT_CONNECTED
#else
#error "Wrong value in SEG_DOT"
#endif


	return Local_u8ErrorState;
}
ES_t   SevenSegmant_enuDisableDot(void){
	u8 Local_u8ErrorState=ES_NOK;
#if   SEG_DOT<=DIO_u8Pin7 && SEG_DOT_Port<=DIO_u8PORTD
#if SEG_TYPE==COMMAN_CATHODE
	Local_u8ErrorState=(DIO_EnuSetPinDirection(SEG_DOT_Port , SEG_DOT, DIO_u8LOW));
#elif SEG_TYPE==COMMAN_ANODE
	Local_u8ErrorState=(DIO_EnuSetPinDirection(SEG_DOT_Port , SEG_DOT, DIO_u8HIGH));
#else
#error "SEG Type has a Wrong Selection"
#endif
#elif SEG_DOT==NOT_CONNECTED || SEG_DOT_Port==NOT_CONNECTED
#else
#error "Wrong value in SEG_DOT"
#endif



	return Local_u8ErrorState;
}
