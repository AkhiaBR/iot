// Atividade Cafeteira Peso 3.0
// Nome: Fernando Gonçalves
// Turma: 2190

#include "DHT.h" // importa a biblioteca do DHT
#include <Ultrasonic.h> // importa a biblioteca do Ultrasonic

#define DHTPIN 2 // define o pino do DHT
#define DHTTYPE DHT11 // define o tipo de DHT sendo utilizado
Ultrasonic ultrasonic(12, 13); // define os pinos do ultrasonic
DHT dht(DHTPIN, DHTTYPE); // Configuração do DHT 1 (o único utilizado)

// definição de variáveis principais: 
const int pin_botao = 3;
const int led_fazer_cafe = 8;
const int led_pronto = 9;
unsigned long tempo_ant =  0;
unsigned long tempo_atual = 0;

// definição de pinos e setup de funções: 
void setup() {
  pinMode(pin_botao, INPUT_PULLUP);
  pinMode(led_fazer_cafe, OUTPUT);
  pinMode(led_pronto, OUTPUT);
  dht.begin();
}

void loop() {
  // definição de variáveis auxiliares: 
  int botao = !digitalRead(pin_botao);
  int distancia = ultrasonic.read();
  float temperatura = dht.readTemperature();

  if(botao==true) { // enquanto o botão estiver pressionado: 
    if(temperatura>=26 && distancia<=5) { // se a temperatura for de 26 grau Celsius e o copo estiver presente abaixo do bloco (distancia menor ou igual a 5cm)
      digitalWrite(led_fazer_cafe, HIGH); // led de fazer café liga
      tempo_atual = millis(); // contador do tempo atual começa

      if(tempo_atual-tempo_ant>=10000) { // se o contador do tempo atual menos o tempo anterior (0) for maior ou igual a 10 segundos:
        digitalWrite(led_fazer_cafe, LOW); // desliga o faz café
        digitalWrite(led_pronto, HIGH); // informa que o café está pronto
      }
      else { // se ainda não se passaram 10 segundos o faz café continuará ligado
        digitalWrite(led_fazer_cafe, HIGH);
        digitalWrite(led_pronto, LOW);
      }
    }
  }
  else { // quando o usuário tira o dedo do botão, o contador reseta
    tempo_atual = 0;
  }
}
