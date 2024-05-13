void setup() {
  // put your setup code here, to run once:
  
  // set LED1 on pin 2 to output
  pinMode(2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  // turn LED1 on
  digitalWrite(2, HIGH);

  // wait half second
  delay(500);

  // turn LED1 off
  digitalWrite(2, LOW);

  // wait again
  delay(500);
}
