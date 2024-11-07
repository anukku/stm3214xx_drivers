#ifndef TIM_H_
#define TIM_H_

#include <stdint.h>
#include "stm32l4xx.h"

/* Timer configuration register bits */
#define CR1_CEN			(1U<<0)
#define SR_UIF			(1U<<0)
#define DIRE_UIE		(1U<<0)

void tim1_1hz_init(void);
void tim1_1hz_interrupt_init(void);

#endif
