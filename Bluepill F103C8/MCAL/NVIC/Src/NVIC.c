#include "NVIC.h"
#include "STM32f103xx.h"


void NVIC_Pref_en(IRQ_t Pref){
	uint8_t RegNum=Pref/32;
	uint8_t BitNum=Pref%32;

	NVIC->NVIC_ISER[RegNum]|=1<<BitNum;


}

void NVIC_Pref_Dis(IRQ_t Pref){
	uint8_t RegNum=Pref/32;
	uint8_t BitNum=Pref%32;

	NVIC->NVIC_ICER[RegNum]|=1<<BitNum;


}


void NVIC_Pref_Flag_en(IRQ_t Pref){
	uint8_t RegNum=Pref/32;
	uint8_t BitNum=Pref%32;

		NVIC->NVIC_ISPR[RegNum]|=1<<BitNum;




}
void NVIC_Pref_Flag_dis(IRQ_t Pref){

	uint8_t RegNum=Pref/32;
	uint8_t BitNum=Pref%32;

	NVIC->NVIC_ICPR[RegNum]|=1<<BitNum;

}


void NVIC_Priority_set(uint8_t IRQ ,uint8_t Pri ){


	NVIC->NVIC_IPR[IRQ]=Pri<<4;


}

