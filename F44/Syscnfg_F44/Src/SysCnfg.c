/*
 * SysCnfg.c
 *
 *  Created on: Aug 13, 2023
 *      Author: Ahmed
 */
#include "SysCnfg.h"

#include <stdint.h>


uint8_t SYSCFG_Set_Port(Port_t PORT,PIN_t PIN ){
uint8_t err=OK;

if( (PIN>=PIN0)&&(PIN<=PIN15)&&(PORT>=PORTA)&&(PORT<=PORTH)  ){
	uint8_t P=PIN/4;
	uint8_t P2=(PIN%4)*4;// times 4



	SYSCFG->EXTICR[P]&=~(0b1111<<P2);
	SYSCFG->EXTICR[P]|=(PORT<<P2);

}
else err=NOK;
return err;

}



