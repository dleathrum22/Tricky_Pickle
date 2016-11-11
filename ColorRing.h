#include "DisplaySignalMaker.h"

class ColorRing {
  public:
    ColorRing(int lightInitial, int lineLength, bool overwriteLap, bool rotation, int flashSpeed);
    /*
    lightInitial - which LED is the first light thats light up
    lineLength - how many LEDs are on starting at the lightInitial
    overwriteLap
    rotation - if the lights are going turn on in a sequence, starting on lightInitial going through lineLength
    flashSpeed - int between 0 and 255 to designate the speed of the flash, 0 is off, 255 is solid
    */
  private:
    int angle1;
    int angle2;
    uint8_t r;
    uint8_t g; 
    uint8_t b;
  
}
