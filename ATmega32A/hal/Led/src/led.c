/*
 * led.c
 *
 *  Created on: Apr 13, 2019
 *      Author: Inspiron-15
 */


#include "led_cfg.h"
#include "led.h"
#include "atmega32a_dio.h"


void LED_Init(void)
{
	DIO_vidSetPinDirection(LED0_PORT, LED0_PIN, DIO_PinOutputDirection);
	DIO_vidSetPinDirection(LED1_PORT, LED1_PIN, DIO_PinOutputDirection);
	DIO_vidSetPinDirection(LED2_PORT, LED2_PIN, DIO_PinOutputDirection);
}

void LED_TurnOn(tenu_LED_ID ledID)
{
	switch(ledID)
	{
	case Led0:
		DIO_vidWritePin(LED0_PORT, LED0_PIN, PIN_HIGH);
		break;
	case Led1:
		DIO_vidWritePin(LED1_PORT, LED1_PIN, PIN_HIGH);
		break;
	case Led2:
		DIO_vidWritePin(LED2_PORT, LED2_PIN, PIN_HIGH);
		break;
	default:
		break;
	}
}

void LED_TurnOff(tenu_LED_ID ledID)
{
	switch(ledID)
	{
	case Led0:
		DIO_vidWritePin(LED0_PORT, LED0_PIN, PIN_LOW);
		break;
	case Led1:
		DIO_vidWritePin(LED1_PORT, LED1_PIN, PIN_LOW);
		break;
	case Led2:
		DIO_vidWritePin(LED2_PORT, LED2_PIN, PIN_LOW);
		break;
	default:
		break;
	}
}

void LED_Toggle(tenu_LED_ID ledID)
{
	switch(ledID)
	{
	case Led0:
		DIO_vidTogglePin(LED0_PORT, LED0_PIN);
		break;
	case Led1:
		DIO_vidTogglePin(LED1_PORT, LED1_PIN);
		break;
	case Led2:
		DIO_vidTogglePin(LED2_PORT, LED2_PIN);
		break;
	default:
		break;
	}
}

tenu_LED_State LED_GetState(tenu_LED_ID ledID)
{
	tenu_LED_State ledState = LED_Off;
	switch(ledID)
	{
	case Led0:
		(DIO_u8ReadPin(LED0_PORT, LED0_PIN) == PIN_HIGH)? (ledState = LED_On): (ledState = LED_Off);
		break;
	case Led1:
		(DIO_u8ReadPin(LED1_PORT, LED1_PIN) == PIN_HIGH)? (ledState = LED_On): (ledState = LED_Off);
		break;
	case Led2:
		(DIO_u8ReadPin(LED2_PORT, LED2_PIN) == PIN_HIGH)? (ledState = LED_On): (ledState = LED_Off);
		break;
	default:
		break;
	}

	return ledState;
}
