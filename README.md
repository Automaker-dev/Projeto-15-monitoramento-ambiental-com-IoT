# 🌤️ Projeto 15: Monitoramento Ambiental com IoT

Este repositório contém o código de desenvolvimento e integração de uma **Estação Meteorológica e de Qualidade do Ar baseada em ESP32**, construída passo a passo desde os testes individuais de cada sensor até o envio automático de dados para a nuvem utilizando a plataforma **ThingSpeak**.

---

## 📌 Visão Geral do Projeto

O objetivo deste projeto é monitorar variáveis ambientais em tempo real e disponibilizar os dados remotamente via Wi-Fi. O sistema faz leituras de:
* **Temperatura e Umidade:** Sensor DHT11
* **Pressão Atmosférica:** Sensor BMP180
* **Qualidade do Ar (Gases):** Sensor MQ-135
* **Presença de Chuva:** Sensor de Chuva Analógico (FC-37)

Os dados coletados são processados pelo ESP32 e enviados periodicamente para o **ThingSpeak**, permitindo visualizações e gráficos em tempo real.

---

## 🛠️ Hardware Utilizado

* **Microcontrolador:** ESP32 (38 pinos)
* **Sensores:**
  * Sensor de Temperatura e Umidade DHT11
  * Sensor de Pressão Atmosférica BMP180
  * Sensor de Qualidade do Ar MQ-135
  * Sensor de Chuva Analógico (FC-37)
* **Protocolos:** I2C (BMP180), Leitura Digital (DHT11), Leituras Analógicas (MQ-135 e Chuva)

---

## 📚 Bibliotecas Necessárias

Para compilar e carregar os códigos na Arduino IDE, certifique-se de instalar as seguintes bibliotecas no **Gerenciador de Bibliotecas** (ou através dos links abaixo):

1. [`DHT sensor library` (por Adafruit)](https://github.com/adafruit/DHT-sensor-library)
2. [`Adafruit BMP085 Library` (por Adafruit)](https://github.com/adafruit/Adafruit-BMP085-Library)
3. [`ThingSpeak` (por MathWorks)](https://github.com/mathworks/thingspeak-arduino)
4. `WiFi` *(Já integrada ao pacote de placas oficial do ESP32 na Arduino IDE)*

---

## 📁 Estrutura do Repositório

O repositório está organizado em etapas para demonstrar a evolução da montagem e programação do projeto:

```text
├── 01-dht11-temperatura-umidade/   # Código de teste isolado para o DHT11
├── 02-bmp180-pressao/              # Código de teste isolado para o BMP180 (I2C)
├── 03-mq135-qualidade-ar/          # Leitura analógica e alerta de qualidade do ar
├── 04-sensor-chuva/                # Leitura analógica e detecção de chuva
├── 05-estacao-completa-local/      # Código unificado exibindo dados no Monitor Serial
└── 06-estacao-iot-thingspeak/      # Código final integrado enviando dados via Wi-Fi ao ThingSpeak
🚀 Como Usar
Clone o repositório:

Bash
git clone [https://github.com/SEU-USUARIO/Projeto-15-monitoramento-ambiental-com-IoT.git](https://github.com/SEU-USUARIO/Projeto-15-monitoramento-ambiental-com-IoT.git)
Abra o arquivo da pasta 06-estacao-iot-thingspeak na Arduino IDE.

Atualize as variáveis no código com os seus dados de Wi-Fi e ThingSpeak:

C++
const char* ssid = "NOME_DA_SUA_REDE";
const char* senha = "SENHA_DA_SUA_REDE";
unsigned long meuCanal = 0000000; // Seu Channel ID
const char* minhaChaveEscrita = "SUA_WRITE_API_KEY"; // Sua Write API Key
Conecte o ESP32 ao computador e faça o upload!


<FollowUp label="Conseguiu colar e salvar o README.md completo no GitHub?" query="Deu tudo certo ao s
