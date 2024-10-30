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

void tim2_output_compare(void)
{
	//Enable clock access for timer 2
	RCC->APB1ENR1 |= TIM2EN;

	//Setting the prescaler register
	TIM2->PSC = 400-1;

	//Setting the auto-reload register
	TIM2->ARR = 10000-1;

	//Output compare toggle mode
	TIM2->CCMR1 |= (1U<<4);
	TIM2->CCMR1 |= (1U<<5);

	//Set match value
	TIM2->CCR1 = 0;

	//Enable CH1 compare mode
	TIM2->CCER |= (1U<<0);

	//Clear counter
	TIM2->CNT = 0;

	//Enable timer 2
	TIM2->CR1 = (1U<<0);
}

void tim1_output_compare(void)
{
	//Enable clock access for timer 1.
	RCC->APB2ENR |= TIM1EN;

	//Setting the prescaler register
	TIM1->PSC = 400-1;

	//Setting the auto-reload register
	TIM1->ARR = 10000-1;

	//Output compare toggle mode
	TIM1->CCMR1 |= (1U<<4);
	TIM1->CCMR1 |= (1U<<5);

	//Set match value
	TIM1->CCR1 = 0;

	//Enable CH1 compare mode
	TIM1->CCER |= (1U<<0);

	//Clear the counter
	TIM1->CNT = 0;

	//Enable the timer
	TIM1->CR1 = CR1_CEN;
}
