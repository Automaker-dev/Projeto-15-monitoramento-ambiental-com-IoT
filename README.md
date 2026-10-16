# 🌤️ Projeto 15: Monitoramento Ambiental com IoT

Este repositório contém a documentação e o código-fonte de uma **Estação Meteorológica e de Qualidade do Ar baseada em ESP32**, desenvolvida passo a passo desde os testes individuais com cada sensor até a integração completa e envio de dados para a nuvem através da plataforma **ThingSpeak**.

---

## 📌 Visão Geral do Projeto

O objetivo do projeto é monitorar variáveis ambientais em tempo real e disponibilizar as informações para acesso remoto via Wi-Fi. O sistema realiza a medição das seguintes grandezas:

* **Temperatura e Umidade Relativa do Ar:** Sensor DHT11
* **Pressão Atmosférica:** Sensor BMP180
* **Qualidade do Ar (Detecção de Gases):** Sensor MQ-135
* **Presença e Intensidade de Chuva:** Sensor de Chuva Analógico (FC-37)

Os dados são coletados pelo ESP32, processados e transmitidos periodicamente para o **ThingSpeak**, permitindo a geração de gráficos e o acompanhamento do histórico do clima local.

---

## 🛠️ Hardware Utilizado

* **Microcontrolador:** ESP32 (38 pinos)
* **Sensores:**
  * Sensor de Temperatura e Umidade DHT11
  * Sensor de Pressão Atmosférica BMP180
  * Sensor de Qualidade do Ar MQ-135
  * Sensor de Chuva Analógico (FC-37)
* **Protocolos e Comunicação:**
  * I2C (BMP180 - SDA/SCL)
  * Leitura Digital (DHT11)
  * Leituras Analógicas (MQ-135 e Sensor de Chuva)

---

## 📚 Bibliotecas Necessárias

Para compilar o código na Arduino IDE, instale as seguintes bibliotecas através do **Gerenciador de Bibliotecas**:

1. [`DHT sensor library` (por Adafruit)](https://github.com/adafruit/DHT-sensor-library)
2. [`Adafruit BMP085 Library` (por Adafruit)](https://github.com/adafruit/Adafruit-BMP085-Library)
3. [`ThingSpeak` (por MathWorks)](https://github.com/mathworks/thingspeak-arduino)
4. `WiFi` *(Inclusa no pacote oficial do ESP32 para Arduino IDE)*

---

## 📁 Estrutura do Repositório

O projeto foi dividido em pastas numeradas para facilitar a organização do código em cada fase de teste:

```text
├── 01-dht11-temperatura-umidade/   # Código de teste isolado para o sensor DHT11
├── 02-bmp180-pressao/              # Código de teste isolado para o sensor BMP180 (I2C)
├── 03-mq135-qualidade-ar/          # Leitura analógica e monitoramento do MQ-135
├── 04-sensor-chuva/                # Leitura analógica do sensor de chuva (FC-37)
├── 05-estacao-completa-local/      # Código integrado exibindo todas as leituras no Monitor Serial
└── 06-estacao-iot-thingspeak/      # Código final integrado enviando dados via Wi-Fi ao ThingSpeak

```

---

## 🚀 Como Executar o Projeto

1. **Clone este repositório:**
```bash
git clone [https://github.com/Automaker-dev/Projeto-15-monitoramento-ambiental-com-IoT.git](https://github.com/Automaker-dev/Projeto-15-monitoramento-ambiental-com-IoT.git)

```


2. **Abra o projeto:**
Navegue até a pasta `06-estacao-iot-thingspeak` e abra o código na **Arduino IDE**.
3. **Configure suas credenciais:**
Altere as linhas abaixo no código com os dados da sua rede Wi-Fi e da sua conta no ThingSpeak:
```cpp
const char* ssid = "NOME_DA_SUA_REDE";
const char* senha = "SENHA_DA_SUA_REDE";
unsigned long meuCanal = 0000000;                     // Seu ID do Canal no ThingSpeak
const char* minhaChaveEscrita = "SUA_WRITE_API_KEY"; // Sua Write API Key

```


4. **Upload:**
Conecte a placa ESP32 ao computador via USB, selecione a porta correta e faça o upload do código.
