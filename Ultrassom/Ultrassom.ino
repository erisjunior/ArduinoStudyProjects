#include <Ultrasonic.h>

#define pino_trigger 5
#define pino_echo 6
Ultrasonic ultrasonic(pino_trigger, pino_echo);

//Ultrasonic ultrassom2(10,11);

void setup() {
  Serial.begin(9600);
}

void loop() {
  //long distancia1 = ultrassom1.Ranging(CM);
  //long distancia2 = ultrassom2.Ranging(CM);
  float cmMsec1;
  long microsec = ultrasonic.timing();
  cmMsec1 = ultrasonic.convert(microsec, Ultrasonic::CM);

  Serial.println(cmMsec1);
  //Serial.println(distancia2);
  delay(100);
}
