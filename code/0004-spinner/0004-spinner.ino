
// create a variable to store delay
int delayTime = 250;

void setup() {

  // set all LED pins (2-9) as output
  for (int i = 4; i <= 11; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {

  // for each LED (loop)
  for (int i = 4; i <= 11; i++) {

    // turn off all LEDs (nested loop)
    for (int j = 4; j <= 11; j++) {
      digitalWrite(j, LOW);
    }

    // turn on the next LED and wait
    digitalWrite(i, HIGH);
    delay(delayTime);
  }
}
