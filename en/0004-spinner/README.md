# 0004-spinner

Let's take the LEDs for a spin!

## Task

Let the light go clockwise on the LED circle, and learn about loops.

## Explanation

We already have a loop: the `loop()`.

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
