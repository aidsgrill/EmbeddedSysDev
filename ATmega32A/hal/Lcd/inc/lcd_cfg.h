/*
 * lcd_cfg.h
 *
 *  Created on: Jan 11, 2019
 *      Author: Inspiron-15
 */

#ifndef LCD_CFG_H_
#define LCD_CFG_H_

#define F_CPU	12000000UL

#define LCD_8BIT_MODE	0

#define LCD_DATA_PORT	DIO_PortA
#define LCD_D7			DIO_Pin7
#define LCD_D6			DIO_Pin6
#define LCD_D5			DIO_Pin5
#define LCD_D4			DIO_Pin4

#if(LCD_8BIT_MODE == 1)
#define LCD_D3			DIO_Pin3
#define LCD_D2			DIO_Pin2
#define LCD_D1			DIO_Pin1
#define LCD_D0			DIO_Pin0
#endif

#define LCD_CTL_PORT	DIO_PortB
#define LCD_RS			DIO_Pin1
#define LCD_RW			DIO_Pin2
#define LCD_E			DIO_Pin3

#endif /* LCD_CFG_H_ */
