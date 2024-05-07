/*
 * PORT_Register.h
 *
 *  Created on: Apr 30, 2024
 *      Author: aboam
 */

#ifndef PORT_REGISTER_H_
#define PORT_REGISTER_H_



/*************     REGISTER A         *************/

#define PORTA (*((volatile u8*)0X3B))
#define DDRA  (*((volatile u8*)0X3A))
#define PINA  (*((volatile u8*)0X39))

/**************************************************/


/*************     REGISTER B         *************/

#define PORTB (*((volatile u8*)0X38))
#define DDRB  (*((volatile u8*)0X37))
#define PINB  (*((volatile u8*)0X36))

/**************************************************/


/*************     REGISTER C         *************/

#define PORTC (*((volatile u8*)0X35))
#define DDRC  (*((volatile u8*)0X34))
#define PINC  (*((volatile u8*)0X33))

/**************************************************/


/*************     REGISTER D         *************/

#define PORTD (*((volatile u8*)0X32))
#define DDRD  (*((volatile u8*)0X31))
#define PIND  (*((volatile u8*)0X30))


#endif /* PORT_REGISTER_H_ */
