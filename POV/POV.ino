

byte POV[8] = {
  0b00000110,
  0b00001001,
  0b00010001,
  0b00100010,
  0b00010001,
  0b00001001,
  0b00000110,
  0b00000000
};
  

void setup() {
  DDRD = B11111111;

}

void loop() {
  for (byte i = 2; i < 9; i++)
  {
    PORTD = POV[i];
    delay(10);
  }
}
