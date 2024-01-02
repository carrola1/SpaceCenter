#ifndef ROCKETSTREAM_HPP
#define ROCKETSTREAM_HPP

#include <stdint.h>
#include "stm32l0xx_hal.h"
#include "NeoPixel.hpp"

#define NUM_ROCKETS 4
#define NUM_LEDS 72
#define NUM_LEDS_ROCKET 2
#define NUM_LEDS_STREAM 32
#define STREAM_START_IND 8

typedef struct PixelColor_s
  {
    uint8_t r;
    uint8_t g;
    uint8_t b;
  } PixelColor_s;

class RocketStream {

public:

  // Constructor: number of boards in group and pointer to touch buttons
  RocketStream(TIM_HandleTypeDef &timHandle, uint32_t timChannel, DMA_HandleTypeDef &dmaHandle);
  ~RocketStream();

  // NeoPixels methods
  void setRocketColor(uint8_t index, uint8_t r, uint8_t g, uint8_t b);
  void setAllRocketColor(uint8_t r, uint8_t g, uint8_t b);
  void setStreamColor(uint8_t index, uint8_t r, uint8_t g, uint8_t b);
  void setAllStreamColor(uint8_t r, uint8_t g, uint8_t b);
  void showPixels();
  PixelColor_s getRocketColor(uint8_t index);
  PixelColor_s getStreamColor(uint8_t index);

private:

  NeoPixel ledArray;
  PixelColor_s pixelColors[NUM_PIXELS_PER_BOARD];
  bool dmaRunning;

#endif /* ROCKETSTREAM_HPP */
