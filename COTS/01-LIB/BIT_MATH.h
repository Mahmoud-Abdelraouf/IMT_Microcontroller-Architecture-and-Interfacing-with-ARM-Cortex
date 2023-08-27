/*******************************************************/
/***** Author    : Mahmoud Abdelraouf Mahmoud   ********/
/***** Date		 : 20 Feb 2022                  ********/
/***** Version   : V01                          ********/
/***** Module    : BIT_MATH.h                   ********/
/*******************************************************/
#ifndef __BIT_MATH_H__
#define __BIT_MATH_H__

#define SET_BIT(REG, BIT_NUMBER) 	REG |= (1<< BIT_NUMBER)
#define CLR_BIT(REG, BIT_NUMBER) 	REG &= ~(1<< BIT_NUMBER)
#define TOG_BIT(REG, BIT_NUMBER) 	REG ^= (1<< BIT_NUMBER)
#define GET_BIT(REG, BIT_NUMBER) 	((REG & (1<< BIT_NUMBER)) >> BIT_NUMBER)



#endif /**< __BIT_MATH_H__ */

