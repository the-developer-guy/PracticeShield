# Lesson 5: Reading a Switch & Making Decisions (`if` / `else`) 🎚️

Up until now, your microcontroller has only been *talking* (sending outputs to LEDs). Today, it learns how to *listen*! You'll read the position of the physical slide switch on your board and make your code react to it.

## 🎯 Your Mission
Read the state of the switch connected to analog pin `A3`, and use conditional statements (`if` / `else`) to control an LED on pin `10`.

---

## 🧠 How It Works

### Wait - Why is a Switch on an *Analog* Pin (`A3`)?!
Good catch! A physical switch only has two positions: **LEFT** (`OFF` / `LOW`) or **RIGHT** (`ON` / `HIGH`). That's a **digital** signal! So why is it wired to pin `A3` (Analog 3)?

![](../media/0005-gpio.png)

Here's a neat hardware secret: **every analog pin on this microcontroller can also act as a regular digital GPIO pin!** Because microcontrollers are tiny, almost every pin wears multiple hats to save space. Depending on how you configure them in code, pins can read analog voltages, control servo motors, talk to sensors (via UART, SPI, or I²C), or act as simple digital inputs and outputs.

So you configure `A3` just like any digital pin - just write `A3` instead of a plain number!

### Step 1: Reading the Switch Once in `setup()`
Let's configure pin `10` as an `OUTPUT` and pin `A3` as an `INPUT`. Then, we use `digitalRead(A3)` to check whether the switch is receiving voltage (`HIGH`, which equals `1`) or connected to ground (`LOW`, which equals `0`), and save that answer in a variable:

```cpp
void setup() {
  pinMode(10, OUTPUT);
  pinMode(A3, INPUT);

  int switchState = digitalRead(A3);
  digitalWrite(10, switchState);
}

void loop() {
}
```
Try this out! Flip the switch to the right and press the **Reset** button on your board - the LED turns on. Flip the switch to the left and press **Reset** - the LED stays off.

### Step 2: Live Update
Having to press Reset every time you flip a light switch would be pretty annoying! Move the `digitalRead()` and `digitalWrite()` lines into `loop()` so the board checks the switch thousands of times per second:

```cpp
void setup() {
  pinMode(10, OUTPUT);
  pinMode(A3, INPUT);
}

void loop() {
  int switchState = digitalRead(A3);
  digitalWrite(10, switchState);
}
```
Now flip the switch back and forth - the LED responds instantly. Congratulations, we invented the wire! It's a bit expensive, but we can do more.

### Step 3: Inverting the Switch with `if` / `else`
Imagine your hardware teammate comes to you and says: *"Oops! The wires were mixed up. Can you make the LED turn **ON** when the switch is on the **LEFT** (`LOW`), and **OFF** when it's on the **RIGHT** (`HIGH`)?"*

In the real world, requirements change all the time, and fixing errors in code is usually the only solution! Well, you can also recall millions of devices and give the customer a new one, but that's usually way more expensive than just sending a software update.

To make decisions in code, we use **conditionals** (`if` and `else`):

```cpp
void setup() {
  pinMode(10, OUTPUT);
  pinMode(A3, INPUT);
}

void loop() {
  int switchState = digitalRead(A3);

  // Notice the DOUBLE equals sign (==) used for comparing two values!
  if (switchState == HIGH) {
    digitalWrite(10, LOW);  // Switch is RIGHT -> Turn LED OFF
  }
  else {
    digitalWrite(10, HIGH); // Otherwise (Switch is LEFT) -> Turn LED ON
  }
}
```

> **Watch Out for `=` vs `==`!** A single `=` *assigns* a value (puts data into a variable), while a double `==` *asks a question* ("are these two things equal?"). Mixing them up is one of the most common bugs in C++!

### Final Step: Same Logic, Written Another Way
We can also flip the condition around and check `if (switchState == LOW)` first:

```cpp
if (switchState == LOW) {
  digitalWrite(10, HIGH);
}
else {
  digitalWrite(10, LOW);
}
```

In fact, because C++ treats `0` (`LOW`) as **false** and everything else is **true**, some programmers often write the condition simply as `if (switchState)`!
