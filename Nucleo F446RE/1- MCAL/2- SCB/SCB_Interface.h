/********************************************************************************************/
/********************************************************************************************/
/**************************		Date:    13 September 2023            			*************/
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

typedef enum {
	NonMaskableInt         = -14,  /*!< Non Maskable Interrupt */
	HardFault              = -13,  /*!< Hard Fault Interrupt */
	MemoryManagement       = -12,  /*!< Memory Management Interrupt */
	BusFault               = -11,  /*!< Bus Fault Interrupt */
	UsageFault             = -10,  /*!< Usage Fault Interrupt */
	SVCall                 = -5,   /*!< SV Call Interrupt */
	DebugMonitor           = -4,   /*!< Debug Monitor Interrupt */
	PendSV                 = -2,   /*!< Pend SV Interrupt */
	SysTick                = -1,   /*!< System Tick Interrupt */
}SystemInterrupt_t;

typedef enum {
	Four_Bit_Group_Zero_Bit_sub,
	Three_Bit_Group_One_Bit_sub=4,
	Two_Bit_Group_Two_Bit_sub,
	One_Bit_Group_Three_Bit_sub,
	Zero_Bit_Group_Four_Bit_sub,
}SCB_GroupPriorityCfg;

void SCB_vSetPriorityCfg(SCB_GroupPriorityCfg copy_eGroupPriorityCfg);

void SCB_vSetInterruptPriority(SystemInterrupt_t copy_SInterrupt,uint8_t copy_u8Priority);

#endif
/********************************************************************************************/
/* END OF FILE: SCB_interface.h                                                             */
/********************************************************************************************/
