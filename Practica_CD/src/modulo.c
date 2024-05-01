#include <stdio.h>
#include <Arduino.h>

void encenderLed(uint16_t led){
    digitalWrite(led, 1);
}
void apagarLed(uint16_t led){
    digitalWrite(led, 0);
}


