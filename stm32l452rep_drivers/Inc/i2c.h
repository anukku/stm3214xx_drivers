#ifndef I2C_H_
#define I2C_H_

#include <stdint.h>
#include "stm32l4xx.h"

#define GPIOBEN			(1U<<1)
#define GPIOCEN			(1U<<2)
#define	I2C1EN			(1U<<21)
#define	I2C3EN			(1U<<23)

#define SLAVE_OWN_ADDRESS		0x5A

#endif
