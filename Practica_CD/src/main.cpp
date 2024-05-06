#include <Arduino.h>
#include <modulo.h>
//Declarar los leds con enums
//Todo lo que no sea setup y loop va a un archivo externo
#define LED_GREEN 2
#define LED_YELLOW 3
#define LED_RED 4
#define LED_BLUE 5
#define SW1 6
#define SW2 7
#define SW3 8
#define SW4 9

void setup() {
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  pinMode(SW1, INPUT);
  pinMode(SW2, INPUT);
  pinMode(SW3, INPUT);
  pinMode(SW4, INPUT);
}



void loop() {
  encenderLed(13);
  delay(500);
  apagarLed(13);
  delay(500);
  }