################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
008_Sprints_Req_4.lss \

FLASH_IMAGE += \
008_Sprints_Req_4.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: 008_Sprints_Req_4.elf secondary-outputs

# Tool invocations
008_Sprints_Req_4.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,008_Sprints_Req_4.map -mmcu=atmega32 -o "008_Sprints_Req_4.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

008_Sprints_Req_4.lss: 008_Sprints_Req_4.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S 008_Sprints_Req_4.elf  >"008_Sprints_Req_4.lss"
	@echo 'Finished building: $@'
	@echo ' '

008_Sprints_Req_4.hex: 008_Sprints_Req_4.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex 008_Sprints_Req_4.elf  "008_Sprints_Req_4.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: 008_Sprints_Req_4.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 008_Sprints_Req_4.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: 008_Sprints_Req_4.elf
	@echo 'Invoking: AVRDude'
	C:\WinAVR-20100110\bin\avrdude -pm32 -cusbasp -Uflash:w:008_Sprints_Req_4.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) 008_Sprints_Req_4.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
