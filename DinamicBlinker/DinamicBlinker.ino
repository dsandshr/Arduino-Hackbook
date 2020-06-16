#define LED_PIN 9

void setup()
{
  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  analogWrite(LED_PIN, 85);
  delay(500);

  analogWrite(LED_PIN, 170);
  delay(500);

  digitalWrite(LED_PIN, 255);
  delay(500);
}
