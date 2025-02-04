#include "leds.h"

// Função que inicializa o pino do LED como saída
void led_init(uint gpio) {
    gpio_init(gpio);
    gpio_set_dir(gpio, GPIO_OUT);
}

void liga_led(uint gpio) {
    gpio_put(gpio, 1);
}

void desliga_led(uint gpio) {
    gpio_put(gpio, 0);
}

void inicializaLEDs() {
    // Inicializando os pinos dos LEDs
    led_init(LED_VERMELHO);
    led_init(LED_AZUL);
    led_init(LED_VERDE);
}