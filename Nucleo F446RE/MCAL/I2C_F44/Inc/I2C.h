/*
 * I2C.h
 *
 *  Created on: Sep 12, 2023
 *      Author: Ahmed
 */

#ifndef I2C_H_
#define I2C_H_

#include "stm32f446re.h"
#include "Error.h"
#include "i2c_priv.h"

#include <stdint.h>

typedef struct i2c{
	uint32_t CR1;
	uint32_t CR2;
	uint32_t OAR1;
	uint32_t OAR2;
	uint32_t DR;
	uint32_t SR1;
	uint32_t SR2;
	uint32_t CCR;
	uint32_t TRISE;
	uint32_t FLTR;

}i2c_reg_t;


typedef enum {
	SM,
	FM


}I2C_mode;


typedef enum {
	System,
	DMA


}interrupt_mode;


typedef enum {
	write,
	Read


}RW_t;

typedef enum {

	i2c1,
	i2c2,
	i2c3


}i2c_number_t;

typedef struct {

	I2C_mode mode;
	i2c_number_t i2c_number;
	uint32_t clock;
	interrupt_mode int_mode;

}i2c_handle_t;






Err_Status i2c_init(i2c_handle_t*);

Err_Status i2c_start(i2c_handle_t*);

Err_Status i2c_write_address(i2c_handle_t*,uint32_t,RW_t);

Err_Status i2c_write_data(i2c_handle_t*,uint32_t Data);

Err_Status i2c_stop(i2c_handle_t*);
void I2C_IRQ_Handler(uint8_t);
#endif /* I2C_H_ */
