/*
 * RCC.h
 *
 *  Created on: Aug 29, 2023
 *      Author: Ahmed
 */

#ifndef RCC_H_
#define RCC_H_


#ifndef RCC_h
#define RCC_h

#include "../Inc/RCC_config.h"
#include "../../LIB/STM32F446xx.h"
void RCC_set_CLKStatus(CLK_Type_t CLK,Status Status);

void RCC_set_Sys_clk(CLK_Type_t CLK);

uint8_t RCC_HSE_Config(HSE_Config_t div);

uint8_t RCC_Pllconfig(uint8_t MUX,CLK_Type_t CLK);

//void RCC_AHBEnableClock(AHB_Prefs_t Pref);
void RCC_AHBEnableClock(AHB_Prefs_t Pref);

void RCC_AHBDisableClock(AHB_Prefs_t Pref);


void RCC_APB1_EnableClock(uint8_t Pref);

void RCC_APB1_DisableClock(uint8_t Pref);


void RCC_APB2_enableClock(uint8_t Pref);

void RCC_APB2_disableClock(uint8_t Pref);


#endif



#endif /* RCC_H_ */
