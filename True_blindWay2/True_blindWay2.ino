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
}

Thread vibraUm;
void callUm(){
  int valor = 255 - (int(cmMsec[0]*1.7));
  analogWrite(pin[0],valor);
  Serial.println(cmMsec[0]);
  Serial.println(valor);
}

Thread lerSensorDois;
void leituraDois(){
  cmMsec[1] = ultrasonic2.read(CM);
}

Thread vibraDois;
void callDois(){
  int valor = 255 - (int(cmMsec[1]*1.7));
  analogWrite(pin[1],valor);
}

Thread lerSensorTres;
void leituraTres(){
  cmMsec[2] = ultrasonic3.read(CM);
}

Thread vibraTres;
void callTres(){
  int valor = 255 - (int(cmMsec[2]*1.7));
  analogWrite(pin[2],valor);
}

void setup(){
  Serial.begin(9600);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

  lerSensorUm.setInterval(100);
  lerSensorUm.onRun(leituraUm);

  vibraUm.setInterval(100);
  vibraUm.onRun(callUm);

  lerSensorDois.setInterval(100);
  lerSensorDois.onRun(leituraDois);

  vibraDois.setInterval(100);
  vibraDois.onRun(callDois);

  lerSensorTres.setInterval(100);
  lerSensorTres.onRun(leituraTres);

  vibraTres.setInterval(100);
  vibraTres.onRun(callTres);
  
  cpu.add(&lerSensorUm);
  cpu.add(&vibraUm);
  cpu.add(&lerSensorDois);
  cpu.add(&vibraDois);
  cpu.add(&lerSensorTres);
  cpu.add(&vibraTres);
}

void loop(){
  cpu.run();
}
