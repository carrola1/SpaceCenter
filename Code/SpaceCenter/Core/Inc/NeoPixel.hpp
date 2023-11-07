#ifndef NEOPIXEL_HPP
#define NEOPIXEL_HPP

#include <stdint.h>
#include "stm32l0xx_hal.h"

class NeoPixel {

  public:

    // Constructor: number of LEDs
    NeoPixel(uint16_t n, TIM_HandleTypeDef &timHandle, uint32_t timChannel, DMA_HandleTypeDef &dmaHandle);
    ~NeoPixel();

    void show(void);
    void setPixelColor(uint16_t n, uint8_t r, uint8_t g, uint8_t b);
    void updateLength(uint16_t n);

  private:

    static const uint8_t PWM_HI = 28;//29;
    static const uint8_t PWM_LO = 12;//10;

    uint16_t wrBufLen;
    uint16_t numLEDs;    ///< Number of RGB LEDs in strip
    uint16_t numBytes;   ///< Size of 'pixels' buffer below
    uint8_t  *pixels;     ///< Holds LED color values (3 bytes each)
    uint8_t  *wr_buf;
    uint_fast8_t wr_buf_p;
    TIM_HandleTypeDef &htim;
    DMA_HandleTypeDef &hdma; 
    uint32_t timCh;
};

#endif // NEOPIXEL_HPP
