/* Generation of LED patterns (part 2) 
 * Reference link : https://www.facebook.com/watch/?v=231378848647363
 * 
 * Hardware components 
 *  Arduino Uno 
 *  LED Bargraph 
 *  
 * Author : Sanghavi 
 * Date : 04-09-2022
 */

const int FIRSTPIN = 1;
const int LASTPIN = 10;
void setup() {
  // configuring 1st to last pin to OUTPUT mode 
  for(int pin = FIRSTPIN;pin<=LASTPIN;pin++)
  {
    pinMode(pin,OUTPUT);
    
  }
}

void loop() {
  pattern7();

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

void pattern3()  // Falling water drop
{
  for(int pin = FIRSTPIN;pin<=LASTPIN;pin++)
  {
    if(pin== FIRSTPIN) {
      digitalWrite(pin,HIGH);
      delay(1000);
      digitalWrite(pin,LOW);
    }
    else{
      digitalWrite(pin,HIGH);
      delay(100);
      digitalWrite(pin,LOW);
    }
  }
}

void pattern4()  // Fade each LED 
{
  for(int pin = FIRSTPIN;pin<=LASTPIN;pin++)
  {
    digitalWrite(pin,HIGH);
    delay(500);
    digitalWrite(pin,LOW);
    delay(500);
  }
}

void pattern5()  // Moving snake 
{
 

}

void pattern6()      // Accelarating LEDs
{
  int midpin = LASTPIN/2;
  int pin;
  for(pin = FIRSTPIN;pin<=midpin;pin++)
  {
    digitalWrite(pin,HIGH);
    delay(1000);
    digitalWrite(pin,LOW);
  }
  for(pin = midpin;pin<=LASTPIN;pin++)
  {
    digitalWrite(pin,HIGH);
    delay(200);
    digitalWrite(pin,LOW);
  }
}

void pattern7()   // Newton's Cradle 
{
  int pin;
  for(pin = FIRSTPIN;pin<=LASTPIN;pin++)   // 3 LEDs HIGH
  {
    if(pin == 5 || pin == 6 | pin == 7)     digitalWrite(pin,HIGH);      
  }
  delay(500);
  for(pin = FIRSTPIN;pin<4;pin++) // MOVE pin 1 to pin 4 
    {
      digitalWrite(pin,HIGH);
      delay(500);
      digitalWrite(pin,LOW);
    }
digitalWrite(pin,HIGH); // pin 4 as HIGH
delay(500);
  for(pin = 7;pin<=LASTPIN; pin++)  // Move pin 7 to pin 10
  {
    digitalWrite(pin,HIGH);
    delay(500);
    digitalWrite(pin,LOW);
  }
  for(pin=LASTPIN;pin>7;pin--)// 2CB  // Move pin 10 to pin 7 
  {
    digitalWrite(pin,HIGH);
    delay(500);
    digitalWrite(pin,LOW);
  }
digitalWrite(pin,HIGH);   // Pin 7 as HIGH
delay(500);
  for(pin=4;pin>FIRSTPIN;pin--) // CBack  Move pin 4 to pin 1 
{
  digitalWrite(pin,HIGH);
  delay(500);
  digitalWrite(pin,LOW);
}
digitalWrite(pin,HIGH); 
}
