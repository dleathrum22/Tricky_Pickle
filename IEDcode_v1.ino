#include <TimerOne.h>
#include "Arduino.h"

#include "DisplaySignalMaker.h"


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Start");
  
  //constant variables
  DisplaySignalMaker signal = DisplaySignalMaker();
  //Timer1.initialize(1000000); // set a timer of length 1000000 microseconds
  //Timer1.attachInterrupt(0); // attach the service routine here
  
  long next;

  //while (true) {
    // put your main code here, to run repeatedly:
    
    next = millis() + 10000;
    while ( (millis() < next) );
    
    next = millis() + 10500;
    Serial.println("turning");
    while ( (millis() < next) ) {
      signal.Turn(false, true, true, 0, 255, 0);
    }

    next = millis() + 1000;
    signal.Clear();
    while (millis() < next);
    
    next = millis() + 5500;
    Serial.println("turning2");
    while ( (millis() < next) ) {
      signal.Turn(true, false, false, 0, 255, 0);
    }
    
    //Serial.println(next);
    next = millis() + 8000;
    //Serial.println(next);
    Serial.println("turning3");
    while ( (millis() < next) ) {
      //Serial.print(next);
      //Serial.print(" ");
      //Serial.println(millis());
      signal.Turn(true, false, true, 0, 255, 0);
    }
    
    next = millis() + 1500;
    while (millis() < next);
    
    next = millis() + 4000;
    Serial.println("turning4");
    while ( (millis() < next) ) {
      signal.Turn(true, false, true, 0, 255, 0);
    }

    next = millis() + 500;
    signal.Clear();
    while (millis() < next);
    
    next = millis() + 12000;
    Serial.println("turning5");
    while ( (millis() < next) ) {
      signal.Turn(false, true, true, 0, 255, 0);
    }
    
    next = millis() + 2000;
    Serial.println("wait1");
    while (millis() < next);
    
    next = millis() + 7000;
    Serial.println("turning6");
    while ( (millis() < next) ) {
      signal.Turn(false, true, false, 255, 255, 0);
    }
    
    next = millis() + 8000;
    Serial.println("turning7");
    while ( (millis() < next) ) {
      signal.Turn(false, true, false, 0, 255, 0);
    }
    
    next = millis() + 8000;
    Serial.println("turning8");
    while ( (millis() < next) ) {
      signal.Turn(false, true, true, 0, 255, 0);
    }

    next = millis() + 3400;
    signal.Clear();
    while (millis() < next);
    
    next = millis() + 3500;
    Serial.println("turning9");
    while ( (millis() < next) ) {
      signal.Turn(false, false, false, 0, 0, 0);
    }
    
    next = millis() + 18500;
    Serial.println("wait2");
    while (millis() < next);
    
    next = millis() + 4000;
    Serial.println("turning10");
    while ( (millis() < next) ) {
      signal.CollisionAvoidance();
    }
    
    signal.Clear();
    next = millis() + 100000;
    Serial.println("wait3");
    while (millis() < next);
  //}
  delay(5);
}

void loop() {

}
/*
void pause(int dur) {
  int temp = time(NULL) + dur;
  while(temp > time(NULL));
}


dot moving in circle
flash
    Lelft/Right
    Full
    Top/Bottom
Full rainbow
fading
Blink at different speeds
*/
