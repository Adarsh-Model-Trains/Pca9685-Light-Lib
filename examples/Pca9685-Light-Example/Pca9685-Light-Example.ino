#include "Pca9685.h"
#include "Pca9685Board.h"

#define NO_OF_BOARDS 4

int MAX_PINS = 0;

Pca9685Board pca9685Board;
void setup() {
  Serial.begin(9600);
  pca9685Board.initPca9685Boards(NO_OF_BOARDS);
  MAX_PINS = NO_OF_BOARDS * 16;
}

void loop() {
  for (int i = 1; i <= MAX_PINS; i++) {
    pca9685Board.switchOn(i);
  }
  pca9685Board.displayPinState();
  delay(1000);
  for (int i = 1; i <= MAX_PINS; i++) {
    pca9685Board.switchOff(i);
  }
  pca9685Board.displayPinState();
  delay(1000);
}
