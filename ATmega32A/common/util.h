/*
 * util.h
 *
 *  Created on: Jan 5, 2019
 *      Author: Ahmed Hessien
 */

#ifndef UTIL_H_
#define UTIL_H_


#define SET_BIT(REG,BIT)		(REG|=(1U<<BIT))
#define CLR_BIT(REG,BIT)		(REG&=~(1U<<BIT))
#define TOG_BIT(REG,BIT)		(REG^=(1U<<BIT))
#define GET_BIT(REG,BIT)		((REG & (1U<<BIT)) == (1U<<BIT))

#define SET_REG(REG)			(REG=0xFF)
#define CLR_REG(REG)			(REG=0x00)
#define GET_REG(REG)			(REG)
#define WRITE_REG(REG,VALUE)	(REG=VALUE)
#define TOG_REG(REG)			(REG^=0xFF)

#endif
