/*
 * PORT_Config.h
 *
 *  Created on: Apr 30, 2024
 *      Author: aboam
 */

#ifndef PORT_CONFIG_H_
#define PORT_CONFIG_H_


/******* define pin As input | output *******/
/*********** PORTA_DIR *********/

#define PORTA_Pin0_Dir     OUTPUT
#define PORTA_Pin1_Dir     OUTPUT
#define PORTA_Pin2_Dir     OUTPUT
#define PORTA_Pin3_Dir     OUTPUT
#define PORTA_Pin4_Dir     OUTPUT
#define PORTA_Pin5_Dir     OUTPUT
#define PORTA_Pin6_Dir     OUTPUT
#define PORTA_Pin7_Dir     OUTPUT
/*********** PORTB_DIR *********/

#define PORTB_Pin0_Dir     OUTPUT
#define PORTB_Pin1_Dir		OUTPUT
#define PORTB_Pin2_Dir		OUTPUT
#define PORTB_Pin3_Dir     OUTPUT
#define PORTB_Pin4_Dir     OUTPUT
#define PORTB_Pin5_Dir     OUTPUT
#define PORTB_Pin6_Dir     OUTPUT
#define PORTB_Pin7_Dir     OUTPUT
/*********** PORTC_DIR *********/

#define PORTC_Pin0_Dir     INPUT
#define PORTC_Pin1_Dir     INPUT
#define PORTC_Pin2_Dir     INPUT
#define PORTC_Pin3_Dir     INPUT
#define PORTC_Pin4_Dir     INPUT
#define PORTC_Pin5_Dir     INPUT
#define PORTC_Pin6_Dir     INPUT
#define PORTC_Pin7_Dir     INPUT
/*********** PORTD_DIR *********/

#define PORTD_Pin0_Dir     INPUT
#define PORTD_Pin1_Dir     INPUT
#define PORTD_Pin2_Dir     INPUT
#define PORTD_Pin3_Dir     INPUT
#define PORTD_Pin4_Dir     INPUT
#define PORTD_Pin5_Dir     INPUT
#define PORTD_Pin6_Dir     INPUT
#define PORTD_Pin7_Dir     INPUT
/***********************************************/

/******* define pin As HIGH |  LOW | FLOAT | PULL_UP *******/

/*********** PORTA_VAL *********/

#define PORTA_Pin0_VAL     LOW
#define PORTA_Pin1_VAL     LOW
#define PORTA_Pin2_VAL     LOW
#define PORTA_Pin3_VAL     LOW
#define PORTA_Pin4_VAL     LOW
#define PORTA_Pin5_VAL     LOW
#define PORTA_Pin6_VAL     LOW
#define PORTA_Pin7_VAL     LOW
/*********** PORTB_VAL *********/

#define PORTB_Pin0_VAL     HIGH
#define PORTB_Pin1_VAL     HIGH
#define PORTB_Pin2_VAL     HIGH
#define PORTB_Pin3_VAL     HIGH
#define PORTB_Pin4_VAL     HIGH
#define PORTB_Pin5_VAL     HIGH
#define PORTB_Pin6_VAL     HIGH
#define PORTB_Pin7_VAL     HIGH
/*********** PORTC_VAL *********/

#define PORTC_Pin0_VAL     FLOAT
#define PORTC_Pin1_VAL     FLOAT
#define PORTC_Pin2_VAL     FLOAT
#define PORTC_Pin3_VAL     FLOAT
#define PORTC_Pin4_VAL     FLOAT
#define PORTC_Pin5_VAL     FLOAT
#define PORTC_Pin6_VAL     FLOAT
#define PORTC_Pin7_VAL     FLOAT
/*********** PORTD_VAL *********/

#define PORTD_Pin0_VAL     PULL_UP
#define PORTD_Pin1_VAL     PULL_UP
#define PORTD_Pin2_VAL     PULL_UP
#define PORTD_Pin3_VAL     PULL_UP
#define PORTD_Pin4_VAL     PULL_UP
#define PORTD_Pin5_VAL     PULL_UP
#define PORTD_Pin6_VAL     PULL_UP
#define PORTD_Pin7_VAL     PULL_UP


#endif /* PORT_CONFIG_H_ */
