/* Generation of LED patterns using Arduino Uno
 * https://www.facebook.com/watch/?v=437404777682929 - Referral link 
 * 
 * Hardware components 
 * Arduino Uno 
 * LED Bargraph
 * 
 * Author : Sanghavi 
 * Date : 2-09-2022
 */
// considering 1st n last pin as 1 and 11 
const int FIRSTPIN = 2;
const int LASTPIN = 11;

void setup() {
  // configuring all pins from 1st to last pin to OUTPUT mode 
  for(int pin = FIRSTPIN;pin<=LASTPIN;pin++){
  pinMode(pin, OUTPUT);
  
  }
}

void loop() {
  // call each pattern
   pattern1();

}

// Generation of first pattern 
void pattern1() {
  for(int pin = FIRSTPIN; pin<=LASTPIN;pin++)
   {
    digitalWrite(pin,HIGH);
    delay(1000);   
    digitalWrite(pin,LOW);
    
   }
   for(int pin = LASTPIN; pin>=FIRSTPIN;pin--)
   {
    digitalWrite(pin,HIGH);
    delay(1000);
    digitalWrite(pin,LOW);
   }
}

//Generation of second pattern  
void pattern2() {
  for(int pin = FIRSTPIN; pin<=LASTPIN-2;pin++)
  {
    digitalWrite(pin,HIGH);
    digitalWrite(pin+1,HIGH);
    digitalWrite(pin+2,HIGH);
    delay(1000);
    digitalWrite(pin,LOW);
    digitalWrite(pin+1,LOW);
    digitalWrite(pin+2,LOW);
    
  }
  for(int pin = LASTPIN;pin>=FIRSTPIN+2;pin--)
  {
    digitalWrite(pin,HIGH);
    digitalWrite(pin-1,HIGH);
    digitalWrite(pin-2,HIGH);
    delay(1000);
    digitalWrite(pin,LOW);
    digitalWrite(pin-1,LOW);
    digitalWrite(pin-2,LOW);
  }
}

//Generation of third pattern  
void pattern3(){
  for(int pin = FIRSTPIN;pin<=LASTPIN;pin++)
  {
    digitalWrite(pin,HIGH);
    delay(1000);
  }
  for(int pin = LASTPIN;pin>=FIRSTPIN;pin--)
  {
    digitalWrite(pin,LOW);
    delay(1000);
  }
}

//Generation of forth pattern  
void pattern4(){
   for(int pin = FIRSTPIN;pin<=LASTPIN;pin++)
   {
    for(int i = 1;i<=pin-1;i++)
    {
    digitalWrite(pin,HIGH);
    delay(500);  
    digitalWrite(pin,LOW);
    delay(500);
   }
   }
}

//Generation of fifth pattern  
void pattern5() {
  int totalPins = (LASTPIN-FIRSTPIN+1);
  int loopCount = totalPins/2;
  // meet at middle 
  for(int i = 0;i<loopCount;i++)
  {
    digitalWrite(FIRSTPIN+i,HIGH);
    digitalWrite(LASTPIN-i,HIGH);
    delay(500);
    
  }
  for(int i = loopCount;i>0;i--)
  {
    digitalWrite(FIRSTPIN+i,LOW);
    digitalWrite(LASTPIN-i,LOW);
    delay(500);
    
  }
}

//Generation of sixth pattern  
void pattern6(){
  int totalPins = (LASTPIN-FIRSTPIN+1);
  int loopCount = totalPins/2;
  for(int i = 0;i<loopCount;i++)
  {
    digitalWrite(FIRSTPIN+i,HIGH);
    digitalWrite(LASTPIN-i,HIGH);
    delay(500);
    digitalWrite(FIRSTPIN+i,LOW);
    digitalWrite(LASTPIN-i,LOW);
    
  }
  for(int i = loopCount;i>0;i--)
  {
    digitalWrite(FIRSTPIN+i,HIGH);
    digitalWrite(LASTPIN-i,HIGH);
    delay(500);
    digitalWrite(FIRSTPIN+i,LOW);
    digitalWrite(LASTPIN-i,LOW);
  }
}

//Generation of seventh pattern  
void pattern7(){
  for(int pin = LASTPIN; pin>=FIRSTPIN;pin--)
   {
    for(int i = FIRSTPIN;i<=pin;i++){
    digitalWrite(i,HIGH);
    delay(1000);
    digitalWrite(i,LOW);
    }
    digitalWrite(pin,HIGH);
    }
   
}
