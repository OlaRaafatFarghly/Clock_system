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
#include "BIT_MATH.h"

/********************************************************************************************/
/* Include Interface Files in MCAL                                                          */
/********************************************************************************************/
#include "GPIO_interface.h"
#include "STK_interface.h"

/********************************************************************************************/
/* Include Component Files                                                                  */
/********************************************************************************************/
#include "BUZZER_interface.h"
#include "BUZZER_private.h"
#include "BUZZER_config.h"


void HBUZZER_voidTurnOn(uint8_t Copy_u8PORT , uint8_t Copy_u8PIN)
{
	/*SET PORT, PIN && MODE*/
	MGPIO_u8SetPinDirection(Copy_u8PORT , Copy_u8PIN , GPIO_OUTPUT_SPEED_10MHZ_PP);

	/*SET PIN HIGH*/
	MGPIO_u8SetPinValue(Copy_u8PORT , Copy_u8PIN , GPIO_HIGH);
}


void HBUZZER_voidTurnOff(uint8_t Copy_u8PORT , uint8_t Copy_u8PIN)
{
	/*SET PORT, PIN && MODE*/
	MGPIO_u8SetPinDirection(Copy_u8PORT , Copy_u8PIN , GPIO_OUTPUT_SPEED_10MHZ_PP);

	/*SET PIN LOW*/
	MGPIO_u8SetPinValue(Copy_u8PORT , Copy_u8PIN , GPIO_LOW);
}

void HBUZZER_voidToggle(uint8_t Copy_u8PORT , uint8_t Copy_u8PIN, uint16_t Copy_u8Delay)
{
	/* Turn on BUZZER */
	HBUZZER_voidTurnOn(Copy_u8PORT , Copy_u8PIN);

	/* Wait for delay */
	MSTK_voidSetBusyWaitInMilliSec(Copy_u8Delay);

	/* Turn off BUZZER */
	HBUZZER_voidTurnOff(Copy_u8PORT , Copy_u8PIN);

	/* Wait for delay */
	MSTK_voidSetBusyWaitInMilliSec(Copy_u8Delay);
}

/********************************************************************************************/
/*   END OF FILE: BUZZER_program.c                                                             */
/********************************************************************************************/
