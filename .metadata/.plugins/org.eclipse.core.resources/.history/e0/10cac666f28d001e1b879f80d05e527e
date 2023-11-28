
#include <stdint.h>


#include "BIT_Math.h"
#include "STM32F103xx.h"
#include "../inc/STK_interface.h"


/* this functions work for SYSCLK with 8MHZ and AHB prescaler 8 */
uint8_t STK_Delay_us(uint16_t time_us)
{
	CLEAR_BIT(STK->STK_CTRL, ENABLE);  /* make sure timer is OFF */
	STK->STK_LOAD = time_us-1;

	CLEAR_BIT(STK->STK_CTRL, CLKSOURCE); /* CLOCK SOURSE SELECTED AHB/8  */

	SET_BIT(STK->STK_CTRL, ENABLE);

	while(READ_BIT(STK->STK_CTRL, COUNTFLAG) == 0);

	STK->STK_CTRL = 0;  /* Close the timer */
}
uint8_t STK_Delay_ms(uint16_t time_ms)
{
	STK->STK_LOAD = 0 ;
	CLEAR_BIT(STK->STK_CTRL, ENABLE);  /* make sure timer is OFF */
	STK->STK_LOAD = (time_ms*1000) - 1;

	CLEAR_BIT(STK->STK_CTRL, CLKSOURCE); /* CLOCK SOURSE SELECTED AHB/8  */

	SET_BIT(STK->STK_CTRL, ENABLE);

	while (READ_BIT(STK->STK_CTRL, COUNTFLAG) == 0);

	STK->STK_CTRL = 0;  /* Close the timer */
}


uint8_t pulling_Delay_ms(uint16_t time_ms)
{
	uint32_t i = 0;

	while(i < (time_ms*100))
	{
		i++;
	}
}
