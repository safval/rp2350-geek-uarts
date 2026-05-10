Raspberry Pi Pico USB-UART Bridge
=================================

This program bridges the [RP2350-GEEK](https://www.waveshare.com/wiki/RP2350-GEEK) HW UARTs to two independent USB CDC serial devices in order to behave like any other USB-to-UART Bridge controllers.

The current parameters of both serial ports are shown on the screen:

![rp2350-geek photo](./img.jxl)


Pinout
------------------------

| Connector | GPIO   | Function |
|:---------:|:------:|:--------:|
| DEBUG     | GPIO2  | UART0 TX |
| DEBUG     | GPIO3  | UART0 RX |
| UART      | GPIO4  | UART1 TX |
| UART      | GPIO5  | UART1 RX |

