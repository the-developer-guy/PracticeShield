# 0002-blinky

This is the embedded Hello World!

## Task

Configure digital pin 2 as an output, and periodically turn it on (HIGH) and off (LOW).

[Click here for video!](https://youtube.com/shorts/rRoTMfvWe2Y?feature=share)

## Explanation

The second step after turning something on - turn it off!

In the first example we configured pin 2 as an output in the `setup()` function. This function runs only once after powering on or a reset.

If we just modify our previous example and write the magic "turn off" command after the "turn on" command, the following will happen:

1. configure pin 2 as output
1. turn pin 2 on
1. turn pin 2 off

Maybe we will briefly see the led blink, but that's all. We want to turn it on and off as long as it has power! That's where the `loop()` function comes into play. If you put anything in the `loop()`, that will be repeatedly executed.

And how do we turn the pin off? `digitalWrite(2, HIGH);` turned it on, so what do you guess, what will turn it off? If you guessed `digitalWrite(2, LOW);`, you were right!

### Step 1: turn on and off in setup()

So let's try the following: put these commands in the `setup()` block and see: "nothing" is happening! The LED is off, because it turns the LED on and off really fast!

### Step 2: turn on and off in loop()

Move the `digitalWrite(2, HIGH);` and `digitalWrite(2, LOW);` in the `loop()`'s block, to see what happens.

Now it's "always on" - maybe not so bright? What happened? We already saw: turning on and off can happen really fast! How fast? Several thousand times per second!

Our eyes are too slow and we can't see it turning on and off. If you have an oscilloscope, you can check it, but let's go to the next step.

### Final step: let's pause!

How could we slow it down? We can wait! There is a function: `delay()`, which can "pause" our program. It doesn't really stop, it only counts until the set time elapsed. `delay(1);` will wait about 1 millisecond long. Don't use it too often because it wastes precious power, but we will start with this.

How do we "blink" with 1 Hz? Turn the LED on for half second (or 500 milliseconds), then turn off for another half second. Now you have everything to make it work! If it appears to be always on or off, think again and check the sample code!

If it works, feel free to speed up or slow down the blinking.
