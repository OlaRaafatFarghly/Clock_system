################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Inc/HAL/RTC/RTC_program.c 

OBJS += \
./Inc/HAL/RTC/RTC_program.o 

C_DEPS += \
./Inc/HAL/RTC/RTC_program.d 


# Each subdirectory must supply rules for building sources it contributes
Inc/HAL/RTC/%.o Inc/HAL/RTC/%.su Inc/HAL/RTC/%.cyclo: ../Inc/HAL/RTC/%.c Inc/HAL/RTC/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Inc-2f-HAL-2f-RTC

clean-Inc-2f-HAL-2f-RTC:
	-$(RM) ./Inc/HAL/RTC/RTC_program.cyclo ./Inc/HAL/RTC/RTC_program.d ./Inc/HAL/RTC/RTC_program.o ./Inc/HAL/RTC/RTC_program.su

.PHONY: clean-Inc-2f-HAL-2f-RTC

