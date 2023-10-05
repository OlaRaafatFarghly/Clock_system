
#include <stdint.h>
#include "../../../LIB/Error_type.h"
#include "../../../LIB/Stm32F103xx.h"
#include "../inc/AFIO_interface.h"
#include "../inc/AFIO_private.h"


uint8_t SYSCFG_Set_Line(EN_SYSCFG_Line_t copy_port, EN_SYSCFG_Line_t copy_line)
{
	uint8_t Local_u8_Error_State = OK;

	if ((copy_line >= 0) && (copy_line <= NUM_LINES) && ((copy_port >= PA) && (copy_port <= PH)))
	{
		AFIO->EXTICR[copy_line / 4] &= ~(AFIO_EXTI_LINE_MASK << ((copy_line % 4) * 4));
		AFIO->EXTICR[copy_line / 4] |= (copy_port << ((copy_line % 4) * 4));
	}
	else
	{
		Local_u8_Error_State = AFIO_EXTI_SRC_LINE_NUM_ERR;
	}

	return Local_u8_Error_State;
}
