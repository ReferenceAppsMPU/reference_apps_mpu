set(DEPENDENT_MP_BIN2HEXsam9x75_test_qspi_default_QSIdgsz5 "c:/Program Files/Microchip/xc32/v4.60/bin/xc32-bin2hex.exe")
set(DEPENDENT_DEPENDENT_TARGET_ELFsam9x75_test_qspi_default_QSIdgsz5 "${CMAKE_CURRENT_LIST_DIR}/../../../../out/sam9x75_test_qspi/default.elf")
set(DEPENDENT_TARGET_DIRsam9x75_test_qspi_default_QSIdgsz5 "${CMAKE_CURRENT_LIST_DIR}/../../../../out/sam9x75_test_qspi")
set(DEPENDENT_BYPRODUCTSsam9x75_test_qspi_default_QSIdgsz5 ${DEPENDENT_TARGET_DIRsam9x75_test_qspi_default_QSIdgsz5}/${sourceFileNamesam9x75_test_qspi_default_QSIdgsz5}.c)
add_custom_command(
    OUTPUT ${DEPENDENT_TARGET_DIRsam9x75_test_qspi_default_QSIdgsz5}/${sourceFileNamesam9x75_test_qspi_default_QSIdgsz5}.c
    COMMAND ${DEPENDENT_MP_BIN2HEXsam9x75_test_qspi_default_QSIdgsz5} --image ${DEPENDENT_DEPENDENT_TARGET_ELFsam9x75_test_qspi_default_QSIdgsz5} --image-generated-c ${sourceFileNamesam9x75_test_qspi_default_QSIdgsz5}.c --image-generated-h ${sourceFileNamesam9x75_test_qspi_default_QSIdgsz5}.h --image-copy-mode ${modesam9x75_test_qspi_default_QSIdgsz5} --image-offset ${addresssam9x75_test_qspi_default_QSIdgsz5} 
    WORKING_DIRECTORY ${DEPENDENT_TARGET_DIRsam9x75_test_qspi_default_QSIdgsz5}
    DEPENDS ${DEPENDENT_DEPENDENT_TARGET_ELFsam9x75_test_qspi_default_QSIdgsz5})
add_custom_target(
    dependent_produced_source_artifactsam9x75_test_qspi_default_QSIdgsz5 
    DEPENDS ${DEPENDENT_TARGET_DIRsam9x75_test_qspi_default_QSIdgsz5}/${sourceFileNamesam9x75_test_qspi_default_QSIdgsz5}.c
    )
