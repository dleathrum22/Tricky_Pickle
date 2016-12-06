#include "DisplaySignalMaker.h"
#include "PixelLocation.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Start");
  /*PixelLocation::pixelAnglePair controlPoints[3];
  controlPoints[0] = PixelLocation::pixelAnglePair(0,1 );
  controlPoints[1] = PixelLocation::pixelAnglePair(4,9000);
  controlPoints[2] = PixelLocation::pixelAnglePair(6,18000);
  PixelLocation pixelLocation = PixelLocation(controlPoints, 3);
  pixelLocation.fullTest();
  pixelLocation.show();*/
  DisplaySignalMaker signal = DisplaySignalMaker();


  //pixelLocation.dot(19000,255,255,255);
  //pixelLocation.setBrightness(50);
  //pixelLocation.fullTest();
  //pixelLocation.dot(1,255,255,255);
  //pixelLocation.line(2250, 13500, 255, 255, 255);
  //pixelLocation.show();
  uint16_t angle = 0;
  //signal.test();
  //while(true);
  while(true) {    
    //pixelLocation.fullTest();
    //signal.Clear();
    //signal.test();
    //signal.Turn(false, true, true, 0, 255, 0);
    //Serial.println("again");
    //signal.Turn(true, false, false, 0, 255, 0);
    //signal.Turn(true, false, true, 0, 255, 0);
    //signal.Turn(true, false, true, 0, 255, 0);
    //signal.Turn(false, true, true, 0, 255, 0);
    //signal.Turn(false, true, false, 255, 255, 0);
    //signal.Turn(true, false, false, 0, 255, 0);
    //signal.Turn(false, true, true, 0, 255, 0);
    signal.Turn(false, false, false, 0, 0, 0);
    //signal.CollisionAvoidance();
    delay(5);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}
