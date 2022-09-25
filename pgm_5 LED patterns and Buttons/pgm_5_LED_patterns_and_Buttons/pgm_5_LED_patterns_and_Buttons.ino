/* Different Button press for LED patterns using Arduino Uno 
 *  
 *  Hardware components 
 *  Arduino Uno 
 *  LED Bar Graph 
 *  Resistor
 *  Button 
 *  
 *  Author : Sanghavi 
 *  Date: 03-09-2022
 */
// considering 1st and last pin as 0 and 9 
const int FIRSTPIN = 0;
const int LASTPIN = 9;
const int BUTTON1 = 10;
const int BUTTON2 = 11;
const int BUTTON3 = 12;

void setup() {
  // configuring all pins from 1st to last pin to OUTPUT mode 
  for(int pin = FIRSTPIN;pin<=LASTPIN;pin++){
  pinMode(pin, OUTPUT);
  
  }

  //configuring all Buttons to INPUT mode 
  pinMode(BUTTON1,INPUT);
  pinMode(BUTTON2,INPUT);
  pinMode(BUTTON3,INPUT);
}

void loop() {
  
   if(digitalRead(BUTTON1) == HIGH)    pattern1();
   if(digitalRead(BUTTON2) == HIGH)    pattern2();
   if(digitalRead(BUTTON3) == HIGH)    pattern3();
}

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
