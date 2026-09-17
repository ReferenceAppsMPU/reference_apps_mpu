include("${CMAKE_CURRENT_LIST_DIR}/rule.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/file.cmake")

set(sama7d65_led_button_default_library_list )

# Handle files with suffix s, for group default-XC32
if(sama7d65_led_button_default_default_XC32_FILE_TYPE_assemble)
add_library(sama7d65_led_button_default_default_XC32_assemble OBJECT ${sama7d65_led_button_default_default_XC32_FILE_TYPE_assemble})
    sama7d65_led_button_default_default_XC32_assemble_rule(sama7d65_led_button_default_default_XC32_assemble)
    list(APPEND sama7d65_led_button_default_library_list "$<TARGET_OBJECTS:sama7d65_led_button_default_default_XC32_assemble>")

endif()

# Handle files with suffix S, for group default-XC32
if(sama7d65_led_button_default_default_XC32_FILE_TYPE_assembleWithPreprocess)
add_library(sama7d65_led_button_default_default_XC32_assembleWithPreprocess OBJECT ${sama7d65_led_button_default_default_XC32_FILE_TYPE_assembleWithPreprocess})
    sama7d65_led_button_default_default_XC32_assembleWithPreprocess_rule(sama7d65_led_button_default_default_XC32_assembleWithPreprocess)
    list(APPEND sama7d65_led_button_default_library_list "$<TARGET_OBJECTS:sama7d65_led_button_default_default_XC32_assembleWithPreprocess>")

endif()

# Handle files with suffix [cC], for group default-XC32
if(sama7d65_led_button_default_default_XC32_FILE_TYPE_compile)
add_library(sama7d65_led_button_default_default_XC32_compile OBJECT ${sama7d65_led_button_default_default_XC32_FILE_TYPE_compile})
    sama7d65_led_button_default_default_XC32_compile_rule(sama7d65_led_button_default_default_XC32_compile)
    list(APPEND sama7d65_led_button_default_library_list "$<TARGET_OBJECTS:sama7d65_led_button_default_default_XC32_compile>")

endif()

# Handle files with suffix cpp, for group default-XC32
if(sama7d65_led_button_default_default_XC32_FILE_TYPE_compile_cpp)
add_library(sama7d65_led_button_default_default_XC32_compile_cpp OBJECT ${sama7d65_led_button_default_default_XC32_FILE_TYPE_compile_cpp})
    sama7d65_led_button_default_default_XC32_compile_cpp_rule(sama7d65_led_button_default_default_XC32_compile_cpp)
    list(APPEND sama7d65_led_button_default_library_list "$<TARGET_OBJECTS:sama7d65_led_button_default_default_XC32_compile_cpp>")

endif()

# Handle files with suffix [cC], for group default-XC32
if(sama7d65_led_button_default_default_XC32_FILE_TYPE_dependentObject)
add_library(sama7d65_led_button_default_default_XC32_dependentObject OBJECT ${sama7d65_led_button_default_default_XC32_FILE_TYPE_dependentObject})
    sama7d65_led_button_default_default_XC32_dependentObject_rule(sama7d65_led_button_default_default_XC32_dependentObject)
    list(APPEND sama7d65_led_button_default_library_list "$<TARGET_OBJECTS:sama7d65_led_button_default_default_XC32_dependentObject>")

endif()


# Main target for this project
add_executable(sama7d65_led_button_default_image_sW8JVgLP ${sama7d65_led_button_default_library_list})

set_target_properties(sama7d65_led_button_default_image_sW8JVgLP PROPERTIES
    OUTPUT_NAME "default"
    SUFFIX ".elf"
    RUNTIME_OUTPUT_DIRECTORY "${sama7d65_led_button_default_output_dir}")
target_link_libraries(sama7d65_led_button_default_image_sW8JVgLP PRIVATE ${sama7d65_led_button_default_default_XC32_FILE_TYPE_link})
# Add the link options from the rule file.
sama7d65_led_button_default_link_rule( sama7d65_led_button_default_image_sW8JVgLP)

# Add bin2hex target for converting built file to a .hex file.
string(REGEX REPLACE [.]elf$ .hex sama7d65_led_button_default_image_name_hex ${sama7d65_led_button_default_image_name})
add_custom_target(sama7d65_led_button_default_Bin2Hex ALL
    COMMAND ${MP_BIN2HEX} \"${sama7d65_led_button_default_output_dir}/${sama7d65_led_button_default_image_name}\"
    BYPRODUCTS ${sama7d65_led_button_default_output_dir}/${sama7d65_led_button_default_image_name_hex}
    COMMENT "Convert built file to .hex")
add_dependencies(sama7d65_led_button_default_Bin2Hex sama7d65_led_button_default_image_sW8JVgLP)




# The following step will be performed after each build if final image is rebuilt
add_custom_command(TARGET sama7d65_led_button_default_Bin2Hex POST_BUILD
    COMMAND ${MP_CC_DIR}/xc32-objcopy -O binary \"out\\sama7d65_led_button\"/default.elf \"out\\sama7d65_led_button\"/harmony.bin
    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/../../../..)
