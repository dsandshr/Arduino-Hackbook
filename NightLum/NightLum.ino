#define LED_PIN 11
#define LDR_PIN A0
#define POT_PIN A1


void setup() {
  pinMode(LED_PIN, OUTPUT);

}

void loop() {
  int light = analogRead(LDR_PIN);
  int threshold = analogRead(POT_PIN);
  boolean tooDark = (light < threshold);
  
  if (tooDark)
    digitalWrite(LED_PIN, HIGH);
  else
    digitalWrite(LED_PIN, LOW); 
}
