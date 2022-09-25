/* Implementation of a Digital locker with Arduino Uno
    In this program 4*3 keypad and 16x2 lCD is used to interface with Arduino

    Hardware components
    Arduino Uno
    4*3 keypad
    16x2 LCD

    Author : Sanghavi
    Date : 12-09-2022
*/

// Include the header file:
#include <Keypad.h>
#include <LiquidCrystal.h>

// Initialise Keypad rows and columns
const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns

// LCD pins initalisation and object creation
const int RS = 13, EN = 12, D4 = 11, D5 = 10, D6 = 9, D7 = 8;
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

// Define Keypad layout
char keys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'9', '8', '7'},
  {'*', '0', '#'}
};

// Keypad row and column pins connections
byte rowPins[ROWS] = {4, 3, 2, 1};
byte colPins[COLS] = {7, 6, 5};

// Initialise Keypad
Keypad customKeypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

// Initialize LED
const int REDLED = A5;
const int GREENLED = A4;

// Variable to store the intermediate keys
static char customKey;
static int firstPassword;
static int secondPassword;
bool validationStatus;
bool pinValidationStatus;
static int enterPassword;

void setup() {
  // Set up the LCD's number of columns and rows
  lcd.begin(16, 2);

  // Cofiguring LED to OUTPUT mode
  pinMode(REDLED, OUTPUT);
  pinMode(GREENLED, OUTPUT);

  // set LED red to HIGH
  digitalWrite(REDLED, HIGH);

  // set cursor column = 0, row = 0
  lcd.setCursor(0, 0);

  // Display message
  lcd.print("GUPTA LOCKERS");

  // wait for 500ms
  delay(500);

  // Clear lcd
  lcd.clear();

  for (int count = 0; count <= 2; count++)
  {
    if (validationStatus == false && count < 3)
    {
      lcd.clear();
      // Call function to set the pin
      setPin();

      // call function to confirm the pin
      confirmPin();

      validationStatus = validatePassword(firstPassword, secondPassword);
    }
  }

  //  // Call function to set the pin
  //  setPin();
  //
  //  // call function to confirm the pin
  //  confirmPin();

  // call function for opening the Locker
  //lockerOpen()

  // checking for validation status
  //validationStatus = validatePassword(firstPassword, secondPassword);

  if (validationStatus)
  {
    // clear lcd
    lcd.clear();

    // set cursor column 0, row 0
    lcd.setCursor(0, 0);

    // Display message
    lcd.print("Entered pin");

    // Set cursor column 0 , row 0
    lcd.setCursor(1, 1);

    // Display password
    lcd.print(firstPassword);

    // wait for 500ms
    delay(500);

    //clear lcd
    lcd.clear();

    //Display message
    lcd.print("The pin is set");

    // wait for 500ms
    delay(500);

    // clear lcd
    lcd.clear();

     for (int count = 0; count <= 2; count++)
  {
    if (pinValidationStatus == false && count < 3)
    {
      lcd.clear();
    // function call to Enter Pin
    enterPin();
    
    pinValidationStatus = validatePin(enterPassword, firstPassword);
    }
  }
    // validate Entered Pin
    //validationStatus = validatePin(enterPassword, firstPassword);
    if (pinValidationStatus)
    {
      // clear lcd
      lcd.clear();

      // set cursor column 0, row,0
      lcd.setCursor(0, 0);

      // Locker open
      lcd.print("Locker Open");
      digitalWrite(GREENLED, HIGH);
      digitalWrite(REDLED, LOW);
    }
    else
    {
      // clear lcd
    lcd.clear();

    // set cursor column 0, row 0
    lcd.setCursor(0, 0);

    // Display message
    lcd.print("Wrong Pin");

    // wait for 500ms
    delay(500);

    // clear lcd
    lcd.clear();

    //set cursor column 0 , row 0
    lcd.setCursor(0, 0);

    // Display message
    lcd.print("Try after 30 minutes");

    // wait for 500ms
    delay(500);
    }

  }
  else
  {

    // clear lcd
    lcd.clear();

    // set cursor column 0, row 0
    lcd.setCursor(0, 0);

    // Display message
    lcd.print("Wrong Pin");

    // wait for 500ms
    delay(500);

    // clear lcd
    lcd.clear();

    //set cursor column 0 , row 0
    lcd.setCursor(0, 0);

    // Display message
    lcd.print("Try after 30 minutes");

    // wait for 500ms
    delay(500);
  }

}

// function to get password
int getPassword()
{
  // Variable to indicate 4 digits are pressed
  int pinCount = 0;

  // Storing password
  int password = 0;

  // waits for user input
  while (!(pinCount == 4))
  {
    // Get the current key from Keypad
    customKey = customKeypad.getKey();

    // Check entered keys are numeric 0...9
    if ( ( (customKey - '0') >= 0) && ( (customKey - '0') <= '9') )
    {
      password = password * 10 + customKey - '0';

      // incrementing the variable
      pinCount++;

      //Hide password using *
      lcd.print("*");
    }
  }
  return password;
}

//function for password validation
bool validatePassword(int x, int y)
{
  if (x == y)  return true;
  else return false;
}


// Function for setting Pin
int setPin()
{
  // Asking the user to set the pin and Confirm it

  // Set cursor column 0, row 0
  lcd.setCursor(0, 0);

  //Display message
  lcd.print("Set pin");

  // Set cursor column 0 , row 0
  lcd.setCursor(1, 1);

  //Calling the function to enter First password
  firstPassword = getPassword();
  return firstPassword ;
  
  // clear lcd
  lcd.clear();
}

// Function for confirm pin
int confirmPin()
{
  lcd.clear();
  // Set cursor column 0, row 0
  lcd.setCursor(0, 0);

  // Display Message
  lcd.print("Confirm pin");

  // Set cursor column 0 , row 0
  lcd.setCursor(1, 1);

  //Calling the function to enter First password
  secondPassword = getPassword();
  return secondPassword;

  // clear lcd
  lcd.clear();

}

// function to Enter pin
int enterPin()
{
  // clear lcd
  lcd.clear();
  
  // Asking the user to enter the pin 
  // Set cursor column 0, row 0
  lcd.setCursor(0, 0);

  //Display message
  lcd.print("Enter Pin");

  // Set cursor column 0 , row 0
  lcd.setCursor(1, 1);

  //Calling the function to enter First password
  enterPassword = getPassword();
  return enterPassword ;
  // clear lcd
  lcd.clear();
}

// Function to validate entered pin
bool validatePin(int a, int b)
{
  if (a == b)  return true;
  else return false;
}




void loop() {

}
