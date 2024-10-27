#include "stdint.h"
#include "stm32l4xx.h"
#include "uart.h"

#define SYS_FREQ			4000000
#define APB1_CLK			SYS_FREQ
#define UART_BAUDRATE		115200

static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t BaudRate);
static uint16_t compute_uart_bd(uint32_t PeriphClk, uint32_t BaudRate);

/**
 * @brief  The function redirects printf to the peripheric, in this case to USART.
 *
 * @param ch: character to send.
 *
 * @return the character that was sent.
 */
int __io_putchar(int ch)
{
	uart2_write(ch);
	return ch;
}

/**
 * @brief  The function writes data.
 *
 * @return None.
 */
void uart2_write(int ch)
{
	//Check transmit data register is empty
	while(!(USART2->ISR & ISR_TXE)) {}
	//Write to transmit data register
	USART2->TDR = (ch & 0xFF);
}

/**
 * @brief  The function reads data.
 *
 * @return None.
 */
char uart2_read(void)
{
	//Check recieve data register is empty
	while(!(USART2->ISR & ISR_RXNE)) {}
	//Return the recieved data
	return USART2->RDR;
}

/**
 * @brief  The function initializes USART2 to transmit and recieve data.
 *
 * @return None.
 */
void uart2_rxtx_init(void)
{
	//Enable clock access to PORT A
	RCC->AHB2ENR |= GPIOAEN;

	//Configure PA2 to alternate function
	GPIOA->MODER &= ~(1U<<4);
	GPIOA->MODER |= (1U<<5);

	//Set alternate function type to UART_TX to PA2
	GPIOA->AFR[0] |= (1U<<8);
	GPIOA->AFR[0] |= (1U<<9);
	GPIOA->AFR[0] |= (1U<<10);
	GPIOA->AFR[0] &= ~(1U<<11);

	//Configure PA3 to alternate function
	GPIOA->MODER &= ~(1U<<6);
	GPIOA->MODER |= (1U<<7);

	//Set alternate function type to UART_RX to PA3
	GPIOA->AFR[0] |= (1U<<12);
	GPIOA->AFR[0] |= (1U<<13);
	GPIOA->AFR[0] |= (1U<<14);
	GPIOA->AFR[0] &= ~(1U<<15);

	//Enable clock access to USART2
	RCC->APB1ENR1 |= UART2EN;

	//Set the baud rate
	uart_set_baudrate(USART2, APB1_CLK, UART_BAUDRATE);

	//Configure the transfer direction
	USART2->CR1 = (CR1_TE | CR1_RE);

	//Enable USART module
	USART2->CR1 |= CR1_UE;

}

/**
 * @brief  The function initializes USART2 to transmit data.
 *
 * @return None.
 */
void uart2_tx_init(void)
{
	//Enable clock access to PORT A
	RCC->AHB2ENR |= GPIOAEN;

	//Configure PA2 to alternate function
	GPIOA->MODER &= ~(1U<<4);
	GPIOA->MODER |= (1U<<5);

	//Configure PA3 to alternate function
	GPIOA->MODER &= ~(1U<<6);
	GPIOA->MODER |= (1U<<7);

	//Set alternate function type to UART_TX to PA2
	GPIOA->AFR[0] |= (1U<<8);
	GPIOA->AFR[0] |= (1U<<9);
	GPIOA->AFR[0] |= (1U<<10);
	GPIOA->AFR[0] &= ~(1U<<11);

	//Enable clock access to USART2
	RCC->APB1ENR1 |= UART2EN;

	//Set the baud rate
	uart_set_baudrate(USART2, APB1_CLK, UART_BAUDRATE);

	//Configure the transfer direction
	USART2->CR1 = CR1_TE;

	//Enable USART module
	USART2->CR1 |= CR1_UE;
}

/**
 * @brief  The function sets the baud rate for the desired USARTx.
 *
 * @param  USARTx: desired USARTx.
 * @param  PeriphClk: clock frequency for the UART peripheral.
 * @param  BaudRate: desired baud rate for UART communication.
 *
 * @return None.
 */
static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t BaudRate)
{
	USARTx->BRR = compute_uart_bd(PeriphClk, BaudRate);
}

/**
 * @brief  The function calculates the the baud rate, providing an approximation to the desired baud rate.
 *
 * @param  PeriphClk: clock frequency for the UART peripheral.
 * @param  BaudRate: desired baud rate for UART communication.
 * @return baud rate divisor for setting up the UART peripheral.
 *
 * @return None.
 */
static uint16_t compute_uart_bd(uint32_t PeriphClk, uint32_t BaudRate)
{
	return ((PeriphClk + (BaudRate/2U))/BaudRate);
}
