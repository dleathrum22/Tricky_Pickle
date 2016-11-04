#include "DisplaySignalMaker.h"

class ColorRing {
  public:
    ColorRing(int lightInitial, int lineLength, bool overwriteLap, bool rotation, int flashSpeed);
    
  private:
    int angle1;
    int angle2;
    uint8_t r;
    uint8_t g; 
    uint8_t b;
  
}
