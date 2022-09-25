/* Pressure Sensor and Temparature sensor are Interfaced with Arduino Uno 
 *  In this project LCD is being used to display current pressure and Temperature value.
 *  RED LED is interfaced to Arduino Uno which will be switched on when temparature exceeds 25C 
 *  GREEN LED will be turned on when pressure exceeds 100kPa
 *  
 *  Hardware components
 *  Arduino Uno 
 *  LCD 
 *  RED LED 
 *  GREEN LED
 *  Tempature Sensor LM35
 *  Pressure Sensor MPX4250
 *  
 *  Author : Sanghavi 
 *  Date : 22-09-2022
 */
 
// Include header files
#include<LiquidCrystal.h>

// LCD pins initalisation and object creation
// RS = 9,  , EN = 11, D4 = 3, D5 = 2, D6 = 1, D7 = 0
LiquidCrystal lcd(9, 11, 3, 2, 1, 0);

// A0 pin for Temparature sensor 
int analogPin0 = A0; 

// A1 Pin For Pressure sensor 
int analogPin1 = A1; 

// Consider Arduino pin 4 and 5 for RED and GREEN LED's respectively
const int LEDRED = 4;
const int LEDGREEN = 5;

void setup() {
  // Configure LED's to OUTPUT mode
  pinMode(LEDRED,OUTPUT);
  pinMode(LEDGREEN,OUTPUT);
  
  // Set up the LCD's number of columns and rows
  lcd.begin(16, 2);

  // set cursor column 0 , row 0
  lcd.setCursor(0, 0);

  // Display message
  lcd.print("T = ");

  // set cursor column 1, row 1
  lcd.setCursor(1,1);

  lcd.print("P = ");

}


void loop() {
  // read the input pin
  float  tempValue = analogRead(analogPin0);
  
  // 488 is a sensitivity factor for a LM35 temparature sensor 
  tempValue= (tempValue/1024.0)* 488;

  // set cursor column 1 , row 1
  lcd.setCursor(5, 0);

  // Display message
  lcd.print(tempValue);

  // to avoid an  an offset 
  lcd.print("   ");

   // read the input pin (5/1023) = 0.0048875   5 is operating voltage and 1023 is Resolution 
  float pressValue = analogRead(analogPin1)*0.0048875;
  
  // 51.06209150326797 is a sensitivity factor for a MPX4250 Pressure sensor 
  pressValue= pressValue*51.06209150326797;

  // set cursor column 1 , row 1
  lcd.setCursor(5, 1);

  // Display message
  lcd.print(pressValue);

  // to avoid an  an offset 
  lcd.print("   ");

  // Turn on RED LED if temparature exceed 25C
  if(tempValue > 25) digitalWrite(LEDRED, HIGH);
  else digitalWrite(LEDRED,LOW);

  // Turn on GREEN LED if Pressure exceeds 100kPa
  if(pressValue > 100) digitalWrite(LEDGREEN,HIGH);
  else digitalWrite(LEDGREEN,LOW);

  

}
