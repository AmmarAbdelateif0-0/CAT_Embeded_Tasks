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
    u8 counter1=0;
    u8 counter2=0;

	DDRA=0XFF;
	DDRB=0XFF;

	while(1)
	{
		PORTA=sevsegchd[counter1];
		PORTB=sevsegchd[counter2];
		_delay_ms(150);
		counter1++;
		if(counter1==10)
		{
			counter2++;
			counter1=0;
			if( counter2==10)
				counter2=0;
		}

	}
}
