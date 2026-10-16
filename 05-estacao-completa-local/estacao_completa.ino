#include "DHT.h" // Biblioteca do sensor de temperatura e umidade
#include <Wire.h> // Biblioteca para comunicação I2C
#include <Adafruit_BMP085.h> // Biblioteca do sensor de pressão BMP180
#define DHTPIN 4 // Pino de dados do DHT11
#define DHTTYPE DHT11 // Modelo do sensor de temperatura/umidade
const int pinoMQ135 = 34; // Pino analógico do sensor de qualidade do ar (ADC1)
const int pinoChuva = 35; // Pino analógico do sensor de chuva (ADC1)
DHT dht(DHTPIN, DHTTYPE); // Objeto do sensor DHT11
Adafruit_BMP085 bmp; // Objeto do sensor BMP180
void setup() {
Serial.begin(115200);
dht.begin();
// Tenta inicializar o BMP180; se falhar, avisa e trava o programa
if (!bmp.begin()) {
Serial.println("Não foi possível encontrar o sensor BMP180! Verifique a fiação.");
while (1) {}
}
pinMode(pinoMQ135, INPUT);
pinMode(pinoChuva, INPUT);
Serial.println("Estação Meteorológica IoT iniciada!");
Serial.println("Aguarde 1 a 3 minutos para o MQ135 aquecer antes de confiar nas leituras.");
}
void loop() {
// --- Leitura dos 4 sensores ---
float umidade = dht.readHumidity();
float temperatura = dht.readTemperature();
float pressao_hPa = bmp.readPressure() / 100.0;
int qualidadeAr = analogRead(pinoMQ135);
int chuva = analogRead(pinoChuva);
// Verifica se a leitura do DHT11 falhou
if (isnan(umidade) || isnan(temperatura)) {
Serial.println("Falha ao ler o sensor DHT11!");
}
// --- Exibe todos os dados juntos no Monitor Serial ---
Serial.println("----- Leitura da Estação -----");
Serial.print("Temperatura: ");
Serial.print(temperatura);
Serial.println(" *C");
Serial.print("Umidade: ");
Serial.print(umidade);
Serial.println(" %");
Serial.print("Pressão: ");
Serial.print(pressao_hPa);
Serial.println(" hPa");
Serial.print("Qualidade do Ar (bruto): ");
Serial.println(qualidadeAr);
Serial.print("Sensor de Chuva (bruto): ");
Serial.println(chuva);
// --- Alertas (ajuste os limiares após calibrar no seu ambiente) ---
if (qualidadeAr > 1000) {
Serial.println("Alerta: qualidade do ar ruim!");
}
if (chuva < 2000) {
Serial.println("Está chovendo!");
} else {
Serial.println("Sem chuva no momento.");
}
Serial.println("-------------------------------");
delay(2000); // Aguarda 2 segundos antes da próxima rodada de leituras
}
