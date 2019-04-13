/*
 * led.h
 *
 *  Created on: Apr 13, 2019
 *      Author: Inspiron-15
 */

#ifndef LED_H_
#define LED_H_

typedef enum
{
	Led0 = 0x01,
	Led1 = 0x02,
	Led2 = 0x04
}tenu_LED_ID;

typedef enum
{
	LED_Off = 0,
	LED_On = !LED_Off
}tenu_LED_State;

void LED_Init(void);

void LED_TurnOn(tenu_LED_ID ledID);

void LED_TurnOff(tenu_LED_ID ledID);

void LED_Toggle(tenu_LED_ID ledID);

tenu_LED_State LED_GetState(tenu_LED_ID ledID);

#endif /* LED_H_ */
