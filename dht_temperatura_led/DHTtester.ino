#include "DHT.h" // Importa
#define DHTPIN 2 // Define o pino do  DHT
#define DHTTYPE DHT11 // Define o tipo do DHT

const int pin_vermelho = 8;
const int pin_amarelo = 9;
const int pin_verde = 10;
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));
  pinMode(pin_vermelho, OUTPUT);
  pinMode(pin_amarelo, OUTPUT);
  pinMode(pin_verde, OUTPUT);
  dht.begin(); // Começa a função do DHT
}

void loop() {
  delay(1000);

  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);

  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  float hif = dht.computeHeatIndex(f, h);
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));

  if(t<=25){
    digitalWrite(pin_verde, HIGH);
    digitalWrite(pin_vermelho, LOW);
    digitalWrite(pin_amarelo, LOW);
  }
  else if(t>25 && t<=30){
    digitalWrite(pin_verde, LOW);
    digitalWrite(pin_vermelho, LOW);
    digitalWrite(pin_amarelo, HIGH);
  }
  else if(t>30){
    digitalWrite(pin_verde, LOW);
    digitalWrite(pin_vermelho, HIGH);
    digitalWrite(pin_amarelo, LOW);
  }
}
