# Lesson 3: Alternating LEDs & Your First Variables 🚦

Controlling one LED is awesome, but real projects control lots of things at once! Think about railroad crossing lights or police sirens - when one light turns on, the other turns off. Today, you'll build that exact effect and learn a huge coding superpower: **variables**.

## 🎯 Your Mission
Configure the left LED (pin `4`) and right LED (pin `8`) as outputs, and make them blink back and forth alternately. Set up your code so you can change the blinking speed by editing **only one number**!

[📺 Watch the Demo Video!](https://youtube.com/shorts/P8eT7SSupE8)

---

## 🧠 How It Works

### Step 1: Blinking Two LEDs
Just like you configured pin `4` in the last lesson, you can configure pin `8` in `setup()`. Then, inside `loop()`, make them take turns:
1. Turn pin `4` **ON** (`HIGH`) and pin `8` **OFF** (`LOW`).
1. Wait `500` milliseconds.
1. Turn pin `4` **OFF** (`LOW`) and pin `8` **ON** (`HIGH`).
1. Wait `500` milliseconds.

```cpp
void setup() {
  pinMode(4, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop() {
  digitalWrite(4, HIGH);
  digitalWrite(8, LOW);
  delay(500);

  digitalWrite(4, LOW);
  digitalWrite(8, HIGH);
  delay(500);
}
```

### Final Step: Introducing Variables!
Now, suppose you want to double the blinking speed by changing the delay from `500` to `250`. Right now, you have to change `500` in **two** places. What if you accidentally change one to `250` and leave the other at `500`? Your lights would get a weird, lopsided limp! And imagine if you had 50 `delay()` lines in a big project - editing them all by hand would be a nightmare. This is a great source for bugs! 🐞

*(Note: did you know? The first computer bug was a moth. [Yes, really!](https://en.wikipedia.org/wiki/Bug_(engineering)#/media/File:First_Computer_Bug,_1947.jpg))*

Enter **variables**! Think of a variable as a labeled storage box in the microcontroller's memory where you can keep a piece of data and reuse it anywhere.

To create a variable, you tell the compiler two things:
1. **The data type:** We'll use `int` (short for *integer*, which holds whole numbers like `500`, `250`, or `-10`).
1. **A clear, descriptive name:** Always give variables meaningful names like `delayTime` instead of mysterious single letters like `x` or `a` - your future self will thank you!

```cpp
int delayTime = 500; // Create a variable named delayTime and store 500 inside it
```

Put this line **at the very top of your code, above `setup()`**. Putting it outside of all functions makes it a **global variable**, meaning every part of your program can see and use it! If you put it inside `setup()`, you won't be able to access it from `loop()`.

Now replace both `500` numbers with `delayTime`:

```cpp
int delayTime = 500;

void setup() {
  pinMode(4, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop() {
  digitalWrite(4, HIGH);
  digitalWrite(8, LOW);
  delay(delayTime);

  digitalWrite(4, LOW);
  digitalWrite(8, HIGH);
  delay(delayTime);
}
```

Upload it - it works just like before! Now change `int delayTime = 500;` at the top to `int delayTime = 250;` and upload again. Your LEDs blink twice as fast, and avoided an annoying mistake!

---

## 🛠️ Hardware & Coding Homework
* **Hardware Check:** If pin `4` blinks nicely, but pin `8` refuses to light up, check your board's solder joints on the LED connected to **D8**!
* **Challenge (Ask your teacher if you want a hint!):** Notice how names like `delayTime` start with a lowercase letter and capitalize the second word? That style is called **camelCase** (because the capital letter looks like a camel's hump!). Can you add a **third** LED (say, pin `6`) to your alternating pattern using your `delayTime` variable?
