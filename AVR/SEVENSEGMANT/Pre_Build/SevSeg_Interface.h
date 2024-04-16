/*
 * SevSeg_Interface.h
 *
 *  Created on: Mar 9, 2024
 *      Author: aboam
 */

#ifndef SEVSEG_INTERFACE_H_
#define SEVSEG_INTERFACE_H_

ES_t   SevenSegmant_enuInit(void);

ES_t   SevenSegmant_enuDisplayNum(u8 Copy_u8Num);
ES_t   SevenSegmant_enuClearDisplay(void);

ES_t   SevenSegmant_enuEnableCommon(void);
ES_t   SevenSegmant_enuDisableCommon(void);

ES_t   SevenSegmant_enuEnableDot(void);
ES_t   SevenSegmant_enuDisableDot(void);

#endif /* SEVSEG_INTERFACE_H_ */
