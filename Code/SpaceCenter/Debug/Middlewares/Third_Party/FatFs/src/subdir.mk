################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/FatFs/src/ccsbcs.c \
../Middlewares/Third_Party/FatFs/src/diskio.c \
../Middlewares/Third_Party/FatFs/src/fat_sd_spi.c \
../Middlewares/Third_Party/FatFs/src/ff.c \
../Middlewares/Third_Party/FatFs/src/syscall.c \
../Middlewares/Third_Party/FatFs/src/unicode.c 

C_DEPS += \
./Middlewares/Third_Party/FatFs/src/ccsbcs.d \
./Middlewares/Third_Party/FatFs/src/diskio.d \
./Middlewares/Third_Party/FatFs/src/fat_sd_spi.d \
./Middlewares/Third_Party/FatFs/src/ff.d \
./Middlewares/Third_Party/FatFs/src/syscall.d \
./Middlewares/Third_Party/FatFs/src/unicode.d 

OBJS += \
./Middlewares/Third_Party/FatFs/src/ccsbcs.o \
./Middlewares/Third_Party/FatFs/src/diskio.o \
./Middlewares/Third_Party/FatFs/src/fat_sd_spi.o \
./Middlewares/Third_Party/FatFs/src/ff.o \
./Middlewares/Third_Party/FatFs/src/syscall.o \
./Middlewares/Third_Party/FatFs/src/unicode.o 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/FatFs/src/%.o Middlewares/Third_Party/FatFs/src/%.su Middlewares/Third_Party/FatFs/src/%.cyclo: ../Middlewares/Third_Party/FatFs/src/%.c Middlewares/Third_Party/FatFs/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L072xx -DDEBUG -c -I../Middlewares/Third_Party/FatFs/src -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -include../Middlewares/Third_Party/FatFs/src/ff.h -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Middlewares-2f-Third_Party-2f-FatFs-2f-src

clean-Middlewares-2f-Third_Party-2f-FatFs-2f-src:
	-$(RM) ./Middlewares/Third_Party/FatFs/src/ccsbcs.cyclo ./Middlewares/Third_Party/FatFs/src/ccsbcs.d ./Middlewares/Third_Party/FatFs/src/ccsbcs.o ./Middlewares/Third_Party/FatFs/src/ccsbcs.su ./Middlewares/Third_Party/FatFs/src/diskio.cyclo ./Middlewares/Third_Party/FatFs/src/diskio.d ./Middlewares/Third_Party/FatFs/src/diskio.o ./Middlewares/Third_Party/FatFs/src/diskio.su ./Middlewares/Third_Party/FatFs/src/fat_sd_spi.cyclo ./Middlewares/Third_Party/FatFs/src/fat_sd_spi.d ./Middlewares/Third_Party/FatFs/src/fat_sd_spi.o ./Middlewares/Third_Party/FatFs/src/fat_sd_spi.su ./Middlewares/Third_Party/FatFs/src/ff.cyclo ./Middlewares/Third_Party/FatFs/src/ff.d ./Middlewares/Third_Party/FatFs/src/ff.o ./Middlewares/Third_Party/FatFs/src/ff.su ./Middlewares/Third_Party/FatFs/src/syscall.cyclo ./Middlewares/Third_Party/FatFs/src/syscall.d ./Middlewares/Third_Party/FatFs/src/syscall.o ./Middlewares/Third_Party/FatFs/src/syscall.su ./Middlewares/Third_Party/FatFs/src/unicode.cyclo ./Middlewares/Third_Party/FatFs/src/unicode.d ./Middlewares/Third_Party/FatFs/src/unicode.o ./Middlewares/Third_Party/FatFs/src/unicode.su

.PHONY: clean-Middlewares-2f-Third_Party-2f-FatFs-2f-src

