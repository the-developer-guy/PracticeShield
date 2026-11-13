void setup() {
  // put your setup code here, to run once:
  
  // set LED1 on pin 10 to output
  pinMode(10, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  // turn LED1 on
  digitalWrite(10, HIGH);

  // wait half second
  delay(500);

  // turn LED1 off
  digitalWrite(10, LOW);

  // wait again
  delay(500);
}
