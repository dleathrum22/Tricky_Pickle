#include <ctime>
#include <iostream>

#include "DisplaySignalMaker.h"

void setup() {
  // put your setup code here, to run once:
  
  //constant variables
  DisplaySignalMaker signal = new DisplaySignalMaker();
  int interrupt;
  
}

void loop() {
  // put your main code here, to run repeatedly:
  while (interrupt < 10);
  while ( (interrupt >= 10) && (interrupt < 21)) {
    signal.Turn(false, true, true, unit8_t 00000000, unit8_t 11111111, unit8_t 00000000);
  }
  while ( (interrupt >= 22) && (interrupt < 28) ) {
    signal.Turn(true, false, false, unit8_t 00000000, unit8_t 11111111, unit8_t 00000000);
  }
  while ( (interrupt >= 28) && (interrupt < 36) ) {
    signal.Turn(true, false, true, unit8_t 00000000, unit8_t 11111111, unit8_t 00000000);
  }
  while (interrupt < 37);
  while ( (interrupt >= 37) && (interrupt < 40) ) {
    signal.Turn(true, false, true, unit8_t 00000000, unit8_t 11111111, unit8_t 00000000);
  }
  while ( (interrupt >= 40) && (interrupt < 52) ) {
    signal.Turn(false, true, true, unit8_t 00000000, unit8_t 11111111, unit8_t 00000000);
  }
  while (interrupt < 54);
  while ( (interrupt >= 54) && (interrupt < 61) ) {
    signal.Turn(false, true, false, unit8_t 11111111, unit8_t 11111111, unit8_t 00000000);
  }
  while ( (interrupt >= 61) && (interrupt < 69) ) {
    signal.Turn(true, false, false, unit8_t 00000000, unit8_t 11111111, unit8_t 00000000);
  }
  while ( (interrupt >= 69) && (interrupt < 80) ) {
    signal.Turn(false, true, true, unit8_t 00000000, unit8_t 11111111, unit8_t 00000000);
  }
  while ( (interrupt >= 80) && (interrupt < 87) ) {
    signal.Turn(false, false, false, unit8_t 00000000, unit8_t 00000000, unit8_t 00000000);
  }
  while (interrupt < 104);
  while ( (interrupt >= 104) && (interrupt < 108) ) {
    signal.CollisionAvoidance();
  }
  while (interrupt < 200);
}

void pause(int dur) {
  int temp = time(NULL) + dur;
  while(temp > time(NULL));
}

/*
dot moving in circle
flash
    Lelft/Right
    Full
    Top/Bottom
Full rainbow
fading
Blink at different speeds
*/
