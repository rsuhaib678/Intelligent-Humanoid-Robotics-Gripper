#include <Servo.h>
 
#define SERVOS 3
 
 Servo myservo[SERVOS];  
 
int servo_pins[SERVOS] = {5,6,7}; 
int potpins[SERVOS] = {A1,A2,A3}; 
int potpin_val[SERVOS]; 
const int buttonPin = 8; 
const int ledPin = 2; 
int buttonState = 0;

void setup() 
{
   
  for(int i = 0; i < SERVOS; i++) 
  {
    myservo[i].attach(servo_pins[i]);
    pinMode(2, INPUT);
    Serial.begin(9600);

  }
}
  
void loop() 
{  
  for(int i = 0; i < SERVOS; i++) {
     
    potpin_val[i] = analogRead(potpins[i]); 
    potpin_val[i] = map(potpin_val[i], 0, 1023, 0, 180);     
    myservo[i].write(potpin_val[i]);  
    delay(15); 

    buttonState = digitalRead(buttonPin);
   
   if (buttonState == HIGH) 
   {
      
      digitalWrite(servo_pins[SERVOS], LOW);
   }
  else 
    {
      
      
      digitalWrite(servo_pins[SERVOS], LOW);
      delay(498);
    }  
}      
