/* Toggling digital pin between HIGH and LOW using Arduino Uno
 *  
 *  Hardware components
 *  Arduino Uno 
 *  LED Red
 *  Oscilloscope
 *  
 *  Author : Sanghavi 
 *  Date : 29-08-2022
 */
// As we need a constant for digital pin 
const int PIN = 2;
void setup() {
  // configure D2 of Arduino to output mode
  pinMode(PIN,OUTPUT);

}

void loop() {
  // write D2 of Arduino to LOW
  digitalWrite(PIN,LOW);
  // delay 1s 
  delay(1000);
  // write D2 of Arduino to HIGH
  digitalWrite(PIN,HIGH);
  // delay 1s 
  delay(1000);

}
