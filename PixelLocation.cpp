/*
PixelLocation.cpp
Alex Elias
*/
#include "Arduino.h"
#include "PixelLocation.h"


PixelLocation::PixelLocation(pixelAnglePair* controlPoints, uint8_t n) {
  strip.begin();
  
	// Generate the pixel map
	// First, iterate through each touching pair...
	for (uint16_t i = 1; i < n; ++i) {
		generateMap(controlPoints[i-1], controlPoints[i]);
	}
	// ...And don't forget the last pair with the first pair.
	generateMap(controlPoints[n-1], controlPoints[0]);

	// Now sort the map by increasing angle
	// Simple (stupid) bubble sort
	pixelAnglePair tempPair;

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
void PixelLocation::fullTest() {
  for (int n = 0; n < NUMBER_PIXELS; ++n) {
    strip.setPixelColor(n, 255, 255, 255);
  }
}
void PixelLocation::dot(uint16_t angle, uint8_t r, uint8_t g, uint8_t b) {
	uint16_t closest1, closest2;
	closestPixels(angle, closest1, closest2);

	// Find angle difference between closest pixels
	uint16_t angleDelta = angleDiff(pixelMap[closest1].angle, pixelMap[closest2].angle);

	// The further the dot angle from the pixel angle, the dimmer
	uint16_t distance1 = angleDiff(pixelMap[closest1].angle, angle);
	uint16_t distance2 = angleDelta - distance1;

	setPixelColorProportion(pixelMap[closest1].pixel, r, g, b, distance2, angleDelta);
	setPixelColorProportion(pixelMap[closest2].pixel, r, g, b, distance1, angleDelta);
  /*
  Serial.print("angleDelta: ");
  Serial.println(angleDelta);
  Serial.print(" distance2: ");
  Serial.println(distance2);
  Serial.print(" distance1: ");
  Serial.println(distance1);
  */
}


void PixelLocation::line(uint16_t angle1, uint16_t angle2, uint8_t r, uint8_t g, uint8_t b) {
	uint16_t Bclosest1, Bclosest2; // Closest 2 pixels to beginning of line
	uint16_t Eclosest1, Eclosest2; // Closest 2 to end of line
	closestPixels(angle1, Bclosest1, Bclosest2);
	closestPixels(angle2, Eclosest1, Eclosest2);

	uint16_t BangleDelta = angleDiff(pixelMap[Bclosest1].angle, pixelMap[Bclosest2].angle);
	uint16_t EangleDelta = angleDiff(pixelMap[Eclosest1].angle, pixelMap[Eclosest2].angle);

	uint16_t Bdistance = angleDiff(angle1, pixelMap[Bclosest2].angle);
	uint16_t Edistance = angleDiff(pixelMap[Eclosest1].angle, angle2);

	setPixelColorProportion(pixelMap[Bclosest1].pixel, r, g, b, Bdistance, BangleDelta);
	setPixelColorProportion(pixelMap[Eclosest2].pixel, r, g, b, Edistance, EangleDelta);
  /*
  Serial.print("Edistance: ");
  Serial.println(Edistance);
  Serial.print("EangleDelta: ");
  Serial.println(EangleDelta);
  */
	// Next, set color of pixels in between
	// Step through all LEDs, setting them to (r,g,b) if
	// within (or equal to) angle1 and angle2
 
	if (angle2 > angle1) {
		for (uint16_t i = 0; i < NUMBER_PIXELS; ++i) {
			if (
			  ((pixelMap[i].angle > angle1) && (pixelMap[i].angle < angle2))
        || pixelMap[i].angle == angle1 || pixelMap[i].angle == angle2
			) {
				strip.setPixelColor(pixelMap[i].pixel, r, g, b);
			}
		}
	}
	else {
		// If the line crosses 0, rather than check for greater than angle1 AND less than angle2
		// check for greater than angle1 OR less than angle2 (or equal to)
		for (uint16_t i = 0; i < NUMBER_PIXELS; ++i) {
			if (
			  (pixelMap[i].angle > angle1) || (pixelMap[i].angle < angle2)
        || pixelMap[i].angle == angle1 || pixelMap[i].angle == angle2
			) {
				strip.setPixelColor(pixelMap[i].pixel, r, g, b);
			}
		}
	}
 
}


void PixelLocation::generateMap(pixelAnglePair pixel1, pixelAnglePair pixel2) {
  /*
  Serial.print("Generating map: pixel 1 (");
  Serial.print(pixel1.pixel);
  Serial.print(", ");
  Serial.print(pixel1.angle);
  Serial.print(") pixel 2 (");
  Serial.print(pixel2.pixel);
  Serial.print(", ");
  Serial.print(pixel2.angle);
  Serial.println(")");
  Serial.flush();
  */
	// For now, the pixel map is ordered by pixel rather than angle

	uint16_t angleDelta = angleDiff(pixel1.angle, pixel2.angle);
	uint16_t nDelta;
  if (pixel2.pixel > pixel1.pixel) {
    nDelta =  pixel2.pixel - pixel1.pixel;
  }
  else {
    nDelta =  (pixel2.pixel + NUMBER_PIXELS) - pixel1.pixel;
  }
	// Put in pixel1 directly in the pixel map
	// Don't worry about putting in pixel2 since all pixels2s will eventually be pixel1s
	// Linearly interpolate every pixel in between
	uint32_t product;
	uint16_t angle;
	if (pixel2.pixel > pixel1.pixel) {
		for(uint16_t n = pixel1.pixel; n < pixel2.pixel; ++n) {
			product = uint32_t(n-pixel1.pixel) * angleDelta;
			angle = (pixel1.angle + (product / nDelta)) % 36000;
			pixelMap[n] = pixelAnglePair(n, angle); // For now, the index and LED number is the same
		}		
	}
	else {
    /*
    Serial.println("pixel1.pixel < pixel2.pixel");
    Serial.print("nDelta: ");
    Serial.println(nDelta);
    */
		for (uint16_t n = pixel1.pixel; n%NUMBER_PIXELS != pixel2.pixel; ++n) {
			product = uint32_t(n-pixel1.pixel) * angleDelta;
			angle = (pixel1.angle + (product / nDelta)) % 36000;
			pixelMap[n%NUMBER_PIXELS] = pixelAnglePair(n%NUMBER_PIXELS, angle);
		}
	}

/*
 Serial.println("Done generating map. Current progress:");
 printMap();
 */
}

void PixelLocation::closestPixels(uint16_t angle, uint16_t& closest1, uint16_t& closest2) {
	// Consider the special case that a is between the first and last items in list
	if (pixelMap[0].angle > angle || angle > pixelMap[NUMBER_PIXELS-1].angle) {
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
  /*
  Serial.print("Closest pixels to angle ");
  Serial.print(angle);
  Serial.print(": ");
  Serial.print(pixelMap[closest1].pixel);
  Serial.print(" and ");
  Serial.println(pixelMap[closest2].pixel);
  */
}


uint16_t PixelLocation::angleDiff(uint16_t angle1, uint16_t angle2) {
	if (angle2 < angle1) {
		return (angle2 + 36000) - angle1;
	}
	else {
    return angle2 - angle1;
	}
}

uint8_t PixelLocation::colorProportion(uint8_t color, uint16_t N, uint16_t D) {
	uint32_t product = uint32_t(color) * N;
	return product / D;
}

void PixelLocation::setPixelColorProportion(uint16_t n, uint8_t r, uint8_t g, uint8_t b,
uint16_t N, uint16_t D) {
	strip.setPixelColor(
		n,
		colorProportion(r, N, D),
		colorProportion(g, N, D),
		colorProportion(b, N, D)
	);
  /*
  Serial.print("Pixel ");
  Serial.print(n);
  Serial.print(": ");
  Serial.println(strip.getPixelColor(n), HEX);
  */
}
