/*LED patttern Blinking on pressing a key on Keypad (method 2 )
 * 
 * Hardware components 
 * Arduino mega 
 * 4x3 Keypad
 * LED Bargraph 
 * 
 * Author : Sanghavi 
 * Date : 07-09-2022
 */
#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'#','0','*'}
};

byte rowPins[ROWS] = {14,15,16,17}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {11,12,13}; //connect to the column pinouts of the keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

// Initialize 1st and last pin 
const int FIRSTPIN = 1;
const int LASTPIN = 10;

void setup() {
  // configure pins to OUTPUT mode  
 for(int pin = FIRSTPIN;pin<=LASTPIN;pin++)
 {
 pinMode(pin,OUTPUT);
 }
}

void loop() {
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
