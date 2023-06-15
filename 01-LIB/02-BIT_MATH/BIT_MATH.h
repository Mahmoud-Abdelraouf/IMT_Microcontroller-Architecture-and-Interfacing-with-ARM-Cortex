/*******************************************************/
/***** Author    : Mahmoud Abdelraouf Mahmoud   ********/
/***** Date		 : 20 Feb 2022                  ********/
/***** Version   : V01                          ********/
/*******************************************************/
#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(REG,BTI)	REG |= (1<<(BTI))
#define CLR_BIT(REG,BTI)	REG &=~(1<<(BTI))
#define GET_BIT(REG,BTI)	((REG >>BIT) & 1)
#define TOG_BIT(REG,BTI)	REG ^= (1<<(BTI))




#endif