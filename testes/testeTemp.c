#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"
#include "testes/testeTemp.h"
#include "bibliotecas/temporizador.h"

/*
 * Callback do temporizador de teste.
 * Ele calcula o tempo decorrido e imprime na tela.
 */
int64_t tempCallback(alarm_id_t id, void *user_data) {
    absolute_time_t tempo_atual = get_absolute_time();
    int tempo_decorrido = absolute_time_diff_us(tempo_inicial, tempo_atual) / 1000; // Converte para ms

    printf("\n --->⏳Tempo decorrido: %d ms\n\n", tempo_decorrido);
    return 0;
}

/*
 * Função de teste do temporizador.
 * Cria um alarme de 3 segundos e mede o tempo real da execução.
 */
void testeTemp() {
    printf("\n⏲️  Teste de temporizador iniciado...\n");
    
    tempo_inicial = get_absolute_time(); // Marca o tempo inicial
    add_alarm_in_ms(3000, tempCallback, NULL, false); // Dispara o alarme após 3 segundos

    sleep_ms(3100); // Aguarda um pouco para garantir a execução do callback
    printf("✅ Teste de temporizador concluído com sucesso.\n\n");
}
