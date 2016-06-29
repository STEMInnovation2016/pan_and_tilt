#include <Servo.h>

Servo myservo1;  // create servo object to control a servo
Servo myservo2;
// twelve servo objects can be created on most boards

int pos1 = 50;    // variable to store the servo position
int pos2 = 80;

int switchstate1 = 0;
int switchstate2 = 0;
int switchstate3 = 0;
int switchstate4 = 0;

void setup() {
  pinMode(2, INPUT);
  pinMode(4, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  myservo1.attach(10);
  myservo2.attach(9);
  
  // attaches the servo on pin 3 to the servo object
  myservo1.write(pos1);
  myservo2.write(pos2);
  //Serial.begin(9600);
 
}

void loop() {
  
  switchstate1 = digitalRead(2);
  switchstate2 = digitalRead(4);
  switchstate3 = digitalRead(7);
  switchstate4 = digitalRead(8);
  
  //Serial.println(pos1);
  //Serial.println(pos2);
  
  if ((switchstate1 == HIGH) && (pos1 < 70)){
     pos1 += 10;
     myservo1.write(pos1);
   }
  
  else if ((switchstate2 == HIGH) && (pos1 > 0)){   
     pos1 -= 10;
     myservo1.write(pos1);  
  }
  

  if (switchstate3 == HIGH && pos2 < 170){
        pos2 += 10;
     myservo2.write(pos2);  
  }
 
  else if (switchstate4 == HIGH && pos2 > 0){    
     pos2 -= 10;
     myservo2.write(pos2);   
  }
  
  
  delay(100);
}

