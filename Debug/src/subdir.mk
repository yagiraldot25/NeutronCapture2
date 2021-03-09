################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../src/N2ActionInitialization.cc \
../src/N2DetectorConstruction.cc \
../src/N2DetectorMessenger.cc \
../src/N2EventAction.cc \
../src/N2Material.cc \
../src/N2PrimaryGeneratorAction.cc 

CC_DEPS += \
./src/N2ActionInitialization.d \
./src/N2DetectorConstruction.d \
./src/N2DetectorMessenger.d \
./src/N2EventAction.d \
./src/N2Material.d \
./src/N2PrimaryGeneratorAction.d 

OBJS += \
./src/N2ActionInitialization.o \
./src/N2DetectorConstruction.o \
./src/N2DetectorMessenger.o \
./src/N2EventAction.o \
./src/N2Material.o \
./src/N2PrimaryGeneratorAction.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/Cellar/geant4/10.5.1/include/Geant4 -I/usr/local/Cellar/root/6.20.00_3/include/root -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


