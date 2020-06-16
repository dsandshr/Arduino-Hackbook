#define BUZZER_PIN 3
#define LDR_PIN A0

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);

}

void loop() {
  int val, fre;

  val = analogRead(LDR_PIN);
  fre = map(val, 0, 1023, 3500, 4500);
  tone(BUZZER_PIN, fre, 100);

}
