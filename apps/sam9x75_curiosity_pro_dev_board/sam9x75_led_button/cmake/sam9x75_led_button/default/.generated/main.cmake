include("${CMAKE_CURRENT_LIST_DIR}/rule.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/file.cmake")

set(sam9x75_led_button_default_library_list )

# Handle files with suffix s, for group default-XC32
if(sam9x75_led_button_default_default_XC32_FILE_TYPE_assemble)
add_library(sam9x75_led_button_default_default_XC32_assemble OBJECT ${sam9x75_led_button_default_default_XC32_FILE_TYPE_assemble})
    sam9x75_led_button_default_default_XC32_assemble_rule(sam9x75_led_button_default_default_XC32_assemble)
    list(APPEND sam9x75_led_button_default_library_list "$<TARGET_OBJECTS:sam9x75_led_button_default_default_XC32_assemble>")

endif()

# Handle files with suffix S, for group default-XC32
if(sam9x75_led_button_default_default_XC32_FILE_TYPE_assembleWithPreprocess)
add_library(sam9x75_led_button_default_default_XC32_assembleWithPreprocess OBJECT ${sam9x75_led_button_default_default_XC32_FILE_TYPE_assembleWithPreprocess})
    sam9x75_led_button_default_default_XC32_assembleWithPreprocess_rule(sam9x75_led_button_default_default_XC32_assembleWithPreprocess)
    list(APPEND sam9x75_led_button_default_library_list "$<TARGET_OBJECTS:sam9x75_led_button_default_default_XC32_assembleWithPreprocess>")

endif()

# Handle files with suffix [cC], for group default-XC32
if(sam9x75_led_button_default_default_XC32_FILE_TYPE_compile)
add_library(sam9x75_led_button_default_default_XC32_compile OBJECT ${sam9x75_led_button_default_default_XC32_FILE_TYPE_compile})
    sam9x75_led_button_default_default_XC32_compile_rule(sam9x75_led_button_default_default_XC32_compile)
    list(APPEND sam9x75_led_button_default_library_list "$<TARGET_OBJECTS:sam9x75_led_button_default_default_XC32_compile>")

endif()

# Handle files with suffix cpp, for group default-XC32
if(sam9x75_led_button_default_default_XC32_FILE_TYPE_compile_cpp)
add_library(sam9x75_led_button_default_default_XC32_compile_cpp OBJECT ${sam9x75_led_button_default_default_XC32_FILE_TYPE_compile_cpp})
    sam9x75_led_button_default_default_XC32_compile_cpp_rule(sam9x75_led_button_default_default_XC32_compile_cpp)
    list(APPEND sam9x75_led_button_default_library_list "$<TARGET_OBJECTS:sam9x75_led_button_default_default_XC32_compile_cpp>")

endif()

# Handle files with suffix [cC], for group default-XC32
if(sam9x75_led_button_default_default_XC32_FILE_TYPE_dependentObject)
add_library(sam9x75_led_button_default_default_XC32_dependentObject OBJECT ${sam9x75_led_button_default_default_XC32_FILE_TYPE_dependentObject})
    sam9x75_led_button_default_default_XC32_dependentObject_rule(sam9x75_led_button_default_default_XC32_dependentObject)
    list(APPEND sam9x75_led_button_default_library_list "$<TARGET_OBJECTS:sam9x75_led_button_default_default_XC32_dependentObject>")

endif()


# Main target for this project
add_executable(sam9x75_led_button_default_image_gjtWIpn2 ${sam9x75_led_button_default_library_list})

set_target_properties(sam9x75_led_button_default_image_gjtWIpn2 PROPERTIES
    OUTPUT_NAME "default"
    SUFFIX ".elf"
    RUNTIME_OUTPUT_DIRECTORY "${sam9x75_led_button_default_output_dir}")
target_link_libraries(sam9x75_led_button_default_image_gjtWIpn2 PRIVATE ${sam9x75_led_button_default_default_XC32_FILE_TYPE_link})
# Add the link options from the rule file.
sam9x75_led_button_default_link_rule( sam9x75_led_button_default_image_gjtWIpn2)

# Add bin2hex target for converting built file to a .hex file.
string(REGEX REPLACE [.]elf$ .hex sam9x75_led_button_default_image_name_hex ${sam9x75_led_button_default_image_name})
add_custom_target(sam9x75_led_button_default_Bin2Hex ALL
    COMMAND ${MP_BIN2HEX} \"${sam9x75_led_button_default_output_dir}/${sam9x75_led_button_default_image_name}\"
    BYPRODUCTS ${sam9x75_led_button_default_output_dir}/${sam9x75_led_button_default_image_name_hex}
    COMMENT "Convert built file to .hex")
add_dependencies(sam9x75_led_button_default_Bin2Hex sam9x75_led_button_default_image_gjtWIpn2)




# The following step will be performed after each build if final image is rebuilt
add_custom_command(TARGET sam9x75_led_button_default_Bin2Hex POST_BUILD
    COMMAND ${MP_CC_DIR}/xc32-objcopy -O binary \"out\\sam9x75_led_button\"/default.elf \"out\\sam9x75_led_button\"/harmony.bin
    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/../../../..)
