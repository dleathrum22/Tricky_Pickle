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
  
  int angle = heading + 270;
  while (angle > 360) { angle -= 360; }
  pixie.dot(angle, unit32_t 0/* make this red */);
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
  
  
}
