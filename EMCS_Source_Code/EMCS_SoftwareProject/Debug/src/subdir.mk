################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Ram.c \
../src/adc_thread_entry.c \
../src/guiapp_event_handlers.c \
../src/hal_entry.c \
../src/main_thread_entry.c \
../src/pwm_thread_entry.c \
../src/rpm_thread_entry.c 

OBJS += \
./src/Ram.o \
./src/adc_thread_entry.o \
./src/guiapp_event_handlers.o \
./src/hal_entry.o \
./src/main_thread_entry.o \
./src/pwm_thread_entry.o \
./src/rpm_thread_entry.o 

C_DEPS += \
./src/Ram.d \
./src/adc_thread_entry.d \
./src/guiapp_event_handlers.d \
./src/hal_entry.d \
./src/main_thread_entry.d \
./src/pwm_thread_entry.d \
./src/rpm_thread_entry.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	C:\Renesas\Synergy\e2studio_v6.2.1_ssp_v1.5.0\eclipse\../Utilities/isdebuild arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal  -g3 -DSF_MESSAGE_CLASS -I../GUIApp/synergy_cfg/ssp_cfg/bsp/ -I../GUIApp/synergy_cfg/ssp_cfg/driver/ -I../GUIApp/synergy/ssp/inc/ -I../GUIApp/synergy/ssp/inc/bsp/ -I../GUIApp/synergy/ssp/inc/bsp/cmsis/Include/ -I../GUIApp/synergy/ssp/inc/driver/api/ -I../GUIApp/synergy/ssp/inc/driver/instances/ -I../GUIApp/synergy_cfg/ssp_cfg/framework/el/ -I../GUIApp/synergy/ssp/inc/framework/el/ -I../GUIApp/synergy/ssp/src/framework/el/tx/ -I../GUIApp/synergy_cfg/ssp_cfg/framework/ -I../GUIApp/synergy/ssp/inc/framework/api/ -I../GUIApp/synergy/ssp/inc/framework/instances/ -I../GUIApp/synergy_cfg/ssp_cfg/framework/tes/ -I../GUIApp/synergy/ssp/inc/framework/tes/ -I../GUIApp/synergy_cfg/framework/ -I../GUIApp/synergy_cfg/ssp_cfg/framework -I../GUIApp/synergy/ssp/inc/framework/api -I../GUIApp/synergy/ssp/inc/framework/instances -I../GUIApp/synergy_cfg/ssp_cfg/framework/tes -I../GUIApp/synergy/ssp/inc/framework/tes -I../GUIApp/synergy_cfg/ssp_cfg/framework/el -I../GUIApp/synergy/ssp/inc/framework/el -I../GUIApp/synergy/ssp/src/framework/el/tx -I../GUIApp/synergy_cfg/ssp_cfg/bsp -I../GUIApp/synergy_cfg/ssp_cfg/driver -I../GUIApp/synergy/ssp/inc -I../GUIApp/synergy/ssp/inc/bsp -I../GUIApp/synergy/ssp/inc/bsp/cmsis/Include -I../GUIApp/synergy/ssp/inc/driver/api -I../GUIApp/synergy/ssp/inc/driver/instances -I"D:\Documentos\Proyecto_Integrador_DSE_2019\EMCS_Source_Code\EMCS_SoftwareProject\synergy_cfg\ssp_cfg\framework" -I"D:\Documentos\Proyecto_Integrador_DSE_2019\EMCS_Source_Code\EMCS_SoftwareProject\synergy\ssp\inc\framework\api" -I"D:\Documentos\Proyecto_Integrador_DSE_2019\EMCS_Source_Code\EMCS_SoftwareProject\synergy\ssp\inc\framework\instances" -I"D:\Documentos\Proyecto_Integrador_DSE_2019\EMCS_Source_Code\EMCS_SoftwareProject\synergy\ssp\inc\framework\tes" -I"D:\Documentos\Proyecto_Integrador_DSE_2019\EMCS_Source_Code\EMCS_SoftwareProject\synergy_cfg\ssp_cfg\framework\el" -I"D:\Documentos\Proyecto_Integrador_DSE_2019\EMCS_Source_Code\EMCS_SoftwareProject\synergy\ssp\inc\framework\el" -I"D:\Documentos\Proyecto_Integrador_DSE_2019\EMCS_Source_Code\EMCS_SoftwareProject\synergy\ssp\src\framework\el\tx" -I"D:\Documentos\Proyecto_Integrador_DSE_2019\EMCS_Source_Code\EMCS_SoftwareProject\synergy_cfg\ssp_cfg\bsp" -I"D:\Documentos\Proyecto_Integrador_DSE_2019\EMCS_Source_Code\EMCS_SoftwareProject\synergy_cfg\ssp_cfg\driver" -I"D:\Documentos\Proyecto_Integrador_DSE_2019\EMCS_Source_Code\EMCS_SoftwareProject\synergy\ssp\inc" -I"D:\Documentos\Proyecto_Integrador_DSE_2019\EMCS_Source_Code\EMCS_SoftwareProject\synergy\ssp\inc\bsp" -I"D:\Documentos\Proyecto_Integrador_DSE_2019\EMCS_Source_Code\EMCS_SoftwareProject\synergy\ssp\inc\bsp\cmsis\Include" -I"D:\Documentos\Proyecto_Integrador_DSE_2019\EMCS_Source_Code\EMCS_SoftwareProject\synergy\ssp\inc\driver\api" -I"D:\Documentos\Proyecto_Integrador_DSE_2019\EMCS_Source_Code\EMCS_SoftwareProject\synergy\ssp\inc\driver\instances" -I"D:\Documentos\Proyecto_Integrador_DSE_2019\EMCS_Source_Code\EMCS_SoftwareProject\src" -I"D:\Documentos\Proyecto_Integrador_DSE_2019\EMCS_Source_Code\EMCS_SoftwareProject\src\synergy_gen" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" -x c "$<"
	@echo 'Finished building: $<'
	@echo ' '


