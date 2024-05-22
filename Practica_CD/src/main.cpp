#include <Arduino.h>
#include <modulo.h>



#define LED_GREEN 9
#define LED_YELLOW 8
#define LED_RED 7
#define LED_BLUE 6
#define SW1 5
#define SW2 4
#define SW3 3
#define SW4 2
uint16_t retraso = 200;
unsigned long prev_time = 0;
int contador = 1;
const uint16_t secuencia[] = {LED_GREEN, LED_YELLOW, LED_RED, LED_BLUE};
bool sentido = true;

void setup() {
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  pinMode(SW1, INPUT);
  pinMode(SW2, INPUT);
  pinMode(SW3, INPUT);
  pinMode(SW4, INPUT);
  Serial.begin(9600);
}


void loop() {
  unsigned long current_time = millis();
  if((current_time - prev_time) >= retraso){
    prev_time = current_time;    
    bool ledsa = apagarLeds();
    bool ledsp = encenderLed(secuencia[contador]);
    if (sentido){contador ++;}else{contador --;}    
    if (contador >= 4){contador = 0;}
    if (contador < 0){contador = 3;}
    
  }
  
 bool tecla1 = leerTecla(SW1);
 bool tecla2 = leerTecla(SW2);
 bool tecla3 = leerTecla(SW3);
 bool tecla4 = leerTecla(SW4);
 if(tecla1){retraso = 200;}
 if(tecla2){retraso = 750;}
 if(tecla3){sentido = true;}
 if(tecla4){sentido = false;}

  }