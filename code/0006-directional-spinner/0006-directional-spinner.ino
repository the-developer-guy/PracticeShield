#define MIN_LED 4
#define MAX_LED 11

// create a variable to store delay AND which LED comes next
int delayTime = 250;
int nextLed = 4;

void setup() {

  // set all LED pins (2-9) as output
  for (int pin = MIN_LED; pin <= MAX_LED; pin++) {
    pinMode(pin, OUTPUT);
  }

  // set analog pin 3 as input
  pinMode(A3, INPUT);
}

void loop() {

  // calculate, which LED comes next
  // if the switch is on the right, go counterclockwise (low pin number to high)
  if (digitalRead(A3) == HIGH) {

    // and add 1 to the LED number
    nextLed++;

    // but if we go over pin 11, the maximum
    if (nextLed > MAX_LED) {
      // jump back to the first LED on pin 4 (MIN_LED)
      nextLed = MIN_LED;
    }
  } 
  
  // if the switch is on the left, go clockwise (high pin number to low)
  else {

    // and subtract 1 from the LED number
    nextLed--;

    // but if we go under the minimum, pin 4
    if (nextLed < MIN_LED) {

      // jump to the last LED on pin 11 (MAX_LED)
      nextLed = MAX_LED;
    }
  }

  // turn off all LEDs
  for (int pin = MIN_LED; pin <= MAX_LED; pin++) {
    digitalWrite(pin, LOW);
  }

  // turn on the next LED and wait
  digitalWrite(nextLed, HIGH);
  delay(delayTime);
}
