################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Inc/MCAL/RCC/Src/RCC_program.c 

OBJS += \
./Inc/MCAL/RCC/Src/RCC_program.o 

C_DEPS += \
./Inc/MCAL/RCC/Src/RCC_program.d 


# Each subdirectory must supply rules for building sources it contributes
Inc/MCAL/RCC/Src/%.o Inc/MCAL/RCC/Src/%.su Inc/MCAL/RCC/Src/%.cyclo: ../Inc/MCAL/RCC/Src/%.c Inc/MCAL/RCC/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Inc-2f-MCAL-2f-RCC-2f-Src

clean-Inc-2f-MCAL-2f-RCC-2f-Src:
	-$(RM) ./Inc/MCAL/RCC/Src/RCC_program.cyclo ./Inc/MCAL/RCC/Src/RCC_program.d ./Inc/MCAL/RCC/Src/RCC_program.o ./Inc/MCAL/RCC/Src/RCC_program.su

.PHONY: clean-Inc-2f-MCAL-2f-RCC-2f-Src

