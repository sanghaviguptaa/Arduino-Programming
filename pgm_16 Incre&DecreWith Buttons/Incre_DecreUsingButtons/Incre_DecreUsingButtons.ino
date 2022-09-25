/* Incrementing and Decrementing based on Button press using Arduino Uno

    Hardware components
    Arduino Uno
    Buttons
    1 digit 7 segment common cathode Display
    Resistor 

    Author : Sanghavi
    Date : 16-09-2022

*/

const int BUTTON1 = 8;
const int BUTTON2 = 9;

// considering 1st n last pin as 1 and 11
const int FIRSTPIN = 0;
const int LASTPIN =  7;

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

int count = 0; 
void setup() {

  //Configuring all buttons to INPUT mode
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);

  // configuring all pins from 1st to last pin to OUTPUT mode
  for (int pin = FIRSTPIN; pin <= LASTPIN; pin++) 
  {
    pinMode(pin, OUTPUT);
  }

   //Function to display number 
   displayNum(count);
}

void loop() {

  // if Button2 is pressed
  if(digitalRead(BUTTON2) == HIGH)
  {
    //wait untill button2 is released 
    while(digitalRead(BUTTON2) == HIGH);

    // decrement value 
    count--;
  }

  // if Button1 is pressed 
  if(digitalRead(BUTTON1) == HIGH)
  {
    // wait untill button1 is release 
    while(digitalRead(BUTTON1) == HIGH);

    // increment the value 
    count++;
  }  

  // check if count is in between 0 and 9 
  if((count>9) || (count<0))
  {
  count = 0;
  }

  // display number after button pressed 
  displayNum(count);

  
  
}

void displayNum(int x)
{
  int i = 0;
  
  //Map the LED Commands to Arduino pins for displaying 1 number
  for (int pin = FIRSTPIN; pin <= LASTPIN; pin++)
  {
    digitalWrite(pin, num [x][i]);

    // increment the column value
    i++;  
  }
}
