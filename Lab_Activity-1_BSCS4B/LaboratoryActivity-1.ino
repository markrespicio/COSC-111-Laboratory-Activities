int ledPins[] = {12, 11, 10, 9, 8};  
int numLEDs = 5;  

void setup() {
  // output lahat ng pinss
  for (int i = 0; i < numLEDs; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  // on lahat with 1 sec delay
  for (int i = 0; i < numLEDs; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(1000); // 1 second delay
  }

  // off lahat with 1 sec delay
  for (int i = 0; i < numLEDs; i++) {
    digitalWrite(ledPins[i], LOW);
    delay(1000); // 1 second delay
  }
}
