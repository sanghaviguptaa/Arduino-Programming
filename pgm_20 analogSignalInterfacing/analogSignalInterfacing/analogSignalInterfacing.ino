/* Analog Signal Interfacing using Arduino Uno

   Hardware components
   Arduino Uno
   16x2 LCD
   potentiometer 


   Author : Sanghavi
   Date: 19-09-2022
*/

// Include header files
#include<LiquidCrystal.h>

// LCD pins initalisation and object creation
// RS = 9,  , EN = 11, D4 = 3, D5 = 2, D6 = 1, D7 = 0
LiquidCrystal lcd(9, 11, 3, 2, 1, 0);

int analogPin = A0; // potentiometer wiper (middle terminal) connected to analog pin 0
// outside leads to ground and +5V
void setup() {
  // Set up the LCD's number of columns and rows
  lcd.begin(16, 2);

  // set cursor column 0 , row 0
  lcd.setCursor(0, 0);

  // Display message
  lcd.print("Analog Value");

}

void loop() {

  // read the input pin
  float  val = analogRead(analogPin);
  val= (val/1024.0)* 100;

  // set cursor column 1 , row 1
  lcd.setCursor(0, 1);

  // Display message
  lcd.print(val);

  // to avoid an  an offset 
  lcd.print("   ");

}
