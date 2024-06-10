#define MIN_LED 2
#define MAX_LED 9

// create a variable to store delay AND which LED comes next
int delayTime = 250;
int nextLed = 2;

void setup() {

  // set all LED pins (2-9) as output
  for (int pin = 2; pin < 10; pin++) {
    pinMode(pin, OUTPUT);
  }

  // set analog pin 3 as input
  pinMode(A3, INPUT);
}

void loop() {

  // calculate, which LED comes next
  // if the switch is on the right, go clockwise
  if (digitalRead(A3) == HIGH) {

    // and add 1 to the LED number
    nextLed++;

    // but if we go over pin 9, the maximum
    if (nextLed > MAX_LED) {
      // jump back to the first LED on pin 2 (MIN_LED)
      nextLed = MIN_LED;
    }
  } 
  
  // if the switch is on the ledt, go counterclockwise
  else {

    // and subtract 1 from the LED number
    nextLed--;

    // but if we go under the minimum, pin 2
    if (nextLed < MIN_LED) {

      // jump to the last LED on pin 9 (MAX_LED)
      nextLed = MAX_LED;
    }
  }

  // turn off all LEDs
  for (int pin = 2; pin < 10; pin++) {
    digitalWrite(pin, LOW);
  }

  // turn on the next LED and wait
  digitalWrite(nextLed, HIGH);
  delay(delayTime);
}
