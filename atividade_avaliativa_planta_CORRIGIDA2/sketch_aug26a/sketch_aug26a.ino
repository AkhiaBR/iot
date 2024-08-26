// Atividade Avaliativa CORRIGIDA Peso 4.0
// Aluno: Fernando Gonçalves
// Turma: 2190

#include <Ultrasonic.h> // importa a biblioteca do sensor ultrasonico
#include "DHT.h" // importa a bilioteca para o sensor DHT
#define DHTPIN 2 // define o pino do DHT para 2
#define DHTTYPE DHT11 // define o tipo do DHT
#define pin_ve 9 // pino de entrada
#define pin_vs 8 // pino de saida
#define pin_aque 7 // pino de aquecimento
#define pin_alarme 5 // pino de alarme

Ultrasonic ultrasonic(12, 13); // define os pinos do sensor ultrasonico
DHT dht(DHTPIN, DHTTYPE); // define os pinos e o tipo do DHT, assim como sua variável
int h; 

void setup() { 
  Serial.begin(9600); // inicializa o serial
  dht.begin(); // inicializa a função do DHT
  pinMode(pin_ve, OUTPUT);
  pinMode(pin_vs, OUTPUT);
  pinMode(pin_aque, OUTPUT);
  pinMode(pin_alarme, OUTPUT);
}

void loop() {
  h = ultrasonic.read(); // a altura é igual a leitura do sensor ultrasonico
  float t = dht.readTemperature(); // a temperatura é igual a leitura da função de leitura de temperatura do DHT

  if (isnan(t)) { // verifica erros com os valores de leitura
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  if(h==0){ // se altura igual a zero, entrada LOW
    digitalWrite(pin_ve, LOW);
  }
  else{
    digitalWrite(pin_ve, HIGH);
  }

  if((h<200) && (t>24) && (t<29)){ // se altura menor que 200 e temperatura entre  24 e 29, saida HIGH
    digitalWrite(pin_vs, HIGH);
  }
  else{
    digitalWrite(pin_vs, LOW);
  }

  if((t<24) && (h<320)){ // se temperatura menor que 24 e altura menor que 320, aquecimento HIGH
    digitalWrite(pin_aque, HIGH);
  }
  else{
    digitalWrite(pin_aque, LOW);
  }

  if(h>360){ // se altura maior que 360, alarme HIGH
    digitalWrite(pin_alarme, HIGH);
  }
  else{
    digitalWrite(pin_alarme, LOW);
  }

  Serial.print(F("%  Temperature: ")); // imprime a temperatura no monitor do serial
  Serial.print(t);
  Serial.println(F("°C "));
}
