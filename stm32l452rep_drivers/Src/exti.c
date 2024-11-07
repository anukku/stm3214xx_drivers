#include "exti.h"

void pc13_exti_init(void)
{
	//Enable clock access to GPIOC
	RCC->AHB2ENR |= GPIOCEN;

	//Enable clock access to SYSCFG
	RCC->APB2ENR |= SYSCFGEN;

	//Set PC13 as input pin
	GPIOC->MODER &= ~(1U<<26);
	GPIOC->MODER &= ~(1U<<27);

	SYSCFG->EXTICR[3] &=~(1U<<4);
	SYSCFG->EXTICR[3] &=~(1U<<5);
	SYSCFG->EXTICR[3] &=~(1U<<6);
	SYSCFG->EXTICR[3] &=~(1U<<7);
	//Select PORT C for EXTI13
	SYSCFG->EXTICR[3] |= PC_EXTI13;

	//Unmask EXTI13(enable the interrupt for EXTI line 13)
	EXTI->IMR1 |= (1U<<13);

	//Select falling edge trigger
	EXTI->FTSR1 |= (1U<<13);

	//Enable EXTI line in NVIC
	NVIC_EnableIRQ(EXTI15_10_IRQn);
}
