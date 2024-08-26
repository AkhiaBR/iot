#include <Servo.h> // importa a biblioteca servo
#include <Ultrasonic.h> // importa a biblioteca ultrasonic

Ultrasonic ultrasonic(12, 13); // define os pinos do ultrasonic
Servo myservo; // declara o nome do servo
const int pin_button = 7; // pino do botão
int pos = 0; // posicao do angulo do servo
int distancia;
bool botao1;
int estado = 0;
int tempo_antigo = millis();
int tempo_atual = millis();

void setup() {
  Serial.begin(9600);
  myservo.attach(9); // define o pino do servo
  pinMode(pin_button, INPUT_PULLUP);
}

void loop() {
  botao1 = !digitalRead(pin_button);
  distancia = ultrasonic.read();

  if(estado==0){
    myservo.write(0);
    if(distancia<10){
      estado=1;
    }
  }
  else if(estado==1){
    Serial.print("Aberte o botão");
    if(botao1==true){
      estado=2;
    }
  }
  else if(estado2){
    Serial.println("");
    if()
  }
}
