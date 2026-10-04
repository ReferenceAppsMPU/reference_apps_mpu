set(DEPENDENT_MP_BIN2HEXsam9x75_led_button_default_gjtWIpn2 "c:/Program Files/Microchip/xc32/v5.10/bin/xc32-bin2hex.exe")
set(DEPENDENT_DEPENDENT_TARGET_ELFsam9x75_led_button_default_gjtWIpn2 ${CMAKE_CURRENT_LIST_DIR}/../../../../out/sam9x75_led_button/default.elf)
set(DEPENDENT_TARGET_DIRsam9x75_led_button_default_gjtWIpn2 ${CMAKE_CURRENT_LIST_DIR}/../../../../out/sam9x75_led_button)
set(DEPENDENT_BYPRODUCTSsam9x75_led_button_default_gjtWIpn2 ${DEPENDENT_TARGET_DIRsam9x75_led_button_default_gjtWIpn2}/${sourceFileNamesam9x75_led_button_default_gjtWIpn2}.c)
add_custom_command(
    OUTPUT ${DEPENDENT_TARGET_DIRsam9x75_led_button_default_gjtWIpn2}/${sourceFileNamesam9x75_led_button_default_gjtWIpn2}.c
    COMMAND ${DEPENDENT_MP_BIN2HEXsam9x75_led_button_default_gjtWIpn2} --image ${DEPENDENT_DEPENDENT_TARGET_ELFsam9x75_led_button_default_gjtWIpn2} --image-generated-c ${sourceFileNamesam9x75_led_button_default_gjtWIpn2}.c --image-generated-h ${sourceFileNamesam9x75_led_button_default_gjtWIpn2}.h --image-copy-mode ${modesam9x75_led_button_default_gjtWIpn2} --image-offset ${addresssam9x75_led_button_default_gjtWIpn2} 
    WORKING_DIRECTORY ${DEPENDENT_TARGET_DIRsam9x75_led_button_default_gjtWIpn2}
    DEPENDS ${DEPENDENT_DEPENDENT_TARGET_ELFsam9x75_led_button_default_gjtWIpn2})
add_custom_target(
    dependent_produced_source_artifactsam9x75_led_button_default_gjtWIpn2 
    DEPENDS ${DEPENDENT_TARGET_DIRsam9x75_led_button_default_gjtWIpn2}/${sourceFileNamesam9x75_led_button_default_gjtWIpn2}.c
    )
