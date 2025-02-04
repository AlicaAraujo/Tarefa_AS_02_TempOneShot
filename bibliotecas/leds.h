#ifndef LEDS_H
#define LEDS_H

#include "pico/stdlib.h"

// Definição dos pinos dos LEDs
#define LED_AZUL    11
#define LED_VERMELHO 12
#define LED_VERDE   13

void inicializaLEDs();
void liga_led(uint gpio);
void desliga_led(uint gpio);

#endif // LEDS_H
