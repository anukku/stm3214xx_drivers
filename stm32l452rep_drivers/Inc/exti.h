#ifndef EXTI_H_
#define EXTI_H_

#include <stdint.h>
#include "stm32l4xx.h"

#define GPIOCEN			(1U<<2)
#define SYSCFGEN		(1U<<0)
#define PC_EXTI13		(1U<<5)
#define PIN13			(1U<<13)

void pc13_exti_init(void);

#endif
