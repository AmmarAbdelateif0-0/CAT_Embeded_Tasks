/*
 * Led_Config.h
 *
 *  Created on: Mar 8, 2024
 *      Author: aboam
 */

#ifndef LED_CONFIG_H_
#define LED_CONFIG_H_

#define LED_NUM     3

#define LED_SINK    0
#define LED_SOURCE  1

#define LED_ON       0
#define LED_OFF      1

typedef struct{
	u8 LED_u8PortID;
	u8 LED_u8PinID;
	u8 LED_u8Connection;
	u8 LED_u8InitState;
}LED_t ;

#endif /* LED_CONFIG_H_ */
