#include <stdio.h>
#include "pico/stdlib.h"
#include "botao.h" // Incluir o arquivo de Botão

// Função para testar o botão (acionar a interrupção)
void testeBotao() {
    printf("\n🔘 Teste do botão iniciado.\n");
    // Simula pressionamento do botão
    gpio_put(BOTAO_A, 0); // Simula o pressionamento do botão
    sleep_ms(200); // Espera 200ms para simular a ação do botão
    gpio_put(BOTAO_A, 1); // Solta o botão
    printf("✅ Teste do botão finalizado com sucesso.\n\n");
}
