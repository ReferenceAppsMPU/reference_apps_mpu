include("${CMAKE_CURRENT_LIST_DIR}/rule.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/file.cmake")

set(sama7g54_led_button_default_library_list )

set(OUTPUT_SUFFIX elf)
# Handle files with suffix s, for group default-XC32
if(sama7g54_led_button_default_default_XC32_FILE_TYPE_assemble)
add_library(sama7g54_led_button_default_default_XC32_assemble OBJECT ${sama7g54_led_button_default_default_XC32_FILE_TYPE_assemble})
    sama7g54_led_button_default_default_XC32_assemble_rule(sama7g54_led_button_default_default_XC32_assemble)
    list(APPEND sama7g54_led_button_default_library_list "$<TARGET_OBJECTS:sama7g54_led_button_default_default_XC32_assemble>")

endif()

# Handle files with suffix S, for group default-XC32
if(sama7g54_led_button_default_default_XC32_FILE_TYPE_assembleWithPreprocess)
add_library(sama7g54_led_button_default_default_XC32_assembleWithPreprocess OBJECT ${sama7g54_led_button_default_default_XC32_FILE_TYPE_assembleWithPreprocess})
    sama7g54_led_button_default_default_XC32_assembleWithPreprocess_rule(sama7g54_led_button_default_default_XC32_assembleWithPreprocess)
    list(APPEND sama7g54_led_button_default_library_list "$<TARGET_OBJECTS:sama7g54_led_button_default_default_XC32_assembleWithPreprocess>")

endif()

# Handle files with suffix [cC], for group default-XC32
if(sama7g54_led_button_default_default_XC32_FILE_TYPE_compile)
add_library(sama7g54_led_button_default_default_XC32_compile OBJECT ${sama7g54_led_button_default_default_XC32_FILE_TYPE_compile})
    sama7g54_led_button_default_default_XC32_compile_rule(sama7g54_led_button_default_default_XC32_compile)
    list(APPEND sama7g54_led_button_default_library_list "$<TARGET_OBJECTS:sama7g54_led_button_default_default_XC32_compile>")

endif()

# Handle files with suffix cpp, for group default-XC32
if(sama7g54_led_button_default_default_XC32_FILE_TYPE_compile_cpp)
add_library(sama7g54_led_button_default_default_XC32_compile_cpp OBJECT ${sama7g54_led_button_default_default_XC32_FILE_TYPE_compile_cpp})
    sama7g54_led_button_default_default_XC32_compile_cpp_rule(sama7g54_led_button_default_default_XC32_compile_cpp)
    list(APPEND sama7g54_led_button_default_library_list "$<TARGET_OBJECTS:sama7g54_led_button_default_default_XC32_compile_cpp>")

endif()

# Handle files with suffix [cC], for group default-XC32
if(sama7g54_led_button_default_default_XC32_FILE_TYPE_dependentObject)
add_library(sama7g54_led_button_default_default_XC32_dependentObject OBJECT ${sama7g54_led_button_default_default_XC32_FILE_TYPE_dependentObject})
    sama7g54_led_button_default_default_XC32_dependentObject_rule(sama7g54_led_button_default_default_XC32_dependentObject)
    list(APPEND sama7g54_led_button_default_library_list "$<TARGET_OBJECTS:sama7g54_led_button_default_default_XC32_dependentObject>")

endif()


# Main target for this project
add_executable(sama7g54_led_button_default_image_yWjSazPV ${sama7g54_led_button_default_library_list})

set_target_properties(sama7g54_led_button_default_image_yWjSazPV PROPERTIES
    OUTPUT_NAME "default"
    SUFFIX ".elf"
    RUNTIME_OUTPUT_DIRECTORY "${sama7g54_led_button_default_output_dir}")
target_link_libraries(sama7g54_led_button_default_image_yWjSazPV PRIVATE ${sama7g54_led_button_default_default_XC32_FILE_TYPE_link})
# Add the link options from the rule file.
sama7g54_led_button_default_link_rule( sama7g54_led_button_default_image_yWjSazPV)

# Add bin2hex target for converting built file to a .hex file.
string(REGEX REPLACE [.]elf$ .hex sama7g54_led_button_default_image_name_hex ${sama7g54_led_button_default_image_name})
add_custom_target(sama7g54_led_button_default_Bin2Hex ALL
    COMMAND ${MP_BIN2HEX} \"${sama7g54_led_button_default_output_dir}/${sama7g54_led_button_default_image_name}\"
    DEPENDS "${sama7g54_led_button_default_output_dir}/${sama7g54_led_button_default_image_name}"
    BYPRODUCTS ${sama7g54_led_button_default_output_dir}/${sama7g54_led_button_default_image_name_hex}
    COMMENT "Convert built file to .hex")
add_dependencies(sama7g54_led_button_default_Bin2Hex sama7g54_led_button_default_image_yWjSazPV)




# The following step will be performed after each build if final image is rebuilt
add_custom_command(TARGET sama7g54_led_button_default_Bin2Hex POST_BUILD
    COMMAND ${MP_CC_DIR}/xc32-objcopy -O binary \"out\\sama7g54_led_button\"/default.elf \"out\\sama7g54_led_button\"/harmony.bin
    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/../../../..)

