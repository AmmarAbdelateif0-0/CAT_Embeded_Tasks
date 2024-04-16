/*
 * LED_Interface.h
 *
 *  Created on: Mar 8, 2024
 *      Author: aboam
 */

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_


ES_t LED_enuInit(LED_t * Copy_pstrLedConfig);


ES_t LED_enuTurnON(LED_t * Copy_pstrLedID);


ES_t LED_enuTurnOFF(LED_t * Copy_pstrLedID);


#endif /* LED_INTERFACE_H_ */
