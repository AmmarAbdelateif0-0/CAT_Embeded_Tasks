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
void main(void)
{
	 DDRA=0XFF;
	 u8 counter =0;
	 while(1)
	 {
		 SET_BIT(PORTA,counter);
		 counter++;
		 _delay_ms(200);
		 if(counter==8)
		 {
			 counter=0;
			 while(counter!=8)
			 {
				 CLR_BIT(PORTA,counter);
				 counter++;
				 _delay_ms(200);
			 }
			 counter=0;
		 }
	 }

}

