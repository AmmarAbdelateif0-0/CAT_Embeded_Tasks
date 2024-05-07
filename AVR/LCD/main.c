/*
 * main.c
 *
 *  Created on: Apr 16, 2024
 *      Author: aboam
 */

#include"STD_TYPES.h"
#include"DIO_ErrorState.h"
#include"DIO_Interface.h"
#include"Lcd_Config.h"
#include"Lcd_Interface.h"
#include<util/delay.h>

int main(void)
{
	u8 LCD_Arrchargen[]={  0x00,0x0F,0x08,0x08,0x1F,0x00,0x00,0x00,
						   0x00,0x00,0x0E,0x0A,0x1B,0x0A,0x0E,0x00,
						   0x10,0x10,0x10,0x10,0x1F,0x00,0x00,0x00,
						   0x00,0x01,0x01,0x03,0x06,0x0C,0x18,0x00};
	DIO_EnuInit();
	LCD_EnuInit();

	LCD_EnuSendCommand(0X40);
	for(u8 i=0;i<32;i++)
	{
		LCD_EnuDisplaychar(LCD_Arrchargen[i]);
	}
	LCD_EnuSendCommand(0X8f);
	LCD_EnuSendCommand(0X04);
	LCD_EnuDisplaychar(0);
	LCD_EnuDisplaychar(1);
	LCD_EnuDisplaychar(2);
	LCD_EnuDisplaychar(3);

	while(1);
	return 0;



}
