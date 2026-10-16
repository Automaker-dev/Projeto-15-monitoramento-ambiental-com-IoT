#include "DHT.h" // Inclui a biblioteca para controlar o sensor DHT
#define DHTPIN 4 // Define que o pino de dados do sensor está conectado ao GPIO 4 do ESP32
#define DHTTYPE DHT11 // Define o modelo do sensor que estamos usando (DHT11)
DHT dht(DHTPIN, DHTTYPE); // Cria o objeto 'dht' passando o pino e o tipo como parâmetros
void setup() {
Serial.begin(115200); // Inicia a comunicação serial com velocidade de 115200 bps (padrão do ESP32)
dht.begin(); // Inicializa o sensor DHT para começar a fazer leituras
}
void loop() {
delay(2000); // Aguarda 2 segundos entre cada leitura (o DHT11 é um sensor lento)

float h = dht.readHumidity(); // Lê a umidade e guarda na variável 'h' (tipo float, com casas deci-
mais)

float t = dht.readTemperature(); // Lê a temperatura em Celsius e guarda na variável 't'
// Verifica se houve erro na leitura (se 'h' ou 't' não são números válidos)
if (isnan(h) || isnan(t)) {
Serial.println("Falha ao ler o sensor DHT!");
return; // Interrompe este ciclo do loop e tenta novamente
}
// Imprime os resultados no Monitor Serial
Serial.print("Umidade: ");
Serial.print(h);
Serial.print(" %\t"); // '\t' adiciona um espaço (tabulação) para organizar o texto
Serial.print("Temperatura: ");
Serial.print(t);
Serial.println(" *C"); // 'println' imprime o texto e pula para a próxima linha
}
