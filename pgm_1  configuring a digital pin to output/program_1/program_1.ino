/* Configuring a Arduino digital pin to OUTPUT mode and write HIGH value continuously 
 * 
 * Choosing Digital pin 1 and configuring to OUTPUT mode and 
 * writting HIGH values continuously.
 * 
 * Hardware components 
 * Arduino Uno 
 * DC Voltmeter
 * 
 * Author: Sanghavi  
 * Date : 27-08-2022
 */
// As we need a constant for a digital pin 
const int PIN=1;
void setup() {
  
  // Configure D1 of Arduino to OUTPUT mode 
  pinMode(PIN,OUTPUT); 
}

void loop() {
  
  // Write D1 of Arduino to HIGH 
  digitalWrite(PIN,HIGH);
}
