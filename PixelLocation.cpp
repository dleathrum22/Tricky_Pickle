/*
PixelLocation.cpp
Alex Elias

TODO: i for index of pixelMap, n for LED number
TODO: make sure loops have breaks
*/

#include "PixelLoaction.h"

PixelLocation::PixelLocation(pixelAnglePair[] controlPoints, uint8_t n) {
	// Generate the pixel map
	// First, iterate through each touching pair...
	for (uint16_t i = 1; i < n; ++i) {
		generateMap(controlPoints[i-1], controlPoints[i]);
	}
	// ...And don't forget the last pair with the first pair.
	generateMap(controlPoints[n], controlPoints[0]);

	// Now sort the map by increasing angle
	// Simple bubble sort
	pixelAnglePair tempPair();

	for (uint16_t i = 0; i < NUMBER_PIXELS; ++i) {              
	    for(uint16_t j = 1; j < NUMBER_PIXELS - i; j++) {              
			if(pixelMap[j-1].angle > pixelMap[j].angle) {
				// Swap them
				tempPair = pixelMap[j];
				pixelMap[j] = pixelMap[j-1];
				pixelMap[j-1] = tempPair;
			} 
	    }
    }
}

void PixelLocation::printMap() {
	Serial.println("Pixel Map:");
	Serial.println("ANGLE | PIXEL");
	Serial.println("------+------");
	for (uint16_t i = 0; i < NUMBER_PIXELS; ++i) {
		Serial.print(pixelMap[i].angle);
		Serial.print(" | ");
		Serial.print(pixelMap[i].pixel);
		Serial.println();
	}
	Serial.println("-------------");
	
}

void PixelLocation::dot(uint16_t angle, uint8_t r, uint8_t g, uint8_t b) {
	uint16_t closest1, closest2; // Indecies of the closest pixels; 2 is CCW of 1
	
	// Search the table for the nearest two angles, considering two special cases
	if (pixelMap[0].angle > angle) { // a is between first and last items in list
		closest2 = 0;
		closest1 = NUMBER_PIXELS - 1;
	}

	else if (a > pixelMap[NUMBER_PIXELS].angle) { // Again, a is between first and last items
		closest2 = 0;
		closest1 = NUMBER_PIXELS - 1;
	}
	
	else for (uint16_t i = 1; i < NUMBER_PIXELS; ++i) {
		if (pixelMap[i].angle > angle) { // a is between i and i-1
			closest2 = i;
			closest1 = i - 1;
			break;
		}
	}

	// Find angle difference between closest pixels
	// TODO: account for 0 crossing
	uint16_t angleDelta = pixelMap[closest2].angle - pixelMap[closest1].angle;

	// The further the dot angle from the pixel angle, the dimmer
	distance1 = (angle - closest1); // TODO account for 0 crossing and fractions
	proportion2 = distance1/angleDelta;
	proportion1 = 1 - proportion1;


	strip.setPixelColor(pixelMap[closest1].pixel, r, g, b); // TODO multiply by proportions
	strip.setPixelColor(pixelMap[closest2].pixel, r, g, b);
}


void PixelLocation::line(uint16_t angle1, uint16_t angle2, uint8_t r, uint8_t g, uint8_t b) {
	uint16_t closest1, closest2; // Indecies of the closest outside pixels; 2 is CCW of 1

	// Find the pixel CW of angle1
	for (uint16_t i = 0; i < NUMBER_PIXELS; ++i) { // TODO: special cases?
		if (angle1 > pixelMap[i]) {
			closest1 = i;
			break;
		}
	}

	// Find the pixel CCW of angle2
	for (uint16_t i = 0; i < NUMBER_PIXELS; ++i) { // TODO: special cases?
		if (angle2 < pixelMap[i]) {
			closest2 = i;
			break;
		}
	}

	// Set color of the pixel CW of angle1
	strip.setPixelColor(closest1.pixel, r, g, b); // TODO multiply by proportion

	// Set color of the pixel CCW of angle2
	strip.setPixelColor(closest2.pixel, r, g, b); // TODO multiply by proportion

	// Set color of pixels in between
	// TODO: deal with 0 crossing
	for (uint16_t n = closest1.pixel; n < closest2.pixel; ++n) {
		strip.setPixelColor(n, r, g, b);
	}

}


void PixelLocation::generateMap(pixelAnglePair pixel1, pixelAnglePair pixel2) {
	// For now, the pixel map is ordered by pixel rather than angle

	// Put in pixel1 directly in the pixel map
	// Linearly interpolate every pixel in between
	// Don't put pixel2 in the map, since every control point will eventually be pixel1
	for(uint16_t i = pixel1.pixel; i < pixel2.pixel; ++i) {
		proportion = (i-pixel1.pixel) / (pixel2.pixel - pixel1.pixel); // TODO: proportion needs to be inline
		angle = pixel1.angle + proportion * (pixel2.angle - pixel1.angle); // TODO: account for zero crossing

		pixelMap[i] = pixelAnglePair(i, angle);
	}		
}
