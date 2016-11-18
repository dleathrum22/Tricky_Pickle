#include "PixelLocation.h"

class DisplaySignalMaker {
  public:
    DisplaySignalMaker(); //When the input data is determined as to what is recieved via bluethooth, put them as a parameter here
    void Heading(int heading1); //Sets a red light to always point to the magnetic North Pole
    void Accelerameter(int x1, int y1);
  private:
    //display signals should be stored here
    bool trigger;
    PixelLocation pixie;
    int x, y;
    int heading, angle;
    int angle1, angle2;
}
