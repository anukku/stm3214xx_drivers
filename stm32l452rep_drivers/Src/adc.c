#include "adc.h"

/**
 * @brief  The function initializes the ADC, after calibration.
 *
 * @return None.
 */
void pa4_adc1_init(void)
{
	//Enable clock access to GPIOA
	RCC->AHB2ENR |= GPIOAEN;

	//Set PA4 to analog mode
	GPIOA->MODER |= (1U << 8);
	GPIOA->MODER |= (1U << 9);

	//Configure Pull-up/Pull-down:
	GPIOA->PUPDR &= ~(0x3 << (4 * 2));

	//Enable clock access to ADC module
	RCC->AHB2ENR |= ADCEN;

	//Set ADC common clock
	ADC1_COMMON->CCR &= ~(1U<<16);
	ADC1_COMMON->CCR |= (1U<<17);

	//Set continuous conversion mode
	ADC1->CFGR |= CFGR_CONT;

	//Set sequencer length
	ADC1->SQR1 = SEQ_LEN_1;

	//Set ADC channel and rank
	ADC1->SQR1 |= (1U<<6);
	ADC1->SQR1 |= (1U<<9);

	//Disable ADC deep power down
	ADC1->CR &= ~(1U<<29);

	//Enable ADC internal voltage regulator
	ADC1->CR |= (1U<<28);

	//Start ADC calibration
	ADC1->CR |= (1U<<31);

	//Enable ADC
	ADC1->CR |= (1U<<0);
}

/**
 * @brief  The function starts the conversion.
 *
 * @return None.
 */
void start_conversion(void)
{
	//Start the conversion
	ADC1->CR |= (1U<<2);
}

/**
 * @brief  The function reads data from the data register.
 *
 * @return Digitally converted data.
 */
uint32_t adc_read(void)
{
	//Wait for End-of-Conversion flag
	while(!(ADC1->ISR & EOC)) {}

	//Clear EOC flag
	ADC1->ISR |= EOC;

	//Read results
	return(ADC1->DR);
}
