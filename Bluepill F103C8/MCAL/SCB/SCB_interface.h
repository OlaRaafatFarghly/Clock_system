/********************************************************************************************/
/********************************************************************************************/
/**************************		Date:    13 September 2023	            		*************/
/**************************		Layer:   MCAL								   	*************/
/**************************		SWC:	 SCB									*************/
/**************************		Version: 1.00 	             					*************/
/********************************************************************************************/
/********************************************************************************************/


/********************************************************************************************/
/* Guard of file will call one time in .c  			                                        */
/********************************************************************************************/
#ifndef SCB_INTERFACE_H
#define SCB_INTERFACE_H


typedef enum 
{
	NonMaskableInt_IRQn         = -14,    /*!< 2 Non Maskable Interrupt                        */
	MemoryManagement_IRQn       = -12,    /*!< 4 Cortex-M3 Memory Management Interrupt         */
	BusFault_IRQn               = -11,    /*!< 5 Cortex-M3 Bus Fault Interrupt                 */
	UsageFault_IRQn             = -10,    /*!< 6 Cortex-M3 Usage Fault Interrupt               */
	SVCall_IRQn                 = -5,     /*!< 11 Cortex-M3 SV Call Interrupt                  */
	DebugMonitor_IRQn           = -4,     /*!< 12 Cortex-M3 Debug Monitor Interrupt            */
	PendSV_IRQn                 = -2,     /*!< 14 Cortex-M3 Pend SV Interrupt                   */
	SysTick_IRQn                = -1,     /*!< 15 Cortex-M3 System Tick Interrupt               */
}SCB_Interrupt_t;

typedef enum {
	Four_Bit_Group_Zero_Bit_sub,
	Three_Bit_Group_One_Bit_sub=4,
	Two_Bit_Group_Two_Bit_sub,
	One_Bit_Group_Three_Bit_sub,
	Zero_Bit_Group_Four_Bit_sub,
}SCB_GroupPriorityCfg;


void SCB_vSetPriorityCfg(SCB_GroupPriorityCfg copy_eGroupPriorityCfg);

void SCB_vSetInterruptPriority(SCB_Interrupt_t copy_eInterrupt,uint8_t copy_u8Priority);

#endif
/********************************************************************************************/
/* END OF FILE: SCB_interface.h                                                             */
/********************************************************************************************/
