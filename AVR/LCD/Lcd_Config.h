/*
 * Lcd_Config.h
 *
 *  Created on: Apr 16, 2024
 *      Author: aboam
 */

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

/*				LCD_MODE					*/
#define LCD_MODE		EIGHT_BIT
/*				CONTROL_PINS				*/
#define RS_PORT	    DIO_u8PORTA
#define RS_PIN	    DIO_u8Pin0

#define RW_PORT	    DIO_u8PORTA
#define RW_PIN	    DIO_u8Pin1

#define EN_PORT	    DIO_u8PORTA
#define EN_PIN	    DIO_u8Pin2

/*				DATA_PINS					*/
#define D7_PORT	    DIO_u8PORTB
#define D7_PIN	    DIO_u8Pin0

#define D6_PORT	    DIO_u8PORTB
#define D6_PIN	    DIO_u8Pin1

#define D5_PORT	    DIO_u8PORTB
#define D5_PIN	    DIO_u8Pin2

#define D4_PORT		DIO_u8PORTB
#define D4_PIN		DIO_u8Pin3

#define D3_PORT		DIO_u8PORTB
#define D3_PIN		DIO_u8Pin4

#define D2_PORT		DIO_u8PORTB
#define D2_PIN	    DIO_u8Pin5

#define D1_PORT		DIO_u8PORTB
#define D1_PIN		DIO_u8Pin6

#define D0_PORT		DIO_u8PORTB
#define D0_PIN		DIO_u8Pin7



#endif /* LCD_CONFIG_H_ */
