#ifndef SYSTICK_H_
#define SYSTICK_H_

#include <stdint.h>
#include "stm32l4xx.h"

/* SysTick configuration register bits */
#define SYSTICK_LOAD_VALUE		4000
#define ONE_SEC_LOAD			4000000
#define CTRL_ENABLE				(1U<<0)
#define CTRL_CLKSRC				(1U<<2)
#define CTRL_COUNTFLAG			(1U<<16)
#define CTRL_TICKINT			(1U<<1)

void systickDelayMs(int delay);
void systick_1hz_interrup(void);

#endif
