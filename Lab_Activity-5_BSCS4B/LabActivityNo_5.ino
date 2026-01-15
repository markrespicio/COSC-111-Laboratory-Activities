#include "LEDControl.h"

void setup() {
  Serial.begin(9600);
  initLEDs(8, 9, 10);
}
 
bool terminate = false;

void loop() {
  // Read all incoming bytes from Python
  while (Serial.available() > 0) {
    char input = Serial.read();
    input = tolower(input);
    if (terminate == true) break;
    if (input == '\n') continue;

    switch(input) {
      case 'r': toggleRed(); break;
      case 'g': toggleGreen(); break;
      case 'b': toggleBlue(); break;
      case 'a': allOn(); break;
      case 'o': allOff(); break;
      case 'x': allOff(); terminate = true; break;
    }
  }
}
