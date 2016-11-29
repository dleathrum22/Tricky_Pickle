/*
PixelLocation.h
Alex Elias

Global variables needed:
NUMBER_PIXELS
LED_PIN
*/
#ifndef _PixelLocation_h_
#define _PixelLocation_h_

#include "Adafruit_NeoPixel.h"

class PixelLocation {
public:
	class pixelAnglePair{
	public:
		pixelAnglePair() : pixel(0), angle(0) {}
		pixelAnglePair(uint16_t p, uint16_t a) : pixel(p), angle(a) {}
		uint16_t pixel;
		uint16_t angle;
	};

	PixelLocation(pixelAnglePair[] controlPoints, uint8_t n); // n is number of points
	void printMap(); // For testing, print the pixel number lookup table over serial
	void setBrightness(uint8_t b) {strip.setBrightness(b);} // Defaults to full
	void clear() {strip.clear();} // Resets all LEDs
	void show() {strip.show()}; // Updates LEDs for next cycle
	
	/*
	Angle is in 100ths of degrees i.e. 18000 is 180.00
	
	Finds the two pixels the dot is between and sets the intensity of each led proportionally
	to how close the dot is.

	For now, any previous data of the two pixels is overwritten rather than blended.
	*/
	void dot(uint16_t angle, uint8_t r, uint8_t g, uint8_t b);
	
	/*
	The line starts at angle1 and goes CCW to angle2

	The two pixels directly outside the line are found and their intensity is set as if there were
	a dot at angle1 and angle2. All pixels between these angles are set to full intensity.

	Again, for now, any previous data of the pixels being written to is overwriten, not blended.
	*/
	void line(uint16_t angle1, uint16_t angle2, uint8_t r, uint8_t g, uint8_t b); // 
private:
	/*
	Given two pixels and their angles, linearly interpolates the angles of the pixels in between
	Pixel2 is CCW of Pixel1
	*/
	void generateMap(pixelAnglePair pixel1, pixelAnglePair pixel2);
	
	/*
	Finds the 2 closest pixels to a given angle, returns by reference
	closest1 and closest2 are indecies of pixelMap
	closest2 is CCW of closest1
	*/
	void closestPixels(uint16_t angle, uint16_t& closest1, uint16_t& closest2);

	// Finds the angle from angle 1 counterclockwise to angle2
	uint16_t angleDiff(uint16_t angle1, uint16_t angle2);
	
	// Finds color * Numerator / Denominator without overflowing
	uint8_t colorProportion(uint8_t color, uint16_t N, uint16_t D);

	// Sets pixel n to (r,g,b) * N / D
	void setPixelColorProportion(uint16_t n, uint8_t r, uint8_t g, uint8_t b,
		uint16_t N, uint16_t D);

	// Variables
	pixelAnglePair pixelMap[NUMBER_PIXELS];
	Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMBER_PIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);
};

#endif
