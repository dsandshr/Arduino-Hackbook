
#include <math.h>

#define FIRST_LED_PIN 2
#define LED_COUNT 10

void setup() {
  for (int i = 0; i < LED_COUNT; ++i)
    pinMode(i + FIRST_LED_PIN, OUTPUT);

}

void loop() {
  float voltage = analogRead(A0) * 5.0 / 1023.0;
  float temperature = 1.0 / (log(voltage / 2.5) / 4300.0 + 1.0 / 298.0) - 273.0;
  for (int i = 0; i < LED_COUNT; ++i)
  {
    boolean enableSegment = (temperature >= 21 + i);
    digitalWrite(FIRST_LED_PIN + i, enableSegment);
  }

}
