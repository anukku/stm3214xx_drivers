#include "systick.h"

/**
 * @brief  The function provides a desired delay.
 *
 * @param delay: desired delay.
 *
 * @return None.
 */
void systickDelayMs(int delay)
{
	//Reload SysTick with number of cycles per millisecond
	SysTick->LOAD = SYSTICK_LOAD_VALUE;

	//Clear SysTick current value register
	SysTick->VAL = 0;

	//Select clock source and enable SysTick
	SysTick->CTRL = CTRL_CLKSRC | CTRL_ENABLE;

	//The while marks the passing of a millisecond for the desired amount(`delay`)
	for(int i = 0; i < delay; i++)
	{
		//Wait until COUNTFLAG is set
		while((SysTick->CTRL & CTRL_COUNTFLAG) == 0){}
	}

	SysTick->CTRL = 0;

}