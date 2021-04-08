cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(template C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(${CMAKE_PROJECT_NAME})

pico_generate_pio_header(${CMAKE_PROJECT_NAME} ${CMAKE_CURRENT_LIST_DIR}/src/template.pio)

target_sources(${CMAKE_PROJECT_NAME} PRIVATE src/main.cpp)

target_link_libraries(${CMAKE_PROJECT_NAME} pico_stdlib hardware_pio)

pico_enable_stdio_usb(${CMAKE_PROJECT_NAME} 1)
#pico_enable_stdio_uart(${CMAKE_PROJECT_NAME} 1)

pico_add_extra_outputs(${CMAKE_PROJECT_NAME})
