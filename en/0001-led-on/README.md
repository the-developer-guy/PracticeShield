# Lesson 1: Make an LED Shine! 💡

Welcome to the world of embedded development! Today, you're going to write your very first piece of code that controls real, physical hardware. Ready to light things up?

## 🎯 Your Mission
Configure digital pin `4` as an output and turn on the LED connected to it.

---

## 🧠 How It Works

### What is a GPIO Pin?
On your microcontroller board, those little metal pins around the edge are called **GPIO** pins, which stands for **General Purpose Input/Output**. Think of them as the microcontroller's hands and senses:
* As an **Input**, a pin listens to the outside world (like checking if a button or switch is pressed).
* As an **Output**, a pin sends signals out to control things (like turning on an LED or spinning a motor).

By default, pins start out as inputs so they don't accidentally send power where it shouldn't go. To light up an LED, we need to tell the board: *"Hey, pin 4 is going to be an output!"*

### Step 1: Setting Up the Pin (`pinMode`)
Look closely at your board—you'll see **LED1** next to the label **D4** (Digital Pin 4). In your code, you just refer to it by its number: `4`.

To configure it, we use the `pinMode()` function inside the `setup()` block (the code inside the curly braces `{}` that runs once when the board turns on):

```cpp
void setup() {
  pinMode(4, OUTPUT);
}
```

> **Pro Tip:** Notice how `OUTPUT` is written in ALL CAPS? That's because it's a special predefined keyword called a **macro** (we'll explore these more in later lessons!). Programming languages are picky—writing lowercase `output` will cause an error, so keep it loud and proud in ALL CAPS!

### Step 2: Turning on the Power (`digitalWrite`)
Now that pin 4 is ready to send signals, let's send some electricity! We use the `digitalWrite()` function to set a pin either `HIGH` (ON) or `LOW` (OFF):
* **`HIGH`**: Connects the pin to the board's power supply (usually **5V** on boards like an Arduino Uno, or **3.3V** on an ESP32), sending electricity through the LED so it glows!
* **`LOW`**: Connects the pin to Ground (**GND / 0V**), turning the LED off.

Let's put it all together inside `setup()`:

```cpp
void setup() {
  pinMode(4, OUTPUT);    // Set pin 4 as an output
  digitalWrite(4, HIGH); // Turn the LED on!
}

void loop() {
  // Nothing needed here yet—the LED stays on!
}
```

Upload this code to your board. If **LED1** lights up, congratulations—you just wrote your first hardware program! 🎉

---

## 🛠️ Hardware & Soldering Check (Homework / Teacher Check-in)
* **Board Inspection:** Take a close look at the solder joints around **LED1** and its resistor on your board. Are they shiny, smooth, and shaped like tiny volcanoes? If the LED doesn't light up even with the right code, a loose or "cold" solder joint might be breaking the circuit!
* **Challenge Question (Ask your teacher if you get stuck!):** LEDs have polarity—meaning electricity can only flow through them in one direction (from the longer leg, the *anode*, to the shorter leg, the *cathode*). Look at your board's markings: why is there also a small resistor connected next to the LED? What would happen if we connected the LED straight to 5V without it?
