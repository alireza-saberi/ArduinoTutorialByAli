/*
 We test analogWrite()
 	
  It fades LEDs up and down one at a time on digital pins 2 through 13.  
  This sketch was written for the Arduino Mega, and will not work on previous boards.
 	
  The circuit:
  * LEDs attached from pins 2 through 13 to ground.

 Written by:
Ali R. Saberi
October 2013
McGill Universty

 */
// These constants won't change.  They're used to give names
// to the pins used:
const int lowestPin = 2;
const int highestPin = 13;


void setup() {
  // set pins 2 through 13 as outputs:
  for (int thisPin =lowestPin; thisPin <= highestPin; thisPin++) { 
    pinMode(thisPin, OUTPUT); 
  }
}

void loop() {
  // iterate over the pins:
  for (int thisPin =lowestPin; thisPin <= highestPin; thisPin++) { 
    // fade the LED on thisPin from off to brightest:
    for (int brightness = 0; brightness < 255; brightness+55) {
      analogWrite(thisPin, brightness);
      delay(10);
    } 
    // fade the LED on thisPin from brithstest to off:
    for (int brightness = 255; brightness >= 0; brightness-55) {
      analogWrite(thisPin, brightness);
      delay(2);
    } 
    // pause between LEDs:
    delay(100);
  }
}
