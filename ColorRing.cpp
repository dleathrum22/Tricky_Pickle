#include <math.h>

#include "ColorRing.h"
#include "PixelLocation.h"

const double PI = std::atan(1.0)*4;

ColorRing::ColorRing(int lightInitial, int lineLength, bool overwriteLap, bool rotation, int flashSpeed, uint8_t r, uint8_t g, uint8_t b) {
  angle1 = lightInitial
  int radius = 10; // in centimeters
  int circumference = 2 * PI * radius;
  if (lineLength => circumference) { PixelLocation( 0, 0, flashSpeed, r, g, b); }
  if (lineLength == 1) { PixelLocation( angle1, flashSpeed, r, g, b); }
  angle2 = angle1 + ((lineLength / radius) * (180 / PI));
  PixelLocation(angle1, angle2, flashSpeed, r, g, b);
  
}
