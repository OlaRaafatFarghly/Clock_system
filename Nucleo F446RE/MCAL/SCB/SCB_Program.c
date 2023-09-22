/********************************************************************************************/
/********************************************************************************************/
/**************************		Date:    13 September 2023            			*************/
/**************************		Layer:   MCAL								   	*************/
/**************************		SWC:	 SCB									*************/
/**************************		Version: 1.00 	             					*************/
/********************************************************************************************/
/********************************************************************************************/

/********************************************************************************************/
/* Include libraries                                                                        */
/********************************************************************************************/
#include <stdio.h>
#include <stdint.h>

#include "Stm32F466xx.h"
#include "Error_type.h"
#include "Utils.h"

/********************************************************************************************/
/* Include Component Files                                                                  */
/********************************************************************************************/
#include "SCB_config.h"
#include "SCB_Interface.h"
#include "SCB_Private.h"


void SCB_vSetPriorityCfg(SCB_GroupPriorityCfg copy_eGroupPriorityCfg)
{
	SCB->AIRCR = VECTKEY <<16 | copy_eGroupPriorityCfg << 8;
}

void SCB_vSetInterruptPriority(SystemInterrupt_t copy_SInterrupt,uint8_t copy_u8Priority)
{
	if (copy_SInterrupt < 0 )
	{
		SCB->SHP[copy_SInterrupt+12] = copy_u8Priority << 4;
	}
}