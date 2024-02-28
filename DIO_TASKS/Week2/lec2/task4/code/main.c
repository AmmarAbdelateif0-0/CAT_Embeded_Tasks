/*
 * main.c
 *
 *  Created on: Feb 28, 2024
 *      Author: aboam
 */


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

	u8 sevsegchd[]={ 0X3F,0X06,0X5B,0X4F,0X66,0X6D,0X7D,0X07,0X7F,0X6F};
	u8 counter=0;

	DDRA=0XFF;  //0b 1111 1111
	DDRB=0X03;  //0b 0000 0011
	PORTB=0X03; //0b 0000 0011
	PORTA=sevsegchd[counter%10];
	while(1)
	{
		SET_BIT(PORTB,1); //disable b1
		PORTA=sevsegchd[counter%10];
		CLR_BIT(PORTB,0); //enable b0
		counter++;
		_delay_ms(8);

		SET_BIT(PORTB,0); //disable b0
		PORTA=sevsegchd[counter/10];
		CLR_BIT(PORTB,1); //enable b1
		_delay_ms(8);

		if(counter>99)
		{
			counter=0;
		}

	}
}
