/*
 * lcd_interface.h
 *
 *  Created on: Apr 16, 2024
 *      Author: aboam
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

ES_t LCD_EnuInit(void);

ES_t LCD_EnuDisplaychar(u8 Cpoy_u8Data);

ES_t LCD_EnuSendCommand(u8 Cpoy_u8Command);


#endif /* LCD_INTERFACE_H_ */
