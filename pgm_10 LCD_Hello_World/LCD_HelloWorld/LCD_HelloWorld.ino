/*Dispaly Hello World in LCD
 * 
 * Hardware components 
 * Arduino Uno 
 * 16x1 LCD 
 * 
 * Author : Sanghavi 
 * Date: 08-09-2022
 */ 

 // Include header files 
#include<LiquidCrystal.h> 

// LCD pins initalisation and object creation
// RS = 13, RW = 12 , EN = 11, D0 = 7, D1 = 6, D2 = 5 , D3 = 4, D4 = 3, D5 = 2, D6 = 1, D7 = 0 
LiquidCrystal lcd(13,12,11,7,6,5,4,3,2,1,0);

void setup() {
   // Set up the LCD's number of columns and rows
   lcd.begin(16,1);

   // set cursor column 0 , row 0
   lcd.setCursor(0,0);

   // Display message 
   lcd.print("Hello World");

}

void loop() {
  

}
