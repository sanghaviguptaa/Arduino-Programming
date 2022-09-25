/*  7 segment Multiplexing to display numbers from 0 to 99 
 *  
 *  Hardware components
 *  Arduino Uno 
 *  2 digit common cathode 7 segment display  
 *  
 *  Author : Sanghavi 
 *  Date : 17-09-2022
 */

// considering 1st n last pin as 1 and 11 
const int FIRSTPIN = 0;
const int LASTPIN =  7;

const int UNITCTRL = 8;
const int DECTRL = 9;
static int count;
// A B C D E F G DP
// 1 1 1 1 1 1 0 0  This value is for displaying 0 
// 0 1 1 0 0 0 0 0  This value is for displaying 1 


bool num[10][8] = {{1,1,1,1,1,1,0,0},
                   {0,1,1,0,0,0,0,0},
                   {1,1,0,1,1,0,1,0},
                   {1,1,1,1,0,0,1,0},
                   {0,1,1,0,0,1,1,0},
                   {1,0,1,1,0,1,1,0},
                   {1,0,1,1,1,1,1,0},
                   {1,1,1,0,0,0,0,0},
                   {1,1,1,1,1,1,1,0},
                   {1,1,1,1,0,1,1,0} };    
void setup() {
  // configuring all pins from 1st to last pin to OUTPUT mode 
  for(int pin = FIRSTPIN;pin<=LASTPIN;pin++){
  pinMode(pin, OUTPUT);
  
  }
  //Configuring control pins to output mode  
  pinMode(UNITCTRL,OUTPUT);
  pinMode(DECTRL,OUTPUT);
  
  // Control pins for 7 segment display 
  digitalWrite(UNITCTRL,HIGH);
  digitalWrite(DECTRL,HIGH);
}

void loop() {
 for(count = 0;count<=99;count++)
 { 
 extractAndDisplay(count);
 delay(50);
 }
}

// Function to display number 
void displayNum(int x)
{
  int i = 0;
  //Map the LED Commands to Arduino pins for displaying respective number
  for(int pin = FIRSTPIN;pin<=LASTPIN;pin++)
  {
    digitalWrite(pin,num[x][i]);
    i++;
  }
}

void extractAndDisplay(int x)
{
  //Enable Unit control  
 digitalWrite(UNITCTRL,LOW);
 // Display number
 displayNum(x/10);
 delay(20);
 // Disable unit control 
 digitalWrite(UNITCTRL,HIGH);

 // Enable Decimal  control 
 digitalWrite(DECTRL,LOW);

 // Display number
 displayNum(x%10);
 delay(20);

 //Disable Decimal control
 digitalWrite(DECTRL,HIGH); 
}
