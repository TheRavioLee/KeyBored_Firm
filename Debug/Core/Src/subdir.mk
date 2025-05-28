################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Processus_Keys.c \
../Core/Src/Processus_LEDS.c \
../Core/Src/ServiceBaseTemps_1ms.c \
../Core/Src/interfaceDebouncing.c \
../Core/Src/interfaceMatrice.c \
../Core/Src/interface_HID_Report.c \
../Core/Src/interface_Key_Config.c \
../Core/Src/interface_RGB.c \
../Core/Src/main.c \
../Core/Src/pilote_COL.c \
../Core/Src/pilote_ROW.c \
../Core/Src/pilote_SK6803.c \
../Core/Src/pilote_Timer14_1ms.c \
../Core/Src/stm32f0xx_hal_msp.c \
../Core/Src/stm32f0xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f0xx.c 

OBJS += \
./Core/Src/Processus_Keys.o \
./Core/Src/Processus_LEDS.o \
./Core/Src/ServiceBaseTemps_1ms.o \
./Core/Src/interfaceDebouncing.o \
./Core/Src/interfaceMatrice.o \
./Core/Src/interface_HID_Report.o \
./Core/Src/interface_Key_Config.o \
./Core/Src/interface_RGB.o \
./Core/Src/main.o \
./Core/Src/pilote_COL.o \
./Core/Src/pilote_ROW.o \
./Core/Src/pilote_SK6803.o \
./Core/Src/pilote_Timer14_1ms.o \
./Core/Src/stm32f0xx_hal_msp.o \
./Core/Src/stm32f0xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f0xx.o 

C_DEPS += \
./Core/Src/Processus_Keys.d \
./Core/Src/Processus_LEDS.d \
./Core/Src/ServiceBaseTemps_1ms.d \
./Core/Src/interfaceDebouncing.d \
./Core/Src/interfaceMatrice.d \
./Core/Src/interface_HID_Report.d \
./Core/Src/interface_Key_Config.d \
./Core/Src/interface_RGB.d \
./Core/Src/main.d \
./Core/Src/pilote_COL.d \
./Core/Src/pilote_ROW.d \
./Core/Src/pilote_SK6803.d \
./Core/Src/pilote_Timer14_1ms.d \
./Core/Src/stm32f0xx_hal_msp.d \
./Core/Src/stm32f0xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f0xx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F072xB -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/HID/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/Processus_Keys.cyclo ./Core/Src/Processus_Keys.d ./Core/Src/Processus_Keys.o ./Core/Src/Processus_Keys.su ./Core/Src/Processus_LEDS.cyclo ./Core/Src/Processus_LEDS.d ./Core/Src/Processus_LEDS.o ./Core/Src/Processus_LEDS.su ./Core/Src/ServiceBaseTemps_1ms.cyclo ./Core/Src/ServiceBaseTemps_1ms.d ./Core/Src/ServiceBaseTemps_1ms.o ./Core/Src/ServiceBaseTemps_1ms.su ./Core/Src/interfaceDebouncing.cyclo ./Core/Src/interfaceDebouncing.d ./Core/Src/interfaceDebouncing.o ./Core/Src/interfaceDebouncing.su ./Core/Src/interfaceMatrice.cyclo ./Core/Src/interfaceMatrice.d ./Core/Src/interfaceMatrice.o ./Core/Src/interfaceMatrice.su ./Core/Src/interface_HID_Report.cyclo ./Core/Src/interface_HID_Report.d ./Core/Src/interface_HID_Report.o ./Core/Src/interface_HID_Report.su ./Core/Src/interface_Key_Config.cyclo ./Core/Src/interface_Key_Config.d ./Core/Src/interface_Key_Config.o ./Core/Src/interface_Key_Config.su ./Core/Src/interface_RGB.cyclo ./Core/Src/interface_RGB.d ./Core/Src/interface_RGB.o ./Core/Src/interface_RGB.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/pilote_COL.cyclo ./Core/Src/pilote_COL.d ./Core/Src/pilote_COL.o ./Core/Src/pilote_COL.su ./Core/Src/pilote_ROW.cyclo ./Core/Src/pilote_ROW.d ./Core/Src/pilote_ROW.o ./Core/Src/pilote_ROW.su ./Core/Src/pilote_SK6803.cyclo ./Core/Src/pilote_SK6803.d ./Core/Src/pilote_SK6803.o ./Core/Src/pilote_SK6803.su ./Core/Src/pilote_Timer14_1ms.cyclo ./Core/Src/pilote_Timer14_1ms.d ./Core/Src/pilote_Timer14_1ms.o ./Core/Src/pilote_Timer14_1ms.su ./Core/Src/stm32f0xx_hal_msp.cyclo ./Core/Src/stm32f0xx_hal_msp.d ./Core/Src/stm32f0xx_hal_msp.o ./Core/Src/stm32f0xx_hal_msp.su ./Core/Src/stm32f0xx_it.cyclo ./Core/Src/stm32f0xx_it.d ./Core/Src/stm32f0xx_it.o ./Core/Src/stm32f0xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f0xx.cyclo ./Core/Src/system_stm32f0xx.d ./Core/Src/system_stm32f0xx.o ./Core/Src/system_stm32f0xx.su

.PHONY: clean-Core-2f-Src

