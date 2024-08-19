#include <Ultrasonic.h>

Ultrasonic ultrasonic(12, 13); // Define os pinos do sensor ultrasonico
int distance;
const int pin_led_vermelho = 2;
const int pin_led_amarelo = 3;
const int pin_led_verde = 4;

void setup() {
  pinMode(pin_led_vermelho, OUTPUT);
  pinMode(pin_led_amarelo, OUTPUT);
  pinMode(pin_led_verde, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  distance = ultrasonic.read();
  
  Serial.print("Distancia em CM:");
  Serial.println(distance);

  if(distance>100){
    digitalWrite(pin_led_verde, HIGH);
    digitalWrite(pin_led_amarelo, LOW);
    digitalWrite(pin_led_vermelho, LOW);
  }
  else if(distance<=100 && distance>20){
    digitalWrite(pin_led_amarelo, HIGH);
    digitalWrite(pin_led_verde, LOW);
    digitalWrite(pin_led_vermelho, LOW);
  }
  else if(distance<=20){
    digitalWrite(pin_led_vermelho, HIGH);
    digitalWrite(pin_led_amarelo, LOW);
    digitalWrite(pin_led_verde, LOW);
  }
}
