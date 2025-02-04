#ifndef TEMPORIZADOR_H
#define TEMPORIZADOR_H

#include "pico/stdlib.h"

// Variável global que define o tempo inicial da contagem
extern uint32_t tempo_inicial;

void iniciaTemp(); // Função para iniciar o temporizador
bool debounce_botao(); // Função para debounce do botão
void gpio_irq_handler(uint gpio, uint32_t eventos); // Interrupção do botão

#endif
