# Lesson 6: Directional Spinner & Macros 🔄

Time to combine everything you've learned so far! Today you'll build an interactive LED spinner where flipping the switch changes the spinning direction *immediately* - plus, you'll learn how pros eliminate "magic numbers" using **macros**.

## 🎯 Your Mission
Read the switch on pin `A3`. When the switch is in one position, spin the LEDs (`4`–`11`) clockwise; when it's in the other position, spin them counterclockwise - and switch directions the instant the switch is flipped!

---

## 🧠 How It Works

### Step 1: Why Two `for` Loops Aren't Enough
At first, you might think: *"Easy! I'll put a counterclockwise `for` loop inside `if`, and a clockwise `for` loop inside `else`!"*

```cpp
// Counterclockwise (4 up to 11)
for (int i = 4; i <= 11; i++) { ... }

// Clockwise (11 down to 4)
for (int i = 11; i >= 4; i--) { ... }
```

That works, **except for one catch**: once a `for` loop starts, the program gets stuck inside it until all 8 LEDs finish spinning! If you flip the switch halfway around the circle, the board ignores you until the full circle finishes.

To change direction **the exact moment** you flick the switch, we need to ditch the outer `for` loop and let Arduino's built-in `loop()` handle one step at a time!

### Step 2: Tracking Position with a Global Variable
If we don't have a `for` loop counting for us, how does the program remember which LED is currently lit? By storing it in a **global variable** at the top of our sketch!

Let's create `int nextLed = 4;` above `setup()`. Each time `loop()` runs, we move `nextLed` by just **one step**:
1. Check the switch (`A3`).
2. If the switch is `HIGH` (Right), add `1` to `nextLed` (`nextLed++`). If it goes past `11`, wrap it back around to `4`!
3. If the switch is `LOW` (Left), subtract `1` from `nextLed` (`nextLed--`). If it drops below `4`, wrap it around to `11`!
4. Turn off all LEDs, turn on `nextLed`, and wait `delayTime`.

Because `loop()` checks the switch before *every single LED step*, changing direction feels completely instantaneous!

### Final Step: Replacing "Magic Numbers" with Macros (`#define`)
Look at the numbers `4` and `11` scattered through our code. If someone reads our code without holding the board, they might wonder: *"Why 4? Why 11? What do these random numbers mean?"* Programmers call unexplained numbers like this **magic numbers** - and we want to avoid them!

We can give those numbers meaningful names using **`#define`**, which creates a **macro**:

```cpp
#define MIN_LED 4
#define MAX_LED 11
```

#### How is a Macro different from a Variable?
* A **variable** (`int delayTime = 150;`) takes up space in the microcontroller's RAM and can change while the program runs.
* A **macro** (`#define MAX_LED 11`) uses **zero RAM**! Before your code is uploaded, the compiler simply does a search-and-replace, swapping every `MAX_LED` with `11`. Because it's not a variable, you can never assign a new value to it in your code (`MAX_LED = 8;` will cause an error!).
* By convention, macros are always written in **`ALL_CAPS_WITH_UNDERSCORES`**. Anytime you see `HIGH`, `LOW`, `INPUT`, `OUTPUT`, or `MAX_LED`, you immediately know it's a macro!

### Complete Code

```cpp
#define MIN_LED 4
#define MAX_LED 11
#define SWITCH_PIN A3

int delayTime = 150;
int nextLed = MIN_LED;

void setup() {
  pinMode(SWITCH_PIN, INPUT);
  for (int pin = MIN_LED; pin <= MAX_LED; pin++) {
    pinMode(pin, OUTPUT);
  }
}

void loop() {
  // 1. Read the switch and update nextLed by 1 step
  if (digitalRead(SWITCH_PIN) == HIGH) {
    nextLed++;
    if (nextLed > MAX_LED) {
      nextLed = MIN_LED; // Wrap around from 11 back to 4
    }
  }
  else {
    nextLed--;
    if (nextLed < MIN_LED) {
      nextLed = MAX_LED; // Wrap around from 4 back to 11
    }
  }

  // 2. Turn off all LEDs
  for (int pin = MIN_LED; pin <= MAX_LED; pin++) {
    digitalWrite(pin, LOW);
  }

  // 3. Light up the new LED and wait
  digitalWrite(nextLed, HIGH);
  delay(delayTime);
}
```

Look how easy that is to maintain: if you ever want the light to bounce around only half the circle, you just change `#define MAX_LED 11` to `#define MAX_LED 8` in **one single spot**!

---

## 🎉 Course Checkpoint & Homework
* **Experiment:** Try changing `MIN_LED` and `MAX_LED` to test a smaller arc of LEDs!
* **Final Challenge (Show your teacher!):** Can you add a **"pause" feature** or speed boost? Think about how you could use another `if` statement - or ask your teacher how to wire up a push button so holding it down makes the spinner go into turbo mode!
