const int pin_led = 8;
int porta = A1;
int valor;

void setup() {
  Serial.begin(9600);
  pinMode(porta, INPUT);
}

void loop() {
  valor = analogRead(porta);
  Serial.println(valor);

  if(valor < 30){ // Se o sensor de luz for menor que 30, o LED ligará, como um poste de luz
    digitalWrite(pin_led, HIGH);
  }
  else if(valor >= 30){
    digitalWrite(pin_led, LOW); // Se ele for maior que 30, ele desligará 
  }
}
