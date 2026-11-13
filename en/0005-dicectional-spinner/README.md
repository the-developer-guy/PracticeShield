# 0005-directional-spinner

Let's take the LEDs for another spin, and learn how to read inputs!

## Task

Read the switch's state by configuring the pin (analog pin 3) as an input, and let the light go clockwise or counterclockwise depending on the switch.

## Explanation

Okay, first of all, this can be confusing. Are we going to read analog signals? No! The switch can be on or off, left or right, it clearly produces a digital signal! But here's the catch. All analog pins are digital pins at the same time! To save space, almost every pin has more, than one function, and you can configure, how would you like to use it. Except power, every pin can work as a GPIO, or General Purpose Input Output. This is how we used it so far: general purpose output - connect the pin to power or ground. Instead of having dedicated input and output pins, you can configure a pin to be either an input or output.

Some pins can also read analog signals, others can drive an RC servo, or communicate with other devices via UART, SPI, I²C, CAN, and many more! It depends on the microcontroller and the pin. To demonstrate this, the switch is connected to the `A3` pin. You will have to configure it just like the previous digital pins, just write a different name.

### Step 1: make a spinner

Before you make the leds spin clockwise AND counterclockwise, make them go clockwise first.

1. configure digital pins 2-9 as output
1. turn on the LED on pin 2
1. wait 200 ms with `delay()`
1. turn off pin 2 and turn on pin 3
1. repeat this turn off - turn on for all LEDs

### Final step: add a variable!

Now speed things up! Double the blinking frequency by changing the delay time from 500 to 250. But how many times we want to do that? Only once! Why?

Let's "forget" to edit one of the numbers, set one of them to 250, and leave the other at 500 milliseconds. Test it, the result will be horrible! It would be SO good, if we could edit both numbers at one place!

This is where you learn about variables. These can store data. We will start with the most basic one: `int`. It can store different integers. If we want to create a variable, we must specify its type and name. Like this: `int delayTime;` - the name tells us its use case too! Always try to give "good" names to variables!

We can also set its value, let's change it: `int delayTime = 500;`.

Put this BEFORE the `void setup() {` line, so "everyone" can access this. And now change both `delay(500);` to `delay(delayTime);` and run the program.

It blinks as usual, right? Now change the `delayTime`'s value to 250. Can you guess? Of course, it's easy: `int delayTime = 250;`

If you upload the code, now it blinks twice as fast!
