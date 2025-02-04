#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"
#include "bibliotecas/leds.h"
#include "bibliotecas/botao.h"
#include "temporizador.h"

// Variável para controle do sistema
volatile bool leds_ligados = false;
uint32_t tempo_inicial; // Tempo inicial da contagem

/*
 * Callback do alarme para desligar os LEDs progressivamente.
 * Essa função é chamada automaticamente após um tempo definido (3 segundos),
 * desligando um LED por vez na seguinte ordem: azul, vermelho e verde.
 */
int64_t turn_off_leds_callback(alarm_id_t id, void *user_data) {
    int estado = (int)(uintptr_t) user_data;
    absolute_time_t tempo_atual = get_absolute_time();
    int tempo_passado = absolute_time_diff_us(tempo_inicial, tempo_atual) / 1000; // Tempo em ms

    if (estado == 2) {
        desliga_led(LED_AZUL);
        printf("    🔵 LED azul desligado, após %d ms.\n", tempo_passado);
    } 
    else if (estado == 1) {
        desliga_led(LED_VERMELHO);
        printf("    🔴 LED vermelho desligado, após %d ms.\n", tempo_passado);
    } 
    else if (estado == 0) {
        desliga_led(LED_VERDE);
        printf("    🟢 LED verde desligado, após %d ms.\n", tempo_passado);
        leds_ligados = false; // Libera o sistema para nova ativação
        printf("\n✅ Todos os LEDs desligados!\n\n");
        printf("🚀 Sistema pronto para nova ativação. |Aperte o botão para atvivar|\n\n");
    }

    return 0;
}

// Função que inicia os temporizadores para desligamento progressivo
void iniciaTemp() {
    tempo_inicial = get_absolute_time(); // Registra o tempo inicial

    add_alarm_in_ms(3000, turn_off_leds_callback, (void *)(uintptr_t)2, false); // LED Azul após 3s
    add_alarm_in_ms(6000, turn_off_leds_callback, (void *)(uintptr_t)1, false); // LED Vermelho após 6s
    add_alarm_in_ms(9000, turn_off_leds_callback, (void *)(uintptr_t)0, false); // LED Verde após 9s
}

// Debounce simples para evitar acionamentos repetidos acidentais
bool debounce_botao() {
    sleep_ms(50); // Aguarda 50ms para estabilizar o sinal
    return gpio_get(BOTAO_A) == 0;
}

/*
 * Função de interrupção do botão.
 * Quando o botão for pressionado, verifica se os LEDs estão desligados.
 * Se estiverem, liga todos os LEDs e inicia o temporizador para o desligamento progressivo.
 */
void gpio_irq_handler(uint gpio, uint32_t eventos) {
    if (!leds_ligados && debounce_botao()) {
        leds_ligados = true;
        liga_led(LED_AZUL);
        liga_led(LED_VERMELHO);
        liga_led(LED_VERDE);
        printf("✨ LEDs ligados! ⏲️  Iniciando cronômetro...\n\n");

        iniciaTemp();
    }
}
