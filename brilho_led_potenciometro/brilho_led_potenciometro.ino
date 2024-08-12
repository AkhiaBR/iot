// Liga o liga e aumenta o brilho de acordo com o potenciometro

const int pin_saida = 9;
const int pin_entrada = A0;
int valor;
float tensao;

void setup() {
  Serial.begin(9600);
  pinMode(pin_entrada, INPUT);
}

void loop() {
  valor = analogRead(pin_entrada);
  tensao = float(valor)*5/255;
  Serial.print("Tensao = ");
  Serial.print(tensao);
  Serial.println(" V");

  analogWrite(pin_saida, tensao);
}
