#include "DisplaySignalMaker.h"

class ColorRing {
  public:
    ColorRing(int lightInitial, int lineLength, bool overwriteLap, bool rotation, int flashSpeed, uint8_t r, uint8_t g, uint8_t b);
    /*
    lightInitial - which LED is the first light thats light up
    lineLength - length of the 
    overwriteLap
    rotation - if the lights are going turn on in a sequence, starting on lightInitial going through lineLength
    flashSpeed - int between 0 and 255 to designate the speed of the flash, 0 is off, 255 is solid
    r - 8bit value of how how much red is shown
    g - 8bit value of how how much green is shown
    b - 8bit value of how how much blue is shown
    */
  private:
    int angle1;
    int angle2;
    uint8_t r;
    uint8_t g; 
    uint8_t b;
  
}
