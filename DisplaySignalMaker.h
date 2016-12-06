#include "PixelLocation.h"

class DisplaySignalMaker {
  public:
    DisplaySignalMaker(); //Sets up the PixelLocation class to be ready to alter the lights
    void Heading(int heading1); //Sets a red light to always point to the magnetic North Pole
    void Accelerameter(int x1, int y1);
    void Turn(bool isLeft, bool isRight, bool isFast, uint8_t r, uint8_t g, uint8_t b);
    void CollisionAvoidance();
    void test();
    void Clear() { pixie->clear(); pixie->show(); }
  private:
    //display signals should be stored here
    bool trigger;
    
    PixelLocation::pixelAnglePair controlPoints[10];
    PixelLocation* pixie;

    int x, y;
    int heading;
    int angle, angle1, angle2;
};
