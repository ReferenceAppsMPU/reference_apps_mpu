# The following functions contains all the flags passed to the different build stages.

set(PACK_REPO_PATH "C:/Users/I76461/.mchp_packs" CACHE PATH "Path to the root of a pack repository.")

function(sama7d65_led_button_default_default_XC32_assemble_rule target)
    set(options
        "-g"
        "${ASSEMBLER_PRE}"
        "-mprocessor=SAMA7D65"
        "-Wa,--defsym=__MPLAB_BUILD=1${MP_EXTRA_AS_POST}"
        "-mdfp=${PACK_REPO_PATH}/Microchip/SAMA7D65_DFP/1.12.120")
    list(REMOVE_ITEM options "")
    target_compile_options(${target} PRIVATE "${options}")
endfunction()
function(sama7d65_led_button_default_default_XC32_assembleWithPreprocess_rule target)
    set(options
        "-x"
        "assembler-with-cpp"
        "-g"
        "${MP_EXTRA_AS_PRE}"
        "-mdfp=${PACK_REPO_PATH}/Microchip/SAMA7D65_DFP/1.12.120"
        "-mprocessor=SAMA7D65"
        "-Wa,--defsym=__MPLAB_BUILD=1${MP_EXTRA_AS_POST}")
    list(REMOVE_ITEM options "")
    target_compile_options(${target} PRIVATE "${options}")
    target_compile_definitions(${target} PRIVATE "XPRJ_default=default")
endfunction()
function(sama7d65_led_button_default_default_XC32_compile_rule target)
    set(options
        "-g"
        "${CC_PRE}"
        "-x"
        "c"
        "-c"
        "-mprocessor=SAMA7D65"
        "-ffunction-sections"
        "-fdata-sections"
        "-O1"
        "-marm"
        "-mdfp=${PACK_REPO_PATH}/Microchip/SAMA7D65_DFP/1.12.120")
    list(REMOVE_ITEM options "")
    target_compile_options(${target} PRIVATE "${options}")
    target_compile_definitions(${target} PRIVATE "XPRJ_default=default")
    target_include_directories(${target}
        PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../../config.mcc/src"
        PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../../config.mcc/src/config/default"
        PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../../config.mcc/src/packs/CMSIS"
        PRIVATE "config.mcc/src/packs/CMSIS/CMSIS/Core_A/Include"
        PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../../config.mcc/src/packs/SAMA7D65_DFP"
        PRIVATE "${PACK_REPO_PATH}/ARM/CMSIS/6.3.0/CMSIS/Core/Include")
endfunction()
function(sama7d65_led_button_default_default_XC32_compile_cpp_rule target)
    set(options
        "-g"
        "${CC_PRE}"
        "-mprocessor=SAMA7D65"
        "-frtti"
        "-fexceptions"
        "-fno-check-new"
        "-fenforce-eh-specs"
        "-ffunction-sections"
        "-O1"
        "-fno-common"
        "-marm"
        "-mdfp=${PACK_REPO_PATH}/Microchip/SAMA7D65_DFP/1.12.120")
    list(REMOVE_ITEM options "")
    target_compile_options(${target} PRIVATE "${options}")
    target_compile_definitions(${target} PRIVATE "XPRJ_default=default")
    target_include_directories(${target}
        PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../../config.mcc/src"
        PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../../config.mcc/src/config/default"
        PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../../config.mcc/src/packs/CMSIS"
        PRIVATE "config.mcc/src/packs/CMSIS/CMSIS/Core_A/Include"
        PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../../config.mcc/src/packs/SAMA7D65_DFP"
        PRIVATE "${PACK_REPO_PATH}/ARM/CMSIS/6.3.0/CMSIS/Core/Include")
endfunction()
function(sama7d65_led_button_default_dependentObject_rule target)
    set(options
        "-mprocessor=SAMA7D65"
        "-mdfp=${PACK_REPO_PATH}/Microchip/SAMA7D65_DFP/1.12.120")
    list(REMOVE_ITEM options "")
    target_compile_options(${target} PRIVATE "${options}")
endfunction()
function(sama7d65_led_button_default_link_rule target)
    set(options
        "-g"
        "${MP_EXTRA_LD_PRE}"
        "-mprocessor=SAMA7D65"
        "-mno-device-startup-code"
        "-Wl,--defsym=__MPLAB_BUILD=1${MP_EXTRA_LD_POST},--script=${sama7d65_led_button_default_LINKER_SCRIPT},--defsym=_min_heap_size=512,--gc-sections,-Map=mem.map,--report-mem,--memorysummary,memoryfile.xml"
        "-mdfp=${PACK_REPO_PATH}/Microchip/SAMA7D65_DFP/1.12.120")
    list(REMOVE_ITEM options "")
    target_link_options(${target} PRIVATE "${options}")
    target_compile_definitions(${target} PRIVATE "XPRJ_default=default")
endfunction()
