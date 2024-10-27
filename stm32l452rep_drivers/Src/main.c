#include "stm32l4xx.h"
#include <stdio.h>
#include <stdint.h>
#include "uart.h"
#include "adc.h"

void pseudo_dly(void);

int x;
int main(void)
{
	pa4_adc1_init();
	pseudo_dly();
	start_conversion();
	while(1)
	{

		x = adc_read();
	}
}

void pseudo_dly(void)
{
	int y;
	for(int i = 0; i< 800000; i++){
		y++;
	}
}








