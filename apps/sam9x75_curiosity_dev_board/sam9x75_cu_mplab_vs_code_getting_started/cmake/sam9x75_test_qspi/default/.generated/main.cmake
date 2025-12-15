# cmake files support debug production
include("${CMAKE_CURRENT_LIST_DIR}/rule.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/file.cmake")

set(sam9x75_test_qspi_default_library_list )

# Handle files with suffix s, for group default-XC32
if(sam9x75_test_qspi_default_default_XC32_FILE_TYPE_assemble)
add_library(sam9x75_test_qspi_default_default_XC32_assemble OBJECT ${sam9x75_test_qspi_default_default_XC32_FILE_TYPE_assemble})
    sam9x75_test_qspi_default_default_XC32_assemble_rule(sam9x75_test_qspi_default_default_XC32_assemble)
    list(APPEND sam9x75_test_qspi_default_library_list "$<TARGET_OBJECTS:sam9x75_test_qspi_default_default_XC32_assemble>")

endif()

# Handle files with suffix S, for group default-XC32
if(sam9x75_test_qspi_default_default_XC32_FILE_TYPE_assembleWithPreprocess)
add_library(sam9x75_test_qspi_default_default_XC32_assembleWithPreprocess OBJECT ${sam9x75_test_qspi_default_default_XC32_FILE_TYPE_assembleWithPreprocess})
    sam9x75_test_qspi_default_default_XC32_assembleWithPreprocess_rule(sam9x75_test_qspi_default_default_XC32_assembleWithPreprocess)
    list(APPEND sam9x75_test_qspi_default_library_list "$<TARGET_OBJECTS:sam9x75_test_qspi_default_default_XC32_assembleWithPreprocess>")

endif()

# Handle files with suffix [cC], for group default-XC32
if(sam9x75_test_qspi_default_default_XC32_FILE_TYPE_compile)
add_library(sam9x75_test_qspi_default_default_XC32_compile OBJECT ${sam9x75_test_qspi_default_default_XC32_FILE_TYPE_compile})
    sam9x75_test_qspi_default_default_XC32_compile_rule(sam9x75_test_qspi_default_default_XC32_compile)
    list(APPEND sam9x75_test_qspi_default_library_list "$<TARGET_OBJECTS:sam9x75_test_qspi_default_default_XC32_compile>")

endif()

# Handle files with suffix cpp, for group default-XC32
if(sam9x75_test_qspi_default_default_XC32_FILE_TYPE_compile_cpp)
add_library(sam9x75_test_qspi_default_default_XC32_compile_cpp OBJECT ${sam9x75_test_qspi_default_default_XC32_FILE_TYPE_compile_cpp})
    sam9x75_test_qspi_default_default_XC32_compile_cpp_rule(sam9x75_test_qspi_default_default_XC32_compile_cpp)
    list(APPEND sam9x75_test_qspi_default_library_list "$<TARGET_OBJECTS:sam9x75_test_qspi_default_default_XC32_compile_cpp>")

endif()

# Handle files with suffix [cC], for group default-XC32
if(sam9x75_test_qspi_default_default_XC32_FILE_TYPE_dependentObject)
add_library(sam9x75_test_qspi_default_default_XC32_dependentObject OBJECT ${sam9x75_test_qspi_default_default_XC32_FILE_TYPE_dependentObject})
    sam9x75_test_qspi_default_default_XC32_dependentObject_rule(sam9x75_test_qspi_default_default_XC32_dependentObject)
    list(APPEND sam9x75_test_qspi_default_library_list "$<TARGET_OBJECTS:sam9x75_test_qspi_default_default_XC32_dependentObject>")

endif()

# Handle files with suffix elf, for group default-XC32
if(sam9x75_test_qspi_default_default_XC32_FILE_TYPE_bin2hex)
add_library(sam9x75_test_qspi_default_default_XC32_bin2hex OBJECT ${sam9x75_test_qspi_default_default_XC32_FILE_TYPE_bin2hex})
    sam9x75_test_qspi_default_default_XC32_bin2hex_rule(sam9x75_test_qspi_default_default_XC32_bin2hex)
    list(APPEND sam9x75_test_qspi_default_library_list "$<TARGET_OBJECTS:sam9x75_test_qspi_default_default_XC32_bin2hex>")

endif()


# Main target for this project
add_executable(sam9x75_test_qspi_default_image_PTVdlW8w ${sam9x75_test_qspi_default_library_list})

if(NOT CMAKE_HOST_WIN32)
    set_target_properties(sam9x75_test_qspi_default_image_PTVdlW8w PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${sam9x75_test_qspi_default_output_dir})
endif()
set_target_properties(sam9x75_test_qspi_default_image_PTVdlW8w PROPERTIES OUTPUT_NAME "default")
set_target_properties(sam9x75_test_qspi_default_image_PTVdlW8w PROPERTIES SUFFIX ".elf")

target_link_libraries(sam9x75_test_qspi_default_image_PTVdlW8w PRIVATE ${sam9x75_test_qspi_default_default_XC32_FILE_TYPE_link})


# Add the link options from the rule file.
sam9x75_test_qspi_default_link_rule(sam9x75_test_qspi_default_image_PTVdlW8w)

# Call bin2hex function from the rule file
sam9x75_test_qspi_default_bin2hex_rule(sam9x75_test_qspi_default_image_PTVdlW8w)

if(CMAKE_HOST_WIN32)
    add_custom_command(
        TARGET sam9x75_test_qspi_default_image_PTVdlW8w
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory ${sam9x75_test_qspi_default_output_dir}
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:sam9x75_test_qspi_default_image_PTVdlW8w> ${sam9x75_test_qspi_default_output_dir}/${sam9x75_test_qspi_default_original_image_name}
        BYPRODUCTS ${sam9x75_test_qspi_default_output_dir}/${sam9x75_test_qspi_default_original_image_name}
        COMMENT "Copying elf to out location")
    set_property(
        TARGET sam9x75_test_qspi_default_image_PTVdlW8w
        APPEND PROPERTY ADDITIONAL_CLEAN_FILES
        ${sam9x75_test_qspi_default_output_dir}/${sam9x75_test_qspi_default_original_image_name})
endif()

# The following step will be performed after each build if final image is rebuilt
add_custom_command(TARGET sam9x75_test_qspi_default_Bin2Hex POST_BUILD
    COMMAND cmd.exe /C \"\"${MP_CC_DIR}/xc32-objcopy\" -O binary  \"out/sam9x75_test_qspi\"/default.elf \"out/sam9x75_test_qspi\"/harmony.bin\"
    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/../../../..)
