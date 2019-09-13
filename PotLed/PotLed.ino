int led = 13;
unsigned int valorLido;
unsigned int pwm;

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  valorLido = analogRead(A0); 
  pwm = map(valorLido, 0, 1023, 0, 255); 
  analogWrite(led,pwm);
}
