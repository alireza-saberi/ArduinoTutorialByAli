/*
  keyboard
 
 Plays a pitch that changes based on a changing analog input
 
Hardware Required
8-ohm speaker
(3) force sensing resistors FSR
(3) 10k ohm resistors
(1) 100 ohm resistor
breadboard
hook up wire

It uses an extra file, pitches.h. This file contains all the pitch values for typical notes. 
For example, NOTE_C4 is middle C. NOTE_FS4 is F sharp, and so forth. This note table was originally
written by Brett Hagman, on whose work the tone() command was based. You may find it useful for whenever
you want to make musical notes.

 
Written by:
Ali R. Saberi
October 2013
McGill Universty
 */

#include "pitches.h"

const int threshold = 10;    // minimum reading of the sensors that generates a note

// notes to play, corresponding to the 3 sensors:
int notes[] = {
  NOTE_A4, NOTE_B4,NOTE_C3 };

void setup() {

}

void loop() {
  for (int thisSensor = 0; thisSensor < 3; thisSensor++) {
    // get a sensor reading:
    int sensorReading = analogRead(thisSensor);

    // if the sensor is pressed hard enough:
    if (sensorReading > threshold) {
      // play the note corresponding to this sensor:
      tone(8, notes[thisSensor], 20);
    } 
  }
}
