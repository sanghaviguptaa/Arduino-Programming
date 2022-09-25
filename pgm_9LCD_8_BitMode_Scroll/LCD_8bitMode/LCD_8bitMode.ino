/*Dispaly Scroll charecters in LCD using Arduino Uno 
 * 
 * Hardare components 
 * Arduino Uno 
 * 16x2 LCD
 * 
 * Author : Sanghavi 
 * Date: 08-09-2022
 * 
 */

// include Header file 
#include<LiquidCrystal.h>

// LCD pins initalisation and object creation
// RS = 13 , RW = 12 , EN = 11, D0= 7, D1 = 6 , D2 = 5 , D3=4, D4 = 3, D5 = 2, D6 = 1, D7 = 0 
LiquidCrystal lcd(13,12,11,7,6,5,4,3,2,1,0); 
void setup() {
  // Set up the LCD's number of columns and rows
  lcd.begin(16,2);
  

}

void loop() {
  //set cursor column 0 , row 0
  lcd.setCursor(0,0);

  // Display message 
  lcd.print("ABCD EFGH IJKL MNOP QRSW");

  // set cursor columnn 0 , row 1 
  lcd.setCursor(0,1);

  // display message 
  lcd.print("1234 5678 9101112 131415");

  // scroll message 
  for(int i = 0;i<=19;i++)
  {
     delay(500);
     lcd.scrollDisplayLeft();
     
  }
  
}
