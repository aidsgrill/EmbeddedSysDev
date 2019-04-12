/*
 * std_types.h
 *
 *  Created on: Jan 4, 2019
 *      Author: Ahmed Hessien
 */

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

typedef unsigned char uint8;
typedef unsigned short int uint16;
typedef unsigned long int unint32;
typedef unsigned long long int uint64;

typedef signed char sint8;
typedef signed short int sint16;
typedef signed long int sint32;
typedef signed long long int singt64;

typedef float float32;
typedef double float64;

typedef enum
{
    False = 0,
    True = !False
}boolean;

#define Std_u8ReturnType uint8

#define BTY_u8ZERO  (0)

#define BTY_u8ONE   (1)

#define BTY_u8OK    (1)

#define BTY_u8NOK   (0)

#define BTY_u8TRUE  (1)

#define BTY_u8FALSE (0)




#endif /* STD_TYPES_H_ */
