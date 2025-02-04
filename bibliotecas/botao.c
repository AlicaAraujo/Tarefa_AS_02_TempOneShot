#include "botao.h"

extern void gpio_irq_handler(uint gpio, uint32_t eventos);

// Função que inicializa o pino do botão e configura como entrada com resistores pull-up
void botao_init(uint gpio) {
    gpio_init(gpio); // Inicializa o botão 
    gpio_set_dir(gpio, GPIO_IN); // Configura botão como entrada
    gpio_pull_up(gpio); // Habilita o pull-up interno do botão

    /* A linha abaixo configura uma interrupção para o botão.
    * Quando o botão for pressionado, a função gpio_irq_handler será chamada.
    * Isso impede que o botão acione os LEDs repetidamente sem que o processo anterior finalize.*/
    gpio_set_irq_enabled_with_callback(gpio, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);

}

void inicializaBotao() {
    //Inicializando o botão A
    botao_init(BOTAO_A);

}