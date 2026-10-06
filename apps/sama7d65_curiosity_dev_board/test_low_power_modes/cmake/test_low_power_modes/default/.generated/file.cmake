# The following variables contains the files used by the different stages of the build process.
set(test_low_power_modes_default_default_XC32_FILE_TYPE_assemble)
set_source_files_properties(${test_low_power_modes_default_default_XC32_FILE_TYPE_assemble} PROPERTIES LANGUAGE ASM)

# For assembly files, add "." to the include path for each file so that .include with a relative path works
foreach(source_file ${test_low_power_modes_default_default_XC32_FILE_TYPE_assemble})
        set_source_files_properties(${source_file} PROPERTIES INCLUDE_DIRECTORIES "$<PATH:NORMAL_PATH,$<PATH:REMOVE_FILENAME,${source_file}>>")
endforeach()

set(test_low_power_modes_default_default_XC32_FILE_TYPE_assembleWithPreprocess "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/src/config/default/cstartup.S")
set_source_files_properties(${test_low_power_modes_default_default_XC32_FILE_TYPE_assembleWithPreprocess} PROPERTIES LANGUAGE ASM)

# For assembly files, add "." to the include path for each file so that .include with a relative path works
foreach(source_file ${test_low_power_modes_default_default_XC32_FILE_TYPE_assembleWithPreprocess})
        set_source_files_properties(${source_file} PROPERTIES INCLUDE_DIRECTORIES "$<PATH:NORMAL_PATH,$<PATH:REMOVE_FILENAME,${source_file}>>")
endforeach()

set(test_low_power_modes_default_default_XC32_FILE_TYPE_compile
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/src/backup.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/src/bsr.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/src/config/default/bsp/bsp.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/src/config/default/fault_handlers.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/src/config/default/initialization.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/src/config/default/interrupts.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/src/config/default/peripheral/adc/plib_adc.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/src/config/default/peripheral/clk/plib_clk.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/src/config/default/peripheral/dwdt/plib_dwdt.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/src/config/default/peripheral/flexcom/usart/plib_flexcom6_usart.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/src/config/default/peripheral/gic/plib_gic.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/src/config/default/peripheral/mmu/plib_mmu.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/src/config/default/peripheral/pio/plib_pio.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/src/config/default/peripheral/pit64b/plib_pit64b0.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/src/config/default/peripheral/rtc/plib_rtc.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/src/config/default/stdio/xc32_monitor.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/src/idle.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/src/main.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/src/ulp0.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/src/ulp1.c")
set_source_files_properties(${test_low_power_modes_default_default_XC32_FILE_TYPE_compile} PROPERTIES LANGUAGE C)
set(test_low_power_modes_default_default_XC32_FILE_TYPE_compile_cpp)
set_source_files_properties(${test_low_power_modes_default_default_XC32_FILE_TYPE_compile_cpp} PROPERTIES LANGUAGE CXX)
set(test_low_power_modes_default_default_XC32_FILE_TYPE_link)

# The linker script used for the build.
set(test_low_power_modes_default_LINKER_SCRIPT "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/src/config/default/ddr.ld")
set(test_low_power_modes_default_image_name "default.elf")
set(test_low_power_modes_default_image_base_name "default")

# The output directory of the final image.
set(test_low_power_modes_default_output_dir "${CMAKE_CURRENT_SOURCE_DIR}/../../../out/test_low_power_modes")

# The full path to the final image.
set(test_low_power_modes_default_full_path_to_image ${test_low_power_modes_default_output_dir}/${test_low_power_modes_default_image_name})
