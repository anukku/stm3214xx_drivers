#include "tim.h"

#define TIM1EN		(1U<<11)
#define TIM2EN		(1U<<0)

void tim1_1hz_init(void)
{
	//Enable clock access for timer 1.
	RCC->APB2ENR |= TIM1EN;

	//Setting the prescaler register
	TIM1->PSC = 400-1;

	//Setting the auto-reload register
	TIM1->ARR = 10000-1;

	//Reset the counter
	TIM1->CNT = 0;

	//Enable the timer
	TIM1->CR1 = CR1_CEN;
}

void tim1_1hz_interrupt_init(void)
{
	//Enable clock access for timer 1.
	RCC->APB2ENR |= TIM1EN;

	//Setting the prescaler register
	TIM1->PSC = 400-1;

	//Setting the auto-reload register
	TIM1->ARR = 10000-1;

	//Reset the counter
	TIM1->CNT = 0;

	//Enable the timer
	TIM1->CR1 = CR1_CEN;

	//Enable timer update interrupt
	TIM1->DIER |= DIRE_UIE;

	//Enable interrupt in NVIC
	NVIC_EnableIRQ(TIM1_UP_TIM16_IRQn);

}








