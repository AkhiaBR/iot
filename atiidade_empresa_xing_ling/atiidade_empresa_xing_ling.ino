// Atividade Peso 3.0 Empresa Xing Ling
// Dupla: Fernando e Vicenzo
// Turma: 2190

#include <Servo.h> // importa a biblioteca servo
#include <Ultrasonic.h> // importa a biblioteca ultrasonic
Servo empurrador; // declara o nome do servo 1
Servo posicionador; // declara o nome do servo 2

Ultrasonic ultrasonic(12, 13); // definicao dos pinos do ultrasonic

// definicao de variaveis e pinos:
const int pin_botao = 2;
const int led_m1 = 8;
int motor1_state = false;
int posicao_empurrador = 0;
int posicao_posicionador = 90;
int medidor_altura;
int contador_caixas_grandes = 0;
int contador_caixas_pequenas = 0;

void setup() {
  Serial.begin(9600); // comeca o serial
  pinMode(pin_botao, INPUT_PULLUP);
  pinMode(led_m1, OUTPUT); 
  empurrador.attach(3); // define o pino do servo 1
  posicionador.attach(4); // define o pino do servo 2
}

void loop() {
  bool estado_botao = !digitalRead(pin_botao); // estado do botao vai ser inverso porque é entrada PULLUP

  if(motor1_state==true){ // se o motor estar ligado:
    digitalWrite(led_m1, HIGH); // led ligará

    // servo 1 comeca a empurrar as pecas para a esteira:
    for (posicao_empurrador = 0; posicao_empurrador <= 90; posicao_empurrador += 1) {
      empurrador.write(posicao_empurrador);                                
    }
    for (posicao_empurrador = 90; posicao_empurrador >= 0; posicao_empurrador -= 1) {
      empurrador.write(posicao_empurrador);                                 
    }
  }
  else { // se o motor desliga, o led desliga 
    digitalWrite(led_m1, LOW);
  }

  // quando o motor e a peca estiver presente na esteira (posicao_empurrador = 90):
  if(motor1_state==true && posicao_empurrador==90) {
    medidor_altura = ultrasonic.read(); // medi a distancia  das caixas

    // condicoes para a altura das caixas
    if(medidor_altura<=15){
      contador_caixas_pequenas += 1; // conta uma caixa pequena
      for (posicao_posicionador = 90; posicao_posicionador <= 120; posicao_posicionador += 1) { // separador coloca as pecas pequenas no armazenamento pequeno
        posicionador.write(posicao_posicionador);                                
      }
    }
    else if(medidor_altura>16 && medidor_altura<=30) {
      contador_caixas_grandes += 1; // conta uma caixa grande
      for (posicao_posicionador = 90; posicao_posicionador <= 60; posicao_posicionador += 1) { // separador coloca as pecas grandes no armazenamento grande
        posicionador.write(posicao_posicionador);                                
      }
    }
    else { // se nao houer caixas na esteira, servo 2 em posicao de descanso
      posicao_posicionador = 90;
    }

    Serial.print("Contagem de caixas pequenas: ");
    Serial.print(contador_caixas_pequenas);
    Serial.println("Contagem de caixas grandes: ");
    Serial.print(contador_caixas_grandes);

    if(estado_botao==true) { // se o botao for pressionado, sistema desliga apresentando mensagem de erro
      Serial.print("ERRO: DESLIGANDO SISTEMA...");
      motor1_state = false;
    }
    else {
      motor1_state = true;
    }
  }
}
