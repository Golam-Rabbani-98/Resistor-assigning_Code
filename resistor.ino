int R_clk_Pin = 5;
int SR_CLK_Pin = 6;
int dataPin = 4;
byte leds = 0;
void setup()
{
pinMode(R_clk_Pin, OUTPUT);
pinMode(dataPin, OUTPUT);
pinMode(SR_CLK_Pin, OUTPUT);
}

void loop()
{
leds = 0;
delay(500);
for (int i = 0; i < 8; i++) // Turn all the LEDs ON one by one.
{
bitSet(leds, i); // Set the bit that controls that LED in the variable 'leds'
updateShiftRegister();
delay(500);
}
}
void updateShiftRegister()
{
digitalWrite(R_clk_Pin , LOW);
shiftOut(dataPin, SR_CLK_Pin, LSBFIRST, leds);
digitalWrite(R_clk_Pin, HIGH);
}
