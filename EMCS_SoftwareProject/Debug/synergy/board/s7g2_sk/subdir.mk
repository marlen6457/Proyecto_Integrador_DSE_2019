################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../synergy/board/s7g2_sk/bsp_init.c \
../synergy/board/s7g2_sk/bsp_leds.c \
../synergy/board/s7g2_sk/bsp_qspi.c 

OBJS += \
./synergy/board/s7g2_sk/bsp_init.o \
./synergy/board/s7g2_sk/bsp_leds.o \
./synergy/board/s7g2_sk/bsp_qspi.o 

C_DEPS += \
./synergy/board/s7g2_sk/bsp_init.d \
./synergy/board/s7g2_sk/bsp_leds.d \
./synergy/board/s7g2_sk/bsp_qspi.d 


# Each subdirectory must supply rules for building sources it contributes
synergy/board/s7g2_sk/%.o: ../synergy/board/s7g2_sk/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	C:\Renesas\Synergy\e2studio_v6.2.1_ssp_v1.5.0\eclipse\../Utilities/isdebuild arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal  -g3 -DSF_MESSAGE_CLASS -I../GUIApp/synergy_cfg/ssp_cfg/bsp/ -I../GUIApp/synergy_cfg/ssp_cfg/driver/ -I../GUIApp/synergy/ssp/inc/ -I../GUIApp/synergy/ssp/inc/bsp/ -I../GUIApp/synergy/ssp/inc/bsp/cmsis/Include/ -I../GUIApp/synergy/ssp/inc/driver/api/ -I../GUIApp/synergy/ssp/inc/driver/instances/ -I../GUIApp/synergy_cfg/ssp_cfg/framework/el/ -I../GUIApp/synergy/ssp/inc/framework/el/ -I../GUIApp/synergy/ssp/src/framework/el/tx/ -I../GUIApp/synergy_cfg/ssp_cfg/framework/ -I../GUIApp/synergy/ssp/inc/framework/api/ -I../GUIApp/synergy/ssp/inc/framework/instances/ -I../GUIApp/synergy_cfg/ssp_cfg/framework/tes/ -I../GUIApp/synergy/ssp/inc/framework/tes/ -I../GUIApp/synergy_cfg/framework/ -I../GUIApp/synergy_cfg/ssp_cfg/framework -I../GUIApp/synergy/ssp/inc/framework/api -I../GUIApp/synergy/ssp/inc/framework/instances -I../GUIApp/synergy_cfg/ssp_cfg/framework/tes -I../GUIApp/synergy/ssp/inc/framework/tes -I../GUIApp/synergy_cfg/ssp_cfg/framework/el -I../GUIApp/synergy/ssp/inc/framework/el -I../GUIApp/synergy/ssp/src/framework/el/tx -I../GUIApp/synergy_cfg/ssp_cfg/bsp -I../GUIApp/synergy_cfg/ssp_cfg/driver -I../GUIApp/synergy/ssp/inc -I../GUIApp/synergy/ssp/inc/bsp -I../GUIApp/synergy/ssp/inc/bsp/cmsis/Include -I../GUIApp/synergy/ssp/inc/driver/api -I../GUIApp/synergy/ssp/inc/driver/instances -I"D:\Documentos\Proyecto_Integrador_DSE_2019\EMCS_SoftwareProject\synergy_cfg\ssp_cfg\framework" -I"D:\Documentos\Proyecto_Integrador_DSE_2019\EMCS_SoftwareProject\synergy\ssp\inc\framework\api" -I"D:\Documentos\Proyecto_Integrador_DSE_2019\EMCS_SoftwareProject\synergy\ssp\inc\framework\instances" -I"D:\Documentos\Proyecto_Integrador_DSE_2019\EMCS_SoftwareProject\synergy\ssp\inc\framework\tes" -I"D:\Documentos\Proyecto_Integrador_DSE_2019\EMCS_SoftwareProject\synergy_cfg\ssp_cfg\framework\el" -I"D:\Documentos\Proyecto_Integrador_DSE_2019\EMCS_SoftwareProject\synergy\ssp\inc\framework\el" -I"D:\Documentos\Proyecto_Integrador_DSE_2019\EMCS_SoftwareProject\synergy\ssp\src\framework\el\tx" -I"D:\Documentos\Proyecto_Integrador_DSE_2019\EMCS_SoftwareProject\synergy_cfg\ssp_cfg\bsp" -I"D:\Documentos\Proyecto_Integrador_DSE_2019\EMCS_SoftwareProject\synergy_cfg\ssp_cfg\driver" -I"D:\Documentos\Proyecto_Integrador_DSE_2019\EMCS_SoftwareProject\synergy\ssp\inc" -I"D:\Documentos\Proyecto_Integrador_DSE_2019\EMCS_SoftwareProject\synergy\ssp\inc\bsp" -I"D:\Documentos\Proyecto_Integrador_DSE_2019\EMCS_SoftwareProject\synergy\ssp\inc\bsp\cmsis\Include" -I"D:\Documentos\Proyecto_Integrador_DSE_2019\EMCS_SoftwareProject\synergy\ssp\inc\driver\api" -I"D:\Documentos\Proyecto_Integrador_DSE_2019\EMCS_SoftwareProject\synergy\ssp\inc\driver\instances" -I"D:\Documentos\Proyecto_Integrador_DSE_2019\EMCS_SoftwareProject\src" -I"D:\Documentos\Proyecto_Integrador_DSE_2019\EMCS_SoftwareProject\src\synergy_gen" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" -x c "$<"
	@echo 'Finished building: $<'
	@echo ' '


