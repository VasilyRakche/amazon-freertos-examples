cmake_minimum_required(VERSION 3.13)

set(MAIN_PROJECT_NAME freertos_examples)
#   Building:
#       cmake -S . -B build -DCMAKE_TOOLCHAIN_FILE=freertos/tools/cmake/toolchains/xtensa-esp32.cmake -GNinja  
#       add 2>&1 | tee /tmp/amazon_build.txt to the end for outputing in the log file aswell
#       OR:
#       idf.py -DVENDOR=espressif -DBOARD=esp32_devkitc -DCOMPILER=xtensa-esp32 build
#       idf.py -DCMAKE_TOOLCHAIN_FILE=freertos/tools/cmake/toolchains/xtensa-esp32.cmake build
project(${MAIN_PROJECT_NAME})


# Tell IDF build to link against this target.
set(IDF_PROJECT_EXECUTABLE ${MAIN_PROJECT_NAME})
set(IDF_EXECUTABLE_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/src/main.c)

# Add some extra components. IDF_EXTRA_COMPONENT_DIRS is an variable used by ESP-IDF
# to collect extra components.
get_filename_component(
    EXTRA_COMPONENT_DIRS
    "components/foo" ABSOLUTE
)
list(APPEND IDF_EXTRA_COMPONENT_DIRS ${EXTRA_COMPONENT_DIRS})

# As of now there's no offical way to redefine config files outside of FreeRTOS source tree.
# This is a temporary approach to inject an include path so that this takes precedence over the
# config file directory inside FreeRTOS.
include_directories(BEFORE freertos-configs)
# option(AFR_ENABLE_DEMOS "Build demos for FreeRTOS." ON)

# Add freertos as an subdirectory. AFR_BOARD tells which board to target.
set(AFR_BOARD espressif.esp32_devkitc CACHE INTERNAL "")
add_subdirectory(freertos)

# Link against the mqtt demo so that we can use it. Dependencies of this demo are transitively
# linked.
target_link_libraries(
    ${MAIN_PROJECT_NAME}
    PRIVATE
    AFR::demo_core_mqtt
    AFR::common_io
    AFR::core_mqtt
    AFR::ble
    AFR::core_mqtt_demo_dependencies
)