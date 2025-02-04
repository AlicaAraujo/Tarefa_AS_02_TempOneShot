/*
Autor (a): Alícia Oliveira Araújo

Tarefa 2 - Temporizador One Shot - Aula Síncrona do dia 29/01/2025

Última modificação: 04/02/2025
*/

#include <stdio.h>
#include "pico/stdlib.h"
#include "bibliotecas/leds.h"
#include "bibliotecas/botao.h"
#include "bibliotecas/temporizador.h" 
#include "testes/testeLeds.h"
#include "testes/testeBotao.h"
#include "testes/testeTemp.h"

int main() {
    stdio_init_all(); 
    inicializaLEDs();
    inicializaBotao();
    
    printf("🚀 Sistema inicializado! Iniciando testes...\n\n");

    // Testes básicos
    testeLeds();
    testeBotao();
    testeTemp();

    printf("\n✅ Testes finalizados com sucesso, aperte o botão para iniciar código principal...\n\n");

    // Configuração da interrupção do botão
    gpio_set_irq_enabled_with_callback(BOTAO_A, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);
    
    while (true) {
        tight_loop_contents();
    }
}
