#include <SoftwareSerial.h>
#include "Adafruit_Thermal.h"

// Nano pin D10 → Printer RX
// Nano pin D11 → (not used, but required by SoftwareSerial)
SoftwareSerial printerSerial(10, 11);
Adafruit_Thermal printer(&printerSerial);

String incomingLine = "";  // Buffer to hold incoming text

void setup() {
  printerSerial.begin(9600);  // Match baud rate with Python
  printer.begin();
  printer.setDefault();

  Serial.begin(9600);  // For communication with Python
}

void loop() {
  while (Serial.available() > 0) {
    char c = Serial.read();

    // Check for end of line
    if (c == '\n') {
      // Print the full line
      printer.println(incomingLine);
      incomingLine = "";  // Clear buffer
    } else {
      incomingLine += c;
    }
  }
}
