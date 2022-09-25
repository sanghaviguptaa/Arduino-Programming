/* Blinking Led number of times upon the number pressed on the Keypad using Arduino Uno 
 *  
 *  Hardware componenets 
 *  Arduino Uno 
 *  Keypad 4x3
 *  LED 
 *  
 * Author : Sanghavi 
 * Date : 06-09-2022
 */

 // Include Header file
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
byte rowPins[ROWS] = {5, 4, 3, 2}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {8, 7, 6}; //connect to the column pinouts of the keypad

// Initialise Keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

// Assigning 1st pin of Arduino to LED
const int LED = 1;

void setup() {
  // Configure LED to OUTPUT mode 
 pinMode(LED,OUTPUT);

}

void loop() {
  // Get the current key from Keypad and store in Variable key 
   char key = keypad.getKey();
  
  for(int i = 0;i<key-'0';i++)
   {
    digitalWrite(LED,HIGH);
    delay(500);
    digitalWrite(LED,LOW);
    delay(500);
   }
}
