// Peripheral usage
#include "NeoPixel.hpp"
#include <stdlib.h>

NeoPixel::NeoPixel(uint16_t n, TIM_HandleTypeDef &timHandle, uint32_t timChannel, DMA_HandleTypeDef &dmaHandle) 
        : htim(timHandle), hdma(dmaHandle), timCh{timChannel} {
  updateLength(n);
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
  pixels[n * 3] = g;
  pixels[n * 3 + 1] = r;
  pixels[n * 3 + 2] = b;
}

void NeoPixel::show(void) {

  for(uint16_t j = 0; j < numBytes; j++) {
	  for(uint_fast8_t i = 0; i < 8; i++) {
		  wr_buf[i+8*j   ] = PWM_LO << (((pixels[j]  << i) & 0x80) > 0);
	  }
  }
  for(uint_fast8_t i = 0; i < 8; i++) {
	  wr_buf[i+8*numBytes   ] = 0;
  }
  HAL_TIM_PWM_Start_DMA(&htim, timCh, (uint32_t *)wr_buf, WR_BUF_LEN);
}

