################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Inc/MCAL/GPIO/GPIO_program.c 

OBJS += \
./Inc/MCAL/GPIO/GPIO_program.o 

C_DEPS += \
./Inc/MCAL/GPIO/GPIO_program.d 


# Each subdirectory must supply rules for building sources it contributes
Inc/MCAL/GPIO/%.o Inc/MCAL/GPIO/%.su Inc/MCAL/GPIO/%.cyclo: ../Inc/MCAL/GPIO/%.c Inc/MCAL/GPIO/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Inc-2f-MCAL-2f-GPIO

clean-Inc-2f-MCAL-2f-GPIO:
	-$(RM) ./Inc/MCAL/GPIO/GPIO_program.cyclo ./Inc/MCAL/GPIO/GPIO_program.d ./Inc/MCAL/GPIO/GPIO_program.o ./Inc/MCAL/GPIO/GPIO_program.su

.PHONY: clean-Inc-2f-MCAL-2f-GPIO

