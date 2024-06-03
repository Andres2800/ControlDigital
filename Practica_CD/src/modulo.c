#include <stdio.h>
#include <Arduino.h>


int anterior;
bool valor;

bool encenderLed(uint16_t led){
  /// Funcion que prende el led que tiene como entrada 
  /// Retorna verdadero cuando se realizó correctamente
  /// Retorna falso cuando no pudo realizarse
    digitalWrite(led, 1);
    return true;
}
bool apagarLeds(){
  /// Funcion que apaga todos los leds 
  /// Retorna verdadero cuando se realizó correctamente
  /// Retorna falso cuando no pudo realizarse
    digitalWrite(6,0);
    digitalWrite(7,0);
    digitalWrite(8,0);
    digitalWrite(9,0);
    return true;
}


bool leerTecla(uint16_t tecla){
  /// Funcion que lee cuando se presiona un boton 
  /// Retorna verdadero cuando se presiono el boton
  /// Retorna falso cuando no se presiono el boton

  int estado = digitalRead(tecla);
  if (anterior==HIGH && estado == LOW){
    valor = true;
  }else{
    valor = false;
  }
  anterior=estado;
  return valor;
  
}


