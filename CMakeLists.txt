# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.13)

include($ENV{PICO_SDK_PATH}/pico_sdk_init.cmake)

if (PICO_SDK_VERSION_STRING VERSION_LESS "1.4.0")
  message(FATAL_ERROR "Raspberry Pi Pico SDK version 1.4.0 (or later) required. Your version is ${PICO_SDK_VERSION_STRING}")
endif()

project(pico_uart_bridge)

set(PICO_BOARD pico2 CACHE STRING "Target board")

pico_sdk_init()

add_subdirectory(./lib/Config)
add_subdirectory(./lib/LCD)
add_subdirectory(./lib/lvgl)
add_subdirectory(./examples)

add_executable(uart_bridge uart-bridge.c usb-descriptors.c)

target_include_directories(uart_bridge PUBLIC
	./
        ./examples
        ./lib/Config
        ./lib/LCD
        ./lib/lvgl
        ./examples/inc
	pico-sdk/lib/tinyusb/src)


set(LV_CONF_PATH
  ${CMAKE_CURRENT_SOURCE_DIR}/lib/LVGL/lv_conf.h
    CACHE STRING "" FORCE)
add_compile_options(-O2)


target_link_libraries(uart_bridge
	hardware_flash
        hardware_spi
        hardware_i2c
        hardware_dma
	pico_multicore
        LCD 
        LVGL
        Config
        examples
	pico_stdlib
	tinyusb_device)


target_include_directories(uart_bridge   PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}
  )

pico_add_extra_outputs(uart_bridge)
