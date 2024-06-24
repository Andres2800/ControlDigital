#include "modulo.h"
#include <Arduino.h>


int init_modulo(void) {
  // Inicialización de pines
  // Pulsante como entrada
  // LED como salida
  pinMode(PULSANTE, INPUT);
  pinMode(LED, OUTPUT);
  return 0;
}

int init_MEF(void) {
  // Inicialización de la MEF
  // Primer estado UP_STATE
  current_state = UP_STATE;
  counter_MEF = 0;
  return 0;
}

int read_LED(void) {
  // Leer estado del LED
  return digitalRead(LED);
}

void write_LED(int state){
    // Escribir estado del LED
    digitalWrite(LED, state);
}

void toggle_LED(void) {
  // Cambiar estado del LED
  write_LED(!read_LED());
}


void update_MEF(void){
    switch (current_state) {

        case UP_STATE:
            if (digitalRead(PULSANTE) == LOW) {
                current_state = FALLING_STATE;
                counter_MEF  = 0;
            }
            break;


        case FALLING_STATE:
            counter_MEF++;
            if (counter_MEF >= 20) {
                if (digitalRead(PULSANTE) == LOW) {
                    toggle_LED();
                    current_state = DOWN_STATE;
                } else {
                    current_state = UP_STATE;
                }
            }
            break;


        case DOWN_STATE:
            if (digitalRead(PULSANTE) == HIGH) {
                current_state = RISING_STATE;
                counter_MEF  = 0;
            }
            break;

        
        case RISING_STATE:
            counter_MEF++;
            if (counter_MEF >= 20) {
                if (digitalRead(PULSANTE) == HIGH) {
                    current_state = UP_STATE;
                } else {
                    current_state = DOWN_STATE;
                }
            }
            break;


        default:
            init_MEF();
            break;


    }
}