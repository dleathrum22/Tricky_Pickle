#include "DisplaySignalMaker.h"
#include "PixelLocation.h"

DisplaySignalMaker::DisplaySignalMaker() {
  pixie = new PixelLocation();
  pixie.clear();
  pixie.show();
}

void DisplaySignalMaker::Heading( int heading1 ) {
  if (heading1 == heading) {
    pixie.show();
    return;
  }
  pixie.clear();
  heading = heading1;
  
  int angle = (heading * 100) + 27000;
  while (angle > 36000) { angle -= 36000; }
  pixie.dot(angle, unit8_t 111111111, unit8_t 0, unit8_t 0);
  return;
}

void DisplaySignalMaker::Accelerameter( int x1, int y1 ) {
  if ( (x1 == x) && (y1 == y) ) {
    pixie.show();
    return;
  }
  x = x1;
  y = y1;
  pixie.clear();
  
  int center = 90 - y;
  int diff = 90 + x;
  while (diff < 180) { diff -= 180; }
  
  angle1 = center + diff;
  angle2 = center - diff;
  if (angle1 > 360) { angle1 -= 360; }
  if (angle2 < 0) { angle2 += 360; }
  
  pixie.dot(angle1, unit8_t 0, unit8_t 0, unit8_t 11111111);
  pixie.dot(angle2, unit8_t 0, unit8_t 0, unit8_t 11111111);
  
}
