set(DEPENDENT_MP_BIN2HEXsama7d65_led_button_default_sW8JVgLP "c:/Program Files/Microchip/xc32/v5.10/bin/xc32-bin2hex.exe")
set(DEPENDENT_DEPENDENT_TARGET_ELFsama7d65_led_button_default_sW8JVgLP ${CMAKE_CURRENT_LIST_DIR}/../../../../out/sama7d65_led_button/default.elf)
set(DEPENDENT_TARGET_DIRsama7d65_led_button_default_sW8JVgLP ${CMAKE_CURRENT_LIST_DIR}/../../../../out/sama7d65_led_button)
set(DEPENDENT_BYPRODUCTSsama7d65_led_button_default_sW8JVgLP ${DEPENDENT_TARGET_DIRsama7d65_led_button_default_sW8JVgLP}/${sourceFileNamesama7d65_led_button_default_sW8JVgLP}.c)
add_custom_command(
    OUTPUT ${DEPENDENT_TARGET_DIRsama7d65_led_button_default_sW8JVgLP}/${sourceFileNamesama7d65_led_button_default_sW8JVgLP}.c
    COMMAND ${DEPENDENT_MP_BIN2HEXsama7d65_led_button_default_sW8JVgLP} --image ${DEPENDENT_DEPENDENT_TARGET_ELFsama7d65_led_button_default_sW8JVgLP} --image-generated-c ${sourceFileNamesama7d65_led_button_default_sW8JVgLP}.c --image-generated-h ${sourceFileNamesama7d65_led_button_default_sW8JVgLP}.h --image-copy-mode ${modesama7d65_led_button_default_sW8JVgLP} --image-offset ${addresssama7d65_led_button_default_sW8JVgLP} 
    WORKING_DIRECTORY ${DEPENDENT_TARGET_DIRsama7d65_led_button_default_sW8JVgLP}
    DEPENDS ${DEPENDENT_DEPENDENT_TARGET_ELFsama7d65_led_button_default_sW8JVgLP})
add_custom_target(
    dependent_produced_source_artifactsama7d65_led_button_default_sW8JVgLP 
    DEPENDS ${DEPENDENT_TARGET_DIRsama7d65_led_button_default_sW8JVgLP}/${sourceFileNamesama7d65_led_button_default_sW8JVgLP}.c
    )
