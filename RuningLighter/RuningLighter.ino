#define FIRST_LED_PIN 2
#define LAST_LED_PIN 11

void setup() {
  for (int pin = FIRST_LED_PIN; pin <= LAST_LED_PIN; ++pin)
  pinMode(pin, OUTPUT);
}

void loop() {
  unsigned long int milsec =millis();
  int pin = FIRST_LED_PIN + (milsec / 120) % 10;
  digitalWrite(pin, HIGH);
  delay(10);
  digitalWrite(pin, LOW);

}
