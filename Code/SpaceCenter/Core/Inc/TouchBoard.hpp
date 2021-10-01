#ifndef TOUCHBOARD_HPP
#define TOUCHBOARD_HPP

#include <stdint.h>
#include "stm32l0xx_hal.h"

#define NUM_PIXELS_PER_BOARD 2

typedef struct PixelColor_s
  {
    uint8_t r;
    uint8_t g;
    uint8_t b;
  } PixelColor_s;

typedef enum
  {
    TOUCHED        = 0,
    NOT_TOUCHED    = 1
  } TouchState_enum;

class TouchBoard {

public:
  // Constructor
  TouchBoard();
  ~TouchBoard();

  void setPixelColor(uint8_t pixel_ind, uint8_t r, uint8_t g, uint8_t b);
  void setAllPixelColor(uint8_t r, uint8_t g, uint8_t b);
  PixelColor_s getPixelColor(uint8_t pixel_ind);

  void setTouchGPIO(GPIO_TypeDef *GPIOx, uint16_t GPIOpin);
  TouchState_enum getTouchState();
  void updateTouchState();

private:
  PixelColor_s pixelColors[NUM_PIXELS_PER_BOARD];

  GPIO_TypeDef *myGpioPort;
  uint16_t myGpioPin;
  TouchState_enum myTouchState;
};

#endif // TOUCHBOARD_HPP
