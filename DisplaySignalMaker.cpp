#include "Arduino.h"

#include "DisplaySignalMaker.h"
#include "PixelLocation.h"

DisplaySignalMaker::DisplaySignalMaker() {
  /*controlPoints[0] = PixelLocation::pixelAnglePair(0,1 );    
  controlPoints[1] = PixelLocation::pixelAnglePair(4,9000);
  controlPoints[2] = PixelLocation::pixelAnglePair(6,18000);
  pixie = PixelLocation(controlPoints, 3);

  pixie->setBrightness(50);
  pixie->clear();
  pixie->show();*/

  //PixelLocation::pixelAnglePair controlPoints[3];
  controlPoints[0] = PixelLocation::pixelAnglePair(0,1000 );
  controlPoints[1] = PixelLocation::pixelAnglePair(2,3000);
  controlPoints[2] = PixelLocation::pixelAnglePair(6,6500);
  controlPoints[3] = PixelLocation::pixelAnglePair(7,11500);
  controlPoints[4] = PixelLocation::pixelAnglePair(11,16000);
  controlPoints[5] = PixelLocation::pixelAnglePair(13,17000);
  controlPoints[6] = PixelLocation::pixelAnglePair(14,20000);
  controlPoints[7] = PixelLocation::pixelAnglePair(19,26000);
  controlPoints[8] = PixelLocation::pixelAnglePair(20,28000);
  controlPoints[9] = PixelLocation::pixelAnglePair(25,34000);
  static PixelLocation pixelLocation = PixelLocation(controlPoints, 10);
  pixie = &pixelLocation;
  //pixie->fullTest();
  //pixie->show();
  pixie->setBrightness(50);
  
}

void DisplaySignalMaker::Heading( int heading1 ) {
  if (heading1 == heading) {
    pixie->show();
    return;
  }
  pixie->clear();
  pixie->show();
  heading = heading1;
  
  int angle = (heading * 100) + 27000;
  while (angle > 36000) { angle -= 36000; }
  pixie->dot(angle, 255, 0, 255);
  pixie->show();
  return;
}

void DisplaySignalMaker::Accelerameter( int x1, int y1 ) {
  if ( (x1 == x) && (y1 == y) ) {
    pixie->show();
    return;
  }
  x = x1;
  y = y1;
  pixie->clear();
  pixie->show();
  
  int center = 90 - y;
  int diff = 90 + x;
  while (diff < 180) { diff -= 180; }
  
  angle1 = center + diff;
  angle2 = center - diff;
  if (angle1 > 360) { angle1 -= 360; }
  if (angle2 < 0) { angle2 += 360; }
  
  pixie->dot(angle1*100, 0, 0, 255);
  pixie->dot(angle2*100, 0, 0, 255);
  pixie->show();
  
}

void DisplaySignalMaker::test() {
  //pixie->clear();
  //pixie->dot(9000, 255, 255, 255);
  pixie->fullTest();
  pixie->show();
}

void DisplaySignalMaker::Turn(bool isLeft, bool isRight, bool isFast, uint8_t r, uint8_t g, uint8_t b) {
  pixie->clear();
  pixie->show();
  int howSlow = 200;
  angle = 0;
  
  if ( isLeft == true ) { angle = 18000; }
  else if ( isRight == true ) { angle = 0; }
  else {    
    Serial.println("uturn");
    angle = 0;
    while (angle <= 18000) {
      pixie->dot(angle, 255, 255, 0);
      pixie->show();
      delay(25);
      pixie->clear();
      pixie->show();
      angle += 500;
    }
    return;
  }
  
  if ( isFast == true ) { howSlow = 100; }
  
  pixie->dot(angle, r, g, b);
  pixie->show();
  delay(howSlow);
  pixie->clear();
  pixie->show();
  delay(howSlow);
  //Serial.println("leaving");
  return;
}
  
void DisplaySignalMaker::CollisionAvoidance() {
  angle1 = 0;
  angle2 = 35900;
  pixie->line(angle1, angle2, 255, 0, 0);
  pixie->show();
  return;
}
