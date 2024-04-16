/*
 * SevSeg_Interface.h
 *
 *  Created on: Mar 9, 2024
 *      Author: aboam
 */

#ifndef SEVSEG_INTERFACE_H_
#define SEVSEG_INTERFACE_H_

ES_t SevenSegmant_enuInit(SEVSEG_t *Copy_PstrSegConfig);

ES_t SevenSegmant_enuDisplayNum(u8 Copy_u8SegID,u8 Copy_u8Num);

ES_t SevenSegmant_enuClearDisplay(u8 Copy_u8SegID);

ES_t SevenSegmant_enuEnableCommon(u8 Copy_u8SegID);

ES_t SevenSegmant_enuDisableCommon(u8 Copy_u8SegID);


ES_t SevenSegmant_enuEnableDot(u8 Copy_u8SegID);

ES_t SevenSegmant_enuDisableDot(u8 Copy_u8SegID);

#endif /* SEVSEG_INTERFACE_H_ */
