const int pin_entrada = A0;
const int pin_saida01 = 8;
int valor; // Valor da tensão lida em bits
float tensao;  // Valores analógicos serão sempre decimais

void setup() {
  Serial.begin(9600);
  pinMode(pin_entrada, INPUT);
}

void loop() {
  valor = analogRead(pin_entrada);
  tensao = float(valor)*5/1023;
  Serial.print("Tensao = ");
  Serial.print(tensao);
  Serial.println(" V");

  if(tensao < 3){ // Liga o LED quando a voltagem ser maior que 3V e desliga quando for menor que 3V.
    digitalWrite(pin_saida01, LOW);
  }
  else  if(tensao >= 3){
    digitalWrite(pin_saida01, HIGH);
  }
}