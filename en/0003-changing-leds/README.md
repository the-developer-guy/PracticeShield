# 0003-changing-leds

Control multiple pins and introduce "variables"!

[Click here for video!](https://youtube.com/shorts/P8eT7SSupE8)

## Task

Configure the left (pin 8) and right (pin 4) LED as an output, and let them blink alternately. Control the blinking speed by only modifying one value!

## Explanation

Of course we can control multiple pins, not just one. We have to configure and set one by one! Level crossing signals (those at the railroad crossings) work in a similar fashion.

### Step 1: blink 2 LEDs

Configure both pins 4 and 8 as an output, and let them blink alternately at the usual 1 Hz frequency. Set the `delay()` time to 500 milliseconds.

### Final step: add a variable!

Now speed things up! Double the blinking frequency by changing the delay time from 500 to 250. But how many times we want to do that? Only once! Why?

Let's "forget" to edit one of the numbers, set one of them to 250, and leave the other at 500 milliseconds. Test it, the result will be horrible! It would be SO good, if we could edit both numbers at one place!

This is where you learn about variables. These can store data. We will start with the most basic one: `int`. It can store different integers. If we want to create a variable, we must specify its type and name. Like this: `int delayTime;` - the name tells us its use case too! Always try to give "good" names to variables!

We can also set its value, let's change it: `int delayTime = 500;`.

Put this BEFORE the `void setup() {` line, so "everyone" can access this. And now change both `delay(500);` to `delay(delayTime);` and run the program.

It blinks as usual, right? Now change the `delayTime`'s value to 250. Can you guess? Of course, it's easy: `int delayTime = 250;`

If you upload the code, now it blinks twice as fast!
