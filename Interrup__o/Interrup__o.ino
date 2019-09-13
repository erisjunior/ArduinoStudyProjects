int led = 13;

void interrupcao(){
  digitalWrite(led, HIGH);
  delay(5000);
}

void setup() {
  pinMode(led, OUTPUT); 
  attachInterrupt(0,interrupcao,RISING); 
}

void loop() {
  digitalWrite(led, HIGH);
  delay(1000);
  digitalWrite(led, LOW);
  delay(1000); 
}
