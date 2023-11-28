/********************************************************************************************/
/********************************************************************************************/
/**************************		Date:    13 September 2023	            		*************/
/**************************		Layer:   HAL								   	*************/
/**************************		SWC:	 BUZZER									*************/
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
#include "BUZZER_interface.h"
#include "BUZZER_private.h"
#include "BUZZER_config.h"


void BUZZER_voidTurnOn(PinConfig_t * BUZZER)
{
	if (NULL != BUZZER)
	{
		GPIO_u8PinInit(BUZZER);

		GPIO_vSetOutputPinValue(BUZZER->PIN_Port, BUZZER->PIN_Number, OUTPUT_HIGH);
	}
	else
	{
		/* Do Nothing */
	}
}


void BUZZER_voidTurnOff(PinConfig_t * BUZZER)
{
	if (NULL != BUZZER)
	{
		GPIO_u8PinInit(BUZZER);

		GPIO_vSetOutputPinValue(BUZZER->PIN_Port, BUZZER->PIN_Number, OUTPUT_LOW);
	}
	else
	{
		/* Do Nothing */
	}
}

void BUZZER_voidToggle(PinConfig_t * BUZZER , uint16_t  Copy_u8Delay)
{
	/* Turn on BUZZER */
	BUZZER_voidTurnOn(BUZZER);

	/* Wait for delay */
	SysTick_Delay_ms(Copy_u8Delay);

	/* Turn off BUZZER */
	BUZZER_voidTurnOff(BUZZER);

	/* Wait for delay */
	SysTick_Delay_ms(Copy_u8Delay);
}

/********************************************************************************************/
/*   END OF FILE: BUZZER_program.c                                                             */
/********************************************************************************************/
