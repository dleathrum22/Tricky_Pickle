#include "Adafruit_Neopixel.h"

class PixelLocation {
  public:
    PixelLocation(double Angle1, double Angle2, int flashSpeed, uint8_t r, uint8_t g, uint8_t b);
    PixelLocation(double Angle, int flashSpeed, uint8_t r, uint8_t g, uint8_t b);
  
  private:
    int numPixels;
    int curve;
    int location;
    int angle;
  
}
