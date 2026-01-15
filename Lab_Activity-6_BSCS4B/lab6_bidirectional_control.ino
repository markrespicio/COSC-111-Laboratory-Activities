#include "LEDControl.h"

// Pin definitions
#define RED_LED     7
#define GREEN_LED   6
#define BLUE_LED    5
#define BTN1        12
#define BTN2        11
#define BTN3        10

void setup() {
  Serial.begin(9600);

  initLEDs(RED_LED, GREEN_LED, BLUE_LED);
  initButtons(BTN1, BTN2, BTN3);
}

// Function moved from header
void handleSerial() {
  if (Serial.available()) {
    char input = Serial.read();
    input = tolower(input);

    switch (input) {
      case '1': toggleRed(); break;
      case '2': toggleGreen(); break;
      case '3': toggleBlue(); break;
    }
  }
}

void loop() {
  handleButtons();   // Button presses → Serial only
  handleSerial();    // Serial input → LED toggle only
}