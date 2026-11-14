# Lesson 4: The LED Spinner & `for` Loops 🎡

Your board has a whole circle of LEDs connected to pins `4` through `11`! Writing `pinMode()` and `digitalWrite()` eight times in a row would be super repetitive. Good programmers are creatively lazy—when a task repeats in a pattern, we make the computer loop through it for us!

## 🎯 Your Mission
Make the light spin counterclockwise around the LED circle (pins `4` to `11`) using a `for` loop, and use a variable to control the spin speed.

---

## 🧠 How It Works

### Step 1: Understanding the Pattern
Before writing a loop, let's trace what needs to happen by hand:
1. Configure digital pins `4` through `11` as outputs.
2. Turn on LED `4` and wait `delayTime` milliseconds.
3. Turn off LED `4`, turn on LED `5`, and wait.
4. Keep moving around the circle until you reach LED `11`!

### Step 2: Meet the `for` Loop
We already know `loop()` repeats forever, but what if we want a controlled loop that counts from `4` up to `11` and then stops? That's what a **`for` loop** does!

Look at how a `for` loop is structured:

```cpp
for (int pin = 4; pin <= 11; pin++) {
  // Code inside here repeats for each pin from 4 to 11!
}
```

Let's break those three parts inside the parentheses down:
1. **`int pin = 4;`** — *Start:* Create a temporary counter variable called `pin` and start it at `4`.
2. **`pin <= 11;`** — *Condition:* Keep repeating the loop as long as `pin` is less than or equal to `11`.
3. **`pin++`** — *Step:* Every time one round finishes, add `1` to `pin` (`pin++` is shorthand for `pin = pin + 1`).

You can even use a `for` loop inside `setup()` to configure all 8 pins in just three lines of code!

```cpp
int delayTime = 250;

void setup() {
  for (int pin = 4; pin <= 11; pin++) {
    pinMode(pin, OUTPUT);
  }
}
```

### Final Step: Ensuring Bulletproof Correctness!
Here's a classic bug beginners run into: if your loop turns on the current LED and waits, when it jumps from LED `11` back to LED `4`, LED `11` might accidentally stay lit! Or what if a quick glitch leaves two LEDs on at the same time?

To make our code **100% bulletproof**, let's follow a clean, predictable rule on every single step:
1. **Turn ALL LEDs off** (using a quick inner `for` loop!).
2. **Turn ON only the next LED** (`pin`).
3. **Wait** (`delay(delayTime)`).

Look how clean and reliable the complete program is:

```cpp
int delayTime = 250;

void setup() {
  for (int pin = 4; pin <= 11; pin++) {
    pinMode(pin, OUTPUT);
  }
}

void loop() {
  for (int pin = 4; pin <= 11; pin++) {
    // 1. Turn off all LEDs first
    for (int offPin = 4; offPin <= 11; offPin++) {
      digitalWrite(offPin, LOW);
    }

    // 2. Turn on the active LED
    digitalWrite(pin, HIGH);

    // 3. Wait before moving to the next one
    delay(delayTime);
  }
}
```

No matter what happens, **one and only one LED** will ever be lit at a time!

---

## 🚀 Homework & Teacher Check-in
* **Experiment:** Change `delayTime` to `50`—it looks like a smooth spinning wheel!
* **Challenge (Ask your teacher if you get stuck!):** Right now, the spinner goes from pin `4` up to `11`. How would you change the `for` loop inside `loop()` to make it spin **backwards** (from `11` down to `4`)? *(Hint: Instead of `pin++`, C++ also has `pin--` to subtract 1!)*
