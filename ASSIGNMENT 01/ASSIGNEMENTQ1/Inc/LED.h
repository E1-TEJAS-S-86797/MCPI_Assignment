/*
 * LED.h
 *
 *  Created on: Sep 21, 2024
 *      Author: tejas
 */

#ifndef LED_H_
#define LED_H_

#include "stm32f4xx.h"

// DEFINING GPIO PIN AND LED PINS
#define GPIO_LED          GPIOD
#define LED_PIN_GREEN     12
#define LED_PIN_RED 	  13
#define LED_PIN_ORANGE    14
#define LED_PIN_BLUE	  15

#define GPIO_LED_CLKEN    3

// DECLARING FUNCTIONS
void LedInit(uint32_t pin);
void LedOn(uint32_t pin);
void LedOff(uint32_t pin);
void LedBlink(uint32_t pin, uint32_t delayMs);



#endif /* LED_H_ */
