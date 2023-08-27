/*******************************************************/
/***** Author    : Mahmoud Abdelraouf Mahmoud   ********/
/***** Date		 : 20 Feb 2022                  ********/
/***** Version   : V01                          ********/
/***** Module    : STD_TYPES.h                  ********/
/*******************************************************/
#ifndef __STD_TYPES_H__
#define __STD_TYPES_H__


typedef unsigned char		u8;
typedef unsigned short  	u16;
typedef unsigned int    	u32;
typedef unsigned long   	u64;

typedef signed char 		s8;
typedef signed short 		s16;
typedef signed int 			s32;
typedef signed long  		s64;

typedef float  				f32;
typedef double 				f64;
typedef long double  		f96;

typedef u8                  Std_ReturnType;



#define NULL				((void *)0)

#define E_OK                (Std_ReturnType)1
#define E_NOT_OK            (Std_ReturnType)0


#endif /**< __STD_TYPES_H__ */