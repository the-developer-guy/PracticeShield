
// create a "variable" to store data
int delayTime = 500;

void setup() {

  // set the right and left LED pin as output
  pinMode(4, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop() {

  // turn left LED on, right LED off, then wait
  digitalWrite(4, HIGH);
  digitalWrite(8, LOW);
  delay(delayTime);

  // and the other way
  digitalWrite(4, LOW);
  digitalWrite(8, HIGH);
  delay(delayTime);
}
