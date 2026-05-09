Raspberry Pi Pico USB-UART Bridge
=================================

This program bridges the [RP2350-GEEK](https://www.waveshare.com/wiki/RP2350-GEEK) HW UARTs to two independent USB CDC serial devices in order to behave like any other USB-to-UART Bridge controllers.


Disclaimer
----------

This software is provided without warranty, according to the MIT License, and should therefore not be used where it may endanger life, financial stakes, or cause discomfort and inconvenience to others.

Raspberry Pi Pico Pinout
------------------------

| Connector | GPIO   | Function |
|:---------:|:------:|:--------:|
| DEBUG     | GPIO2  | UART0 TX |
| DEBUG     | GPIO3  | UART0 RX |
| UART      | GPIO4  | UART1 TX |
| UART      | GPIO5  | UART1 RX |

Build for Raspberry Pi Pico / Pico 2
------------------------------------

Prerequisites:
- CMake
- ARM GCC toolchain (e.g. `arm-none-eabi-gcc`)
- Python 3

Build steps:
1. Initialize submodules if you haven't already:
   - `git submodule update --init --recursive`
2. Run the build script (defaults to Pico 1):
   - `./build.sh`

The `.uf2` output will be created at `build/uart_bridge.uf2`.

Board override:
- To build for Pico 2, set `PICO_BOARD`:
  - `PICO_BOARD=pico2 ./build.sh`
