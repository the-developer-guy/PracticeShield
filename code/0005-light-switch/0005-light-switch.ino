void setup() {
  // make LED 1 output on pin 10
  pinMode(10, OUTPUT);

  // set analog pin 3 as input
  pinMode(A3, INPUT);
}

void loop() {
  // read the state of the switch and store it in a variable
  int switchState = digitalRead(A3);

  // set the LED on or off based on the switch state
  if(switchState == LOW) {
    digitalWrite(10, HIGH);
  }
  else {
    digitalWrite(10, LOW);
  }

  // NO DELAY!
}
