#include <Wire.h> // Inclui a biblioteca Wire, necessária para a comunicação I2C
#include <Adafruit_BMP085.h> // Inclui a biblioteca específica para o sensor BMP180/BMP085
Adafruit_BMP085 bmp; // Cria o objeto 'bmp' para interagir com o sensor
void setup() {
Serial.begin(115200); // Inicia a comunicação serial
// Tenta inicializar o sensor. Se falhar, entra em um loop infinito
if (!bmp.begin()) {
Serial.println("Não foi possível encontrar um sensor BMP180 válido, verifique a fiação!");
while (1) {} // Loop infinito que trava o programa em caso de erro
}
}
void loop() {
// Lê a pressão em Pascals (Pa) usando a função readPressure()
// Dividimos por 100.0 para converter Pascals para hectoPascals (hPa), que é a medida padrão
float pressao_hPa = bmp.readPressure() / 100.0;
Serial.print("Pressão: ");
Serial.print(pressao_hPa);
Serial.println(" hPa");
delay(2000); // Aguarda 2 segundos antes da próxima leitura
}
