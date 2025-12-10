# The following variables contains the files used by the different stages of the build process.
set(sam9x75_test_qspi_default_default_XC32_FILE_TYPE_assemble)
set_source_files_properties(${sam9x75_test_qspi_default_default_XC32_FILE_TYPE_assemble} PROPERTIES LANGUAGE ASM)

# For assembly files, add "." to the include path for each file so that .include with a relative path works
foreach(source_file ${sam9x75_test_qspi_default_default_XC32_FILE_TYPE_assemble})
        set_source_files_properties(${source_file} PROPERTIES INCLUDE_DIRECTORIES "$<PATH:NORMAL_PATH,$<PATH:REMOVE_FILENAME,${source_file}>>")
endforeach()

set(sam9x75_test_qspi_default_default_XC32_FILE_TYPE_assembleWithPreprocess "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/src/config/default/cstartup.S")
set_source_files_properties(${sam9x75_test_qspi_default_default_XC32_FILE_TYPE_assembleWithPreprocess} PROPERTIES LANGUAGE ASM)

# For assembly files, add "." to the include path for each file so that .include with a relative path works
foreach(source_file ${sam9x75_test_qspi_default_default_XC32_FILE_TYPE_assembleWithPreprocess})
        set_source_files_properties(${source_file} PROPERTIES INCLUDE_DIRECTORIES "$<PATH:NORMAL_PATH,$<PATH:REMOVE_FILENAME,${source_file}>>")
endforeach()

set(sam9x75_test_qspi_default_default_XC32_FILE_TYPE_compile
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/src/app.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/src/config/default/bsp/bsp.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/src/config/default/fault_handlers.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/src/config/default/initialization.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/src/config/default/interrupts.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/src/config/default/peripheral/aic/plib_aic.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/src/config/default/peripheral/clk/plib_clk.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/src/config/default/peripheral/mmu/plib_mmu.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/src/config/default/peripheral/pio/plib_pio.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/src/config/default/peripheral/pit/plib_pit.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/src/config/default/peripheral/qspi/plib_qspi.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/src/config/default/stdio/xc32_monitor.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/src/main.c")
set_source_files_properties(${sam9x75_test_qspi_default_default_XC32_FILE_TYPE_compile} PROPERTIES LANGUAGE C)
set(sam9x75_test_qspi_default_default_XC32_FILE_TYPE_compile_cpp)
set_source_files_properties(${sam9x75_test_qspi_default_default_XC32_FILE_TYPE_compile_cpp} PROPERTIES LANGUAGE CXX)
set(sam9x75_test_qspi_default_default_XC32_FILE_TYPE_link)
set(sam9x75_test_qspi_default_default_XC32_FILE_TYPE_bin2hex)

# The linker script used for the build.
set(sam9x75_test_qspi_default_LINKER_SCRIPT "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/src/config/default/ddram.ld")
set(sam9x75_test_qspi_default_image_name "default.elf")
set(sam9x75_test_qspi_default_image_base_name "default")

# The output directory of the final image.
set(sam9x75_test_qspi_default_output_dir "${CMAKE_CURRENT_SOURCE_DIR}/../../../out/sam9x75_test_qspi")

# The full path to the final image.
set(sam9x75_test_qspi_default_full_path_to_image ${sam9x75_test_qspi_default_output_dir}/${sam9x75_test_qspi_default_image_name})
