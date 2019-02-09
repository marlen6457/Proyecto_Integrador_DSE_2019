################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../synergy/ssp/src/bsp/mcu/all/bsp_common.c \
../synergy/ssp/src/bsp/mcu/all/bsp_common_leds.c \
../synergy/ssp/src/bsp/mcu/all/bsp_delay.c \
../synergy/ssp/src/bsp/mcu/all/bsp_irq.c \
../synergy/ssp/src/bsp/mcu/all/bsp_locking.c \
../synergy/ssp/src/bsp/mcu/all/bsp_register_protection.c \
../synergy/ssp/src/bsp/mcu/all/bsp_sbrk.c 

OBJS += \
./synergy/ssp/src/bsp/mcu/all/bsp_common.o \
./synergy/ssp/src/bsp/mcu/all/bsp_common_leds.o \
./synergy/ssp/src/bsp/mcu/all/bsp_delay.o \
./synergy/ssp/src/bsp/mcu/all/bsp_irq.o \
./synergy/ssp/src/bsp/mcu/all/bsp_locking.o \
./synergy/ssp/src/bsp/mcu/all/bsp_register_protection.o \
./synergy/ssp/src/bsp/mcu/all/bsp_sbrk.o 

C_DEPS += \
./synergy/ssp/src/bsp/mcu/all/bsp_common.d \
./synergy/ssp/src/bsp/mcu/all/bsp_common_leds.d \
./synergy/ssp/src/bsp/mcu/all/bsp_delay.d \
./synergy/ssp/src/bsp/mcu/all/bsp_irq.d \
./synergy/ssp/src/bsp/mcu/all/bsp_locking.d \
./synergy/ssp/src/bsp/mcu/all/bsp_register_protection.d \
./synergy/ssp/src/bsp/mcu/all/bsp_sbrk.d 


# Each subdirectory must supply rules for building sources it contributes
synergy/ssp/src/bsp/mcu/all/%.o: ../synergy/ssp/src/bsp/mcu/all/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	C:\Renesas\Synergy\e2studio_v6.2.1_ssp_v1.5.0\eclipse\../Utilities/isdebuild arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal  -g3 -DSF_MESSAGE_CLASS -I../GUIApp/synergy_cfg/ssp_cfg/bsp/ -I../GUIApp/synergy_cfg/ssp_cfg/driver/ -I../GUIApp/synergy/ssp/inc/ -I../GUIApp/synergy/ssp/inc/bsp/ -I../GUIApp/synergy/ssp/inc/bsp/cmsis/Include/ -I../GUIApp/synergy/ssp/inc/driver/api/ -I../GUIApp/synergy/ssp/inc/driver/instances/ -I../GUIApp/synergy_cfg/ssp_cfg/framework/el/ -I../GUIApp/synergy/ssp/inc/framework/el/ -I../GUIApp/synergy/ssp/src/framework/el/tx/ -I../GUIApp/synergy_cfg/ssp_cfg/framework/ -I../GUIApp/synergy/ssp/inc/framework/api/ -I../GUIApp/synergy/ssp/inc/framework/instances/ -I../GUIApp/synergy_cfg/ssp_cfg/framework/tes/ -I../GUIApp/synergy/ssp/inc/framework/tes/ -I../GUIApp/synergy_cfg/framework/ -I../GUIApp/synergy_cfg/ssp_cfg/framework -I../GUIApp/synergy/ssp/inc/framework/api -I../GUIApp/synergy/ssp/inc/framework/instances -I../GUIApp/synergy_cfg/ssp_cfg/framework/tes -I../GUIApp/synergy/ssp/inc/framework/tes -I../GUIApp/synergy_cfg/ssp_cfg/framework/el -I../GUIApp/synergy/ssp/inc/framework/el -I../GUIApp/synergy/ssp/src/framework/el/tx -I../GUIApp/synergy_cfg/ssp_cfg/bsp -I../GUIApp/synergy_cfg/ssp_cfg/driver -I../GUIApp/synergy/ssp/inc -I../GUIApp/synergy/ssp/inc/bsp -I../GUIApp/synergy/ssp/inc/bsp/cmsis/Include -I../GUIApp/synergy/ssp/inc/driver/api -I../GUIApp/synergy/ssp/inc/driver/instances -I"C:\Users\JPRMEXDI\Documents\Repository\project_git\Proyecto_Integrador_DSE_2019_v2\EMCS_SoftwareProject\synergy_cfg\ssp_cfg\framework" -I"C:\Users\JPRMEXDI\Documents\Repository\project_git\Proyecto_Integrador_DSE_2019_v2\EMCS_SoftwareProject\synergy\ssp\inc\framework\api" -I"C:\Users\JPRMEXDI\Documents\Repository\project_git\Proyecto_Integrador_DSE_2019_v2\EMCS_SoftwareProject\synergy\ssp\inc\framework\instances" -I"C:\Users\JPRMEXDI\Documents\Repository\project_git\Proyecto_Integrador_DSE_2019_v2\EMCS_SoftwareProject\synergy\ssp\inc\framework\tes" -I"C:\Users\JPRMEXDI\Documents\Repository\project_git\Proyecto_Integrador_DSE_2019_v2\EMCS_SoftwareProject\synergy_cfg\ssp_cfg\framework\el" -I"C:\Users\JPRMEXDI\Documents\Repository\project_git\Proyecto_Integrador_DSE_2019_v2\EMCS_SoftwareProject\synergy\ssp\inc\framework\el" -I"C:\Users\JPRMEXDI\Documents\Repository\project_git\Proyecto_Integrador_DSE_2019_v2\EMCS_SoftwareProject\synergy\ssp\src\framework\el\tx" -I"C:\Users\JPRMEXDI\Documents\Repository\project_git\Proyecto_Integrador_DSE_2019_v2\EMCS_SoftwareProject\synergy_cfg\ssp_cfg\bsp" -I"C:\Users\JPRMEXDI\Documents\Repository\project_git\Proyecto_Integrador_DSE_2019_v2\EMCS_SoftwareProject\synergy_cfg\ssp_cfg\driver" -I"C:\Users\JPRMEXDI\Documents\Repository\project_git\Proyecto_Integrador_DSE_2019_v2\EMCS_SoftwareProject\synergy\ssp\inc" -I"C:\Users\JPRMEXDI\Documents\Repository\project_git\Proyecto_Integrador_DSE_2019_v2\EMCS_SoftwareProject\synergy\ssp\inc\bsp" -I"C:\Users\JPRMEXDI\Documents\Repository\project_git\Proyecto_Integrador_DSE_2019_v2\EMCS_SoftwareProject\synergy\ssp\inc\bsp\cmsis\Include" -I"C:\Users\JPRMEXDI\Documents\Repository\project_git\Proyecto_Integrador_DSE_2019_v2\EMCS_SoftwareProject\synergy\ssp\inc\driver\api" -I"C:\Users\JPRMEXDI\Documents\Repository\project_git\Proyecto_Integrador_DSE_2019_v2\EMCS_SoftwareProject\synergy\ssp\inc\driver\instances" -I"C:\Users\JPRMEXDI\Documents\Repository\project_git\Proyecto_Integrador_DSE_2019_v2\EMCS_SoftwareProject\src" -I"C:\Users\JPRMEXDI\Documents\Repository\project_git\Proyecto_Integrador_DSE_2019_v2\EMCS_SoftwareProject\src\synergy_gen" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" -x c "$<"
	@echo 'Finished building: $<'
	@echo ' '


