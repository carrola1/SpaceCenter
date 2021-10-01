#include "TouchBoard.hpp"

TouchBoard::TouchBoard() {
  myTouchState = NOT_TOUCHED;
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

void TouchBoard::setTouchGPIO(GPIO_TypeDef *GPIOx, uint16_t GPIOpin) {
  myGpioPort = GPIOx;
  myGpioPin = GPIOpin;
}

void TouchBoard::updateTouchState() {
  if (HAL_GPIO_ReadPin(myGpioPort, myGpioPin) == GPIO_PIN_RESET) {
    myTouchState = TOUCHED;
  } else {
    myTouchState = NOT_TOUCHED;
  }
}

TouchState_enum TouchBoard::getTouchState() {
  return myTouchState;
}
