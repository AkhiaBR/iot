// Atividade Avaliativa Peso 4.0
// Aluno: Fernando Gonçalves
// Turma: 2190

#include <Ultrasonic.h> // importa a biblioteca do sensor ultrasonico
#include "DHT.h" // importa a bilioteca para o sensor DHT

#define DHTPIN 2 // define o pino do DHT para 2
#define DHTTYPE DHT11 // define o tipo do DHT
Ultrasonic ultrasonic(12, 13); // define os pinos do sensor ultrasonico
DHT dht(DHTPIN, DHTTYPE); // define os pinos e o tipo do DHT, assim como sua variável

// definição das variáveis principais:
int distance; 
const int led_aquecimento = 5;
const int led_amarelo = 7;
const int led_saida = 8;
const int led_entrada = 9;
float nivel_tanque;
float nivel_tanque_atual;

void setup() { 
  Serial.begin(9600); // inicializa o serial
  dht.begin(); // inicializa a função do DHT
}

void loop() {
  bool aquecimento = digitalRead(led_aquecimento); // define os estados dos LEDs como booleanas
  bool amarelo = digitalRead(led_amarelo); // define os estados dos LEDs como booleanas
  bool saida = digitalRead(led_saida); // define os estados dos LEDs como booleanas
  bool entrada = digitalRead(led_entrada); // define os estados dos LEDs como booleanas
  distance = ultrasonic.read(); // a distância é igual a leitura do sensor ultrasonico
  nivel_tanque = (40*40)*3.14*(16000*3.14); // define o volume do tanque (252.405.760)
  nivel_tanque_atual = nivel_tanque - distance; // define o nível do líquido presente no tanque
  float t = dht.readTemperature(); // a temperatura é igual a leitura da função de leitura de temperatura do DHT

  if (isnan(t)) { // verifica erros com os valores de leitura
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  if(entrada == true){ // Se o valor de entrada for true, liquido entra, ligando o LED de entrada
    digitalWrite(led_entrada, HIGH);
  }
  else{
    digitalWrite(led_entrada, LOW);
  }

  if(saida == true){ // Se o valor de entrada for true, liquido sai, ligando o LED de saída
    if(nivel_tanque>75721728 && (t>=24 || t<=29)){
      digitalWrite(led_saida, HIGH);
    }
  }
  else{
    digitalWrite(led_saida, LOW);
  }

  if(aquecimento == true){ // se o aquecimento for true executar a condicao abaixo:
    if(nivel_tanque<25240576){ // se o nivel do tanque for menor que 10% liga os LEDs
      digitalWrite(led_aquecimento, HIGH);
      digitalWrite(led_amarelo, HIGH);
    }
  }
  else if(aquecimento == false){ // se o aquecimento for false, deliga-os
      digitalWrite(led_aquecimento, LOW);
      digitalWrite(led_amarelo, LOW);
  }

  Serial.print(F("%  Temperature: ")); // imprime a temperatura no monitor do serial
  Serial.print(t);
  Serial.println(F("°C "));
}
