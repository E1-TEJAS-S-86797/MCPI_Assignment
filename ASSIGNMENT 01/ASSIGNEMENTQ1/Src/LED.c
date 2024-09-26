/*
 * LED.c
 *
 *  Created on: Sep 21, 2024
 *      Author: tejas
 */

#include "LED.h"

void LedInit(uint32_t pin)
{
	// POWER
	RCC->AHB1ENR |= BV(GPIO_LED_CLKEN);
	// MODER
	GPIO_LED->MODER &= ~BV(pin*2+1); // 1
	GPIO_LED->MODER |= BV(pin*2);   // 0
	// OTYPER ----->
	GPIO_LED->OTYPER |= BV(pin);
	//SPEDD ---> SET TO FAST SPEED
	GPIO_LED->OSPEEDR |= BV(pin*2+1); // 1
	GPIO_LED->OSPEEDR &= ~BV(pin*2);   // 0
	// NO PULL NO PULL DOWN
	GPIO_LED->PUPDR |= BV(pin*2);
	GPIO_LED->PUPDR &= ~BV(pin*2+1);
}
void LedOn(uint32_t pin)
{
	// TO LED ON SET PIN TO 1
	GPIO_LED->BSRR = BV(pin);
}
void LedOff(uint32_t pin)
{
	// TO LED OFF SET PIN TO 0
	GPIO_LED->BSRR = BV(pin+16);
}
void LedBlink(uint32_t pin, uint32_t delayMs)
{
	LedOn(pin);
	DelayMs(delayMs);
	LedOff(pin);
}

