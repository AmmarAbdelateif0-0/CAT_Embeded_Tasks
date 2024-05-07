/*
 * main.c
 *
 *  Created on: May 1, 2024
 *      Author: aboam
 */

#include "STD_TYPES.h"

#include"DIO_ErrorState.h"
#include "DIO_Interface.h"
#include"Keypad_Interface.h"

#include "CLCD_Interface.h"

void main(void){

	u8 Local_u8Key=0xff;

	DIO_EnuInit();
	CLCD_EnuInit();

	s32 Local_u8Operand=0;

	u8 Local_u8Operation;

	u8 Local_u8Counter=1;

	u8 i=0;
	s32 result=0;
	s32 OPER1;
3211+1
	while(1){
		do{

			Local_u8Key=KPD_u8GetPressedKey();


		}while(Local_u8Key==0XFF);

		if(i==1)
		{
			CLCD_EnuClearDisplay();
			i=0;
		}
		if( ( (Local_u8Key+'0')>='0' ) && ( (Local_u8Key+'0')<='9') )
		{
			if(Local_u8Counter!=1) {
				Local_u8Operand *= Local_u8Counter;
			}
			Local_u8Operand+=(Local_u8Key-'0');
			Local_u8Counter=10;
			CLCD_EnuSendData(Local_u8Key+'0');
		}
		else if(( Local_u8Key=='o' ))
		{
			CLCD_EnuClearDisplay();
			Local_u8Counter=1;
			result=0;
			Local_u8Operand=0;
		}

		else if(( Local_u8Key=='=' )){
			CLCD_EnuGoToXY(1,0);
			switch(Local_u8Operation){
			case '+':
				result=OPER1+Local_u8Operand;
				break;
			case '-':
				result=OPER1-Local_u8Operand;
				break;
			case '*':
				result=OPER1*Local_u8Operand;
				break;
			case '/':
				result=OPER1/Local_u8Operand;
				break;
			default:
				result=Local_u8Operand;
				break;
			}
			CLCD_EnuWriteNumber(result);
			i=1;

		}
		else
		{
			Local_u8Operation=Local_u8Key;
			OPER1=Local_u8Operand;
			Local_u8Counter=1;
			Local_u8Operand=0;
			CLCD_EnuSendData(Local_u8Key);

		}

	}

}
