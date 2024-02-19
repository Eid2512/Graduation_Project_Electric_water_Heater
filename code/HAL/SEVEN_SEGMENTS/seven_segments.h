/*
 * seven_segments.h
 *
 *  Created on: Dec 13, 2023
 *      Author: Eid Elsayed Okda
 */

#ifndef HAL_SEVEN_SEGMENTS_SEVEN_SEGMENTS_H_
#define HAL_SEVEN_SEGMENTS_SEVEN_SEGMENTS_H_

#include "std_types.h"
#include "dio.h"

#define SEVENSEG_DISPLAY_PORT DIO_PORTA
#define SEVENSEG_DISPLAY_SHIFT 4

#define SEVENSEG1_EN_PORT DIO_PORTB
#define SEVENSEG1_EN_PIN PIN6

#define SEVENSEG2_EN_PORT DIO_PORTB
#define SEVENSEG2_EN_PIN PIN7

void SevenSeg_Init(void);
void SevenSeg_Display(uint8 num);
void SevenSeg_Off(void);
#endif /* HAL_SEVEN_SEGMENTS_SEVEN_SEGMENTS_H_ */
