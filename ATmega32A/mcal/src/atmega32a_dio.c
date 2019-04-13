/*
 * dio.c
 *
 *  Created on: Jan 5, 2019
 *      Author: Ahmed Hessien
 */


#include "util.h"
#include "std_types.h"
#include "atmega32a_dio.h"
#include "register_map.h"


void DIO_vidSetPinDirection(DIO_tenuPortID enuPortID, DIO_tenuPinPosition enuPinPosition, DIO_tenuPinDataDirection enuPinDirection)
{
	switch(enuPortID)
	{
	case DIO_PortA:
		if(enuPinDirection == DIO_PinOutputDirection)
		{
			SET_BIT(REG_DDRA, enuPinPosition);
		}
		else if(enuPinDirection == DIO_PinInputDirection)
		{
			CLR_BIT(REG_DDRA, enuPinPosition);
		}
		else
		{
			;
		}

		break;

	case DIO_PortB:
		if(enuPinDirection == DIO_PinOutputDirection)
		{
			SET_BIT(REG_DDRB, enuPinPosition);
		}
		else if(enuPinDirection == DIO_PinInputDirection)
		{
			CLR_BIT(REG_DDRB, enuPinPosition);
		}
		else
		{
			;
		}

		break;

	case DIO_PortC:
		if(enuPinDirection == DIO_PinOutputDirection)
		{
			SET_BIT(REG_DDRC, enuPinPosition);
		}
		else if(enuPinDirection == DIO_PinInputDirection)
		{
			CLR_BIT(REG_DDRC, enuPinPosition);
		}
		else
		{
			;
		}

		break;

	case DIO_PortD:
		if(enuPinDirection == DIO_PinOutputDirection)
		{
			SET_BIT(REG_DDRD, enuPinPosition);
		}
		else if(enuPinDirection == DIO_PinInputDirection)
		{
			CLR_BIT(REG_DDRD, enuPinPosition);
		}
		else
		{
			;
		}

		break;

	default:
		break;
	}

}

void DIO_vidWritePin(DIO_tenuPortID enuPortID, DIO_tenuPinPosition enuPinPosition, uint8 PinLevel)
{

	switch(enuPortID)
	{
	case DIO_PortA:
		if(PinLevel == PIN_HIGH)
		{
			SET_BIT(REG_PORTA, enuPinPosition);
		}
		else if(PinLevel == PIN_LOW)
		{
			CLR_BIT(REG_PORTA, enuPinPosition);
		}
		else
		{
			;
		}

		break;

	case DIO_PortB:
		if(PinLevel == PIN_HIGH)
		{
			SET_BIT(REG_PORTB, enuPinPosition);
		}
		else if(PinLevel == PIN_LOW)
		{
			CLR_BIT(REG_PORTB, enuPinPosition);
		}
		else
		{
			;
		}

		break;

	case DIO_PortC:
		if(PinLevel == PIN_HIGH)
		{
			SET_BIT(REG_PORTC, enuPinPosition);
		}
		else if(PinLevel == PIN_LOW)
		{
			CLR_BIT(REG_PORTC, enuPinPosition);
		}
		else
		{
			;
		}

		break;

	case DIO_PortD:
		if(PinLevel == PIN_HIGH)
		{
			SET_BIT(REG_PORTD, enuPinPosition);
		}
		else if(PinLevel == PIN_LOW)
		{
			CLR_BIT(REG_PORTD, enuPinPosition);
		}
		else
		{
			;
		}

		break;

	default:
		break;
	}

}

uint8 DIO_u8ReadPin(DIO_tenuPortID enuPortID, DIO_tenuPinPosition enuPinPosition)
{
	uint8 PinLevel;
	switch(enuPortID)
	{
	case DIO_PortA:
		PinLevel = GET_BIT(REG_PINA, enuPinPosition);
		break;

	case DIO_PortB:
		PinLevel = GET_BIT(REG_PINB, enuPinPosition);
		break;

	case DIO_PortC:
		PinLevel = GET_BIT(REG_PINB, enuPinPosition);
		break;

	case DIO_PortD:
		PinLevel = GET_BIT(REG_PINB, enuPinPosition);
		break;
	}

	return PinLevel;
}

void DIO_vidSetPortDirection(DIO_tenuPortID enuPortID, DIO_tenuPortDataDirection enuPortDirection)
{
	switch(enuPortID)
	{
	case DIO_PortA:
		if(enuPortDirection == DIO_PortOutputDirection)
		{
			SET_REG(REG_DDRA);
		}
		else if(enuPortDirection == DIO_PortInputDirection)
		{
			CLR_REG(REG_DDRA);
		}
		else
		{
			;
		}

		break;

	case DIO_PortB:
		if(enuPortDirection == DIO_PortOutputDirection)
		{
			SET_REG(REG_DDRB);
		}
		else if(enuPortDirection == DIO_PortInputDirection)
		{
			CLR_REG(REG_DDRB);
		}
		else
		{
			;
		}

		break;

	case DIO_PortC:
		if(enuPortDirection == DIO_PortOutputDirection)
		{
			SET_REG(REG_DDRC);
		}
		else if(enuPortDirection == DIO_PortInputDirection)
		{
			CLR_REG(REG_DDRC);
		}
		else
		{
			;
		}

		break;

	case DIO_PortD:
		if(enuPortDirection == DIO_PortOutputDirection)
		{
			SET_REG(REG_DDRD);
		}
		else if(enuPortDirection == DIO_PortInputDirection)
		{
			CLR_REG(REG_DDRD);
		}
		else
		{
			;
		}

		break;

	default:
		break;
	}

}

void DIO_vidWritePort(DIO_tenuPortID enuPortID, uint8 PortValue)

{

	switch(enuPortID)
	{
	case DIO_PortA:
		WRITE_REG(REG_PORTA, PortValue);
		break;

	case DIO_PortB:
		WRITE_REG(REG_PORTB, PortValue);
		break;

	case DIO_PortC:
		WRITE_REG(REG_PORTC, PortValue);
		break;

	case DIO_PortD:
		WRITE_REG(REG_PORTD, PortValue);
		break;

	default:
		break;
	}

}

uint8 DIO_u8ReadPort(DIO_tenuPortID enuPortID)
{
	uint8 PortValue;
	switch(enuPortID)
	{
	case DIO_PortA:
		PortValue = GET_REG(REG_PORTA);
		break;

	case DIO_PortB:
		PortValue = GET_REG(REG_PORTB);
		break;

	case DIO_PortC:
		PortValue = GET_REG(REG_PORTC);
		break;

	case DIO_PortD:
		PortValue = GET_REG(REG_PORTD);
		break;

	default:
		break;
	}

	return PortValue;
}

void DIO_vidTogglePin(DIO_tenuPortID enuPortID, DIO_tenuPinPosition enuPinPosition)
{

	switch(enuPortID)
	{
	case DIO_PortA:
		TOG_BIT(REG_PORTA, enuPinPosition);
		break;

	case DIO_PortB:
		TOG_BIT(REG_PORTB, enuPinPosition);
		break;

	case DIO_PortC:
		TOG_BIT(REG_PORTC, enuPinPosition);
		break;

	case DIO_PortD:
		TOG_BIT(REG_PORTD, enuPinPosition);
		break;

	default:
		break;
	}

}

void DIO_vidTogglePort(DIO_tenuPortID enuPortID)
{

	switch(enuPortID)
	{
	case DIO_PortA:
		TOG_REG(REG_PORTA);
		break;

	case DIO_PortB:
		TOG_REG(REG_PORTB);
		break;

	case DIO_PortC:
		TOG_REG(REG_PORTC);
		break;

	case DIO_PortD:
		TOG_REG(REG_PORTD);
		break;

	default:
		break;
	}

}

uint8 DIO_u8ActivatePinPullupResistor(DIO_tenuPortID enuPortID, DIO_tenuPinPosition enuPinPosition)
{
	uint8 returnStatus = BTY_u8OK;
	switch(enuPortID)
	{
	case DIO_PortA:
		if(GET_BIT(REG_DDRA, enuPinPosition) == DIO_PinInputDirection)
		{
			SET_BIT(REG_PORTA, enuPinPosition);
		}
		else if(GET_BIT(REG_DDRA, enuPinPosition) == DIO_PinOutputDirection)
		{
			returnStatus = BTY_u8NOK;
		}
		else
		{
			;	//Do nothing
		}
		break;

	case DIO_PortB:
		if(GET_BIT(REG_DDRB, enuPinPosition) == DIO_PinInputDirection)
		{
			SET_BIT(REG_PORTB, enuPinPosition);
		}
		else if(GET_BIT(REG_DDRB, enuPinPosition) == DIO_PinOutputDirection)
		{
			returnStatus = BTY_u8NOK;
		}
		else
		{
			;	//Do nothing
		}
		break;

	case DIO_PortC:
		if(GET_BIT(REG_DDRC, enuPinPosition) == DIO_PinInputDirection)
		{
			SET_BIT(REG_PORTC, enuPinPosition);
		}
		else if(GET_BIT(REG_DDRC, enuPinPosition) == DIO_PinOutputDirection)
		{
			returnStatus = BTY_u8NOK;
		}
		else
		{
			;	//Do nothing
		}
		break;

	case DIO_PortD:
		if(GET_BIT(REG_DDRD, enuPinPosition) == DIO_PinInputDirection)
		{
			SET_BIT(REG_PORTD, enuPinPosition);
		}
		else if(GET_BIT(REG_DDRD, enuPinPosition) == DIO_PinOutputDirection)
		{
			returnStatus = BTY_u8NOK;
		}
		else
		{
			;	//Do nothing
		}
		break;

	default:
		returnStatus = BTY_u8NOK;
		break;
	}

	return returnStatus;

}

uint8 DIO_u8ActivatePortPullupResistor(DIO_tenuPortID enuPortID)
{
	uint8 returnStatus = BTY_u8OK;
	switch(enuPortID)
	{
	case DIO_PortA:
		if(GET_REG(REG_DDRA) == DIO_PortInputDirection)
		{
			SET_REG(REG_PORTA);
		}
		else if(GET_REG(REG_DDRA) == DIO_PortOutputDirection)
		{
			returnStatus = BTY_u8NOK;
		}
		else
		{
			;	//Do nothing
		}
		break;

	case DIO_PortB:
		if(GET_REG(REG_DDRB) == DIO_PortInputDirection)
		{
			SET_REG(REG_PORTB);
		}
		else if(GET_REG(REG_DDRB) == DIO_PortOutputDirection)
		{
			returnStatus = BTY_u8NOK;
		}
		else
		{
			;	//Do nothing
		}
		break;

	case DIO_PortC:
		if(GET_REG(REG_DDRC) == DIO_PortInputDirection)
		{
			SET_REG(REG_PORTC);
		}
		else if(GET_REG(REG_DDRC) == DIO_PortOutputDirection)
		{
			returnStatus = BTY_u8NOK;
		}
		else
		{
			;	//Do nothing
		}
		break;

	case DIO_PortD:
		if(GET_REG(REG_DDRD) == DIO_PortInputDirection)
		{
			SET_REG(REG_PORTD);
		}
		else if(GET_REG(REG_DDRD) == DIO_PortOutputDirection)
		{
			returnStatus = BTY_u8NOK;
		}
		else
		{
			;	//Do nothing
		}
		break;

	default:
		returnStatus = BTY_u8NOK;
		break;
	}

	return returnStatus;

}

uint8 DIO_u8DeactivatePinPullupResistor(DIO_tenuPortID enuPortID, DIO_tenuPinPosition enuPinPosition)
{
	uint8 returnStatus = BTY_u8OK;
	switch(enuPortID)
	{
	case DIO_PortA:
		if(GET_BIT(REG_DDRA, enuPinPosition) == DIO_PinInputDirection)
		{
			CLR_BIT(REG_PORTA, enuPinPosition);
		}
		else if(GET_BIT(REG_DDRA, enuPinPosition) == DIO_PinOutputDirection)
		{
			returnStatus = BTY_u8NOK;
		}
		else
		{
			;	//Do nothing
		}
		break;

	case DIO_PortB:
		if(GET_BIT(REG_DDRB, enuPinPosition) == DIO_PinInputDirection)
		{
			CLR_BIT(REG_PORTB, enuPinPosition);
		}
		else if(GET_BIT(REG_DDRB, enuPinPosition) == DIO_PinOutputDirection)
		{
			returnStatus = BTY_u8NOK;
		}
		else
		{
			;	//Do nothing
		}
		break;

	case DIO_PortC:
		if(GET_BIT(REG_DDRC, enuPinPosition) == DIO_PinInputDirection)
		{
			CLR_BIT(REG_PORTC, enuPinPosition);
		}
		else if(GET_BIT(REG_DDRC, enuPinPosition) == DIO_PinOutputDirection)
		{
			returnStatus = BTY_u8NOK;
		}
		else
		{
			;	//Do nothing
		}
		break;

	case DIO_PortD:
		if(GET_BIT(REG_DDRD, enuPinPosition) == DIO_PinInputDirection)
		{
			CLR_BIT(REG_PORTD, enuPinPosition);
		}
		else if(GET_BIT(REG_DDRD, enuPinPosition) == DIO_PinOutputDirection)
		{
			returnStatus = BTY_u8NOK;
		}
		else
		{
			;	//Do nothing
		}
		break;

	default:
		returnStatus = BTY_u8NOK;
		break;
	}

	return returnStatus;

}

uint8 DIO_u8DeactivatePortPullupResistor(DIO_tenuPortID enuPortID)
{
	uint8 returnStatus = BTY_u8OK;
	switch(enuPortID)
	{
	case DIO_PortA:
		if(GET_REG(REG_DDRA) == DIO_PortInputDirection)
		{
			CLR_REG(REG_PORTA);
		}
		else if(GET_REG(REG_DDRA) == DIO_PortOutputDirection)
		{
			returnStatus = BTY_u8NOK;
		}
		else
		{
			;	//Do nothing
		}
		break;

	case DIO_PortB:
		if(GET_REG(REG_DDRB) == DIO_PortInputDirection)
		{
			CLR_REG(REG_PORTB);
		}
		else if(GET_REG(REG_DDRB) == DIO_PortOutputDirection)
		{
			returnStatus = BTY_u8NOK;
		}
		else
		{
			;	//Do nothing
		}
		break;

	case DIO_PortC:
		if(GET_REG(REG_DDRC) == DIO_PortInputDirection)
		{
			CLR_REG(REG_PORTC);
		}
		else if(GET_REG(REG_DDRC) == DIO_PortOutputDirection)
		{
			returnStatus = BTY_u8NOK;
		}
		else
		{
			;	//Do nothing
		}
		break;

	case DIO_PortD:
		if(GET_REG(REG_DDRD) == DIO_PortInputDirection)
		{
			CLR_REG(REG_PORTD);
		}
		else if(GET_REG(REG_DDRD) == DIO_PortOutputDirection)
		{
			returnStatus = BTY_u8NOK;
		}
		else
		{
			;	//Do nothing
		}
		break;

	default:
		returnStatus = BTY_u8NOK;
		break;
	}

	return returnStatus;

}

void DIO_vidSetPort(DIO_tenuPortID enuPortID)
{

	switch(enuPortID)
	{
	case DIO_PortA:
		SET_REG(REG_PORTA);
		break;

	case DIO_PortB:
		SET_REG(REG_PORTB);
		break;

	case DIO_PortC:
		SET_REG(REG_PORTC);
		break;

	case DIO_PortD:
		SET_REG(REG_PORTD);
		break;

	default:
		break;
	}

}

void DIO_vidClearPort(DIO_tenuPortID enuPortID)
{

	switch(enuPortID)
	{
	case DIO_PortA:
		CLR_REG(REG_PORTA);
		break;

	case DIO_PortB:
		CLR_REG(REG_PORTB);
		break;

	case DIO_PortC:
		CLR_REG(REG_PORTC);
		break;

	case DIO_PortD:
		CLR_REG(REG_PORTD);
		break;

	default:
		break;
	}

}

