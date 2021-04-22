#ifndef TOUCHBOARDGROUP_HPP
#define TOUCHBOARDGROUP_HPP

#include <stdint.h>
#include <vector>
#include "NeoPixel.hpp"
#include "touchsensing.h"

class TouchBoardGroup {

public:

  // Constructor: number of boards in group and pointer to touch buttons
  TouchBoardGroup(uint8_t n, uint8_t touchKeyOffset,
                  TIM_HandleTypeDef &timHandle, uint32_t timChannel, DMA_HandleTypeDef &dmaHandle);
  ~TouchBoardGroup();

  void setPixelColor(uint8_t board_num, uint8_t r, uint8_t g, uint8_t b);
  void setAllPixelColor(uint8_t r, uint8_t g, uint8_t b);
  std::vector<TSL_StateId_enum_T> getTouchStates();
  void updateTouchStates();
  bool getTouchDetected();
  void updatePixelHalfDMA();

private:
  uint8_t numBoards;
  NeoPixel ledArray;
  uint8_t myTouchKeyOffset;
  bool dmaRunning;
  std::vector<TSL_StateId_enum_T> touch_states;
  bool touchDetected;
};

#endif // TOUCHBOARDGROUP_HPP
