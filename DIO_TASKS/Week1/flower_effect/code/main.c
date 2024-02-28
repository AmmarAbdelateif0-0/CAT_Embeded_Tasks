/*
 * main.c

 *
 *  Created on: Feb 21, 2024
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

/************************************/

void main(void)
{
	 DDRA=0XFF;
	 u8 R,L;
	 u8 counter;
	 while(1)
	 {
		 R=4 ;
		 L=3 ;
		 for(counter=0;counter<5;counter++)
		 {
			 SET_BIT(PORTA,R);
			 SET_BIT(PORTA,L);
			 _delay_ms(50);
			 R++;
			 L--;

		 }
		 R=7;
	     L=0;
		 for(counter=0;counter<5;counter++)
		 {

			 CLR_BIT(PORTA,R);
			 CLR_BIT(PORTA,L);
			 _delay_ms(50);
			 R--;
			 L++;

		 }
	 }
}
