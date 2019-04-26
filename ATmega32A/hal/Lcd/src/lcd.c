/*
 * lcd.c
 *
 *  Created on: Jan 11, 2019
 *      Author: Ahmed Hessien
 */

#include "lcd_cfg.h"
#include "lcd.h"
#include "atmega32a_dio.h"
#include <util/delay.h>


extern void LCD_vidInit(void)
{


	DIO_vidSetPortDirection(LCD_DATA_PORT, DIO_PortOutputDirection);

	DIO_vidSetPinDirection(LCD_CTL_PORT, LCD_RS, DIO_PinOutputDirection);
	DIO_vidSetPinDirection(LCD_CTL_PORT, LCD_RW, DIO_PinOutputDirection);
	DIO_vidSetPinDirection(LCD_CTL_PORT, LCD_E, DIO_PinOutputDirection);


	DIO_vidWritePin(LCD_CTL_PORT, LCD_RS, PIN_LOW);
	DIO_vidWritePin(LCD_CTL_PORT, LCD_RW, PIN_LOW);
	DIO_vidWritePin(LCD_CTL_PORT, LCD_E, PIN_LOW);

	//wait 50 ms till LCD Vdd rises to 4.5v
	_delay_ms(70);

#if (LCD_8BIT_MODE == 1)


	//Function Set	(8-bit mode, 2 lines, 5x7 format)
	LCD_vidSendCommand(0x38);
	_delay_ms(1);

	//Display Control (cursor off, blinking off)
	LCD_vidSendCommand(0x0C);
	_delay_ms(1);

	//Clear Display
	LCD_vidSendCommand(0x01);
	_delay_ms(2);

	//Entry mode (no display shift, AC increase)
	LCD_vidSendCommand(0x06);
	_delay_ms(1);
#else

	DIO_vidWritePin(LCD_CTL_PORT, LCD_RS, PIN_LOW);
	DIO_vidWritePin(LCD_CTL_PORT, LCD_RW, PIN_LOW);
	DIO_vidWriteUpperNibble(LCD_DATA_PORT, 0x30);
	DIO_vidWritePin(LCD_CTL_PORT, LCD_E, PIN_HIGH);
	_delay_ms(1);
	DIO_vidWritePin(LCD_CTL_PORT, LCD_E, PIN_LOW);
	_delay_ms(8);


	DIO_vidWritePin(LCD_CTL_PORT, LCD_RS, PIN_LOW);
	DIO_vidWritePin(LCD_CTL_PORT, LCD_RW, PIN_LOW);
	DIO_vidWriteUpperNibble(LCD_DATA_PORT, 0x30);
	DIO_vidWritePin(LCD_CTL_PORT, LCD_E, PIN_HIGH);
	_delay_ms(1);
	DIO_vidWritePin(LCD_CTL_PORT, LCD_E, PIN_LOW);
	_delay_ms(2);

	DIO_vidWritePin(LCD_CTL_PORT, LCD_RS, PIN_LOW);
	DIO_vidWritePin(LCD_CTL_PORT, LCD_RW, PIN_LOW);
	DIO_vidWriteUpperNibble(LCD_DATA_PORT, 0x30);
	DIO_vidWritePin(LCD_CTL_PORT, LCD_E, PIN_HIGH);
	_delay_ms(1);
	DIO_vidWritePin(LCD_CTL_PORT, LCD_E, PIN_LOW);
	_delay_ms(2);


	DIO_vidWritePin(LCD_CTL_PORT, LCD_RS, PIN_LOW);
	DIO_vidWritePin(LCD_CTL_PORT, LCD_RW, PIN_LOW);
	DIO_vidWriteUpperNibble(LCD_DATA_PORT, 0x20);
	DIO_vidWritePin(LCD_CTL_PORT, LCD_E, PIN_HIGH);
	_delay_ms(1);
	DIO_vidWritePin(LCD_CTL_PORT, LCD_E, PIN_LOW);
	_delay_ms(2);

	LCD_vidSendCommand(0x28);
	LCD_vidSendCommand(LCD_DISPLAY_OFF);
	LCD_vidSendCommand(LCD_CLEAR_DISPLAY);
	LCD_vidSendCommand(0x06);
	LCD_vidSendCommand(LCD_DISPLAY_ON);

#endif
}


extern void LCD_vidSendCommand(uint8 Command)
{
	//select instruction register
	DIO_vidWritePin(LCD_CTL_PORT, LCD_RS, PIN_LOW);

	//write command
	DIO_vidWritePin(LCD_CTL_PORT, LCD_RW, PIN_LOW);
#if (LCD_8BIT_MODE == 1)
	DIO_vidWritePort(LCD_DATA_PORT, Command);

	DIO_vidWritePin(LCD_CTL_PORT, LCD_E, PIN_HIGH);
	_delay_ms(2);
	DIO_vidWritePin(LCD_CTL_PORT, LCD_E, PIN_LOW);
#else

	DIO_vidWriteUpperNibble(LCD_DATA_PORT, Command);
	DIO_vidWritePin(LCD_CTL_PORT, LCD_E, PIN_HIGH);
	_delay_ms(1);
	DIO_vidWritePin(LCD_CTL_PORT, LCD_E, PIN_LOW);
	DIO_vidWriteUpperNibble(LCD_DATA_PORT, (Command << 4));
	DIO_vidWritePin(LCD_CTL_PORT, LCD_E, PIN_HIGH);
	_delay_ms(1);
	DIO_vidWritePin(LCD_CTL_PORT, LCD_E, PIN_LOW);

#endif
}


extern void LCD_vidSendCharacter(char Character)
{
	//select data register
	DIO_vidWritePin(LCD_CTL_PORT, LCD_RS, PIN_HIGH);

	//write command
	DIO_vidWritePin(LCD_CTL_PORT, LCD_RW, PIN_LOW);

#if (LCD_8BIT_MODE == 1)
	DIO_vidWritePort(LCD_DATA_PORT, Character);

	DIO_vidWritePin(LCD_CTL_PORT, LCD_E, PIN_HIGH);
	_delay_ms(2);
	DIO_vidWritePin(LCD_CTL_PORT, LCD_E, PIN_LOW);

#else

	DIO_vidWriteUpperNibble(LCD_DATA_PORT, Character);
	DIO_vidWritePin(LCD_CTL_PORT, LCD_E, PIN_HIGH);
	_delay_ms(1);
	DIO_vidWritePin(LCD_CTL_PORT, LCD_E, PIN_LOW);
	DIO_vidWriteUpperNibble(LCD_DATA_PORT, (Character << 4));
	DIO_vidWritePin(LCD_CTL_PORT, LCD_E, PIN_HIGH);
	_delay_ms(1);
	DIO_vidWritePin(LCD_CTL_PORT, LCD_E, PIN_LOW);

#endif
}

extern void LCD_vidSendString(const char * pString)
{
	while(*pString != 0)
	{
		LCD_vidSendCharacter(*pString);
		pString++;
	}

}


extern void LCD_vidGoTo(uint8 x, uint8 y)
{

	if(0 == y)
	{
		if (x <=15)
		{
			LCD_vidSendCommand(0x80 + x);
		}
	}
	else if (1 == y)
	{
		if (x <=15)
		{
			LCD_vidSendCommand(0xC0 + x);
		}
	}
}


extern void LCD_vidWriteNewLine(const char* pString)
{
	LCD_vidClearDisplay();
	LCD_vidSendString(pString);
}

extern void LCD_vidReturnHome(void)
{
	LCD_vidSendCommand(LCD_RETURN_HOME);
}

extern void LCD_vidClearDisplay(void)
{
	LCD_vidSendCommand(LCD_CLEAR_DISPLAY);
}
