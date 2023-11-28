################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Inc/MCAL/SYSTICK/src/SysTick_prog.c 

OBJS += \
./Inc/MCAL/SYSTICK/src/SysTick_prog.o 

C_DEPS += \
./Inc/MCAL/SYSTICK/src/SysTick_prog.d 


# Each subdirectory must supply rules for building sources it contributes
Inc/MCAL/SYSTICK/src/%.o Inc/MCAL/SYSTICK/src/%.su Inc/MCAL/SYSTICK/src/%.cyclo: ../Inc/MCAL/SYSTICK/src/%.c Inc/MCAL/SYSTICK/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Inc-2f-MCAL-2f-SYSTICK-2f-src

clean-Inc-2f-MCAL-2f-SYSTICK-2f-src:
	-$(RM) ./Inc/MCAL/SYSTICK/src/SysTick_prog.cyclo ./Inc/MCAL/SYSTICK/src/SysTick_prog.d ./Inc/MCAL/SYSTICK/src/SysTick_prog.o ./Inc/MCAL/SYSTICK/src/SysTick_prog.su

.PHONY: clean-Inc-2f-MCAL-2f-SYSTICK-2f-src

