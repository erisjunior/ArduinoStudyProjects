int led = 13;
int butao = 2;
boolean sinal;
void setup() {
  pinMode(led,OUTPUT);
  pinMode(butao, INPUT);
  Serial.begin(9600);
}

void loop() {

  sinal = digitalRead(butao);
  
  if(sinal == HIGH){
    digitalWrite(led, HIGH);
    }
  if(sinal == LOW){
    digitalWrite(led, LOW);
    }
}
