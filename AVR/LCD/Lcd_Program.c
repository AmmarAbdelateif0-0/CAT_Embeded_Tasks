/*
 * Lcd_Program.c
 *
 *  Created on: Apr 16, 2024
 *      Author: aboam
 */
#include "STD_TYPES.h"
#include "DIO_ErrorState.h"

#include "DIO_Interface.h"

#include "Lcd_Config.h"
#include "Lcd_Private.h"


#include"util/delay.h"


ES_t LCD_EnuInit(void)
{
	u8 Local_u8ErrorState= ES_NOK;
	_delay_ms(35);

	DIO_EnuSetPinDirection(RS_PORT,RS_PIN,DIO_u8OUTPUT);
	DIO_EnuSetPinDirection(RW_PORT,RW_PIN,DIO_u8OUTPUT);
	DIO_EnuSetPinDirection(EN_PORT,EN_PIN,DIO_u8OUTPUT);

	DIO_EnuSetPinDirection(D7_PORT,D7_PIN,DIO_u8OUTPUT);
	DIO_EnuSetPinDirection(D6_PORT,D6_PIN,DIO_u8OUTPUT);
	DIO_EnuSetPinDirection(D5_PORT,D5_PIN,DIO_u8OUTPUT);
	DIO_EnuSetPinDirection(D4_PORT,D4_PIN,DIO_u8OUTPUT);
#if LCD_MODE == EIGHT_BIT
	DIO_EnuSetPinDirection(D3_PORT,D3_PIN,DIO_u8OUTPUT);
	DIO_EnuSetPinDirection(D2_PORT,D2_PIN,DIO_u8OUTPUT);
	DIO_EnuSetPinDirection(D1_PORT,D1_PIN,DIO_u8OUTPUT);
	DIO_EnuSetPinDirection(D0_PORT,D0_PIN,DIO_u8OUTPUT);

	LCD_invoidSendCommend(0X38);
#elif LCD_MODE == FOUR_BIT
	LCD_invoidSendCommend(0X28);

#else
#error "LCD_MODE out of range"
#endif
	_delay_ms(1);
	LCD_invoidSendCommend(0X0f);
	_delay_ms(1);
	LCD_invoidSendCommend(0X01);
	_delay_ms(2);
	LCD_invoidSendCommend(0X06 );

	return Local_u8ErrorState;
}

ES_t LCD_EnuDisplaychar(u8 Cpoy_u8Data)
{
	u8 Local_u8ErrorState= ES_NOK;


	// set RS as Data
	DIO_EnuSetPinValue(RS_PORT , RS_PIN , DIO_u8HIGH);

	LCD_invoidLactch(Cpoy_u8Data);

	return Local_u8ErrorState;
}


ES_t LCD_EnuSendCommand(u8 Cpoy_u8Command)
{
	u8 Local_u8ErrorState= ES_NOK;
	// set RS as command
	DIO_EnuSetPinValue(RS_PORT , RS_PIN , DIO_u8LOW);

	LCD_invoidLactch(Cpoy_u8Command);

	return Local_u8ErrorState;
}
static void LCD_invoidLactch (u8 Cpoy_u8Data)
{
	// set r/w as write operation
		DIO_EnuSetPinValue(RW_PORT , RW_PIN , DIO_u8LOW);
		// set enable as low
		DIO_EnuSetPinValue(EN_PORT , EN_PIN , DIO_u8LOW);

		// Write Data
		DIO_EnuSetPinValue(D7_PORT,D7_PIN,((Cpoy_u8Data>>7)&1));
		DIO_EnuSetPinValue(D6_PORT,D6_PIN,((Cpoy_u8Data>>6)&1));
		DIO_EnuSetPinValue(D5_PORT,D5_PIN,((Cpoy_u8Data>>5)&1));
		DIO_EnuSetPinValue(D4_PORT,D4_PIN,((Cpoy_u8Data>>4)&1));
#if     LCD_MODE == EIGHT_BIT

		DIO_EnuSetPinValue(D3_PORT,D3_PIN,((Cpoy_u8Data>>3)&1));
		DIO_EnuSetPinValue(D2_PORT,D2_PIN,((Cpoy_u8Data>>2)&1));
		DIO_EnuSetPinValue(D1_PORT,D1_PIN,((Cpoy_u8Data>>1)&1));
		DIO_EnuSetPinValue(D0_PORT,D0_PIN,((Cpoy_u8Data>>0)&1));

#elif	LCD_MODE == FOUR_BIT

#endif
		// enable latch
		DIO_EnuSetPinValue(EN_PORT , EN_PIN , DIO_u8HIGH);
		_delay_ms(10);
		DIO_EnuSetPinValue(EN_PORT , EN_PIN , DIO_u8LOW);



}
static inline void LCD_invoidSendCommend(u8 Cpoy_u8Command)
{
	// set rs as command
	DIO_EnuSetPinValue(RS_PORT , RS_PIN , DIO_u8LOW);
	// set r/w as write operation
	DIO_EnuSetPinValue(RW_PORT , RW_PIN , DIO_u8LOW);
	// set enable as low
	DIO_EnuSetPinValue(EN_PORT , EN_PIN , DIO_u8LOW);

	// Write Data
	DIO_EnuSetPinValue(D7_PORT,D7_PIN,((Cpoy_u8Command>>7)&1));
	DIO_EnuSetPinValue(D6_PORT,D6_PIN,((Cpoy_u8Command>>6)&1));
	DIO_EnuSetPinValue(D5_PORT,D5_PIN,((Cpoy_u8Command>>5)&1));
	DIO_EnuSetPinValue(D4_PORT,D4_PIN,((Cpoy_u8Command>>4)&1));
	DIO_EnuSetPinValue(D3_PORT,D3_PIN,((Cpoy_u8Command>>3)&1));
	DIO_EnuSetPinValue(D2_PORT,D2_PIN,((Cpoy_u8Command>>2)&1));
	DIO_EnuSetPinValue(D1_PORT,D1_PIN,((Cpoy_u8Command>>1)&1));
	DIO_EnuSetPinValue(D0_PORT,D0_PIN,((Cpoy_u8Command>>0)&1));

	// enable latch
	DIO_EnuSetPinValue(EN_PORT , EN_PIN , DIO_u8HIGH);
	_delay_ms(10);
	DIO_EnuSetPinValue(EN_PORT , EN_PIN , DIO_u8LOW);

}
