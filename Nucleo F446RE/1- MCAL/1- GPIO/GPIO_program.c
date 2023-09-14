/********************************************************************************************/
/********************************************************************************************/
/**************************		Date:    13 September 2023            			*************/
/**************************		Layer:   MCAL								   	*************/
/**************************		SWC:	 GPIO									*************/
/**************************		Version: 1.00 	             					*************/
/********************************************************************************************/
/********************************************************************************************/

/********************************************************************************************/
/* Include libraries                                                                        */
/********************************************************************************************/
#include <stdio.h>
#include <stdint.h>

#include "Stm32F466xx.h"
#include "ErrType.h"
#include "Utils.h"

/********************************************************************************************/
/* Include Component Files                                                                  */
/********************************************************************************************/
#include "GPIO_config.h"
#include "GPIO_private.h"
#include "GPIO_interface.h"


static GPIO_RegDef_t* GPIO_PORT[GPIO_PERIPHERAL_NUM] = {GPIOA,GPIOB,GPIOC,GPIOD,GPIOE,GPIOF,GPIOG,GPIOH};

/***************************************************************************************
/* @fn GPIO_u8PinInit
 * @brief the function initialization the GPIO pin according to the input paramters
 * @param[in] PinConfg : the initialization values of the pin
 * @retval ErrorStatus
 */
uint8_t GPIO_u8PinInit(const GPIO_PinConfig_t* PinConfig )
{
	uint8_t Local_u8ErrorState = OK;

	if (PinConfig != NULL)
	{
		if((PinConfig->Port <= PORTH) && (PinConfig ->PinNum <= PIN15))
		{
			/* Select GPIO Mode: INPUT - OUTPUT - ANALOG - AF */
			GPIO_PORT[PinConfig->Port]-> MODER &= ~( MODER_MASK		   << (PinConfig->PinNum * MODER_PIN_ACCESS)); /* clear mode bits */
			GPIO_PORT[PinConfig->Port]-> MODER |=  ((PinConfig-> Mode) << (PinConfig->PinNum * MODER_PIN_ACCESS));

			/* Select GPIO pull state: PULLUP - PULLDOWN - NOPULL */
			GPIO_PORT[PinConfig->Port]-> PUPDR &= ~(PUPDR_MASK			   << (PinConfig->PinNum * PUPDR_PIN_ACCESS)); /* clear mode bits */
			GPIO_PORT[PinConfig->Port]-> PUPDR |=  ((PinConfig-> PullType)  << (PinConfig->PinNum * PUPDR_PIN_ACCESS));

			/* Select output type and speed in case of OUTPUT / AF  */
			if ((PinConfig-> Mode == OUTPUT) || (PinConfig-> Mode == ALTERNATE_FUNCTION))
			{
				/* select output type PUSHPULL - OPEN DRAIN */
				GPIO_PORT[PinConfig->Port]-> OTYPER &= ~(OTYPER_MASK		 << (PinConfig->PinNum)); /*  clear mode bits */
				GPIO_PORT[PinConfig->Port]-> OTYPER |=  (PinConfig-> Mode << (PinConfig->PinNum));

				/* select speed type LOW_SPEED - MEDIUM_SPEED - FAST_SPEED - HIGH_SPEED */
				GPIO_PORT[PinConfig->Port]-> OSPEEDR &= ~(OPSEEDR_MASK	   << (PinConfig->PinNum * OPSEEDR_PIN_ACCESS)); /* clear mode bits */
				GPIO_PORT[PinConfig->Port]-> OSPEEDR |=  (PinConfig-> Speed << (PinConfig->PinNum * OPSEEDR_PIN_ACCESS));
				/* select AF PIN */
				if ((PinConfig-> Mode == ALTERNATE_FUNCTION))
				{
					uint8_t Local_u8RegNum = PinConfig->PinNum / 8U;
					uint8_t Local_u8BitNum = PinConfig->PinNum % 8U;

					GPIO_PORT[PinConfig->Port]-> AFR[Local_u8RegNum] &= ~(AFR_MASK			  << ( Local_u8BitNum*AFR_PIN_ACCESS)); /* clear mode bits */
					GPIO_PORT[PinConfig->Port]-> AFR[Local_u8RegNum] |=  (PinConfig-> AltFunc << ( Local_u8BitNum*AFR_PIN_ACCESS));
				}
			}
		}
		else
		{
			Local_u8ErrorState = NOK;
		}
	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}
	return Local_u8ErrorState;
}

/**********************************************************************************
 * @fn GPIO_vSetPinValue
 * @brief the function outputs value on pin
 * @param[in] GPIO_Port : the port number, get options @GPIO_Port_t ENUM
 * @param[in] GPIO_Pin : the pin number, get options @GPIO_Pin_t ENUM
 * @param[in] GPIO_ODR : the pin number, get options @GPIO_ODR_t ENUM
 * @retval ErrorStatus
 *
 */
uint8_t GPIO_u8SetPinValue(Port_t Port, Pin_t PinNum, PinVal_t PinVal )
{
	uint8_t Local_u8ErrorState = OK ;

	if ((Port < PORTH ) && (PinNum <= PIN15))
	{
		if ( PinVal == PIN_LOW )
		{
			GPIO_PORT[Port]-> ODR = ~( 1 << PinNum);
			/* GPIO_PORT[Port]-> BSRR =  ( 1 << (16 + PinNum)); */
		}
		else if ( PinVal == PIN_HIGH)
		{
			GPIO_PORT[Port]-> ODR |= ( 1 << PinNum);
			/* GPIO_PORT[Port]-> BSRR =  ( 1 << PinNum ); */
		}
		else
		{
			Local_u8ErrorState = NOK;
		}
	}
	else
	{
		Local_u8ErrorState = NOK;
	}
	return Local_u8ErrorState;

}

/**********************************************************************************
 * @fn GPIO_vToggleOutputPinValue
 * @brief the function toggles value on pin
 * @param[in] copy_eGPIO_Port : the port number, get options @GPIO_Port_t ENUM
 * @param[in] copy_eGPIO_Pin : the pin number, get options @GPIO_Pin_t ENUM
 * @retval ErrorStatus
 *
 */
uint8_t GPIO_u8TogglePinValue(Port_t Port, Pin_t PinNum )
{
	uint8_t Local_u8ErrorState = OK ;
	if (( Port <= PORTH) && ( PinNum <= PIN15))
	{

		TOG_BIT(GPIO_PORT[Port]->ODR ,PinNum);
	}
	else
	{
		Local_u8ErrorState = NOK;
	}
	return Local_u8ErrorState;
}

/**********************************************************************************
 * @fn MGPIO_vReadInputPinValue
 * @brief the function reads value from pin
 * @param[in] copy_eGPIO_Port : the port number, get options @GPIO_Port_t ENUM
 * @param[in] copy_eGPIO_Pin : the pin number, get options @GPIO_Pin_t ENUM
 * @param[out] copy_GPIO_ODR : the pin value, get options @GPIO_ODR_t ENUM
 * @retval ErrorStatus
 *
 */
uint8_t GPIO_uGetPinValue(Port_t Port , Pin_t PinNum, PinVal_t* Copy_GPIO_ODR )
{
	uint8_t Local_u8ErrorState = OK ;

	if (( Port <= PORTH) && ( PinNum <= PIN15))
	{
		*Copy_GPIO_ODR = GET_BIT(GPIO_PORT[Port]->ODR ,PinNum);
	}
	else
	{
		Local_u8ErrorState = NOK;
	}
	return Local_u8ErrorState;

}
