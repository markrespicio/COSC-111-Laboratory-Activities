#ifndef LEDCONTROL_H
#define LEDCONTROL_H

int redPin, greenPin, bluePin;
bool redState = false, greenState = false, blueState = false;

void initLEDs(int r, int g, int b) {
  redPin = r;
  greenPin = g;
  bluePin = b;
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

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

#endif
