/*
 * SevSeg_Config.h
 *
 *  Created on: Mar 9, 2024
 *      Author: aboam
 */

#ifndef SEVSEG_CONFIG_H_
#define SEVSEG_CONFIG_H_



#define SEG_NUMBER 2


typedef struct{
u8 SEG_APin;
u8 SEG_APort;

u8 SEG_BPin;
u8 SEG_BPort;

u8 SEG_CPin;
u8 SEG_CPort;

u8 SEG_DPin ;
u8 SEG_DPort ;

u8 SEG_EPin  ;
u8 SEG_EPort  ;

u8 SEG_FPin;
u8 SEG_FPort;

u8 SEG_GPin;
u8 SEG_GPort;

u8 SEG_DOT;
u8 SEG_DOT_Port;

u8 SEG_CMN 	;
u8 SEG_CMN_Port;

u8   SEG_TYPE ;
}SEVSEG_t;


#endif /* SEVSEG_CONFIG_H_ */
