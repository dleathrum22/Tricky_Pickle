void setup() {
  // put your setup code here, to run once:
  
  //constant variables
  const int leftPin = 1;
  const int rightPin = 2;
  const int topPin = 3;
  const int bottomPin = 4;
  
  
  
}

void loop() {
  // put your main code here, to run repeatedly:

  //Speed will be a value between 0 and 255 for the speed of the LED flash
}


void LeftBlink(int speed) {
  if (speed < 0) { speed = 0; }
  else if (speed > 255) { speed = 255; }
  analogWrite(leftPin, speed);
}

void RightBlink(int speed) {
  if (speed < 0) { speed = 0; }
  else if (speed > 255) { speed = 255; }
  analogWrite(rightPin, speed);
}

void FullBlink(int speed) {
  if (speed < 0) { speed = 0; }
  else if (speed > 255) { speed = 255; }
  analogWrite(leftPin, speed);
  analogWrite(rightPin, speed);
  analogWrite(topPin, speed);
  analogWrite(bottomPin, speed);
}

void TopBlink(int speed) {
  if (speed < 0) { speed = 0; }
  else if (speed > 255) { speed = 255; }
  analogWrite(topPin, speed);
}

void BottomBlink(int speed) {
  if (speed < 0) { speed = 0; }
  else if (speed > 255) { speed = 255; }
  analogWrite(bottomPin, speed);
}

void RainbowTest() {
  
}

void FadingTest(int speed) {
  if (speed < 0) { speed = 0; }
  else if (speed > 255) { speed = 255; }
  while (speed > 0) {
    analogWrite(leftPin, speed);
    analogWrite(rightPin, speed);
    analogWrite(topPin, speed);
    analogWrite(bottomPin, speed);
    speed =- 10;
  }
}

/*
dot moving in circle
flash
    Lelft/Right
    Full
    Top/Bottom
Full rainbow
fading
Blink at different speeds
*/
