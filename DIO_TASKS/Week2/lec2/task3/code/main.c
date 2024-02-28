/*
* main.c
*
*  Created on: Feb 28, 2024
*      Author: aboam
*/

/************************************/
#include<util/delay.h>
#include"STD_TYPES.h"
#include"BIT_MATH.h"

/************************************/

#define PORTA (*((volatile u8*)0X3B))
#define DDRA  (*((volatile u8*)0X3A))
#define PINA  (*((volatile u8*)0X39))

#define PORTB (*((volatile u8*)0X38))
#define DDRB  (*((volatile u8*)0X37))
#define PINB  (*((volatile u8*)0X36))
/************************************/

void main(void)
{

	u8 sevsegchd[]={ 0X3F,0X06,0X5B
					,0X4F,0X66,0X6D
					,0X7D,0X07,0X7F
					,0X6F};
	u8 counter=0,one=0,deci=0;
	DDRA  = 0X7f; // 0b 0000 0110
	DDRB  = 0X7F;
	PORTB = 0;
	PORTA = 0X80; // 0b 0000 0101
	PORTA= 0x80 | sevsegchd[one];
	PORTB=  sevsegchd[deci];
	while(1)
	{
		if(!(GET_BIT(PINA,7)))
		{
			counter++;
			one=counter%10;
			deci=counter/10;
			PORTA= 0x80 | sevsegchd[one];
			PORTB=  sevsegchd[deci];
			while(!(GET_BIT(PINA,7)));
		}
	}
}
