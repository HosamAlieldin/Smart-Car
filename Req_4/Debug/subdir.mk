################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Car_prog.c \
../DIO_prog.c \
../ICU_prog.c \
../INTERRUPT_prog.c \
../LCD.c \
../TIMER_prog.c \
../main.c 

OBJS += \
./Car_prog.o \
./DIO_prog.o \
./ICU_prog.o \
./INTERRUPT_prog.o \
./LCD.o \
./TIMER_prog.o \
./main.o 

C_DEPS += \
./Car_prog.d \
./DIO_prog.d \
./ICU_prog.d \
./INTERRUPT_prog.d \
./LCD.d \
./TIMER_prog.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


