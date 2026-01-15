#ifndef LEDCONTROL_H
#define LEDCONTROL_H

int redPin, greenPin, bluePin;
bool redState = false, greenState = false, blueState = false;

int btn1Pin, btn2Pin, btn3Pin;
bool lastBtn1 = HIGH, lastBtn2 = HIGH, lastBtn3 = HIGH;

// Initialize LED pins
void initLEDs(int r, int g, int b) {
  redPin = r;
  greenPin = g;
  bluePin = b;

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, LOW);
}

// Initialize button pins
void initButtons(int b1, int b2, int b3) {
  btn1Pin = b1;
  btn2Pin = b2;
  btn3Pin = b3;

  pinMode(btn1Pin, INPUT_PULLUP);
  pinMode(btn2Pin, INPUT_PULLUP);
  pinMode(btn3Pin, INPUT_PULLUP);
}

// Toggle functions for individual LEDs
void toggleRed() {
  redState = !redState;
  digitalWrite(redPin, redState ? HIGH : LOW);
}

void toggleGreen() {
  greenState = !greenState;
  digitalWrite(greenPin, greenState ? HIGH : LOW);
}

void toggleBlue() {
  blueState = !blueState;
  digitalWrite(bluePin, blueState ? HIGH : LOW);
}

// Turn all LEDs ON or OFF
void allOn() {
  digitalWrite(redPin, HIGH);
  digitalWrite(greenPin, HIGH);
  digitalWrite(bluePin, HIGH);
  redState = greenState = blueState = true;
}

void allOff() {
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, LOW);
  redState = greenState = blueState = false;
}

// Read button states and send serial output (independent)
void handleButtons() {
  bool btn1 = digitalRead(btn1Pin);
  bool btn2 = digitalRead(btn2Pin);
  bool btn3 = digitalRead(btn3Pin);

  if (lastBtn1 == HIGH && btn1 == LOW) Serial.println("R");
  if (lastBtn2 == HIGH && btn2 == LOW) Serial.println("G");
  if (lastBtn3 == HIGH && btn3 == LOW) Serial.println("B");

  lastBtn1 = btn1;
  lastBtn2 = btn2;
  lastBtn3 = btn3;
}

#endif