#ifndef TOUCHBOARDGROUP_HPP
#define TOUCHBOARDGROUP_HPP

#include <stdint.h>
#include "NeoPixel.hpp"
#include "tsl_touchkey.h"

class TouchBoardGroup {

public:

  // Constructor: number of boards in group and pointer to touch buttons
  TouchBoardGroup(uint8_t n, TSL_TouchKeyB_T &touchKeysRef, uint8_t touchKeyOffset,
                  TIM_HandleTypeDef *timHandle, uint32_t timChannel, DMA_HandleTypeDef *dmaHandle);
  ~TouchBoardGroup();

  void setPixelColor(uint8_t board_num, uint8_t r, uint8_t g, uint8_t b);
  void setAllPixelColor(uint8_t r, uint8_t g, uint8_t b);
  uint8_t getTouchStates();
  uint8_t getTouchStateChanges();
  bool touchStateChangeDet();

private:
  uint8_t numBoards;
  NeoPixel ledArray;
  TSL_TouchKeyB_T touchKeys;
  uint8_t myTouchKeyOffset;
};

#endif // TOUCHBOARDGROUP_HPP