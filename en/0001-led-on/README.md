# 0001-led-on

Make a LED shine!

## Task

Configure digital pin 2 as an output, and turn it on (HIGH).

## Explanation

This example shows how to control a GPIO pin.

A GPIO pin needs to be set as an input (read signals) or output (produce control signals). The pinMode() function sets a single pin to be an input or output. A pin is usually an input by default.

In this example we will just turn on a single LED, LED1. It's connected to GPIO pin 4. The label says D4 on the PCB, but you should only use `4` for these pins. The `pinMode(4, OUTPUT);` line will set pin 4 to be an output. You can't just write lowercase `output`, because the uppercase `OUTPUT` is a special keyword, it's a `macro`. You can write your own macros too, but this one is made by Arduino for this function.

You can turn an output pin on or off with the `digitalWrite()` function. Turning on makes the power pin's voltage appear on the pin. If you have a 5V Arduino Uno, it means 5V. If you have an ESP32, it's operating voltage is usually just 3.3V! Turning off is always driving a pin to ground/GND/0V. So the `digitalWrite(4, HIGH);` line powers the pin, which will drive the LED.

This should only run once, so this should go in the `setup()` function's block. (inside the curly braces `{}`)
