#include "RocketStream.hpp"
#include "stm32l0xx_hal.h"

RocketStream::RocketStream(TIM_HandleTypeDef &timHandle, uint32_t timChannel, DMA_HandleTypeDef &dmaHandle)
                : ledArray((uint16_t)(NUM_LEDS), timHandle, timChannel, dmaHandle) {
  for (int i=0; i<NUM_LEDS; i++) {
      pixelColors[i].r = 0;
      pixelColors[i].g = 0;
      pixelColors[i].b = 0;
    }
}

RocketStream::~RocketStream() {
}

void RocketStream::setRocketColor(uint8_t index, uint8_t r, uint8_t g, uint8_t b) {
  for (int i=index*2; i<index*2+2; i++) {
    pixelColors[i].r = 0;
    pixelColors[i].g = 0;
    pixelColors[i].b = 0;
  }
}

void RocketStream::setAllRocketColor(uint8_t r, uint8_t g, uint8_t b) {
  for (int i=0; i<NUM_ROCKETS*NUM_LEDS_ROCKET; i++) {
    pixelColors[i].r = r;
    pixelColors[i].g = g;
    pixelColors[i].b = b;
  }
}

void RocketStream::setStreamColor(uint8_t index, uint8_t r, uint8_t g, uint8_t b) {
  // Left side stream
  pixelColors[STREAM_START_IND+index].r = r;
  pixelColors[STREAM_START_IND+index].g = g;
  pixelColors[STREAM_START_IND+index].b = b;

  // Right side stream
  pixelColors[STREAM_START_IND+index+NUM_LEDS_STREAM].r = r;
  pixelColors[STREAM_START_IND+index+NUM_LEDS_STREAM].g = g;
  pixelColors[STREAM_START_IND+index+NUM_LEDS_STREAM].b = b;

}

