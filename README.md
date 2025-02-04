<h1 align="center">⏳💡Tarefa 2 - Controle de LEDs com Temporizador One Shot e Botão</h1>

<h2 align="center">📝 Descrição do Projeto</h2>

Este projeto implementa o controle de três LEDs (azul, vermelho e verde) utilizando a placa Raspberry Pi Pico. Os LEDs são ativados por um botão e desligam progressivamente após intervalos de tempo predefinidos. O sistema inclui:
- Uso de interrupções para captura de eventos do botão.
- Temporização para desligamento dos LEDs de forma sequencial.
- Testes automatizados para validar o funcionamento dos componentes.

<h2 align="center">📂 Estrutura do Projeto</h2>

- **bibliotecas/**: Contém arquivos para o funcionamento dos LEDs e do botão.
  - `leds.c` e `leds.h`: Inicializa e controla o estado dos LEDs.
  - `botao.c` e `botao.h`: Gerencia o botão e sua interrupção.
  
- **testes/**: Contém arquivos de testes para validação dos componentes.
  - `testeLeds.c` e `testeLeds.h`: Testes para os LEDs.
  - `testeBotao.c` e `testeBotao.h`: Testes para o botão.
  - `testeTemp.c` e `testeTemp.h`: Testes para o temporizador.

- **principal/**: Contém o arquivo `main.c`, que gerencia a execução do sistema.
- **build/**: Diretório gerado automaticamente na compilação.
- **Arquivos adicionais:**
  - `.gitignore`: Define arquivos a serem ignorados pelo Git.
  - `CMakeLists.txt`: Configuração do CMake para compilação.
  - `diagram.json` e `wokwi.toml`: Arquivos para simulação no Wokwi.
  - `pico_sdk_import.cmake`: Importação do SDK do Raspberry Pi Pico.
  - `README.md`: Descrição do projeto.

<h2 align="center">🔧 Requisitos</h2>

- Raspberry Pi Pico
- SDK do Pico instalado
- Biblioteca `pico-sdk`
- Ambiente de desenvolvimento configurado (VS Code recomendado)

<h2 align="center">🖥️ Como Compilar e Executar</h2>

1. Clone o repositório:
   ```sh
   git clone https://github.com/seu-repo/projeto-leds-pico.git
   cd projeto-leds-pico
   ```

2. Configure o ambiente e compile o projeto:
   ```sh
   mkdir build
   cd build
   cmake ..
   make
   ```

3. Suba o arquivo `.uf2` para a Raspberry Pi Pico e monitore a saída:
   ```sh
   minicom -b 115200 -o -D /dev/ttyUSB0
   ```

<h2 align="center">✅ Testes</h2>

Para rodar os testes automatizados:
```sh
make test
```
Os testes verificam a inicialização e funcionamento dos LEDs, botão e temporizador.

<h2 align="center">📅 Informações</h2>

📌 **Autor(a):** Alícia Oliveira Araújo  
📅 **Data da Aula:** 29/01/2025  
🛠 **Última Modificação do Código:** 04/02/2025

