#include "PixelLocation.h"

class DisplaySignalMaker {
  public:
    DisplaySignalMaker(); //Sets up the PixelLocation class to be ready to alter the lights
    void Heading(int heading1); //Sets a red light to always point to the magnetic North Pole
    void Accelerameter(int x1, int y1);
    void Turn(bool isLeft, bool isRight, bool isFast, unit8_t r, unit8_t g, unit8_t b);
    void CollisionAvoidance();
  private:
    //display signals should be stored here
    bool trigger;
    PixelLocation pixie;
    int x, y;
    int heading, angle;
    int angle, angle1, angle2;
}
