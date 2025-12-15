set(DEPENDENT_MP_BIN2HEXsam9x75_test_qspi_default_PTVdlW8w "c:/Program Files/Microchip/xc32/v4.60/bin/xc32-bin2hex.exe")
set(DEPENDENT_DEPENDENT_TARGET_ELFsam9x75_test_qspi_default_PTVdlW8w ${CMAKE_CURRENT_LIST_DIR}/../../../../out/sam9x75_test_qspi/default.elf)
set(DEPENDENT_TARGET_DIRsam9x75_test_qspi_default_PTVdlW8w ${CMAKE_CURRENT_LIST_DIR}/../../../../out/sam9x75_test_qspi)
set(DEPENDENT_BYPRODUCTSsam9x75_test_qspi_default_PTVdlW8w ${DEPENDENT_TARGET_DIRsam9x75_test_qspi_default_PTVdlW8w}/${sourceFileNamesam9x75_test_qspi_default_PTVdlW8w}.c)
add_custom_command(
    OUTPUT ${DEPENDENT_TARGET_DIRsam9x75_test_qspi_default_PTVdlW8w}/${sourceFileNamesam9x75_test_qspi_default_PTVdlW8w}.c
    COMMAND ${DEPENDENT_MP_BIN2HEXsam9x75_test_qspi_default_PTVdlW8w} --image ${DEPENDENT_DEPENDENT_TARGET_ELFsam9x75_test_qspi_default_PTVdlW8w} --image-generated-c ${sourceFileNamesam9x75_test_qspi_default_PTVdlW8w}.c --image-generated-h ${sourceFileNamesam9x75_test_qspi_default_PTVdlW8w}.h --image-copy-mode ${modesam9x75_test_qspi_default_PTVdlW8w} --image-offset ${addresssam9x75_test_qspi_default_PTVdlW8w} 
    WORKING_DIRECTORY ${DEPENDENT_TARGET_DIRsam9x75_test_qspi_default_PTVdlW8w}
    DEPENDS ${DEPENDENT_DEPENDENT_TARGET_ELFsam9x75_test_qspi_default_PTVdlW8w})
add_custom_target(
    dependent_produced_source_artifactsam9x75_test_qspi_default_PTVdlW8w 
    DEPENDS ${DEPENDENT_TARGET_DIRsam9x75_test_qspi_default_PTVdlW8w}/${sourceFileNamesam9x75_test_qspi_default_PTVdlW8w}.c
    )
