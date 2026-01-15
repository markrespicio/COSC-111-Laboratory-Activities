#define HEAT A0
#define LIGHT A2
#define BULB 12
#define SPEAKER 11 

const float TEMP_THRESHOLD = 50.0;  // Celsius
const int LIGHT_THRESHOLD = 220;    // Analog brightness threshold (0–1023)

const int RESISTOR = 10000;      // 10kΩ fixed resistor
const int RESISTANCE = 10000;   // thermistor resistance at 25°C
const float TEMPERATURE = 25.0; // 25°C baseline
const float BETA = 3950;       // beta value for the thermistor

float readTemperature() {
  delay(100);
  int HValue = analogRead(HEAT);
  delay(500);
  if (HValue <= 0) return -999; // safety check

  float resistance = RESISTOR * (1023.0 / HValue - 1.0);

  float steinhart;
  steinhart = resistance / RESISTANCE;
  steinhart = log(steinhart);
  steinhart /= BETA;
  steinhart += 1.0 / (TEMPERATURE + 273.15);
  steinhart = 1.0 / steinhart;
  steinhart -= 273.15;

  return steinhart;
}

int readBrightness() {
  delay(100);
  int value = analogRead(LIGHT);
  delay(500);
  return value;
}

void fireAlert() {
  digitalWrite(BULB, HIGH);
  digitalWrite(SPEAKER, HIGH);
  delay(5000);
  digitalWrite(BULB, LOW);
  digitalWrite(SPEAKER, LOW);
  delay(1);
}

void setup() {
  Serial.begin(9600);
  pinMode(BULB, OUTPUT);
  pinMode(SPEAKER, OUTPUT);
}

void loop() {
  float temperature = readTemperature();
  int brightness = readBrightness();

  Serial.print("Temp: ");
  Serial.print(temperature);
  Serial.print(" °C | Brightness: ");
  Serial.println(brightness);

  // Trigger fire alert if both thresholds are met
  if (temperature >= TEMP_THRESHOLD && brightness <= LIGHT_THRESHOLD) {
    fireAlert();
  } else {
    digitalWrite(BULB, LOW);
    digitalWrite(SPEAKER, LOW);
  }

  delay(300);
}
