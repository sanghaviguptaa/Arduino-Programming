/*Interfacing Stepper motor with Arduino Uno 
 * 
 * Hardware components
 * Arduino Uno 
 * L298 - Driver
 * stepper motor 
 */
 
#include <Stepper.h>

// 8 steps are taken here to complete 360degrees in 45 degree angle 
const int stepsPerRevolution = 8;  // change this to fit the number of steps per revolution
// for your motor

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

void setup() {
  // set the speed at 60 rpm:
  myStepper.setSpeed(10);
  
}

void loop() {
  // step one revolution  in one direction: 
  myStepper.step(stepsPerRevolution);
  delay(500);

  // step one revolution in the other direction:
  myStepper.step(-stepsPerRevolution);
  delay(500);
}
