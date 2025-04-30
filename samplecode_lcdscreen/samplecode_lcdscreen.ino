#include <LiquidCrystal.h>
#include <RotaryEncoder.h>

// LCD: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 6, 5, 4, 3, 2);

// Rotary Encoder: CLK = A3, DT = A4
RotaryEncoder encoder(A3, A4);

const int wordCount = 10;
String words[wordCount] = {
  "Apple", "Banana", "Cherry", "Dragonfruit", "Elderberry",
  "Fig", "Grape", "Honeydew", "Kiwi", "Lemon"
};

int currentWordIndex = 0; // Store current selected word index

void setup() {
  // Initialize LCD
  lcd.begin(16, 2);
  lcd.print("Rotary Display");
  delay(1000);
  lcd.clear();

  // Initialize serial (optional)
  Serial.begin(57600);

  // Display the first word
  displayWord(currentWordIndex);
}

void loop() {
  static int lastPos = 0;

  // Poll the encoder
  encoder.tick();

  int newPos = encoder.getPosition();

  // Update LCD if position changed
  if (newPos != lastPos) {
    currentWordIndex = newPos;
    displayWord(currentWordIndex);
    lastPos = newPos;
  }
}

void displayWord(int index) {

  int count = sizeof(words) / sizeof(words[0]);
  while (index < 0) {
    index += count;
  }
  index %= count;

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Word:");
  lcd.setCursor(0, 1);
  lcd.print(words[index]);

  // Optional for debugging
  Serial.print("Word Index: ");
  Serial.print(index);
  Serial.print(" --> ");
  Serial.println(words[index]);
}