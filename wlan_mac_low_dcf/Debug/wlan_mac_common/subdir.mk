################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/EDK_Projects/RefDes/SDK_Workspace/wlan_mac_shared/wlan_mac_common/wlan_mac_ipc_util.c 

OBJS += \
./wlan_mac_common/wlan_mac_ipc_util.o 

C_DEPS += \
./wlan_mac_common/wlan_mac_ipc_util.d 


# Each subdirectory must supply rules for building sources it contributes
wlan_mac_common/wlan_mac_ipc_util.o: D:/EDK_Projects/RefDes/SDK_Workspace/wlan_mac_shared/wlan_mac_common/wlan_mac_ipc_util.c
	@echo Building file: $<
	@echo Invoking: MicroBlaze gcc compiler
	mb-gcc -Wall -O2 -g3 -I"D:\EDK_Projects\RefDes\SDK_Workspace\wlan_mac_shared\wlan_mac_common\include" -I"D:\EDK_Projects\RefDes\SDK_Workspace\wlan_mac_shared\wlan_mac_low_framework\include" -I"D:\EDK_Projects\RefDes\SDK_Workspace\wlan_mac_low_dcf\src\include" -c -fmessage-length=0 -Wl,--no-relax -I../../wlan_bsp_cpu_low/mb_low/include -mlittle-endian -mxl-barrel-shift -mxl-pattern-compare -mno-xl-soft-div -mcpu=v8.40.b -mno-xl-soft-mul -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo Finished building: $<
	@echo ' '


