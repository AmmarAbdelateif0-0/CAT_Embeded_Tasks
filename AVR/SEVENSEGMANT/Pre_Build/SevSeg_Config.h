/*
 * SevSeg_Config.h
 *
 *  Created on: Mar 9, 2024
 *      Author: aboam
 */

#ifndef SEVSEG_CONFIG_H_
#define SEVSEG_CONFIG_H_
/*You Must define Every Pin with (DIO_u8Pin(x))And Every Port With (DIO_u8PORT(Y) OR NOT_CONNECTED If Pin is float)*/
/* ( 0<=X<=7 ) &&  ( 'A'<=Y<='D' ) */
#define SEG_APin   			DIO_u8Pin0
#define SEG_APort			DIO_u8PORTA

#define SEG_BPin  	        DIO_u8Pin1
#define SEG_BPort           DIO_u8PORTA

#define SEG_CPin  	        DIO_u8Pin2
#define SEG_CPort           DIO_u8PORTA

#define SEG_DPin  	        DIO_u8Pin3
#define SEG_DPort           DIO_u8PORTA

#define SEG_EPin  	        DIO_u8Pin4
#define SEG_EPort           DIO_u8PORTA

#define SEG_FPin  	        DIO_u8Pin5
#define SEG_FPort           DIO_u8PORTA

#define SEG_GPin            DIO_u8Pin6
#define SEG_GPort           DIO_u8PORTA

#define SEG_DOT             NOT_CONNECTED
#define SEG_DOT_Port        NOT_CONNECTED

#define SEG_CMN 			NOT_CONNECTED
#define SEG_CMN_Port		NOT_CONNECTED

/*SEG_TYPE Is ( COMMAN_CATHODE | COMMAN_ANODE ) */
#define SEG_TYPE 			COMMAN_CATHODE

#endif /* SEVSEG_CONFIG_H_ */
