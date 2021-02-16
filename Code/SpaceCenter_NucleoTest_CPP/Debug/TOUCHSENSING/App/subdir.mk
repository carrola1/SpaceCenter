################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../TOUCHSENSING/App/stmCriticalSection.c \
../TOUCHSENSING/App/touchsensing.c \
../TOUCHSENSING/App/tsl_user.c 

C_DEPS += \
./TOUCHSENSING/App/stmCriticalSection.d \
./TOUCHSENSING/App/touchsensing.d \
./TOUCHSENSING/App/tsl_user.d 

OBJS += \
./TOUCHSENSING/App/stmCriticalSection.o \
./TOUCHSENSING/App/touchsensing.o \
./TOUCHSENSING/App/tsl_user.o 


# Each subdirectory must supply rules for building sources it contributes
TOUCHSENSING/App/stmCriticalSection.o: ../TOUCHSENSING/App/stmCriticalSection.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F042x6 -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I../TOUCHSENSING/App -I../Middlewares/ST/STM32_TouchSensing_Library/inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"TOUCHSENSING/App/stmCriticalSection.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
TOUCHSENSING/App/touchsensing.o: ../TOUCHSENSING/App/touchsensing.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F042x6 -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I../TOUCHSENSING/App -I../Middlewares/ST/STM32_TouchSensing_Library/inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"TOUCHSENSING/App/touchsensing.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
TOUCHSENSING/App/tsl_user.o: ../TOUCHSENSING/App/tsl_user.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F042x6 -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I../TOUCHSENSING/App -I../Middlewares/ST/STM32_TouchSensing_Library/inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"TOUCHSENSING/App/tsl_user.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

