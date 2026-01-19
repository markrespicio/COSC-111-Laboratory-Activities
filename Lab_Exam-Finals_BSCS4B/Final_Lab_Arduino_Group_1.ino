#include <Arduino.h>



// ================= BUTTON PINS =================
const int BTN   = 2;


// ================= BUTTON STATES =================
bool lastStateBtn   = HIGH;



void setup() {
    Serial.begin(9600);

    pinMode(BTN, INPUT_PULLUP);

}

void loop() {
    // ================= READ SERIAL COMMAND =================
    bool currentBtn = digitalRead(BTN);
    // ================= BUTTONS =================
    if (lastStateBtn == HIGH && currentBtn == LOW) {
        Serial.println("1");
        delay(150);
    }
    lastStateBtn = currentBtn;

  

    delay(50);
}
