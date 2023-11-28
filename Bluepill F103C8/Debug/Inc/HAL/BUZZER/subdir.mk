################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Inc/HAL/BUZZER/BUZZER_program.c 

OBJS += \
./Inc/HAL/BUZZER/BUZZER_program.o 

C_DEPS += \
./Inc/HAL/BUZZER/BUZZER_program.d 


# Each subdirectory must supply rules for building sources it contributes
Inc/HAL/BUZZER/%.o Inc/HAL/BUZZER/%.su Inc/HAL/BUZZER/%.cyclo: ../Inc/HAL/BUZZER/%.c Inc/HAL/BUZZER/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Inc-2f-HAL-2f-BUZZER

clean-Inc-2f-HAL-2f-BUZZER:
	-$(RM) ./Inc/HAL/BUZZER/BUZZER_program.cyclo ./Inc/HAL/BUZZER/BUZZER_program.d ./Inc/HAL/BUZZER/BUZZER_program.o ./Inc/HAL/BUZZER/BUZZER_program.su

.PHONY: clean-Inc-2f-HAL-2f-BUZZER

