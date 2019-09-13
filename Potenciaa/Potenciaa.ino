int pot =0;
int vpot =0;
int led = 13;
void setup() {
pinMode(led,OUTPUT);
pinMode(pot, INPUT);
Serial.begin(96000);
}

void loop() {
  vpot = analogRead(pot);
  Serial.println(vpot);

delay(60);

  }
