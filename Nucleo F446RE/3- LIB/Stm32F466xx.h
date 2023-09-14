/********************************************************************************************/
/********************************************************************************************/
/**************************		Date:    13 September 2023	            		*************/
/**************************		Layer:   LIB								   	*************/
/**************************		SWC:	 STM32F446xx Registers					*************/
/**************************		Version: 1.00 	             					*************/
/********************************************************************************************/
/********************************************************************************************/

/********************************************************************************************/
/* Guard of file will call one time in .c  			                                        */
/********************************************************************************************/
#ifndef STM33F446xx_H_
#define STM33F446xx_H_

/**************************************** Various Memories Base Addresses **********************/
#define FLASH_BASE_ADDRESS    			0x08000000UL
#define SRAM_BASE_ADDRESS				0x20000000UL
#define ROM_BASE_ADDRESS				0x1FFF0000UL

/******************************* Core peripheral Base Addresses 	*******************************/
#define SysTick_BASE_ADDRESS 			0xE000E010UL
#define NVIC_BASE_ADDRESS 	   			0xE000E100UL
#define SCB_BASE_ADDRESS 	   			0xE000E008UL

/**************************************** AHB1 Peripheral Base Addresses **********************/
#define GPIOA_BASE_ADDRESS 				0x40020000UL
#define GPIOB_BASE_ADDRESS 				0x40020400UL
#define GPIOC_BASE_ADDRESS 				0x40020800UL
#define GPIOD_BASE_ADDRESS 				0x40020C00UL
#define GPIOE_BASE_ADDRESS 				0x40021000UL
#define GPIOF_BASE_ADDRESS 				0x40021400UL
#define GPIOG_BASE_ADDRESS 				0x40021800UL
#define GPIOH_BASE_ADDRESS 				0x40021C00UL

#define RCC_BASE_ADDRESS    0x40023800UL 

#define DMA1_BASE_ADDRESS   0x40026000UL 
#define DMA2_BASE_ADDRESS   0x40026400UL 


/**************************************** AHB2 Peripheral Base Addresses **********************/


/**************************************** AHB3 Peripheral Base Addresses **********************/

/**************************************** APB1 Peripheral Base Addresses **********************/
#define UART4_BASE_ADDRESS  0x40004C00UL
#define UART5_BASE_ADDRESS  0x40005000UL
#define USART2_BASE_ADDRESS 0x40004400UL
#define USART3_BASE_ADDRESS 0x40004800UL


#define SPI2_BASE_ADDRESS 	0x40003800UL
#define SPI3_BASE_ADDRESS 	0x40003C00UL

#define I2C1_BASE_ADDRESS 	0x40005400UL
#define I2C2_BASE_ADDRESS 	0x40005800UL
#define I2C3_BASE_ADDRESS 	0x40005C00UL

/**************************************** APB2 Peripheral Base Addresses **********************/
#define USART1_BASE_ADDRESS 0x40011000UL
#define USART6_BASE_ADDRESS 0x40011400UL

#define SPI1_BASE_ADDRESS 	0x40013000UL
#define SPI4_BASE_ADDRESS 	0x40013400UL

/**************************************** GPIO Register Definition Structure **********************/

typedef struct
{
	volatile uint32_t MODER;				/* GPIO PORT Mode Register */
	volatile uint32_t OTYPER;               /* GPIO PORT Output type Register */
	volatile uint32_t OSPEEDR;              /* GPIO PORT Output speed Register */
	volatile uint32_t PUPDR;                /* GPIO PORT Pull up/down Register */
	volatile uint32_t IDR;                  /* GPIO PORT Input Data Register */
	volatile uint32_t ODR;                  /* GPIO PORT Output Data Register */
	volatile uint32_t BSRR;                 /* GPIO PORT Bit Set/Reset Register */
	volatile uint32_t LCKR;                 /* GPIO PORT Lock Register */
	volatile uint32_t AFR[2];               /* GPIO PORT Alternate function Register */
}GPIO_RegDef_t;

/**************************************** RCC Peripheral Definition  *****************************/
typedef struct {
	volatile uint32_t CR;         /* Clock control register */
	volatile uint32_t PLLCFGR;    /* PLL configuration register */
	volatile uint32_t CFGR;       /* Clock configuration register */
	volatile uint32_t CIR;        /* Clock interrupt register */
	volatile uint32_t AHB1RSTR;   /* AHB1 peripheral reset register */
	volatile uint32_t AHB2RSTR;   /* AHB2 peripheral reset register */
	volatile uint32_t AHB3RSTR;   /* AHB3 peripheral reset register */
	uint32_t RESERVED0;           /* Reserved */
	volatile uint32_t APB1RSTR;   /* APB1 peripheral reset register */
	volatile uint32_t APB2RSTR;   /* APB2 peripheral reset register */
	uint32_t RESERVED1[2];        /* Reserved */
	volatile uint32_t AHB1ENR;    /* AHB1 peripheral clock enable register */
	volatile uint32_t AHB2ENR;    /* AHB2 peripheral clock enable register */
	volatile uint32_t AHB3ENR;    /* AHB3 peripheral clock enable register */
	uint32_t RESERVED2;           /* Reserved */
	volatile uint32_t APB1ENR;    /* APB1 peripheral clock enable register */
	volatile uint32_t APB2ENR;    /* APB2 peripheral clock enable register */
	uint32_t RESERVED3[2];        /* Reserved */
	volatile uint32_t AHB1LPENR;  /* AHB1 peripheral clock enable in low power mode register */
	volatile uint32_t AHB2LPENR;  /* AHB2 peripheral clock enable in low power mode register */
	volatile uint32_t AHB3LPENR;  /* AHB3 peripheral clock enable in low power mode register */
	uint32_t RESERVED4;           /* Reserved */
	volatile uint32_t APB1LPENR;  /* APB1 peripheral clock enable in low power mode register */
	volatile uint32_t APB2LPENR;  /* APB2 peripheral clock enable in low power mode register */
	uint32_t RESERVED5[2];        /* Reserved */
	volatile uint32_t BDCR;       /* Backup domain control register */
	volatile uint32_t CSR;        /* Clock control & status register */
	uint32_t RESERVED6[2];        /* Reserved */
	volatile uint32_t SSCGR;      /* Spread spectrum clock generation register */
	volatile uint32_t PLLI2SCFGR; /* PLLI2S configuration register */
} RCC_RegDef_t;

/******************************* STK Register Definition Structure *******************************/

typedef struct{
	volatile uint32_t STK_CTRL;
	volatile uint32_t STK_LOAD;
	volatile uint32_t STK_VAL;
	volatile uint32_t STK_CALIB;

}MSTK_RegDef_t;

/******************************* NVIC Register Definition Structure *******************************/
typedef struct{
	volatile uint32_t NVIC_ISER[8];
	volatile uint32_t Reserved1[24];
	volatile uint32_t NVIC_ICER[8];
	volatile uint32_t Reserved2[24];
	volatile uint32_t NVIC_ISPR[8];
	volatile uint32_t Reserved3[24];
	volatile uint32_t NVIC_ICPR[8];
	volatile uint32_t Reserved4[24];
	volatile uint32_t NVIC_IABR[8];
	volatile uint32_t Reserved5[24];
	volatile uint8_t  NVIC_IPR [240];
	volatile uint32_t Reserved6[644];
	volatile uint32_t NVIC_STIR;
}NVIC_RegDef_t;

/******************************* SCB Register Definition Structure *******************************/
typedef struct{
	uint32_t ACTLR;
	uint32_t CPUID;
	uint32_t ICSR;
	uint32_t VTOR;
	uint32_t AIRCR;
	uint32_t SCR;
	uint32_t CCR;
	uint8_t  SHP[12U];
	uint32_t SHCSR;
}SCB_RegDef_t;

/******************************* EXTI Register Definition Structure *******************************/
typedef struct{
	uint32_t EXTI_IMR;
	uint32_t EXTI_EMR;
	uint32_t EXTI_RTSR;
	uint32_t EXTI_FTSR;
	uint32_t EXTI_SWIER;
	uint32_t EXTI_PR;	
}EXTI_RegDef_t;

/******************************* EXTI Register Definition Structure *******************************/
typedef struct{
	uint32_t SYSCFG_MEMRMP;
	uint32_t SYSCFG_PMC;
	uint32_t SYSCFG_EXTICR[4];
	uint32_t Reserved1[2];
	uint32_t SYSCFG_CMPCR;
	uint32_t Reserved2[2];
	uint32_t SYSCFG_CFGR;
}SYSCFG_RegDef_t;

/******************************* EXTI Register Definition Structure *******************************/
typedef struct{
	uint32_t DMA_SxCR;
	uint32_t DMA_SxNDTR;
	uint32_t DMA_SxPAR;
	uint32_t DMA_SxM0AR;
	uint32_t DMA_SxM1AR;
	uint32_t DMA_SxFCR;	
}STREAM_RegDef_t;

typedef struct{
	uint32_t DMA_LISR;
	uint32_t DMA_HISR;
	uint32_t DMA_LIFCR;
	uint32_t DMA_HIFCR;
	STREAM_RegDef_t DMA_STREAM[7];
}DMA_RegDef_t;

/******************************* GPIO Peripheral Definitions 		 *******************************/
 #define GPIOA       	   ((GPIO_RegDef_t*)GPIOA_BASE_ADDRESS)
 #define GPIOB             ((GPIO_RegDef_t*)GPIOB_BASE_ADDRESS)
 #define GPIOC             ((GPIO_RegDef_t*)GPIOC_BASE_ADDRESS)
 #define GPIOD             ((GPIO_RegDef_t*)GPIOD_BASE_ADDRESS)
 #define GPIOE             ((GPIO_RegDef_t*)GPIOE_BASE_ADDRESS)
 #define GPIOF             ((GPIO_RegDef_t*)GPIOF_BASE_ADDRESS)
 #define GPIOG             ((GPIO_RegDef_t*)GPIOG_BASE_ADDRESS)
 #define GPIOH             ((GPIO_RegDef_t*)GPIOH_BASE_ADDRESS)

/******************************* RCC Peripheral Definitions 		 *******************************/
#define RCC       	   	   ((RCC_RegDef_t*)RCC_BASE_ADDRESS)

/******************************* STK Peripheral Definitions 		 *******************************/
#define STK  			   ((MSTK_RegDef_t*)SysTick_BASE_ADDRESS)

/******************************* NVIC Peripheral Definitions 		 *******************************/
#define NVIC  		 	   ((NVIC_RegDef_t*)NVIC_BASE_ADDRESS)

/******************************* SCB Peripheral Definitions 		 *******************************/
#define  SCB  		 	   ((SCB_RegDef_t*)SCB_BASE_ADDRESS)

/******************************* EXTI Peripheral Definitions 		 *******************************/
#define  EXTI  		 	   ((EXTI_RegDef_t*)EXTI_BASE_ADDRESS)

/******************************* SYSCFG Peripheral Definitions 		 *******************************/
#define  SYSCFG  	 	   ((SYSCFG_RegDef_t*)SYSCFG_BASE_ADDRESS)
	
/******************************* DMA Peripheral Definitions 		 *******************************/
#define  DMA1  	  	  	   ((DMA_RegDef_t*)DMA1_BASE_ADDRESS)
#define  DMA2  	      	   ((DMA_RegDef_t*)DMA2_BASE_ADDRESS)

#endif
/********************************************************************************************/
/* END OF FILE: STM32F446xx.h                                                               */
/********************************************************************************************/
