/*
 * lcd.h
 *
 *  Created on: Jan 11, 2019
 *      Author: Inspiron-15
 */

#ifndef LCD_H_
#define LCD_H_

#include "std_types.h"


#define LCD_CLEAR_DISPLAY       0x01
#define LCD_RETURN_HOME         0x02
#define LCD_DISPLAY_ON          0x0C
#define LCD_DISPLAY_OFF         0x08
#define LCD_CURSOR_SHIFT_LEFT   0x10
#define LCD_CURSOR_SHIFT_RIGHT  0x14

extern void LCD_vidInit(void);

extern void LCD_vidSendCommand(uint8 Command);

extern void LCD_vidSendCharacter(char Character);

extern void LCD_vidSendString(const char* pString);

extern void LCD_vidGoTo(uint8 x, uint8 y);

extern void LCD_vidReturnHome(void);

extern void LCD_vidClearDisplay(void);

extern void LCD_vidWriteNewLine(const char* pString);

#endif /* LCD_H_ */
