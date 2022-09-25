/*Simple Calculator Program Using Arduino Mega 
 * In this program 32x2 LCD and a 4x4 Keypad is used to interface with Arduino.
 * 
 * Hardware Components:
 * Arduino Mega
 * 4x4 Keypad
 * 16x2 LCD
 * 
 * Author : Sanghavi 
 * Date : 09-09-2022
 */
// Include the header file:
#include <Keypad.h>
#include <LiquidCrystal.h>

// Initialise Keypad rows and columns
const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns

// LCD pins initalisation and object creation
const int RS = 13, EN = 12, D4 = 11, D5 = 10, D6 = 9, D7 = 8;
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

// Define Keypad layout
char keys[ROWS][COLS] = {
  {'7','8','9', '/'},
  {'4','5','6', '*'},
  {'1','2','3','-'},
  {'C','0','=', '+'}
};

// Keypad row and column pins connections
byte rowPins[ROWS] = {7,6,5,4}; 
byte colPins[COLS] = {3,2,1,0}; 

// Initialise Keypad
Keypad customKeypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

// Global variables for first argument, second argument and result
static float firstArgument;
static float secondArgument;
static double result;

// Flags used in the program
static bool isSecondArgument;
static bool isAdd;
static bool isSub;
static bool isMul;
static bool isDiv;
static bool isExecuted;

void setup()
{
  // Set up the LCD's number of columns and rows
  lcd.begin(32, 2);

  // Set cursor column 0, and row 0
  lcd.setCursor(0,0);

  // Display the message 
  lcd.print("WELCOME");
  delay(500); // Wait for 1000ms
  lcd.clear();
  
  lcd.print("MINI CALCULATOR ");
  delay(100);  // Wait for 100ms
  // Set cursor column 0, and row 1
  lcd.setCursor(0,1);
  lcd.print("- Sanghavi");
  delay(500); // Wait for 1000ms
  lcd.clear(); // Clear LCD 

}
  
void loop()
{
  // Variable to store the intermediate keys
  char customKey; 

  // Get the current key from Keypad
  customKey = customKeypad.getKey();

 switch (customKey)
 {
  // continium operator | Ellipsis 
  case '0'...'9':
          //Clear the screen after every execution 
          if (isExecuted)
          {
            lcd.clear();
            lcd.setCursor(0,0);
            isExecuted = false;
            firstArgument = 0;
            secondArgument = 0;
            result = 0;          
          }

          // Keep reading first and second arguments
          if (!isSecondArgument) firstArgument = firstArgument * 10 + (customKey - '0');
          else secondArgument = secondArgument * 10 + (customKey - '0');
          
          lcd.print(customKey-'0');     
          break;  
          
    case '+':
          if (!isExecuted)
          {
            isAdd = true;lcd.print(customKey);isSecondArgument = true;
          }
          break;
          
    case '-':
          if (!isExecuted)
          {
            isSub = true;lcd.print(customKey);isSecondArgument = true;
          }
          break;
          
    case '*':
          if (!isExecuted)
          {
            isMul = true;lcd.print(customKey);isSecondArgument = true;
          }
          break;
          
    case '/':
          if (!isExecuted)
          {
            isDiv = true;lcd.print(customKey);isSecondArgument = true;
          }
          break;
          
    case '=':
          // Set cursor column 1, and row 1
          lcd.setCursor(1,1);
          isSecondArgument = false;
          if (isAdd)
          {
           result = firstArgument+secondArgument;
           isAdd = false; 
          }
          
         if (isSub)
          {
           result = firstArgument-secondArgument; 
           isSub = false; 
          }
          
         if (isMul)
          {
           result = firstArgument*secondArgument;
           isMul = false; 
          }
          
         if (isDiv)
          {
           result = firstArgument/secondArgument;
           isDiv = false; 
          }

          // Display result in LCD
          lcd.print(result);
          isExecuted = true;
          break;

    case 'C':
          lcd.clear();
          firstArgument=0;
          secondArgument=0;
      
          // Set cursor column 0, and row 0
          lcd.setCursor(0,0);
          break;     
 }
}
