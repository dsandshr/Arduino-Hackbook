#define CONTROL_PIN 9

int bghs = 0;

void setup() {
  pinMode(CONTROL_PIN, OUTPUT);

}

void loop() {
  bghs = (bghs + 1) % 256;
  analogWrite(CONTROL_PIN, bghs);
  delay(10 );

}
