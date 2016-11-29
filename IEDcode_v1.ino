#include <ctime>
#include <iostream>

#include "DisplaySignalMaker.h"
#include "Timer.h"

void setup() {
  // put your setup code here, to run once:
  
  //constant variables
  DisplaySignalMaker signal = new DisplaySignalMaker();
  time_t timer = now();
  
  int next;
  
}

void loop() {
  // put your main code here, to run repeatedly:
  next = time_t.second(timer) + 10;
  while (sec < next) { timer = now(); }
  
  next = next + 11;
  while ( time_t.second(timer) < next ) {
    signal.Turn(false, true, true, unit8_t 00000000, unit8_t 11111111, unit8_t 00000000);
    timer = now();
  }
  
  next = next + 4
  while ( time_t.second(timer) < next ) {
    signal.Turn(true, false, false, unit8_t 00000000, unit8_t 11111111, unit8_t 00000000);
    timer = now(); 
  }
  
  next = next + 8;
  while ( time_t.second(timer) < next ) {
    signal.Turn(true, false, true, unit8_t 00000000, unit8_t 11111111, unit8_t 00000000);
    timer = now(); 
  }
  
  next = next + 1;
  while (time_t.second(timer) < next) { timer = now(); }
  
  next = next + 3
  while ( time_t.second(timer) < next ) {
    signal.Turn(true, false, true, unit8_t 00000000, unit8_t 11111111, unit8_t 00000000);
    timer = now(); 
  }
  
  next = next + 12;
  while ( time_t.second(timer) < next ) {
    signal.Turn(false, true, true, unit8_t 00000000, unit8_t 11111111, unit8_t 00000000);
    timer = now(); 
  }
  
  next = next + 2;
  while (time_t.second(timer) < next) { timer = now(); }
  
  next = next + 7;
  while ( time_t.second(timer) < next ) {
    signal.Turn(false, true, false, unit8_t 11111111, unit8_t 11111111, unit8_t 00000000);
    timer = now(); 
  }
  
  next = next + 8;
  while ( time_t.second(timer) < next ) {
    signal.Turn(true, false, false, unit8_t 00000000, unit8_t 11111111, unit8_t 00000000);
    timer = now(); 
  }
  
  next = next + 11;
  while ( time_t.second(timer) < next ) {
    signal.Turn(false, true, true, unit8_t 00000000, unit8_t 11111111, unit8_t 00000000);
    timer = now();
  }
  
  next = next + 7;
  while ( time_t.second(timer) < next ) {
    signal.Turn(false, false, false, unit8_t 00000000, unit8_t 00000000, unit8_t 00000000);
    timer = now();
  }
  
  next = next + 17;
  while (time_t.second(timer) < next) { timer = now(); }
  
  next = next + 4
  while ( time_t.second(timer) < next ) {
    signal.CollisionAvoidance();
    timer = now();
  }
  
  next = next + 100
  while (time_t.second(timer) < next) { timer = now(); }
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
