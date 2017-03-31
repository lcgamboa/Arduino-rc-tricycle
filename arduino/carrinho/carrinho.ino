/* Simple and cheap DIY arduino rc tricycle controlled by smartphone 

 modified 31 March 2017
 by lcgamboa@yahoo.com
 https://www.youtube.com/watch?v=XjhdBfRUhjk
*/

//code for arduino uno

#include <Servo.h>

Servo myservo;  // create servo object to control a servo

#define center 94 //angle to align center position

void setup() {

  pinMode(10, OUTPUT); //Foward H bridge
  pinMode(11, OUTPUT); //Backward H bridge
  
  myservo.attach(9);  // Direction servo
  myservo.write(center);

  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
            
  Serial.begin(19200); //Bluetooth connection
}

void loop() {

  if (Serial.available() > 0) { //if receveid bluetooth command
     unsigned char cmd = Serial.read();

     switch(cmd)
     {
       case 'w'://frente - foward
         digitalWrite(10, HIGH);
         digitalWrite(11, LOW);
         break; 
       case 'r'://parar - stop
         digitalWrite(10, LOW);
         digitalWrite(11, LOW);
         break; 
       case 's'://trás - backward
         digitalWrite(10, LOW);
         digitalWrite(11, HIGH);
         break; 
       case 'd'://direita  - right
         myservo.write(140); //angle in degrees
         break; 
       case 'a'://esquerda  -left
         myservo.write(40); //angle in degrees
         break; 
       case 'q'://centro  -center
         myservo.write(center); 
         break; 
       default:
         break; 
     }

  }
                
    
}

