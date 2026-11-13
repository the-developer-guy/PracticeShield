# 0004-spinner

Let's take the LEDs for a spin!

## Task

Let the light go counterclockwise on the LED circle, and learn about loops.

## Explanation

We already have a loop: the `loop()`. But we need will need our "controlled" loop too, with its own variables and whatnot. It's usually called a `for` loop.

### Step 1: make a spinner

Before you make the leds spin clockwise AND counterclockwise, make them go just counterclockwise first.

1. configure digital pins 4-11 as output
1. turn on the LED on pin 4
1. wait 500 ms with `delay()`
1. turn off pin 4 and turn on pin 5
1. repeat this turn off - turn on for all LEDs

### Step 2: spin infinitely

Putting all of these in the `setup()` function will run only once, and stop there. You only have to configure the pins as outputs once, leave that in the `setup()` and move the LED logic to the `loop()`.

### Step 3: add a variable!

Now speed things up! Double the blinking frequency by changing the delay time from 500 to 250. But how many times we want to do that? Only once! Why?

Let's "forget" to edit one of the numbers, set one of them to 250, and leave the other at 500 milliseconds. Test it, the result will be horrible! It would be SO good, if we could edit both numbers at one place!

This is where you learn about variables. These can store data. We will start with the most basic one: `int`. It can store different integers. If we want to create a variable, we must specify its type and name. Like this: `int delayTime;` - the name tells us its use case too! Always try to give "good" names to variables!

We can also set its value, let's change it: `int delayTime = 500;`.

Put this BEFORE the `void setup() {` line, so "everyone" can access this. And now change all `delay(500);` to `delay(delayTime);` and run the program.

It runs with the same speed, right? Now change the `delayTime`'s value to 250. Can you guess? Of course, it's easy: `int delayTime = 250;`

If you upload the code, it will run twice as fast!

### Final step: ensure correctness

Depending on the solution, the last LED may stay on - if the last step is `turn LED 10 off` with `turn LED 11 on`, then we jump back to just `turn on LED 4`. Make the code "more correct"!

Let's redefine our task and run this in an infinite loop:

1. turn all LEDs off
1. turn on the next LED
1. wait

The difference? No matter what glitch or error happened during execution, one and only one LED will be on.
