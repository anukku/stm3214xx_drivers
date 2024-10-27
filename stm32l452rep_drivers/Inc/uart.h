#ifndef UART_H_
#define UART_H_

#include "stdint.h"
#include "stm32l4xx.h"
#include "uart.h"

/* Clock and GPIO register definitions */
#define GPIOAEN				(1U<<0)
#define UART2EN				(1U<<17)

/* UART configuration register bits */
#define CR1_TE				(1U<<3)
#define CR1_RE				(1U<<2)
#define CR1_UE				(1U<<0)
#define ISR_TXE				(1U<<7)
#define ISR_RXNE			(1U<<5)

/* Public function prototypes */
void uart2_rxtx_init(void);
void uart2_tx_init(void);
char uart2_read(void);
void uart2_write(int ch);

#endif
