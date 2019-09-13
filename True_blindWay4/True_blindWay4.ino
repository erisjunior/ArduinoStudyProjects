#include <Thread.h>
#include <ThreadController.h>
#include <Ultrasonic.h>

Ultrasonic ultrasonic1(2, 3);
Ultrasonic ultrasonic2(4, 5);
Ultrasonic ultrasonic3(6, 7);

int pin[3] = {9,10,11};
long microsec[3];
float cmMsec[3];

ThreadController cpu;

Thread lerSensorUm;
void leituraUm(){
  cmMsec[0] = ultrasonic1.read(CM);
  Serial.println(cmMsec[0]);
      
  if(cmMsec[0]>150){
    analogWrite(pin[0],0);
  }else{
    int valor = 255 - (int(cmMsec[0]*1.7));
    analogWrite(pin[0],valor);
  }
}

Thread lerSensorDois;
void leituraDois(){
  cmMsec[1] = ultrasonic2.read(CM);
  Serial.println(cmMsec[1]);
      
  if(cmMsec[1]>150){
    analogWrite(pin[1],0);
  }else{
    int valor = 255 - (int(cmMsec[1]*1.7));
    analogWrite(pin[1],valor);
  }
}

Thread lerSensorTres;
void leituraTres(){
  cmMsec[2] = ultrasonic3.read(CM);
  Serial.println(cmMsec[2]);
      
  if(cmMsec[2]>150){
    analogWrite(pin[2],0);
  }else{
    int valor = 255 - (int(cmMsec[2]*1.7));
    analogWrite(pin[2],valor);
  }
}

void setup(){
  Serial.begin(9600);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

  lerSensorUm.setInterval(10);
  lerSensorUm.onRun(leituraUm);

  lerSensorDois.setInterval(15);
  lerSensorDois.onRun(leituraDois);

  lerSensorTres.setInterval(20);
  lerSensorTres.onRun(leituraTres);
  
  cpu.add(&lerSensorUm);
  cpu.add(&lerSensorDois);
  cpu.add(&lerSensorTres);
}

void loop(){
  cpu.run();
}
