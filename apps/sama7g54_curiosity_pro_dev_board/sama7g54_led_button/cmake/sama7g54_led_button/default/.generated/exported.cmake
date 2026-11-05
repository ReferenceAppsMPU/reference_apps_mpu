set(DEPENDENT_MP_BIN2HEXsama7g54_led_button_default_yWjSazPV "c:/Program Files/Microchip/xc32/v5.10/bin/xc32-bin2hex.exe")
set(DEPENDENT_DEPENDENT_TARGET_ELFsama7g54_led_button_default_yWjSazPV ${CMAKE_CURRENT_LIST_DIR}/../../../../out/sama7g54_led_button/default.elf)
set(DEPENDENT_TARGET_DIRsama7g54_led_button_default_yWjSazPV ${CMAKE_CURRENT_LIST_DIR}/../../../../out/sama7g54_led_button)
set(DEPENDENT_BYPRODUCTSsama7g54_led_button_default_yWjSazPV ${DEPENDENT_TARGET_DIRsama7g54_led_button_default_yWjSazPV}/${sourceFileNamesama7g54_led_button_default_yWjSazPV}.c)
add_custom_command(
    OUTPUT ${DEPENDENT_TARGET_DIRsama7g54_led_button_default_yWjSazPV}/${sourceFileNamesama7g54_led_button_default_yWjSazPV}.c
    COMMAND ${DEPENDENT_MP_BIN2HEXsama7g54_led_button_default_yWjSazPV} --image ${DEPENDENT_DEPENDENT_TARGET_ELFsama7g54_led_button_default_yWjSazPV} --image-generated-c ${sourceFileNamesama7g54_led_button_default_yWjSazPV}.c --image-generated-h ${sourceFileNamesama7g54_led_button_default_yWjSazPV}.h --image-copy-mode ${modesama7g54_led_button_default_yWjSazPV} --image-offset ${addresssama7g54_led_button_default_yWjSazPV} 
    WORKING_DIRECTORY ${DEPENDENT_TARGET_DIRsama7g54_led_button_default_yWjSazPV}
    DEPENDS ${DEPENDENT_DEPENDENT_TARGET_ELFsama7g54_led_button_default_yWjSazPV})
add_custom_target(
    dependent_produced_source_artifactsama7g54_led_button_default_yWjSazPV 
    DEPENDS ${DEPENDENT_TARGET_DIRsama7g54_led_button_default_yWjSazPV}/${sourceFileNamesama7g54_led_button_default_yWjSazPV}.c
    )
