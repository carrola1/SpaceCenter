// Peripheral usage
#include "NeoPixel.hpp"
#include <stdlib.h>

NeoPixel::NeoPixel(uint16_t n, TIM_HandleTypeDef &timHandle, uint32_t timChannel, DMA_HandleTypeDef &dmaHandle) 
        : htim(timHandle), hdma(dmaHandle), timCh{timChannel} {
  updateLength(n);
  dmaRunning = false;
}

NeoPixel::~NeoPixel() {
}

void NeoPixel::updateLength(uint16_t n) {

  // Allocate new data -- note: ALL PIXELS ARE CLEARED
  numBytes = n * 3;
  pixels = (uint8_t *)malloc(numBytes);
  numLEDs = n;
}

void NeoPixel::setPixelColor(uint16_t n, uint8_t r, uint8_t g, uint8_t b) {
  pixels[n * 3] = r;
  pixels[n * 3 + 1] = g;
  pixels[n * 3 + 2] = b;
}

void NeoPixel::show(void) {

  wr_buf_p = 0;
  dmaRunning = true;

  // This block should never get run as long as you don't try to run 
  // the show method before the last transaction finished
  if(wr_buf_p != 0 || hdma.State != HAL_DMA_STATE_READY) {
    // Ongoing transfer, cancel!
    for(uint8_t i = 0; i < WR_BUF_LEN; ++i) wr_buf[i] = 0;
    wr_buf_p = 0;
    HAL_TIM_PWM_Stop_DMA(&htim, timCh);
    dmaRunning = false;
    return;
  }

  // Ooh boi the first data buffer half (and the second!)
  for(uint_fast8_t i = 0; i < 8; ++i) {
    wr_buf[i     ] = PWM_LO << (((pixels[0] << i) & 0x80) > 0);
    wr_buf[i +  8] = PWM_LO << (((pixels[1] << i) & 0x80) > 0);
    wr_buf[i + 16] = PWM_LO << (((pixels[2] << i) & 0x80) > 0);
    wr_buf[i + 24] = PWM_LO << (((pixels[3] << i) & 0x80) > 0);
    wr_buf[i + 32] = PWM_LO << (((pixels[4] << i) & 0x80) > 0);
    wr_buf[i + 40] = PWM_LO << (((pixels[5] << i) & 0x80) > 0);
  }

  HAL_TIM_PWM_Start_DMA(&htim, timCh, (uint32_t *)wr_buf, WR_BUF_LEN);
  wr_buf_p = 2;
}

// Halfway through DMA wr_buf write, load up next 3 bytes in first half of wr_buf
void NeoPixel::updateHalfDMA() {
  // Make sure callback is not from a different NeoPixel by checking dmaRunning
  if (dmaRunning) {
    // DMA buffer set from LED(wr_buf_p) to LED(wr_buf_p + 1)
    if(wr_buf_p < numLEDs) {
      // We're in. Fill the even buffer
      for(uint_fast8_t i = 0; i < 8; ++i) {
        wr_buf[i     ] = PWM_LO << (((pixels[3 * wr_buf_p    ] << i) & 0x80) > 0);
        wr_buf[i +  8] = PWM_LO << (((pixels[3 * wr_buf_p + 1] << i) & 0x80) > 0);
        wr_buf[i + 16] = PWM_LO << (((pixels[3 * wr_buf_p + 2] << i) & 0x80) > 0);
      }
      wr_buf_p++;
    } else if (wr_buf_p < numLEDs + 2) {
      // Last two transfers are resets. 64 * 1.25 us = 80 us == good enough reset
      // First half reset zero fill
      for(uint8_t i = 0; i < WR_BUF_LEN / 2; ++i) wr_buf[i] = 0;
      wr_buf_p++;
    } else {
      HAL_TIM_PWM_Stop_DMA(&htim, timCh);
      dmaRunning = false;
    }
  }
  return;
}

// End of wr_buf write, load up next 3 bytes in second half of wr_buf
void NeoPixel::updateDMA() {
  // Make sure callback is not from a different NeoPixel by checking dmaRunning
  if (dmaRunning) {
    // DMA buffer set from LED(wr_buf_p) to LED(wr_buf_p + 1)
    if(wr_buf_p < numLEDs) {
      // We're in. Fill the even buffer
      for(uint_fast8_t i = 0; i < 8; ++i) {
        wr_buf[i + 24] = PWM_LO << (((pixels[3 * wr_buf_p    ] << i) & 0x80) > 0);
        wr_buf[i + 32] = PWM_LO << (((pixels[3 * wr_buf_p + 1] << i) & 0x80) > 0);
        wr_buf[i + 40] = PWM_LO << (((pixels[3 * wr_buf_p + 2] << i) & 0x80) > 0);
      }
      wr_buf_p++;
    } else if (wr_buf_p < numLEDs + 2) {
      // Last two transfers are resets. 64 * 1.25 us = 80 us == good enough reset
      // Second half reset zero fill
      for(uint8_t i = WR_BUF_LEN / 2; i < WR_BUF_LEN; ++i) wr_buf[i] = 0;
      wr_buf_p++;
    } else {
      wr_buf_p = 0;
      HAL_TIM_PWM_Stop_DMA(&htim, timCh);
      dmaRunning = false;
    }
  }
  return;
}

