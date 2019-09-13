#include <Ultrasonic.h>

Ultrasonic ultra[3] = {(2,3),(4,5),(6,7)};
int porta[3] = {8,9,10};

int indice = 0;

void setup() {
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}


void loop() {

  //medida1
  float cmMsec = ultra[indice].read(CM);
  int frequencia = 6000 - (cmMsec*60);

  if(indice == 2){
    if(cmMsec>150){
      digitalWrite(porta[indice],LOW);
    }else{
      digitalWrite(porta[indice],HIGH);
    }
    indice = 0;
  }else{
    if(cmMsec>150){
      
      noTone(porta[indice]);
    
    }else{
      for(int x=0;x<100;x++){
        tone(porta[indice],frequencia,5);      
      }
    }
    indice++;
  }
}
