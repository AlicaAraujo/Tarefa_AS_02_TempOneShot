#ifndef BOTAO_H
#define BOTAO_H

#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "hardware/clocks.h"
#include "hardware/pio.h"
#include "pico/bootrom.h"
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/timer.h"

// Definição do pino do botão
#define BOTAO_A 5

void inicializaBotao();

#endif // BOTAO_H
