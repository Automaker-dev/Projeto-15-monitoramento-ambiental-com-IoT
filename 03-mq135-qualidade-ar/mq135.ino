const int pinoMQ135 = 34; // Define uma constante inteira para o pino onde o sensor está conectado (GPIO
34)
void setup() {
Serial.begin(115200); // Inicia a comunicação serial
// Não é estritamente necessário definir pinMode para leitura analógica no ESP32, mas é uma boa prática
pinMode(pinoMQ135, INPUT);
}
void loop() {
// A função analogRead() lê a tensão no pino e converte para um número.
// No ESP32, o conversor analógico-digital (ADC) tem 12 bits, então o valor vai de 0 a 4095.
int valorQualidadeAr = analogRead(pinoMQ135);
Serial.print("Qualidade do Ar (Valor Bruto): ");
Serial.println(valorQualidadeAr);
