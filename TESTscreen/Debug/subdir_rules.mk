################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1030/ccs/tools/compiler/ti-cgt-arm_20.2.4.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/CCSworkspace/TESTscreen" --include_path="C:/CCSworkspace/TESTscreen/Debug" --include_path="C:/ti/simplelink_msp432p4_sdk_3_30_00_13/source" --include_path="C:/ti/simplelink_msp432p4_sdk_3_30_00_13/source/third_party/CMSIS/Include" --include_path="C:/ti/simplelink_sdk_lvgl_plugin_3_30_00_06/source" --include_path="C:/ti/simplelink_sdk_lvgl_plugin_3_30_00_06/source/third_party" --include_path="C:/ti/simplelink_sdk_lvgl_plugin_3_30_00_06/source/third_party/lvgl" --include_path="C:/ti/simplelink_msp432p4_sdk_3_30_00_13/source/ti/posix/ccs" --include_path="C:/ti/ccs1030/ccs/tools/compiler/ti-cgt-arm_20.2.4.LTS/include" --advice:power=none --define=LV_CONF_INCLUDE_SIMPLE -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" --include_path="C:/CCSworkspace/TESTscreen/Debug/syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

build-221797217: ../kentectouchwidgets.syscfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: SysConfig'
	"C:/ti/ccs1030/ccs/utils/sysconfig_1.8.0/sysconfig_cli.bat" -s "C:/ti/simplelink_msp432p4_sdk_3_30_00_13/.metadata/product.json" -s "C:/ti/simplelink_sdk_lvgl_plugin_3_30_00_06/.metadata/product.json" -s "C:/ti/simplelink_msp432p4_sdk_3_30_00_13/.metadata/product.json" --script "C:/CCSworkspace/TESTscreen/kentectouchwidgets.syscfg" -o "syscfg"
	@echo 'Finished building: "$<"'
	@echo ' '

syscfg/ti_drivers_config.c: build-221797217 ../kentectouchwidgets.syscfg
syscfg/ti_drivers_config.h: build-221797217
syscfg/syscfg_c.rov.xs: build-221797217
syscfg/lv_conf.h: build-221797217
syscfg/lv_drv_conf.h: build-221797217
syscfg/ti_lvgl_disp_interface.c: build-221797217
syscfg/ti_lvgl_disp_interface.h: build-221797217
syscfg/ti_lvgl_ssd2119_disp.c: build-221797217
syscfg/lv_port_disp.h: build-221797217
syscfg/lv_port_indev.c: build-221797217
syscfg/lv_port_indev.h: build-221797217
syscfg/: build-221797217

syscfg/%.obj: ./syscfg/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1030/ccs/tools/compiler/ti-cgt-arm_20.2.4.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/CCSworkspace/TESTscreen" --include_path="C:/CCSworkspace/TESTscreen/Debug" --include_path="C:/ti/simplelink_msp432p4_sdk_3_30_00_13/source" --include_path="C:/ti/simplelink_msp432p4_sdk_3_30_00_13/source/third_party/CMSIS/Include" --include_path="C:/ti/simplelink_sdk_lvgl_plugin_3_30_00_06/source" --include_path="C:/ti/simplelink_sdk_lvgl_plugin_3_30_00_06/source/third_party" --include_path="C:/ti/simplelink_sdk_lvgl_plugin_3_30_00_06/source/third_party/lvgl" --include_path="C:/ti/simplelink_msp432p4_sdk_3_30_00_13/source/ti/posix/ccs" --include_path="C:/ti/ccs1030/ccs/tools/compiler/ti-cgt-arm_20.2.4.LTS/include" --advice:power=none --define=LV_CONF_INCLUDE_SIMPLE -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="syscfg/$(basename $(<F)).d_raw" --include_path="C:/CCSworkspace/TESTscreen/Debug/syscfg" --obj_directory="syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


