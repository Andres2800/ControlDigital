#include <Arduino.h>   //Inlcusion del modulo con las funciones de Arduino
#include <modulo.h>   // Inclusion del modulo creado para la practica


//Declaracion de los pins conectados a los leds y botones
#define LED_GREEN 9
#define LED_YELLOW 8
#define LED_RED 7
#define LED_BLUE 6
#define SW1 5
#define SW2 4
#define SW3 3
#define SW4 2
uint16_t retraso = 200;       //Tiempo de encendido de los leds
unsigned long prev_time = 0;  //Variable utilizada para el retardo no bloqueante
int contador = 1;             //Variable que indica que posicion de la secuencia encender
const uint16_t secuencia[] = {LED_GREEN, LED_YELLOW, LED_RED, LED_BLUE};  //Secuencia de encendido de leds
bool sentido = true;          //Sentido de recorrido de la secuencia 
//
void setup() {
  //Declaracion de los pins de entrada y salida
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
  unsigned long current_time = millis();            //Valor utilizado para el retardo no bloqueante
  ///////////////////////////// Retardo no bloqueante  /////////////////////////////
  if((current_time - prev_time) >= retraso){    
    prev_time = current_time;    
    bool ledsa = apagarLeds();                      //Llamado a la funcion que apaga todos los leds
    bool ledsp = encenderLed(secuencia[contador]);  //Llamado a la funcion que enciende un led de la secuencia
    if (sentido){contador ++;}else{contador --;}    //Recorrido de la secuencia de acuerdo al sentido
    if (contador >= 4){contador = 0;}               //Reinicio de la secuencia 
    if (contador < 0){contador = 3;}                //Reinicio de la secuencia 
    
  }
  
///////////////////////////// Lectura de los botones  /////////////////////////////
 bool tecla1 = leerTecla(SW1);    //Llamado a la funcion de lectura para el boton 1
 bool tecla2 = leerTecla(SW2);    //Llamado a la funcion de lectura para el boton 2
 bool tecla3 = leerTecla(SW3);    //Llamado a la funcion de lectura para el boton 3
 bool tecla4 = leerTecla(SW4);    //Llamado a la funcion de lectura para el boton 4
 if(tecla1){retraso = 200;}       //Tiempo de encendido de 200ms al presionar el boton 1
 if(tecla2){retraso = 750;}       //Tiempo de encendido de 700ms al presionar el boton 2
 if(tecla3){sentido = true;}      //Cambio de sentido de la secuencia al presionar el boton 3
 if(tecla4){sentido = false;}     //Cambio de sentido de la secuencia al presionar el boton 4

  }