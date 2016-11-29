#include <ctime>
#include <iostream>

#include "DisplaySignalMaker.h"

void setup() {
  // put your setup code here, to run once:
  
  //constant variables
  DisplaySignalMaker signal = new DisplaySignalMaker();
  int timer = timer(0);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  while (timer < 10);
  while ( (timer >= 10) && (timer < 21)) {
    signal.Turn(false, true, true, unit8_t 00000000, unit8_t 11111111, unit8_t 00000000);
  }
  while ( (timer >= 22) && (timer < 28) ) {
    signal.Turn(true, false, false, unit8_t 00000000, unit8_t 11111111, unit8_t 00000000);
  }
  while ( (timer >= 28) && (timer < 36) ) {
    signal.Turn(true, false, true, unit8_t 00000000, unit8_t 11111111, unit8_t 00000000);
  }
  while (timer < 37);
  while ( (timer >= 37) && (timer < 40) ) {
    signal.Turn(true, false, true, unit8_t 00000000, unit8_t 11111111, unit8_t 00000000);
  }
  while ( (timer >= 40) && (timer < 52) ) {
    signal.Turn(false, true, true, unit8_t 00000000, unit8_t 11111111, unit8_t 00000000);
  }
  while (timer < 54);
  while ( (timer >= 54) && (timer < 61) ) {
    signal.Turn(false, true, false, unit8_t 11111111, unit8_t 11111111, unit8_t 00000000);
  }
  while ( (timer >= 61) && (timer < 69) ) {
    signal.Turn(true, false, false, unit8_t 00000000, unit8_t 11111111, unit8_t 00000000);
  }
  while ( (timer >= 69) && (timer < 80) ) {
    signal.Turn(false, true, true, unit8_t 00000000, unit8_t 11111111, unit8_t 00000000);
  }
  while ( (timer >= 80) && (timer < 87) ) {
    signal.Turn(false, false, false, unit8_t 00000000, unit8_t 00000000, unit8_t 00000000);
  }
  while (timer < 104);
  while ( (timer >= 104) && (timer < 108) ) {
    signal.CollisionAvoidance();
  }
  while (timer < 200);
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
