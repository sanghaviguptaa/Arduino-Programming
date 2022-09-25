/* Traffic Light program using Arduino Uno

    Hardware components
    Arduino Uno
    1digit 7 segment common cathode
    Traffic lights

    Author : Sanghavi
    Date : 18-09-2022

*/


// considering 1st n last pin as 1 and 11
const int FIRSTPIN = 0;
const int LASTPIN =  7;
const int UNITCTRL = 8;
const int REDLED = 13;
const int YELLOWLED = 12;
const int GREENLED = 11;
// A B C D E F G DP
// 1 1 1 1 1 1 0 0  This value is for displaying 0
// 0 1 1 0 0 0 0 0  This value is for displaying 1
bool num[10][8] = {{1, 1, 1, 1, 1, 1, 0, 0},
  {0, 1, 1, 0, 0, 0, 0, 0},
  {1, 1, 0, 1, 1, 0, 1, 0},
  {1, 1, 1, 1, 0, 0, 1, 0},
  {0, 1, 1, 0, 0, 1, 1, 0},
  {1, 0, 1, 1, 0, 1, 1, 0},
  {1, 0, 1, 1, 1, 1, 1, 0},
  {1, 1, 1, 0, 0, 0, 0, 0},
  {1, 1, 1, 1, 1, 1, 1, 0},
  {1, 1, 1, 1, 0, 1, 1, 0}
};

void setup() {
  // configuring all pins from 1st to last pin to OUTPUT mode
  for (int pin = FIRSTPIN; pin <= LASTPIN; pin++) {
    pinMode(pin, OUTPUT);

  }
  pinMode(UNITCTRL, OUTPUT);

  // configure all the LED's to OUTPUT mode
  pinMode(REDLED, OUTPUT);
  pinMode(YELLOWLED, OUTPUT);
  pinMode(GREENLED, OUTPUT);

  // Disable 7 segment display
  digitalWrite(UNITCTRL, HIGH);

  // TurnOFf all LEDs Initially
  digitalWrite(REDLED, LOW);
  digitalWrite(YELLOWLED, LOW);
  digitalWrite(GREENLED, LOW);
}

void loop() {
  // Turn on RED LED
  digitalWrite(REDLED, HIGH);

  // Enable 7 segment display
  digitalWrite(UNITCTRL, LOW);

  //decrement the count
  decrement();

  //Turn off RED LED off
  digitalWrite(REDLED, LOW);

  // Disable 7 segment
  digitalWrite(UNITCTRL, HIGH);

  // Turn on YELLOW led
  digitalWrite(YELLOWLED, HIGH);

  // wait for 1000ms
  delay(1000);

  // Turn off YELLOW led
  digitalWrite(YELLOWLED, LOW);

  // Turn on GREEN led
  digitalWrite(GREENLED, HIGH);

  // Enable 7 segment
  digitalWrite(UNITCTRL, LOW);

  //Decrement the count
  decrement();

  //Turn off GREEN led
  digitalWrite(GREENLED, LOW);

  // Disable 7 segment
  digitalWrite(UNITCTRL, HIGH);
  delay(1000);
}

void decrement()
{
  // Decrementing numbers
  for (int j = 9; j >= 0; j--)
  {
    
    int i = 0;
    //Map the LED Commands to Arduino pins for displaying 1 number
    for (int pin = FIRSTPIN; pin <= LASTPIN; pin++)
    {
      digitalWrite(pin, num [j][i]);
      i++;
    }
    delay(1000);    
  }
}
