// Programa : Sensor de detecção de osbtaculos para ciclistas com HC-SR04  
// Autor : Equipe IFMA CC 09
   
#include <Ultrasonic.h>   //Carrega a biblioteca Ultrasonic  
#include <NewTone.h>    //Carrega a biblioteca Newtone  
   
//Dados do buzzer  
#define tempo 500   
int frequencia = 1000;
int Pinofalante = 2;   
    
int atraso = 1000;  
   
//Define o pino do Arduino a ser utilizado com o pino Trigger do sensor  
#define PINO_TRIGGER 13   
//Define o pino do Arduino a ser utilizado com o pino Echo do sensor  
#define PINO_ECHO   10   

//Inicializa o sensor ultrasonico  
Ultrasonic ultrasonic(PINO_TRIGGER, PINO_ECHO);   
   
void setup()  
{  
  pinMode(Pinofalante,OUTPUT); //Pino do buzzer   
  Serial.begin(9600); //Inicializa a serial
}  
   
void loop()  
{  
  float cmMsec, inMsec;  
    
  //Le os dados do sensor, com o tempo de retorno do sinal  
  long microsec = ultrasonic.timing();   
   
  //Calcula a distancia em centimetros  
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);

  //Ajusta o atraso de acordo com a distancia 
  if (cmMsec < 2000)
  {  
    NewTone(Pinofalante, frequencia, tempo);
  }
  
   
  delay(tempo);  
}