# Lesson 2: Blinky — The Embedded "Hello, World!" 🚨

The classic first coding project is printing *"Hello, World!"* on a screen. Can you find a screen on the board? Me neither! Our version is making an LED blink. You already know how to turn an LED on - now let's learn how to turn it off too, and create a steady heartbeat. This is more important than you think - a lot of industrial devices have one of these heartbeat LEDs to show if it's running, or something happened and it stopped working.

## 🎯 Your Mission
Configure digital pin `4` as an output, and make it blink on (`HIGH`) and off (`LOW`) once every second (1 Hz).

[📺 Watch the Demo Video!](https://youtube.com/shorts/rRoTMfvWe2Y?feature=share)

---

## 🧠 How It Works

### `setup()` and `loop()`
Every Arduino/C++ sketch has two main sections:
1. **`setup()`**: Runs **only once** when you power on or press the reset button. This is where we do our initial prep work, like calling `pinMode()`.
1. **`loop()`**: Runs **over and over again forever** as long as the board has power. Anything inside `loop()` repeats endlessly!

And if `digitalWrite(4, HIGH);` turns the LED on, what turns it off? You guessed it: `digitalWrite(4, LOW);`!

### Step 1: Testing in `setup()`
Imagine we put both commands inside `setup()`:

```cpp
void setup() {
  pinMode(4, OUTPUT);
  digitalWrite(4, HIGH); // Turn ON
  digitalWrite(4, LOW);  // Turn OFF immediately
}

void loop() {
}
```
If you run this, it looks like... nothing happened! Why? Because the microcontroller executes millions of commands every second. It turned the LED on and off so fast your eyes couldn't even catch it!

### Step 2: Moving to `loop()` (Still Too Fast!)
Okay, let's move the on/off commands into `loop()` so it repeats forever:

```cpp
void setup() {
  pinMode(4, OUTPUT);
}

void loop() {
  digitalWrite(4, HIGH);
  digitalWrite(4, LOW);
}
```
Now the LED looks like it's always on, maybe just a tiny bit dimmer! That's because it's blinking **thousands of times per second**. Our eyes blur rapid flashes together into a steady glow. (the exact same trick used in every dimmable light source)

### Final Step: Adding a Pause with `delay()`
To slow things down, we need to tell the microcontroller to wait between switching states. We can do that using the `delay()` function, which pauses the program for a specific number of **milliseconds** (1,000 milliseconds = 1 second).

To blink at **1 Hz** (one full on-off cycle per second):
1. Turn the LED **ON** (`HIGH`)
1. Wait **500 ms** (half a second)
1. Turn the LED **OFF** (`LOW`)
1. Wait **500 ms** (half a second)

```cpp
void setup() {
  pinMode(4, OUTPUT);
}

void loop() {
  digitalWrite(4, HIGH); // Turn LED on
  delay(500);            // Wait 0.5 second
  digitalWrite(4, LOW);  // Turn LED off
  delay(500);            // Wait 0.5 second
}
```
*(Note: While `delay()` is great for learning and in some rare cases, keep in mind that the microcontroller literally sits there counting and can't do anything else while waiting. Later on, you'll learn clever ways to time things without pausing the whole chip!)*

---

## 🚀 Level Up & Homework Check
* **Experiment:** Try changing `500` to `100` for a rapid strobe effect, or `2000` for a slow, sleepy pulse. What happens if you make the ON time `50` and the OFF time `950`?
* **Think & Ask Your Teacher:** Why do you think you need *two* `delay(500);` lines instead of just one between `HIGH` and `LOW`? Try deleting the second `delay(500);` and see what happens!
