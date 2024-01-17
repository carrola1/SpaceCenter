#include "RocketStream.hpp"
#include "stm32l0xx_hal.h"

RocketStream::RocketStream(TIM_HandleTypeDef &timHandle, uint32_t timChannel, DMA_HandleTypeDef &dmaHandle)
                : ledArray((uint16_t)(NUM_LEDS_ROCKET_STREAM), timHandle, timChannel, dmaHandle) {
  for (int i=0; i<NUM_LEDS_ROCKET_STREAM; i++) {
    ledArray.setPixelColor(i, 0, 0, 0);
  }
  showPixels();
}

RocketStream::~RocketStream() {
}

void RocketStream::setRocketColor(uint8_t index, uint8_t r, uint8_t g, uint8_t b) {
  for (int i=index*2; i<index*2+2; i++) {
    ledArray.setPixelColor(i, r, g, b);
  }
}

void RocketStream::setAllRocketColor(uint8_t r, uint8_t g, uint8_t b) {
  for (int i=0; i<NUM_ROCKETS*NUM_LEDS_ROCKET; i++) {
    ledArray.setPixelColor(i, r, g, b);
  }
}

void RocketStream::setStreamColor(uint8_t index, uint8_t r, uint8_t g, uint8_t b) {
  // Left side stream
  ledArray.setPixelColor(STREAM_START_IND+index, r, g, b);

  // Right side stream
  ledArray.setPixelColor(STREAM_START_IND+NUM_LEDS_STREAM*2-1-index, r, g, b);
}

void RocketStream::setAllStreamColor(uint8_t r, uint8_t g, uint8_t b) {
  for (int i=STREAM_START_IND; i<STREAM_START_IND+NUM_LEDS_STREAM*2; i++) {
    ledArray.setPixelColor(i, r, g, b);
  }
}

void RocketStream::showPixels() {
  ledArray.show();
}

