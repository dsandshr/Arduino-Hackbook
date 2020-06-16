#define BUTTON_PIN 3
#define LED_PIN 13
boolean buttonWasUp = true;
boolean lenEnabled = false;

  void setup() {
    pinMode(LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT_PULLUP);
}

  void loop() {
    boolean buttonIsUp = digitalRead(BUTTON_PIN);
    if (buttonWasUp && !buttonIsUp)
    {
      delay(10);
      if (buttonIsUp = digitalRead(BUTTON_PIN))
      {
        lenEnabled = !lenEnabled;
        digitalWrite(LED_PIN, lenEnabled);
      }
    }
}
