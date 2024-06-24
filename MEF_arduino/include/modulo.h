#ifndef __MODULO_H__
#define __MODULO_H__

#include <stdint.h>

#define PULSANTE 5
#define LED 4

// State Machine STATES
typedef enum {
    UP_STATE,       // 0
    DOWN_STATE,     // 1
    FALLING_STATE,  // 2
    RISING_STATE    // 3
} mef_state_t;

// Global Variables
mef_state_t current_state; 
int counter_MEF;


// Fonctions
int init_modulo(void);
int init_MEF(void);
void update_MEF(void);
int read_LED(void);
void write_LED(int state);
void toggle_LED(void);


#endif