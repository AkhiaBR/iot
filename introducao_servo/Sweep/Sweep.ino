#include <Servo.h> // importa a biblioteca servo

Servo myservo; // declara o nome do servo

int pos = 0; // posicao do angulo do servo

void setup() {
  myservo.attach(9); // define o pino do servo
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) {
    myservo.write(pos);                                
  }
  for (pos = 180; pos >= 0; pos -= 1) {
    myservo.write(pos);                                 
  }
}
