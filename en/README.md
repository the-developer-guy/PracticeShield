# Arduino practice shield user manual

## 0001-led-on

This example shows how to control a GPIO pin.

A GPIO pin needs to be set as an input (read signals) or output (make control signals). The pinMode() function sets a single pin to be an input or output. A pin is usually an input by default.

In this example we will just turn on a single LED, LED1. It's connected to GPIO pin 2. The label says D2 on the PCB, but you should only use `2` for these pins. The `pinMode(2, OUTPUT);` line will set pin 2 to be an output. You can't just write lowercase `output`, because the uppercase `OUTPUT` is a special keyword, it's a `macro`. You can write your own macros too, but this one is made by Arduino for this function.

You can turn an output pin on or off with the `digitalWrite()` function. Turning on makes the power pin's voltage appear on the pin. If you have a 5V Arduino Uno R3, it means 5V. If you have an Arduino Uno R4, it's operating voltage is just 3.3V! Turning off is always driving a pin to ground/GND/0V. So the `digitalWrite(2, HIGH);` line powers the pin, which will drive the LED.
