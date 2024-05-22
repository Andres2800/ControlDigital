#include <stdio.h>
#include <Arduino.h>

//extern "C"{#include "modulo.h"}

int anterior;
bool valor;

bool encenderLed(uint16_t led){
    digitalWrite(led, 1);
    return true;
}
bool apagarLeds(){
    digitalWrite(6,0);
    digitalWrite(7,0);
    digitalWrite(8,0);
    digitalWrite(9,0);
    return true;
}


bool leerTecla(uint16_t tecla){

  int estado = digitalRead(tecla);
  
  if (anterior==HIGH && estado == LOW){
    valor = true;
  }else{
    valor = false;
  }
  anterior=estado;
  return valor;
  
}


