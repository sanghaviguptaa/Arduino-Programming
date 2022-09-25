/* Interfacing 7 segment display with Arduino uno 
 *  
 *  Hardware components
 *  Arduino Uno 
 *  1 digit common cathode 7 segment display  
 *  
 *  Author : Sanghavi 
 *  Date : 15-09-2022
 */

// considering 1st n last pin as 1 and 11 
const int FIRSTPIN = 0;
const int LASTPIN =  7;
// A B C D E F G DP
// 1 1 1 1 1 1 0 0  This value is for displaying 0 
// 0 1 1 0 0 0 0 0  This value is for displaying 1 
bool num[8] = {0,1,1,0,0,0,0,1}; 
void setup() {
  // configuring all pins from 1st to last pin to OUTPUT mode 
  for(int pin = FIRSTPIN;pin<=LASTPIN;pin++){
  pinMode(pin, OUTPUT);
  
  }
}

void loop() {
  int i = 0;
  //Map the LED Commands to Arduino pins for displaying respective number
  for(int pin = FIRSTPIN;pin<=LASTPIN;pin++)
  {
    digitalWrite(pin,num[i]);
    i++;
  }
}
