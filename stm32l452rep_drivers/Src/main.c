#include "uart.h"
#include "systick.h"
#include "stdio.h"
#include "tim.h"
#define GPIOBEN				(1U<<0)
#define PIN5				(1U<<5)
#define LED_PIN				PIN5
#define AF1_TIM				(1U<<20)
int main(void) {
	RCC->AHB2ENR |= GPIOBEN;
	GPIOB->MODER &= ~(1U << 26);
	GPIOB->MODER |= (1U << 27);

	GPIOB->AFR[1] |= AF1_TIM;

    tim1_output_compare();

    while (1)
    {

    }
}
