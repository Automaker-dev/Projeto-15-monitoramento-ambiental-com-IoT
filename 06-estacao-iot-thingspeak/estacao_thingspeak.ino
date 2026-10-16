#include "DHT.h"
#include <Wire.h>
#include <Adafruit_BMP085.h>
#include <WiFi.h> // Biblioteca de Wi-Fi, já embutida no núcleo do ESP32
#include "ThingSpeak.h" // Biblioteca para enviar dados ao ThingSpeak
#define DHTPIN 4
#define DHTTYPE DHT11
const int pinoMQ135 = 34;
const int pinoChuva = 35;
DHT dht(DHTPIN, DHTTYPE);
Adafruit_BMP085 bmp;
WiFiClient client;
// --- Credenciais de Wi-Fi (preencha com os dados da sua rede) ---
const char* ssid = "NOME_DA_SUA_REDE";
const char* senha = "SENHA_DA_SUA_REDE";
// --- Dados do canal ThingSpeak (preencha com os dados do seu canal) ---
unsigned long meuCanal = 0000000; // Channel ID
const char* minhaChaveEscrita = "XXXXXXXXXXXXXXXX"; // Write API Key
void setup() {
Serial.begin(115200);
dht.begin();
if (!bmp.begin()) {
Serial.println("Não foi possível encontrar o sensor BMP180! Verifique a fiação.");
while (1) {}
}
pinMode(pinoMQ135, INPUT);
pinMode(pinoChuva, INPUT);
WiFi.mode(WIFI_STA);
ThingSpeak.begin(client); // Inicializa a comunicação com o ThingSpeak
}
void loop() {
// --- Garante que o Wi-Fi está conectado antes de enviar dados ---
if (WiFi.status() != WL_CONNECTED) {
Serial.print("Conectando ao Wi-Fi");
WiFi.begin(ssid, senha);
while (WiFi.status() != WL_CONNECTED) {
delay(500);
Serial.print(".");
}
Serial.println(" conectado!");
}
// --- Leitura dos 4 sensores (igual à Atividade 5) ---
float umidade = dht.readHumidity();
float temperatura = dht.readTemperature();
float pressao_hPa = bmp.readPressure() / 100.0;
int qualidadeAr = analogRead(pinoMQ135);
int chuva = analogRead(pinoChuva);
// --- Envia cada leitura para um campo (field) do canal ThingSpeak ---
ThingSpeak.setField(1, temperatura);
ThingSpeak.setField(2, umidade);
ThingSpeak.setField(3, pressao_hPa);
ThingSpeak.setField(4, qualidadeAr);
ThingSpeak.setField(5, chuva);
int codigoResposta = ThingSpeak.writeFields(meuCanal, minhaChaveEscrita);
if (codigoResposta == 200) {
Serial.println("Dados enviados ao ThingSpeak com sucesso!");
} else {
Serial.println("Erro ao enviar dados. Código HTTP: " + String(codigoResposta));
}
delay(20000); // O plano gratuito do ThingSpeak exige intervalo mínimo de 15s entre envios
}
