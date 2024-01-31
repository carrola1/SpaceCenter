#include "RocketStream.hpp"
#include "stm32l0xx_hal.h"

RocketStream::RocketStream(TIM_HandleTypeDef &timHandle, uint32_t timChannel, DMA_HandleTypeDef &dmaHandle)
                : ledArray((uint16_t)(NUM_LEDS_ROCKET_STREAM), timHandle, timChannel, dmaHandle) {
  for (int i=0; i<NUM_LEDS_ROCKET_STREAM; i++) {
    ledArray.setPixelColor(i, 0, 0, 0);
  }
  setRocketColor(0, 0, 0, 0);
  setStreamColor(0, 0, 0, 0);
  setStreamColor(1, 0, 0, 0);
  showPixels();
  lastUpdateTime = HAL_GetTick();
  streamCnt = 0;
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

void RocketStream::rocketLaunch(bool newSwitchPress) {
  uint32_t newTime = HAL_GetTick();

  if (newSwitchPress == 0) {
    if (newTime - lastUpdateTime >= STREAM_TIMEOUT_MS) {
      if (streamCnt > 0) {
        lastUpdateTime = newTime;
        decrementLaunch();
      }
    }
  } else {
    lastUpdateTime = newTime;
    incrementLaunch();
  }
}

void RocketStream::incrementLaunch() {
  // Increment Stream
  if (streamCnt < 15) {
    setStreamColor(streamCnt, 250, 0, 0);
    setStreamColor(streamCnt+1, 250, 0, 0);
  } else if (streamCnt < 25) {
    setStreamColor(streamCnt, 250, 136, 3);
    setStreamColor(streamCnt+1, 250, 136, 3);
  } else if (streamCnt < 31) {
    setStreamColor(streamCnt, 240, 252, 0);
    setStreamColor(streamCnt+1, 240, 252, 3);
  } else {
    setAllStreamColor(0, 0, 0);
    setStreamColor(0, 250, 0, 0);
    setStreamColor(1, 250, 0, 0);
  }

  // Increment Rockets
  if (streamCnt == 0) {
    setRocketColor(0, 250, 0, 0);
  } else if (streamCnt == 8) {
    setRocketColor(1, 250, 0, 0);
  } else if (streamCnt == 16) {
    setRocketColor(2, 250, 0, 0);
  } else if (streamCnt == 24) {
    setRocketColor(3, 250, 0, 0);
  } else if (streamCnt == 32) {
    streamCnt = 0;
    setAllRocketColor(0, 0, 0);
    setRocketColor(0, 250, 0, 0);
  }
  streamCnt = streamCnt + 2;
  showPixels();
}

void RocketStream::decrementLaunch() {
  streamCnt = streamCnt - 2;

  // Decrement Stream
  setStreamColor(streamCnt, 0, 0, 0);
  setStreamColor(streamCnt+1, 0, 0, 0);

  // Decrement Rockets
  if (streamCnt == 0) {
    setRocketColor(0, 0, 0, 0);
  } else if (streamCnt == 8) {
    setRocketColor(1, 0, 0, 0);
  } else if (streamCnt == 16) {
    setRocketColor(2, 0, 0, 0);
  } else if (streamCnt == 24) {
    setRocketColor(3, 0, 0, 0);
  }
  showPixels();
}

void RocketStream::showPixels() {
  ledArray.show();
}

