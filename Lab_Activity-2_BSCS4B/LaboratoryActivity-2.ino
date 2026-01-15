int ledPins[] = {12, 11, 10, 9, 8};  
int brightness[] = {255, 20, 80, 100, 150}; //set the brightness of each led
int numLEDs = 5;  

void setup() {
  int i = 0;
  while(i<numLEDs) {
    pinMode(ledPins[i], OUTPUT); // set all pins as output
    i++;
  }
}
void loop(){
  int i=0;
  //turn on leds one by one
  while (i < numLEDs) {
    analogWrite(ledPins[i], brightness[i]);
    delay(1000); //one second delay
    i++;
  }
  i = 0;
  //turn off led one by one
  while (i<numLEDs){
    analogWrite(ledPins[i], 0);
    delay(1000); //one second delay
    i++;
  }
}