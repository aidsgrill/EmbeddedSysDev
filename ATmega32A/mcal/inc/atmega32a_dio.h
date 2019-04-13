/*
 * dio.h
 *
 *  Created on: Jan 5, 2019
 *      Author: Ahmed Hessien
 */

#ifndef DIO_H_
#define DIO_H_

#include "std_types.h"

#define PIN_HIGH	1
#define PIN_LOW		0

#define REG_HIGH	0xFF
#define REG_LOW		0x00


typedef enum
{
	DIO_PortInputDirection = 0x00,
	DIO_PortOutputDirection = 0xFF
}DIO_tenuPortDataDirection;

typedef enum
{
	DIO_PinInputDirection = 0,
	DIO_PinOutputDirection = 1
}DIO_tenuPinDataDirection;

typedef enum
{
	DIO_PortA = 0,
	DIO_PortB,
	DIO_PortC,
	DIO_PortD
}DIO_tenuPortID;

typedef enum
{
	DIO_Pin0 = 0,
	DIO_Pin1,
	DIO_Pin2,
	DIO_Pin3,
	DIO_Pin4,
	DIO_Pin5,
	DIO_Pin6,
	DIO_Pin7
}DIO_tenuPinPosition;


void DIO_vidSetPinDirection(DIO_tenuPortID enuPortID, DIO_tenuPinPosition enuPinPosition, DIO_tenuPinDataDirection PinDirection);

void DIO_vidWritePin(DIO_tenuPortID enuPortID, DIO_tenuPinPosition enuPinPosition, uint8 PinLevel);

uint8 DIO_u8ReadPin(DIO_tenuPortID enuPortID, DIO_tenuPinPosition enuPinPosition);

void DIO_vidSetPortDirection(DIO_tenuPortID enuPortID, DIO_tenuPortDataDirection enuPortDirection);

void DIO_vidWritePort(DIO_tenuPortID enuPortID, uint8 PortValue);

uint8 DIO_u8ReadPort(DIO_tenuPortID enuPortID);

void DIO_vidTogglePin(DIO_tenuPortID enuPortID, DIO_tenuPinPosition enuPinPosition);

void DIO_vidTogglePort(DIO_tenuPortID enuPortID);

uint8 DIO_u8ActivatePinPullupResistor(DIO_tenuPortID enuPortID, DIO_tenuPinPosition enuPinPosition);

uint8 DIO_u8ActivatePortPullupResistor(DIO_tenuPortID enuPortID);

uint8 DIO_u8DeactivatePinPullupResistor(DIO_tenuPortID enuPortID, DIO_tenuPinPosition enuPinPosition);

uint8 DIO_u8DeactivatePortPullupResistor(DIO_tenuPortID enuPortID);

void DIO_vidSetPort(DIO_tenuPortID enuPortID);

void DIO_vidClearPort(DIO_tenuPortID enuPortID);


#endif /* DIO_H_ */
