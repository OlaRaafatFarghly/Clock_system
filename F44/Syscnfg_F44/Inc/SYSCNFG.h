/*
 * SYSCNFG.h
 *
 *  Created on: Aug 13, 2023
 *      Author: Ahmed
 */

#ifndef SYSCNFG_H_
#define SYSCNFG_H_
#include <stdio.h>
#include "Error.h"
#include <stdint.h>
#define Sys_Cnfg_Base_Address 0x40013800

typedef struct{

	uint32_t MEMRMP;
	uint32_t PMC;
	uint32_t EXTICR[4];
	uint32_t CMPCR;
	uint32_t Rev;
	uint32_t Rev2;
	uint32_t CFGR;


}SYSCFG_t;


typedef enum{

	 PIN0=0,
	 PIN1,
	 PIN2,
	 PIN3,
	 PIN4,
	 PIN5,
	 PIN6,
	 PIN7,
	 PIN8,
	 PIN9,
	 PIN10,
	 PIN11,
	 PIN12,
	 PIN13,
	 PIN14,
	 PIN15



	 }PIN_t;


	 typedef enum{

	 	 PORTA=0,
	 	 PORTB,
	 	 PORTC,
	 	 PORTD,
	 	 PORTE,
	 	 PORTF,
	 	 PORTG,
	 	 PORTH

	 	 }Port_t;

#define SYSCFG ((SYSCFG_t*) Sys_Cnfg_Base_Address  )


uint8_t SYSCFG_Set_Port(Port_t ,PIN_t  );



#endif /* SYSCNFG_H_ */
