/*
 * UART.c
 *
 *  Created on: Sep 8, 2023
 *      Author: Ahmed
 */
#include "UART.h"

UART_reg_t* USART[5]={(UART_reg_t*)UART1_Base_Address,(UART_reg_t*)UART2_Base_Address,(UART_reg_t*)UART3_Base_Address,(UART_reg_t*)UART4_Base_Address,(UART_reg_t*)UART5_Base_Address};

Err_Status USART_init(UART_Handle_t*USART_Handle){
	Err_Status err=OK;
	USART[USART_Handle->USART_Type]->CR1|=0b1<<2;
	USART[USART_Handle->USART_Type]->CR1|=0b1<<5;
	if(USART_Handle!=NULL){

/**************          Control Config        *********/
USART[USART_Handle->USART_Type]->CR1= 0x00000000;
USART[USART_Handle->USART_Type]->CR2= 0x00000000;
USART[USART_Handle->USART_Type]->CR3= 0x00000000;

USART[USART_Handle->USART_Type]->CR1|= USART_Handle->OS;
USART[USART_Handle->USART_Type]->CR1|= (USART_Handle->Transmit_Status)<<3;
USART[USART_Handle->USART_Type]->CR1|= (USART_Handle->Recieve_Status)<<2;
USART[USART_Handle->USART_Type]->CR1|= (USART_Handle->RXNEIE_Interrupt)<<5;
USART[USART_Handle->USART_Type]->CR1|= (USART_Handle->TXE_Interrupt)<<7;
USART[USART_Handle->USART_Type]->CR1|= (USART_Handle->TC_Interrupt)<<6;
USART[USART_Handle->USART_Type]->CR1|= (USART_Handle->PE_int_en)<<8;

USART[USART_Handle->USART_Type]->CR2|= (USART_Handle->Stop_Bit_Mode)<<12;
USART[USART_Handle->USART_Type]->CR2|= (USART_Handle->Clock_Status)<<11;


USART[USART_Handle->USART_Type]->CR3|= (USART_Handle->Duplex_Mode)<<3;
USART[USART_Handle->USART_Type]->CR3|= (USART_Handle->CTSE)<<9;
USART[USART_Handle->USART_Type]->CR3|= (USART_Handle->RTSE)<<8;
/**************          Math Equatioxns        *********/
uint32_t USART_Div=(16000000000)/(8*   (2-USART_Handle->OS)   *(USART_Handle->BaudRate) );

 USART_Div=( SysClk_Mask/(8*2*9600) );

uint32_t Real_Part=USART_Div/1000;
uint32_t Fraction_Part=USART_Div%1000;
uint32_t Fraction_Reg=(16*Fraction_Part+500)/1000;
/**************          Math Equations        *********/
USART[USART_Handle->USART_Type]->BRR|=Fraction_Reg;
USART[USART_Handle->USART_Type]->BRR|=Real_Part<<4;


	USART[USART_Handle->USART_Type]->CR1=0b1<<13;




	}

	else{
		err=NOK;
	}

	return err;


}


Err_Status USART_Send_Poll(UART_Handle_t*USART_Handle,uint32_t Data){
	Err_Status err=OK;

	if(USART_Handle!=NULL){

		USART[USART_Handle->USART_Type]->DR=Data;

		while(    ((USART[USART_Handle->USART_Type]->SR)<<7) ==0); // Poll for Data Transfer check
		while(    ((USART[USART_Handle->USART_Type]->SR)<<6) ==0); // Poll for Transmission complete check


		}
	else err=NOK;




	return err;

}

Err_Status USART_Rec_Poll(UART_Handle_t*USART_Handle,uint32_t* Dest){
	Err_Status err=OK;

	if(USART_Handle!=NULL){

		while(    ((USART[USART_Handle->USART_Type]->SR)<<5) ==0); // Poll for Data Recieve check
		*Dest=USART[USART_Handle->USART_Type]->DR;



		}
	else err=NOK;




	return err;

}


Err_Status USART_Send_DMA(UART_Handle_t*COPY_Handle,uint32_t data){


}



