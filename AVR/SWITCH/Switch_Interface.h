/*
 * Switch_Interface.h
 *
 *  Created on: Mar 8, 2024
 *      Author: aboam
 */

#ifndef SWITCH_INTERFACE_H_
#define SWITCH_INTERFACE_H_

ES_t Switch_enuInit(SW_t * Copy_AstrSwitchs);

ES_t Switch_enuGetState(SW_t * Copy_AstrSwitchs,u8 * Copy_pu8StateValue);

#endif /* SWITCH_INTERFACE_H_ */
