// Peripheral usage
#include "stm32f0xx_hal.h"
#include "NeoPixel.hpp"
#include <stdlib.h>
extern TIM_HandleTypeDef htim2;
extern DMA_HandleTypeDef hdma_tim2_ch1;

NeoPixel::NeoPixel(uint16_t n) {
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
  pixels[n * 3] = r;
  pixels[n * 3 + 1] = g;
  pixels[n * 3 + 2] = b;
}

void NeoPixel::show(void) {

  wr_buf_p = 0;

  if(wr_buf_p != 0 || hdma_tim2_ch1.State != HAL_DMA_STATE_READY) {
    // Ongoing transfer, cancel!
    for(uint8_t i = 0; i < WR_BUF_LEN; ++i) wr_buf[i] = 0;
    wr_buf_p = 0;
    HAL_TIM_PWM_Stop_DMA(&htim2, TIM_CHANNEL_1);
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
    wr_buf[i + 48] = PWM_LO << (((pixels[6] << i) & 0x80) > 0);
    wr_buf[i + 56] = PWM_LO << (((pixels[7] << i) & 0x80) > 0);
  }

  HAL_TIM_PWM_Start_DMA(&htim2, TIM_CHANNEL_1, (uint32_t *)wr_buf, WR_BUF_LEN);
  wr_buf_p = 2; // Since we're ready for the next buffer
}
