/********************************************************************************************/
/********************************************************************************************/
/**************************		Date:    13 September 2023	            		*************/
/**************************		Layer:   HAL								   	*************/
/**************************		SWC:	 LED									*************/
/**************************		Version: 1.00 	             					*************/
/********************************************************************************************/
/********************************************************************************************/


/********************************************************************************************/
/* Include libraries                                                                        */
/********************************************************************************************/
#include <stdint.h>
#include <stdio.h>

/********************************************************************************************/
/* Include Interface Files in MCAL                                                          */
/********************************************************************************************/
#include "GPIO_interface.h"
#include "SysTick_interface.h"

/********************************************************************************************/
/* Include Component Files                                                                  */
/********************************************************************************************/
#include "LED_interface.h"
#include "LED_private.h"
#include "LED_config.h"


void LED_voidTurnOn(PinConfig_t * LED)
{
	if (NULL != LED)
	{
		GPIO_u8PinInit(LED);

		GPIO_vSetOutputPinValue(LED->PIN_Port, LED->PIN_Number, OUTPUT_HIGH);
	}
	else
	{
		/* Do Nothing */
	}
}

void LED_voidTurnOff(PinConfig_t * LED)
{
	if (NULL != LED)
	{
		GPIO_u8PinInit(LED);

		GPIO_vSetOutputPinValue(LED->PIN_Port, LED->PIN_Number, OUTPUT_LOW);
	}
	else
	{
		/* Do Nothing */
	}
}

void LED_voidToggle(PinConfig_t * LED, uint16_t Copy_u8Delay)
{
	/* Turn on Led */
	LED_voidTurnOn(LED);

	/* Wait for delay */
	SysTick_Delay_ms(Copy_u8Delay);

	/* Turn off led */
	LED_voidTurnOff(LED);

	/* Wait for delay */
	SysTick_Delay_ms(Copy_u8Delay);
}


