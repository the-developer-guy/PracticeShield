# Lesson 4: The LED Spinner & `for` Loops 🎡

Your board has a whole circle of LEDs connected to pins `4` through `11`! Writing `pinMode()` and `digitalWrite()` eight times in a row would be super repetitive and error-prone. Good programmers are creatively lazy - when a task repeats in a pattern, we make the computer loop through it for us!

## 🎯 Your Mission
Make the light spin counterclockwise around the LED circle (pins `4` to `11`) using a `for` loop, and use a variable to control the spin speed.

---

## 🧠 How It Works

### Step 1: Understanding the Pattern
Before writing even a single line of code, let's trace what needs to happen by hand:
1. Configure digital pins `4` through `11` as outputs.
1. Turn on LED `4` and wait `delayTime` milliseconds.
1. Turn off LED `4`, turn on LED `5`, and wait.
1. Keep moving around the circle until you reach LED `11`!

### Step 2: Meet the `for` Loop
Focus on the first step: how would you initialize all 8 LEDs?

```cpp
void setup() {
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  ...
  pinMode(11, OUTPUT);
}
```

That's long and boring. Loops are used to simplify repeating things - especially when you can find a **pattern**. And it's easy to find one here.

We already know `loop()` repeats forever, but what if we want a controlled loop that counts from `4` up to `11` and then stops? That's what a **`for` loop** does! Look at how a `for` loop is structured:

```cpp
for (int pin = 4; pin <= 11; pin++) {
  // Code inside here repeats for each pin from 4 to 11!
}
```

Let's break those three parts inside the parentheses down:
1. **`int pin = 4;`** - *Start:* Create a temporary counter variable called `pin` and start it at `4`.
1. **`pin <= 11;`** - *Condition:* Keep repeating the loop as long as `pin` is less than or equal to `11`.
1. **`pin++`** - *Step:* Every time one round finishes, add `1` to `pin` (`pin++` is shorthand for `pin = pin + 1`).

You can use a `for` loop inside `setup()` to configure all 8 pins, but instead of calling `pinMode()` for each and every pin, we can reference the `pin` variable!

```cpp
void setup() {
  for (int pin = 4; pin <= 11; pin++) {
    pinMode(pin, OUTPUT);
  }
}
```

### Step 3: Implement the Spinner
Now all 8 LED pins are outputs, focus on the light pattern! This part goes into the `loop()`:

1. Turn on the LED on pin `4` and wait `delayTime` milliseconds.
1. Turn off the LED on pin `4`, turn on the LED 2 on pin `5`, and wait.
1. Keep moving around the circle until you reach pin `11`!

```cpp
void loop() {
  digitalWrite(4, HIGH); // turn on pin 4
  delay(delayTime); // and wait delayTime milliseconds

  digitalWrite(4, LOW); // turn off pin 4
  digitalWrite(5, HIGH); // turn on pin 5
  delay(delayTime); // and wait

  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  delay(delayTime);

  ... // until you reach pin 11
}
```

It will be about 40 long, but finish the pattern!

### Step 4: Ensuring Correctness
There is a little bug hiding in plain sight - the LED on pin D11 stays turned on after the first cycle! There is a small mistake in our logic:

1. Turn on the LED on pin `4` and wait `delayTime` milliseconds.
1. Turn off the LED on pin `4`, turn on the LED on pin `5`, and wait.
1. Keep moving around the circle until you reach pin `11`!

We forgot to turn pin 11 off, when we turned pin 4 on! We focused on the *previous* LED, which is almost correct. But turning off the *last* LED requires too much effort on our side. As an exercise, come up with a solution for this by yourself.

To make our code shorter, easier to understand AND bulletproof, let's rephrase our algorithm:
1. **Turn ALL LEDs off** using another `for` loop.
1. **Turn ON only the next `pin`**.
1. **Wait** `delay(delayTime)`.

```cpp
void loop() {
  for (int pin = 4; pin <= 11; pin++) {
    digitalWrite(pin, LOW);
  }
  digitalWrite(4, HIGH);
  delay(delayTime);

  for (int pin = 4; pin <= 11; pin++) {
    digitalWrite(pin, LOW);
  }
  digitalWrite(5, HIGH);
  delay(delayTime);
  ...
}
```

No matter what happens, **one and only one LED** will ever be lit at a time!

### Final Step: Spin in a For Loop
The previous example works, but I hope you can see the pattern! Turning LEDs (or pins) off, on, and waiting is practically the same for 8 LEDs. Let's *compress* our code! I prepared a skeleton, just fill the gap. The result will be much-much shorter than before - easier to understand, easier to maintain!

```cpp
int delayTime = 500;

void setup() {
  for (int pin = 4; pin <= 11; pin++) {
    pinMode(pin, OUTPUT);
  }
}

void loop() {
  for (int pin = 4; pin <= 11; pin++) {
    ...
    delay(delayTime)
  }
}
```
