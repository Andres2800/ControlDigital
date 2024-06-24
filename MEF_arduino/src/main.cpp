#include <Arduino.h>
#include <module.c>


void setup() {
  init_modulo();
  init_MEF();
  Serial.begin(9600);
}

void loop() {
  update_MEF();
  delay(1);
}