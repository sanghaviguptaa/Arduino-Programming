/*LED patttern Blinking on pressing a key on Keypad 
 * 
 * Hardware components 
 * Arduino Uno 
 * 4x3 Keypad
 * LED Bargraph 
 * 
 * Author : Sanghavi 
 * Date : 07-09-2022
 */

 // Include the header file
#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns

// Define Keypad layout
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'#','0','*'}
};

byte rowPins[ROWS] = {A0,A1,A2,A3}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {11,12,13}; //connect to the column pinouts of the keypad

// Initialise Keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

//Initialise 1st and last pin of LED 
const int FIRSTPIN = 1;
const int LASTPIN = 10;

void setup() {
  // configuring pins to OUTPUT mode 
 for(int pin = FIRSTPIN;pin<=LASTPIN;pin++)
 {
 pinMode(pin,OUTPUT);
 }
}

void loop() {

  // Get the current key from Keypad and store in the Variable key
   char key = keypad.getKey();
   switch(key) 
   {
    case '1': pattern1(); break;
    case '2': pattern2(); break;
    
   }
   
}

void pattern1() // LED FILL 
{
  for(int pin = FIRSTPIN;pin<=LASTPIN;pin++)
  {
    digitalWrite(pin,HIGH);
    delay(1000);
  }
  for(int pin = FIRSTPIN;pin<=LASTPIN;pin++)
  {
    digitalWrite(pin,LOW);
    delay(1000);
  }
}

void pattern2() // 2-Alternate LEDs
{
  for(int pin = FIRSTPIN;pin<=LASTPIN;pin= pin+2)
  {
    digitalWrite(pin,HIGH);
    delay(500);
    digitalWrite(pin,LOW);
  }
  for(int pin = FIRSTPIN+1;pin<=LASTPIN;pin = pin+2)
  {
    digitalWrite(pin,HIGH);
    delay(500);
    digitalWrite(pin,LOW);
  }
}
