# 🌤️ Estação Meteorológica e de Qualidade do Ar com ESP32 (IoT)

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

## 📁 Estrutura do Repositório

O repositório está organizado em etapas para demonstrar a evolução da montagem e programação do projeto:

```text
├── 01-dht11-temperatura-umidade/   # Código de teste isolado para o DHT11
├── 02-bmp180-pressao/              # Código de teste isolado para o BMP180 (I2C)
├── 03-mq135-qualidade-ar/          # Leitura analógica e alerta de qualidade do ar
├── 04-sensor-chuva/                # Leitura analógica e detecção de chuva
├── 05-estacao-completa-local/      # Código unificado exibindo dados no Monitor Serial
└── 06-estacao-iot-thingspeak/      # Código final integrado enviando dados via Wi-Fi ao ThingSpeak
