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

#define PORTC (*((volatile u8*)0X35))
#define DDRC  (*((volatile u8*)0X34))
#define PINC  (*((volatile u8*)0X33))

#define PORTD (*((volatile u8*)0X32))
#define DDRD  (*((volatile u8*)0X31))
#define PIND  (*((volatile u8*)0X30))
/************************************/

void main(void)
{

	u8 sevsegchd[]={ 0X3F,0X06,0X5B,0X4F,0X66,0X6D,0X7D,0X07,0X7F,0X6F};
	u8 pinstate=0;

	DDRA=0;     //0b 0000 0000
	DDRB=0XFF;  //0b 1111 1111
	DDRC=0XFF;  //0b 1111 1111
	DDRD=0XFF;  //0b 1111 1111

	while(1)
	{
		pinstate=PINA;
		PORTB=sevsegchd[pinstate%10];
		pinstate/=10;
		PORTC=sevsegchd[pinstate%10];
		pinstate/=10;
		PORTD=sevsegchd[pinstate%10];
		_delay_ms(100);
	}
}
