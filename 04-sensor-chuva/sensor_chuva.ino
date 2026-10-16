const int pinoChuva = 35; // Define o pino analógico conectado ao sensor de chuva (GPIO 35)
void setup() {
Serial.begin(115200); // Inicia a comunicação serial
pinMode(pinoChuva, INPUT);
}
void loop() {
// Lê o valor analógico do sensor (0 a 4095)
int valorChuva = analogRead(pinoChuva);
Serial.print("Leitura do Sensor de Chuva: ");
Serial.println(valorChuva);
// O sensor funciona de forma inversa:
// Seco = Resistência alta = Valor lido alto (próximo a 4095)
// Molhado = Resistência baixa = Valor lido baixo
if (valorChuva < 2000) {
Serial.println("Está chovendo!");
} else {
Serial.println("Sem chuva no momento.");
}
delay(2000); // Aguarda 2 segundos
}
