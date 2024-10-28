#ifndef ADC_H_
#define ADC_H_

#include <stdint.h>
#include "stm32l4xx.h"

/* Clock and GPIO register definitions */
#define GPIOAEN				(1U<<0)
#define ADCEN				(1U<<13)

/* ADC configuration register bits */
#define CFGR_CONT			(1U<<13)
#define SEQ_LEN_1			0
#define EOC					(1U<<2)

void pa4_adc1_init(void);
void start_conversion(void);
uint32_t adc_read(void);

#endif
