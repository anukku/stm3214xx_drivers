#include "i2c.h"

static void i2c1_setOwnAddress1(uint32_t OwnAddress1, uint32_t OwnAddrsize);

void i2c1_slave_config(void){
	RCC->AHB2ENR |= GPIOBEN;

	GPIOB->MODER &=~(1U<<16);
	GPIOB->MODER |= (1U<<17);

	GPIOB->AFR[1] &=~ (1U<<0);
	GPIOB->AFR[1] &=~ (1U<<1);
	GPIOB->AFR[1] |=  (1U<<2);
	GPIOB->AFR[1] &=~ (1U<<3);

	GPIOB->OTYPER |= (1U<<8);

	GPIOB->PUPDR |=  (1U<<16);
	GPIOB->PUPDR &=~ (1U<<17);

	GPIOB->MODER &=~ (1U<<18);
	GPIOB->MODER |=  (1U<<19);

	GPIOB->AFR[1] &=~ (1U<<4);
	GPIOB->AFR[1] &=~ (1U<<5);
	GPIOB->AFR[1] |=  (1U<<6);
	GPIOB->AFR[1] &=~ (1U<<7);

	GPIOB->OTYPER |= (1U<<9);

	GPIOB->PUPDR |=  (1U<<18);
	GPIOB->PUPDR &=~ (1U<<19);

	RCC->APB1ENR1 |= I2C1EN;

	NVIC_EnableIRQ(I2C1_EV_IRQn);

	I2C1->CR1 &=~ (1U<<0);

	i2c1_setOwnAddress1(SLAVE_OWN_ADDRESS, 0);

	I2C1->OAR1 |= (1U<<15);

	I2C1->CR1 |= (1U<<0);

	I2C1->CR1 |= (1U<<4);

	I2C1->CR1 |= (1U<<5);

}

void i2c3_master_config(void){
	RCC->AHB2ENR |= GPIOEN;

}

static void i2c1_setOwnAddress1(uint32_t OwnAddress1, uint32_t OwnAddrsize)
{
	MODIFY_REG(I2C1->OAR1, I2C_OAR1_OA1 | I2C_OAR1_OA1MODE, OwnAddress1 | OwnAddrsize);
}
