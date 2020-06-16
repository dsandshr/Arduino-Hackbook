#define PLUS_BUTTON_PIN   2
#define MINUS_BUTTON_PIN  3
#define LED_PIN           9
int brightness = 100;
boolean plusUp = true;
boolean minusUp = true;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(PLUS_BUTTON_PIN, INPUT_PULLUP);
  pinMode(MINUS_BUTTON_PIN, INPUT_PULLUP); 

}

void loop() {
  analogWrite(LED_PIN, brightness);
  plusUp = handleClick(PLUS_BUTTON_PIN, plusUp, +85);
  minusUp = handleClick(MINUS_BUTTON_PIN, minusUp, -85);
}

boolean handleClick(int buttonPin, boolean wasUp, int delta)
{
   boolean isUp = digitalRead(buttonPin);
   if (wasUp && !isUp)
   {
    delay(10);
    isUp = digitalRead(buttonPin);
    if (!isUp)
     brightness = constrain(brightness + delta, 0, 255);
   }
   return (isUp);
}
