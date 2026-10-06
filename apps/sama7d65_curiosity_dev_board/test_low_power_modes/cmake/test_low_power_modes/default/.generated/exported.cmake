set(DEPENDENT_MP_BIN2HEXtest_low_power_modes_default_z_SkxH5k "c:/Program Files/Microchip/xc32/v5.10/bin/xc32-bin2hex.exe")
set(DEPENDENT_DEPENDENT_TARGET_ELFtest_low_power_modes_default_z_SkxH5k ${CMAKE_CURRENT_LIST_DIR}/../../../../out/test_low_power_modes/default.elf)
set(DEPENDENT_TARGET_DIRtest_low_power_modes_default_z_SkxH5k ${CMAKE_CURRENT_LIST_DIR}/../../../../out/test_low_power_modes)
set(DEPENDENT_BYPRODUCTStest_low_power_modes_default_z_SkxH5k ${DEPENDENT_TARGET_DIRtest_low_power_modes_default_z_SkxH5k}/${sourceFileNametest_low_power_modes_default_z_SkxH5k}.c)
add_custom_command(
    OUTPUT ${DEPENDENT_TARGET_DIRtest_low_power_modes_default_z_SkxH5k}/${sourceFileNametest_low_power_modes_default_z_SkxH5k}.c
    COMMAND ${DEPENDENT_MP_BIN2HEXtest_low_power_modes_default_z_SkxH5k} --image ${DEPENDENT_DEPENDENT_TARGET_ELFtest_low_power_modes_default_z_SkxH5k} --image-generated-c ${sourceFileNametest_low_power_modes_default_z_SkxH5k}.c --image-generated-h ${sourceFileNametest_low_power_modes_default_z_SkxH5k}.h --image-copy-mode ${modetest_low_power_modes_default_z_SkxH5k} --image-offset ${addresstest_low_power_modes_default_z_SkxH5k} 
    WORKING_DIRECTORY ${DEPENDENT_TARGET_DIRtest_low_power_modes_default_z_SkxH5k}
    DEPENDS ${DEPENDENT_DEPENDENT_TARGET_ELFtest_low_power_modes_default_z_SkxH5k})
add_custom_target(
    dependent_produced_source_artifacttest_low_power_modes_default_z_SkxH5k 
    DEPENDS ${DEPENDENT_TARGET_DIRtest_low_power_modes_default_z_SkxH5k}/${sourceFileNametest_low_power_modes_default_z_SkxH5k}.c
    )
