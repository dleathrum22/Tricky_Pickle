

class DisplaySignalMaker {
  public:
    DisplaySignalMaker(); //When the input data is determined as to what is recieved via bluethooth, put them as a parameter here
    Heading(int heading);
    Accelerameter(int x1, int y1, int z1);
  private:
    //display signals should be stored here
    bool trigger;
    int x, y, z;
    int heading;
}
