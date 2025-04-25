#include <LiquidCrystal.h>

// RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 6, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);  // Change to (20, 4) if you're using a 20x4 LCD
  lcd.print("Hello, world!");
}

void loop() {
  // You can update the screen here if needed
}
