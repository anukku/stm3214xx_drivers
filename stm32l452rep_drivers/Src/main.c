#include "stm32l4xx.h"
#include <stdio.h>
#include <stdint.h>
#include "uart.h"

#define GPIOBEN				(1U<<1)
#define PIN13				(1U<<13)

#define LED_PIN				PIN13
//PA2 & PA3 for UART's RX and TX

char key;
int main(void)
{

	RCC->AHB2ENR |= GPIOBEN;

	GPIOB->MODER |= (1U<<26);
	GPIOB->MODER &= ~(1U<<27);
	uart2_rxtx_init();

	while(1)
	{
		key = uart2_read();
		if(key == '1')
		{
			GPIOB->BSRR = LED_PIN;
			uart2_write('x');
		}
		else
		{
			GPIOB->BSRR = (1U<<29);
		}

	}
}








