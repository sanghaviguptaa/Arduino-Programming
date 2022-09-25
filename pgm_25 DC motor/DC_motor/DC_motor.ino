/* Interfaceing DC motor with Arduino Uno 
 *  
 *  Hardware components
 *  Arduino Uno 
 *  DC Motor 
 *  L293D
 *  
 *  Author : Sanghavi 
 *  Date : 25-09-2022
 */

// Following pins are for Right motor 
const int IN1 = 11;
const int IN2 = 10;
const int EN1 = 9;

// Following pins are for Left motor 
const int EN2 = 7;
const int IN3 = 6;
const int IN4 = 5;

void setup() {
  // configuring L293D pins to OUTPUT mode
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(EN1,OUTPUT);

  // Not to turn on the motor at initial stage 
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(EN1,LOW);

  // configuring L293D pins to OUTPUT mode
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(EN2,OUTPUT);

  // Not to turn on the motor at initial stage 
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
  digitalWrite(EN2,LOW);
  

}

void loop() {
  
  moveForward();
  delay(2000);
  moveBack();
  delay(2000);
  moveLeft();
  delay(2000);
  moveRight();
  delay(2000);
  stopMotors();
  delay(2000);

}

void moveBack()  // Clockwise 
{
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(EN1,HIGH);

  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  digitalWrite(EN2,HIGH);
}

void moveForward() // Anticlockwise
{
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(EN1,HIGH);

  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  digitalWrite(EN2,HIGH);
}

void moveLeft()   // Forward Left 
{
  // Stop the right motor 
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(EN1,LOW);

  // Left motor should rotate in anticlockwise direction 
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  digitalWrite(EN2,HIGH);

}

void moveRight()   // Forward Right  
{
  // Stop the Left motor 
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
  digitalWrite(EN2,LOW);

  // Right motor should rotate in anticlockwise direction 
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(EN1,HIGH);
}

// Function to stop all the motors 
void stopMotors() 
{
  // Stop the Left motor 
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
  digitalWrite(EN2,LOW);

  // Stop Right motor 
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(EN1,LOW);
}
