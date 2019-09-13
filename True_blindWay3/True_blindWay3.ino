#include <Ultrasonic.h>

Ultrasonic ultrasonic1(2, 3);
Ultrasonic ultrasonic2(4, 5);
Ultrasonic ultrasonic3(6, 7);

int pin[3] = {9,10,11};
long microsec[3];
float cmMsec[3];

int lastLUm =0;
int lastLDois =0;
int lastLTres =0;

int leitura(int i){
  if(i == 0){
    cmMsec[i] = ultrasonic1.read(CM);
  }else if(i == 1){
    cmMsec[i] = ultrasonic2.read(CM);
  }else if(i == 2){
    cmMsec[i] = ultrasonic3.read(CM);
  }
}

int lastCUm =0;
int lastCDois =0;
int lastCTres =0;
int call(int i){
  int valor = 255 - (int(cmMsec[i]*0.785));
  analogWrite(pin[i],valor);
}

void setup(){
  Serial.begin(9600);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop(){
  if( (millis() - lastLUm) >= 100 ){
    leitura(0);
    lastLUm = millis();
  }

  if( (millis() - lastLDois) >= 100 ){
    leitura(1);
    lastLDois = millis();
  }

  if( (millis() - lastLTres) >= 100 ){
    leitura(2);
    lastLTres = millis();
  }

  if( (millis() - lastLUm) >= 100 ){
    call(0);
    lastCUm = millis();
  }

  if( (millis() - lastLDois) >= 100 ){
    call(1);
    lastCDois = millis();
  }

  if( (millis() - lastLTres) >= 100 ){
    call(2);
    lastCTres = millis();
  }
}
