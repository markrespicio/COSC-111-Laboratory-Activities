const int sensorPin = A0;     // Photoresistor connected to analog pin A0
const int ledPin = 8;         // LED connected to digital pin 8
const int threshold = 220;    // Brightness threshold to trigger LED blinking

bool isBlinking = false;      // Tracks if LED is currently blinking
bool isActive = true;         // Tracks if the system is active or stopped

void setup() {
  Serial.begin(9600);          // Initialize serial communication at 9600 bps
  pinMode(sensorPin, INPUT);   // Set photoresistor pin as input
  pinMode(ledPin, OUTPUT);     // Set LED pin as output
  Serial.println("System Ready. Type 'stop' to stop the system."); // Inform user
}

void loop() {
  // Check if there is any data from Serial Monitor
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n'); // Read input until Enter is pressed
    command.trim();                                // Remove extra spaces/newlines
    command.toLowerCase();                         // Convert input to lowercase for case-insensitive comparison

    // If user types "stop", halt blinking and deactivate system
    if (command == "stop" | "STOP") {
      isBlinking = false;
      isActive = false;
      digitalWrite(ledPin, LOW);                  // Turn off LED
      Serial.println("Blinking stopped. System halted."); // Notify user
    }
  }

  // If system is inactive, skip reading sensor and blinking
  if (!isActive) return;

  // Read brightness value from photoresistor
  int brightness = analogRead(sensorPin);
  Serial.print("Brightness: ");   // Print label
  Serial.println(brightness);     // Print actual brightness reading

  // Start blinking if brightness exceeds threshold and LED is not already blinking
  if (brightness >= threshold && !isBlinking) {
    isBlinking = true;
    Serial.println("Threshold reached!"); // Notify user that blinking started
  }

  // Handle LED blinking
  if (isBlinking) {
    digitalWrite(ledPin, HIGH);   // Turn LED ON
    delay(100);                   // Wait 100 milliseconds
    digitalWrite(ledPin, LOW);    // Turn LED OFF
    delay(100);                   // Wait 100 milliseconds
  } else {
    delay(200);                   // Wait 200 milliseconds when LED is not blinking
  }
}
