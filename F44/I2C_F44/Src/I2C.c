/*
 * I2C.c
 *
 *  Created on: Sep 12, 2023
 *      Author: Ahmed
 */


#include "I2C.h"
#include <stdlib.h>
#include "std_macro.h"

#define System_Clock 16UL
i2c_reg_t * I2C[3]={(i2c_reg_t * )i2c1_Base_Address,(i2c_reg_t * )i2c2_Base_Address,(i2c_reg_t * )i2c3_Base_Address};
uint32_t status;



Err_Status i2c_init(i2c_handle_t*i2c_h){

uint8_t x=i2c_h->i2c_number-1;
	I2C[x]->CR1|=0b1<<15;
	// reseting

	I2C[x]->CCR|=FM<<15;
	// FM MODE

	I2C[x]->CR2|=i2c_h->clock;
	// Clock
	I2C[x]->CR2|=0b1<<(10);
	I2C[x]->CR2|=0b1<<(11);

	I2C[x]->CR2|=0b1<<9;


	if(i2c_h->mode==SM){

	I2C[x]->CCR|=System_Clock*5;

	}
	else if (i2c_h->mode==FM){

		I2C[x]->CCR|=(System_Clock*125)/100;

	}
	I2C[x]->CR1|=0b1;


}
Err_Status i2c_start(i2c_handle_t*i2c_h){

	Err_Status err=OK;
	if(i2c_h!=NULL){
	I2C[i2c_h->i2c_number-1]->CR1|=0b1<<8;
	//while (READBIT ((I2C[i2c_h->i2c_number]->SR1),0)==0   );
	}
	else err=NOK;
	return err;
}

Err_Status i2c_write_address(i2c_handle_t*i2c_h,uint32_t address,RW_t RW){

	Err_Status err=OK;

	if(i2c_h!=NULL){

		if(  (status==Start)  ){

		I2C[i2c_h->i2c_number-1]->DR|=(address<<1)|RW;

		//while (READBIT ((I2C[i2c_h->i2c_number]->SR1),2)==0   );  // Un-comment if you wanna use polling method

			}
			else err=start_error;
			return err;
	}
	else err=NOK;
return err;
}


Err_Status i2c_write_data(i2c_handle_t*i2c_h,uint32_t Data){


	Err_Status err=OK;

	if(i2c_h!=NULL){

		if(  (status==Address_Sent_NAck)||(status==Data_Sent_NAck) ){

           	I2C[i2c_h->i2c_number-1]->DR=Data;
	//while (READBIT ((I2C[i2c_h->i2c_number]->SR1),2)==0   );// Un-comment if you wanna use polling method

		}
		else err=NACK_err;


		}
		else err=NOK;
		return err;

	}



Err_Status i2c_stop(i2c_handle_t*i2c_h){

	Err_Status err=OK;

	if(i2c_h!=NULL){


				I2C[i2c_h->i2c_number-1]->CR1|=0b1<<9;



	}

	else err=NOK;


}

void I2C_IRQ_Handler(uint8_t num){
	if(     READBIT(  (I2C[num]->SR1) ,0   )     ){

			status=Start;


		if(     READBIT(  (I2C[num]->SR1) ,1   )     ){

					status=Address_Sent;

					if(     READBIT(  (I2C[num]->SR1) ,2   )     ){

							status=Address_Sent_Ack;

						}
					else {
						status=Address_Sent_NAck;
					}
		}


		if(   (READBIT(  (I2C[num]->SR1) ,2   )) ==1    ){

					status=Data_Sent;
					if(     READBIT(  (I2C[num]->SR1) ,2   )     ){

						status=Data_Sent_Ack;

							}
						else {
							status=Data_Sent_NAck;
						}

		}

		}


		if(     READBIT(  (I2C[num]->SR1) ,4   )     ){

						status=0;

					}
}

void 	DMA1_Stream4_IRQHandler(void){

	uint8_t num=2;

	I2C_IRQ_Handler(num);



}

void 	DMA1_Stream6_IRQHandler(void){

	uint8_t num=0;

		I2C_IRQ_Handler(num);


}


void 	DMA1_Stream7_IRQHandler(void){

	uint8_t num=1;

		I2C_IRQ_Handler(num);


}
void I2C1_EV_IRQHandler(void){


	uint8_t num=0;

			I2C_IRQ_Handler(num);





}

void I2C2_EV_IRQHandler(void){


	uint8_t num=1;

			I2C_IRQ_Handler(num);





}

void I2C3_EV_IRQHandler(void){


	uint8_t num=2;

			I2C_IRQ_Handler(num);





}
