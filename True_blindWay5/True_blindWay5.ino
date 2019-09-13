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
}

Thread lerSensorDois;
void leituraDois(){
  cmMsec[1] = ultrasonic2.read(CM);
  
}

Thread lerSensorTres;
void leituraTres(){
  cmMsec[2] = ultrasonic3.read(CM);
}

void setup(){
  Serial.begin(9600);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

  lerSensorUm.setInterval(4);
  lerSensorUm.onRun(leituraUm);

  lerSensorDois.setInterval(3);
  lerSensorDois.onRun(leituraDois);

  lerSensorTres.setInterval(2);
  lerSensorTres.onRun(leituraTres);

  cpu.add(&lerSensorUm);
  cpu.add(&lerSensorDois);
  cpu.add(&lerSensorTres);
}

void loop(){
  cpu.run();
  if(cmMsec[0]>150){
    analogWrite(pin[0],0);
  }else{
    int valor = 255 - (int(cmMsec[0]*1.7));
    analogWrite(pin[0],valor);
  }

  int valor2 = 255 - (int(cmMsec[1]*0.785));
  analogWrite(pin[1],valor2);

  int valor1 = 255 - (int(cmMsec[2]*0.785));
  analogWrite(pin[2],valor1);
}
