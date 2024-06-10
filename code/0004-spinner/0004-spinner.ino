
// create a variable to store delay
int delayTime = 250;

void setup() {

  // set all LED pins (2-9) as output
  for (int i = 2; i < 10; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {

  // for each LED (loop)
  for (int i = 2; i < 10; i++) {

    // turn off all LEDs (nested loop)
    for (int j = 2; j < 10; j++) {
      digitalWrite(j, LOW);
    }

    // turn on the next LED and wait
    digitalWrite(i, HIGH);
    delay(delayTime);
  }
}
