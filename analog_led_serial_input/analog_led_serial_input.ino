int ledPin = 9;
int ledPin2 = 3;
int ledPin3 = 5;
int contador = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if(contador==0 && Serial.available()>=3){
    Serial.println("Digite um valor de 0 a 255:");
    int valor1 = Serial.parseInt();
    if(valor1>=0 && valor1<=255){
      analogWrite(ledPin, valor1);
      contador = 1;
    }
  }
  else if(contador==1 && Serial.available()>=3){
    Serial.println("Digite um valor de 0 a 255:");
    int valor2 = Serial.parseInt();
    if(valor2>=0 && valor2<=255){
      analogWrite(ledPin2, valor2);
      contador = 2;
    }
  }
  else if(contador==2 && Serial.available()>=3){
    Serial.println("Digite um valor de 0 a 255:");
    int valor3 = Serial.parseInt();
    if(valor3>=0 && valor3<=255){
      analogWrite(ledPin3, valor3);
      contador = 0;
    }
  }
}
