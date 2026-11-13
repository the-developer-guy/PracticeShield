# 0006-directional-spinner

Let's take the LEDs for another spin, and practice how to read inputs! Also, learn about macros.

## Task

Read the switch's state by configuring the pin (analog pin 3) as an input, and let the light go clockwise or counterclockwise depending on the switch.

## Explanation

Something something correctness.

### Step 1: make two spinners

The example wasn't too specific, let's do the easy way first.

We learned about conditionals, try to solve our problem using one:

1. read the value of the switch
    1. if: it's in the left state, spin counterclockwise once 
    1. else: it's in the rigth state, spin clockwise

We can put the clockwise and counterclockwise spinners in their own `for` loop, and run the whole `for` loop. Not a bad start, let's do that first.

The counterclockwise spinner starts at 4, goes up to 11, then restarts.

``` C++
for (int i = 4; i <= 11; i++) {
```

The clockwise spinner must go the opposite way: start from 11, and **decrease** the value until it reaches 4!

``` C++
for (int i = 11; i >= 4; i--) {
```

### Step 2: stop and continue

The only problem with our solution is the following: we have to wait for the whole loop to finish. I "forgot" to write it in the specification, so let's add some clarification: I want to change the spinning direction whenever the switch is flicked! Now what?

We can't wait until the `for` loop finishes the animation. Someone may have heard of a magic jumping keyword that could let you escape the loop. (and I'm not referring to `break` or `continue`, but something so sinister I'm not even naming it here) We have to ditch the `for` loops completely, and depend on the outer `loop()`. But how?

Simplify the task a little bit: run the counterclockwise spinner when the switch is in the right position (`HIGH`), and stop when the switch is in the left position (`LOW`). 

 Let's ask another queston: what was the `for` loop's task? Break it down:

``` C++
for (int i = 4; i <= 11; i++) {
    // turn off all LEDs (nested loop)
    for (int j = 4; j <= 11; j++) {
        digitalWrite(j, LOW);
    }

    // turn on the next LED and wait
    digitalWrite(i, HIGH);
    delay(delayTime);
}
```

We created `i` for indexing. The variable name i-j-k... used in loops and nested loops is practically the only time when a single letter can actually tell what it does, but we could still do better! The variable `i` stored which pin comes next in our spinner. We go from 4 to 11 (pin D4 to D11 on the board), turn all LEDs off in the nested loop, turn the current LED (stored in `i`) on, then wait.

So, if we could just SOMEHOW store the next LED value without a `for` loop! Create a **global variable**, called `nextLed`, just the way we stored the delay time in a variable - outside all functions. We'll start with the LED on pin 4.

``` C++
int nextLed = 4;

void setup() {
}

void loop() {
}
```

Configure all D4-D11 pins to `OUTPUT` in the `setup()`, and focus on the `loop()`, and spin counterclockwise. (low pin number to high) How would we do that?

1. increase the number in the variable `nextLed` by 1
1. clear/turn off all LEDs
1. turn LED on pin `nextLed` on
1. wait

This goes fine for a while, but after pin 11? Darkness. We forgot to jump back to pin 4 when we went over 11! Correct this mistake:

1. increase the number in the variable `nextLed` by 1
1. if `nextLed` went over 11, set `nextLed` to 4 (aka. the first LED)
1. clear/turn off all LEDs
1. turn LED on pin `nextLed` on
1. wait

Almost there! Now move all of this inside a conditional statement. Only do this, when the switch is in the right position. Otherwise do nothing. This way we can stop and continue the spinner.

### Step 3: both directions!

You can try to guess the task. If not in the mood for that: extend the conditional statement!

If the switch is in the right position, increase the `nextLed` value each round, and jump from 12 to 4.

Otherwise (aka. the switch being in the left position) **decrease** the `nextLed` value each round, and jump **how**? From 3 to 11!

Organize!

1. read the switch value
    1. if `HIGH`, increment `nextLed`
        1. if `nextLed` is over 11, set `nextLed` to 4
    1. if `LOW`, decrement `nextLed`
        if `nextLed` is below 4, set `nextLed` to 11
1. clear all LEDs
1. set pin `nextLed` to `HIGH`
1. wait

This work perfectly, but the code is far from perfect!

### Final step: give name to the numbers!

Pin number 4 and 11 are called **magic numbers**. The values have no explanation or meaning without having a board in your hand.

We can `#define` a name for such values. These are called **macros**. This is NOT a variable! This doesn't take up precious RAM, it just get replaced in the code when it's turned into binary. So don't even try to assign a new value to a marco, it won't work!

Pin 4 was the lowest LED pin, pin 11 was the highest LED pin. Create 2 macros, and give them a meaningful name:

``` C++
#define MIN_LED 4
#define MAX_LED 11
```

Macros must be all caps, and use an underscore when a word boundary is reached. So if you encounter something like `HIGH`, `LOW`, `INPUT`, `OUTPUT`, or `MAX_LED`, you know it's a macro.

So, instead of this

``` C++
for (int pin = 4; pin <= 11; pin++)
```

we can write

``` C++
for (int pin = MIN_LED; pin <= MAX_LED; pin++)
```

Also, we can turn this meaningless piece of code

``` C++
if (nextLed > 11) {
    nextLed = 4;
}
```

into something much easier to understand:

``` C++
if (nextLed > MAX_LED) {
    nextLed = MIN_LED;
}
```

Last but not least: if we want to change a full circle into a halfpipe, just change `MAX_LED` to 8 - only one place! Much easier to maintain and fix if macros are used instead of magic numbers.
