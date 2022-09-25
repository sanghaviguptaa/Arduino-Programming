/* Interfacing Button and LED to Arduino Uno
 *  
 *  Hardware components
 *  Arduino Uno
 *  Resistor 
 *  Button or switch 
 *  LED 
 *
 Author : Sanghavi
 Date : 03-09-2022
 
 */
const int LEDPIN = 1;
const int BUTTONPIN = 2;
static bool value;
void setup() {

  // Configuring BUTTONPIN to INPUT mode 
  pinMode(BUTTONPIN,INPUT);

  // Configuring LEDPIN to OUTPUT mode 
  pinMode(LEDPIN,OUTPUT);
}

void loop() {
  
  value = digitalRead(BUTTONPIN);
  if(value == HIGH){
    digitalWrite(LEDPIN,HIGH);
  }
  else{
    digitalWrite(LEDPIN,LOW);
  }
  
}
// both switch and Buttons can be used 
