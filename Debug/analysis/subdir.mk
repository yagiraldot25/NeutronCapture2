################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_UPPER_SRCS += \
../analysis/Plot_01.C \
../analysis/Plot_02.C 

OBJS += \
./analysis/Plot_01.o \
./analysis/Plot_02.o 

C_UPPER_DEPS += \
./analysis/Plot_01.d \
./analysis/Plot_02.d 


# Each subdirectory must supply rules for building sources it contributes
analysis/%.o: ../analysis/%.C
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/Cellar/geant4/10.5.1/include/Geant4 -I/usr/local/Cellar/root/6.20.00_3/include/root -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


