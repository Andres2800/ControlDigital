#include <Arduino.h>
#include <modulo.h>
//Declarar los leds con enums
//Todo lo que no sea setup y loop va a un archivo externo

int del = 20;
void setup() {
  pinMode(2, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(4, OUTPUT);
}



void loop() {
  encenderLed(13);
  delay(del);
  apagarLed(13);
  delay(del);
  }