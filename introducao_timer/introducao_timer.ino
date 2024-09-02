const byte led_pin = 13; 
const byte interrupt_button = 2;
volatile byte state = LOW;

void setup() {
  pinMode(led_pin, OUTPUT);
  pinMode(interrupt_button, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interrupt_button), blink, LOW); // seta o funcionamento do interruptor // CHANGE: caso alguma alteracao
                                                                                                                  // RISING: caso botao true
                                                                                                                  // FALLING: caso botao false
}

void loop() {
  digitalWrite(led_pin, state);
}

void blink() {
  state = !state; 
}