/*
 * bit_math.h
 *
 *  Created on: Dec 13, 2023
 *      Author: Eid Elsayed Okda
 */

#ifndef MCAL_BIT_MATH_H_
#define MCAL_BIT_MATH_H_

#define SET_BIT(REG,BIT)         REG |=(1 << BIT)
#define CLEAR_BIT(REG,BIT)       REG &= ~(1 << BIT)
#define TOGGLE_BIT(REG,BIT)      REG ^=(1<<BIT)
#define IS_BIT_SET(REG,BIT)      REG & (1 << BIT)
#define IS_BIT_CLEARED(REG,BIT)  !(REG & (1 << BIT))
#define GET_BIT(REG,BIT)         1 & (REG >> BIT)


#endif /* MCAL_BIT_MATH_H_ */
