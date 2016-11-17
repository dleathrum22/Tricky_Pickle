/*
PixelLocation.h
Alex Elias
*/

class PixelLocation {
public:
	class pixelAnglePair{
	public:
		pixelAnglePair() : pixel(0), angle(0) {}
		pixelAnglePair(uint16_t p, uint16_t a) : pixel(p), angle(a) {}
		uint16_t pixel;
		uint16_t angle;
	};

	PixelLocation(); // TODO Constructor takes in control points
	~PixelLocation();
	void printMap(); // For testing, print the pixel number lookup table over serial
	void clear(); // Resets all LEDs
	void dot(uint16_t angle, uint32_t color); // Angle is in 100ths of degrees i.e. 18000 is 180.00
	void line(uint16_t angle1, uint16_t angle2, uint32_t color); // Line starts at angle1, goes ccw
	void show(); // Updates LEDs for next cycle
private:
// Setup functions
	void generatemap(); // Using given control points, generate the pixel number lookup table
	
// Runtime functions

// Variables
	pixelAnglePair pixelMap[NUMBER_PIXELS]; // TODO initialize to 0
};
