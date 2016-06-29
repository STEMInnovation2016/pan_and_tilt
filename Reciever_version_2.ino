#include <nRF24L01.h>
#include <printf.h>
#include <RF24.h>
#include <RF24_config.h>

/*
nrf24l reciever unit with servo controller for pan and tilt rig

 For more on info visit here https://www.youtube.com/watch?v=F5KHyYiL24s and here http://www.instructables.com/id/wireless-pan-and-tilt-camera-rig-with-arduino/

 created 2015
 by TheOverclocker
 last update 28 Nov 2015

please subscribe for more tutorials

 <https://www.youtube.com/channel/UC9CqbqZjjuGsSXhD3di2_zA>

 */

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>
#define CE_PIN   9
#define CSN_PIN 10

const uint64_t pipe = 0xE8E8F0F0E1LL;
int servoy;

Servo Yservo; 
Servo servoMouse; 

RF24 radio(CE_PIN, CSN_PIN);

int joystick[2];
int pos = 40;
int buttonState = 0;

void setup()//RF24
{
  Serial.begin(9600);
  delay(1000);
  radio.begin();
  radio.openReadingPipe(1,pipe);
  radio.startListening();
  servoMouse.attach(3);
  Yservo.attach(5);
}

void loop()
{
  if ( radio.available() )
  {
    bool done = false;
    
      radio.read( joystick, sizeof(joystick) );
      buttonState= joystick[0]; 
      servoy= joystick[1];    
      Serial.println(servoy);
      Serial.println(pos);
      
      if (servoy > 1000 && pos < 45){
        pos += 1;
        Yservo.write(pos);
        delay(100);
      }
      else if (servoy < 100 && pos > 0){
        pos -= 1;
        Yservo.write(pos);
        delay(100);
        
      }
       if (buttonState == HIGH){
     
          servoMouse.write(170);
          delay(1000);
          servoMouse.write(110);
          delay(10);
   }
    
  }
  else
  {    
      Serial.println("NO RADIO CONECTION");
  }

}

