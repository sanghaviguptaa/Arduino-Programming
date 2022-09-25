/* Interfacing 14 segment display with Arduino mega

    Hardware components
    Arduino mega
    1 Digit 14 segment common cathode display

    Author : Sanghavi
    Date : 15-09-2022
*/

// considering 1st n last pin as 1 and 11
const int FIRSTPIN = 0;
const int LASTPIN =  13;
// Arduino pin numbers connection sequence
//                   0 1 2 3 4 5 6 7 8 9 10 11 12 13
//                   a b c d e f h i j g k l m g1
bool num[26][15] = {{1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0},
  {1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0},
  {1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
  {1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0},
  {1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0},
  {1, 0, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0},
  {0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0},
  {1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
  {0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0},
  {0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0},
  {0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0},
  {1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0},
  {1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0},
  {1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0},
  {1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0},
  {1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
  {0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0},
  {0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0},
  {0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0},
  {0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0},
  {1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}
};


void setup() {
  // configuring all pins from 1st to last pin to OUTPUT mode
  for (int pin = FIRSTPIN; pin <= LASTPIN; pin++) {
    pinMode(pin, OUTPUT);

  }
}

void loop() {
  // Incrementing numbers
  for (int j = 0; j <= 25; j++)
  {
    int i = 0;
    //Map the LED Commands to Arduino pins for displaying 1 number
    for (int pin = FIRSTPIN; pin <= LASTPIN; pin++)
    {
      digitalWrite(pin, num [j][i]);
      i++;
    }

    // wait for 1000ms
    delay(1000);
  }
}
