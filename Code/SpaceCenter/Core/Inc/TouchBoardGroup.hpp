#ifndef TOUCHBOARDGROUP_HPP
#define TOUCHBOARDGROUP_HPP

#include <stdint.h>
#include <vector>
#include "NeoPixel.hpp"
#include "TouchBoard.hpp"
#include "touchsensing.h"

class TouchBoardGroup {

public:

  // Constructor: number of boards in group and pointer to touch buttons
  TouchBoardGroup(uint8_t n, uint8_t touchKeyOffset,
                  TIM_HandleTypeDef &timHandle, uint32_t timChannel, DMA_HandleTypeDef &dmaHandle);
  ~TouchBoardGroup();

  // NeoPixels methods
  void setPixelColor(uint8_t board_num, uint8_t pixel_ind, uint8_t r, uint8_t g, uint8_t b);
  void setAllPixelColor(uint8_t r, uint8_t g, uint8_t b);
  void setBoardColor(uint8_t board_num, uint8_t r, uint8_t g, uint8_t b);
  void twinkleBoard(uint8_t board_num);
  void showPixels();
  PixelColor_s getPixelColor(uint8_t board_num, uint8_t pixel_ind);
  void updatePixelHalfDMA();

  // Touch methods
  std::vector<TouchState_enum> getTouchStates();
  void updateTouchStates();

private:
  uint8_t numBoards;
  uint8_t numPixels;
  
  NeoPixel ledArray;
  bool dmaRunning;

  uint8_t myTouchKeyOffset;
  std::vector<TouchBoard> touchBoards;
  std::vector<TouchState_enum> touchStates;
};

#endif // TOUCHBOARDGROUP_HPP
