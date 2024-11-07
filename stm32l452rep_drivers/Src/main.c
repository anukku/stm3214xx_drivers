#include "uart.h"
#include "systick.h"
#include "stdio.h"
#include "tim.h"
#include "exti.h"
#define GPIOBEN				(1U<<1)
#define PIN5				(1U<<13)
#define LED_PIN				PIN5
#define AF1_TIM				(1U<<20)
static void systick_callback(void);

int main(void) {
	RCC->AHB2ENR |= GPIOBEN;
	GPIOB->MODER |= (1U << 26);
	GPIOB->MODER &= ~(1U << 27);
	GPIOB->ODR ^= LED_PIN;
	GPIOB->ODR ^= LED_PIN;

	uart2_tx_init();
	tim1_1hz_interrupt_init();
	printf("INIT!\r\n");
	while (1)
    {

    }
}

static void systick_callback(void)
{
	printf("A second passed from systick\n\r");
}
void TIM1_UP_TIM16_IRQHandler(void) //tabela de vectori pt intreruperi!!!
{
	TIM1->SR &=~SR_UIF;
	//Clear update interrupt flag
	systick_callback();
}
