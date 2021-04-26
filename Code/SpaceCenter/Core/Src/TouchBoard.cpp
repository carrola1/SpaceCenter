#include "TouchBoard.hpp"
#include "touchsensing.h"

TouchBoard::TouchBoard() {
  myTouchState = NOT_TOUCHED;
  myTouchKeyOffset = 0;
  for (int i=0; i<NUM_PIXELS_PER_BOARD; i++) {
    pixelColors[i].r = 0;
    pixelColors[i].g = 0;
    pixelColors[i].b = 0;
  }
}

TouchBoard::~TouchBoard() {
}

void TouchBoard::setPixelColor(uint8_t pixel_num, uint8_t r, uint8_t g, uint8_t b) {
  pixelColors[pixel_num].r = r;
  pixelColors[pixel_num].g = g;
  pixelColors[pixel_num].b = b;
}

void TouchBoard::setAllPixelColor(uint8_t r, uint8_t g, uint8_t b) {
  for (int i=0; i<NUM_PIXELS_PER_BOARD; i++) {
    pixelColors[i].r = r;
    pixelColors[i].g = g;
    pixelColors[i].b = b;
  }
}

PixelColor_s TouchBoard::getPixelColor(uint8_t pixel_ind) {
  return pixelColors[pixel_ind];
}

void TouchBoard::setTouchKeyOffset(uint8_t touchKeyOffset) {
  myTouchKeyOffset = touchKeyOffset;
}

void TouchBoard::updateTouchState() {
  if (MyTKeysB[myTouchKeyOffset].p_Data->StateId == TSL_STATEID_DETECT) {
    myTouchState = TOUCHED;
  } else if (MyTKeysB[myTouchKeyOffset].p_Data->StateId == TSL_STATEID_RELEASE) {
    myTouchState = NOT_TOUCHED;
  }
}

TouchState_enum TouchBoard::getTouchState() {
  return myTouchState;
}