
#include <stdint.h>

#include "../../../LIB/Error_type.h"
#include "../../../LIB/Stm32F446xx.h"
#include "../../../LIB/BIT_Math.h"

#include "../inc/SysTick_private.h"
#include "../inc/SysTick_interface.h"

/* this functions work for SYSCLK with 16MHZ internal clock */
uint8_t STK_Delay_us(uint16_t time_us)
{
	CLR_BIT(STK->STK_CTRL, ENABLE);  /* make sure timer is OFF */
	STK->STK_LOAD = 2*(time_us) -1;     /* */

	CLEAR_BIT(STK->STK_CTRL, CLKSOURCE); /* CLOCK SOURSE SELECTED AHB/8  */

	SET_BIT(STK->STK_CTRL, ENABLE);

	while(GET_BIT(STK->STK_CTRL, COUNTFLAG) == 0);

	STK->STK_CTRL = 0;  /* Close the timer */
}
uint8_t STK_Delay_ms(uint16_t time_ms)
{
	CLR_BIT(STK->STK_CTRL, ENABLE);  /* make sure timer is OFF */
	STK->STK_LOAD = 2*(time_ms*1000) - 1;

	CLR_BIT(STK->STK_CTRL, CLKSOURCE); /* CLOCK SOURSE SELECTED AHB/8  */

	SET_BIT(STK->STK_CTRL, ENABLE);

	while (GET_BIT(STK->STK_CTRL, COUNTFLAG) == 0);

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
