#include "PixelLocation.h"
void setup() {
  Serial.begin(9600);
  Serial.println("Starting!");
  PixelLocation::pixelAnglePair controlPoints[3];
  controlPoints[0] = PixelLocation::pixelAnglePair(0,1 );
  controlPoints[1] = PixelLocation::pixelAnglePair(4,9000);
  controlPoints[2] = PixelLocation::pixelAnglePair(6,18000);
  PixelLocation pixelLocation = PixelLocation(controlPoints, 3);

  pixelLocation.printMap();


  //pixelLocation.dot(19000,255,255,255);
  pixelLocation.setBrightness(50);
  //pixelLocation.fullTest();
  //pixelLocation.dot(1,255,255,255);
  //pixelLocation.line(2250, 13500, 255, 255, 255);
  //pixelLocation.show();
  uint16_t angle = 0;
 
  while(true) {
    angle = (angle + 10)%36000;
    pixelLocation.clear();
    pixelLocation.line(angle, (angle+10000)%36000, 255, 0, 0);
    pixelLocation.dot(36000 - angle,0,0,255);
    pixelLocation.dot((2*angle)%36000, 0, 255, 0);
    pixelLocation.show();
    //Serial.println(angle);
    delay(5);
  }
 
  //Serial.println("Done!");
}

void loop() {

}
