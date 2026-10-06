include("${CMAKE_CURRENT_LIST_DIR}/rule.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/file.cmake")

set(test_low_power_modes_default_library_list )

# Handle files with suffix s, for group default-XC32
if(test_low_power_modes_default_default_XC32_FILE_TYPE_assemble)
add_library(test_low_power_modes_default_default_XC32_assemble OBJECT ${test_low_power_modes_default_default_XC32_FILE_TYPE_assemble})
    test_low_power_modes_default_default_XC32_assemble_rule(test_low_power_modes_default_default_XC32_assemble)
    list(APPEND test_low_power_modes_default_library_list "$<TARGET_OBJECTS:test_low_power_modes_default_default_XC32_assemble>")

endif()

# Handle files with suffix S, for group default-XC32
if(test_low_power_modes_default_default_XC32_FILE_TYPE_assembleWithPreprocess)
add_library(test_low_power_modes_default_default_XC32_assembleWithPreprocess OBJECT ${test_low_power_modes_default_default_XC32_FILE_TYPE_assembleWithPreprocess})
    test_low_power_modes_default_default_XC32_assembleWithPreprocess_rule(test_low_power_modes_default_default_XC32_assembleWithPreprocess)
    list(APPEND test_low_power_modes_default_library_list "$<TARGET_OBJECTS:test_low_power_modes_default_default_XC32_assembleWithPreprocess>")

endif()

# Handle files with suffix [cC], for group default-XC32
if(test_low_power_modes_default_default_XC32_FILE_TYPE_compile)
add_library(test_low_power_modes_default_default_XC32_compile OBJECT ${test_low_power_modes_default_default_XC32_FILE_TYPE_compile})
    test_low_power_modes_default_default_XC32_compile_rule(test_low_power_modes_default_default_XC32_compile)
    list(APPEND test_low_power_modes_default_library_list "$<TARGET_OBJECTS:test_low_power_modes_default_default_XC32_compile>")

endif()

# Handle files with suffix cpp, for group default-XC32
if(test_low_power_modes_default_default_XC32_FILE_TYPE_compile_cpp)
add_library(test_low_power_modes_default_default_XC32_compile_cpp OBJECT ${test_low_power_modes_default_default_XC32_FILE_TYPE_compile_cpp})
    test_low_power_modes_default_default_XC32_compile_cpp_rule(test_low_power_modes_default_default_XC32_compile_cpp)
    list(APPEND test_low_power_modes_default_library_list "$<TARGET_OBJECTS:test_low_power_modes_default_default_XC32_compile_cpp>")

endif()

# Handle files with suffix [cC], for group default-XC32
if(test_low_power_modes_default_default_XC32_FILE_TYPE_dependentObject)
add_library(test_low_power_modes_default_default_XC32_dependentObject OBJECT ${test_low_power_modes_default_default_XC32_FILE_TYPE_dependentObject})
    test_low_power_modes_default_default_XC32_dependentObject_rule(test_low_power_modes_default_default_XC32_dependentObject)
    list(APPEND test_low_power_modes_default_library_list "$<TARGET_OBJECTS:test_low_power_modes_default_default_XC32_dependentObject>")

endif()


# Main target for this project
add_executable(test_low_power_modes_default_image_z_SkxH5k ${test_low_power_modes_default_library_list})

set_target_properties(test_low_power_modes_default_image_z_SkxH5k PROPERTIES
    OUTPUT_NAME "default"
    SUFFIX ".elf"
    RUNTIME_OUTPUT_DIRECTORY "${test_low_power_modes_default_output_dir}")
target_link_libraries(test_low_power_modes_default_image_z_SkxH5k PRIVATE ${test_low_power_modes_default_default_XC32_FILE_TYPE_link})
# Add the link options from the rule file.
test_low_power_modes_default_link_rule( test_low_power_modes_default_image_z_SkxH5k)

# Add bin2hex target for converting built file to a .hex file.
string(REGEX REPLACE [.]elf$ .hex test_low_power_modes_default_image_name_hex ${test_low_power_modes_default_image_name})
add_custom_target(test_low_power_modes_default_Bin2Hex ALL
    COMMAND ${MP_BIN2HEX} \"${test_low_power_modes_default_output_dir}/${test_low_power_modes_default_image_name}\"
    BYPRODUCTS ${test_low_power_modes_default_output_dir}/${test_low_power_modes_default_image_name_hex}
    COMMENT "Convert built file to .hex")
add_dependencies(test_low_power_modes_default_Bin2Hex test_low_power_modes_default_image_z_SkxH5k)




# The following step will be performed after each build if final image is rebuilt
add_custom_command(TARGET test_low_power_modes_default_Bin2Hex POST_BUILD
    COMMAND ${MP_CC_DIR}/xc32-objcopy -O binary \"out\\test_low_power_modes\"/default.elf \"out\\test_low_power_modes\"/harmony.bin
    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/../../../..)
