#include <Ultrasonic.h>

//definindo triggers e echos

#define pino_trigger1 4
#define pino_echo1 5

#define pino_trigger2 2
#define pino_echo2 3

#define pino_trigger3 6
#define pino_echo3 7


//setando sensores

Ultrasonic ultrasonic1(pino_trigger1, pino_echo1);
Ultrasonic ultrasonic2(pino_trigger2, pino_echo2);
Ultrasonic ultrasonic3(pino_trigger3, pino_echo3);

void setup() {
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
}


void loop() {

  //medida1
  float cmMsec1 = ultrasonic1.read(CM);
  int frequencia1 = 6000 - (cmMsec1*60);
  
  //medida2
  float cmMsec2 = ultrasonic2.read(CM);
  int frequencia2 = 6000 - (cmMsec2*60);

  //medida3
  float cmMsec3 = ultrasonic3.read(CM);
   
  int velo = 5;


  //Sensor 1

  if(cmMsec1>100){
    
    noTone(9);
  
  }else{
    
    for(int x=0;x<100;x++){
      tone(9,frequencia1,velo);
      
    }
    delay(cmMsec1*3);
  }


  //Sensor 2

  if(cmMsec2>100){
 
    noTone(8);
  
  }else{
    
    for(int x=0;x<100;x++){
      tone(8,frequencia2,velo);
    }
    delay(cmMsec2*3);
  }


  //Sensor 3

  if(cmMsec3>100){
    digitalWrite(10,LOW);
  }else{
    digitalWrite(10,HIGH);
  }
}
