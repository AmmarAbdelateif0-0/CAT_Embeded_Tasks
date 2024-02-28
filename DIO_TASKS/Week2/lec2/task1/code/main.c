
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

	DDRA  = 0X06; // 0b 0000 0110
	PORTA = 0X05; // 0b 0000 0101

	while(1)
	{
		if(!(GET_BIT(PINA,0)))
		{
			CLR_BIT(PORTA,2);
			SET_BIT(PORTA,1);
			_delay_ms(50);
			while(!(GET_BIT(PINA,0)));
		}
		else
		{
			CLR_BIT(PORTA,1);
			SET_BIT(PORTA,2);
			_delay_ms(50);
		}
	}
}
