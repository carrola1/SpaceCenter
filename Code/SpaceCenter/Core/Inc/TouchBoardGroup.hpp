#ifndef TOUCHBOARDGROUP_HPP
#define TOUCHBOARDGROUP_HPP

#include <stdint.h>
#include <vector>
#include "NeoPixel.hpp"
#include "TouchBoard.hpp"
#include "stm32l0xx_hal.h"

class TouchBoardGroup {

#define IM_A_STAR_DELAY 500 // Delay between star animation
#define IM_A_STAR_NUM_STARS 48 // # of stars to cycle through
#define IM_A_STAR_NUM_COLORS 4

public:

  // Constructor: number of boards in group and pointer to touch buttons
  TouchBoardGroup(uint8_t n, TIM_HandleTypeDef &timHandle, uint32_t timChannel, DMA_HandleTypeDef &dmaHandle);
  ~TouchBoardGroup();

  // NeoPixels methods
  void setPixelColor(uint8_t board_num, uint8_t pixel_ind, uint8_t r, uint8_t g, uint8_t b);
  void setAllPixelColor(uint8_t r, uint8_t g, uint8_t b);
  void setBoardColor(uint8_t board_num, uint8_t r, uint8_t g, uint8_t b);
  void twinkleBoard(uint8_t board_num);
  void imAStarSetup();
  bool imAStarUpdate();
  void showPixels();
  PixelColor_s getPixelColor(uint8_t board_num, uint8_t pixel_ind);

  // Touch methods
  std::vector<TouchState_enum> getTouchStates();
  std::vector<TouchEvent_enum> getTouchEvents();
  void updateTouchStates();

private:
  uint8_t numBoards;
  uint8_t numPixels;
  uint8_t starInd;
  uint8_t colorInd;
  uint8_t starCount;
  uint32_t timer;
  
  std::vector<PixelColor_s> imAStarColors = {
      {200, 10, 200},
      {50, 50, 200},
      {200, 50, 50},
      {50, 200, 100}
  };

  NeoPixel ledArray;
  bool dmaRunning;

  uint8_t myTouchKeyOffset;
  std::vector<TouchBoard> touchBoards;
  std::vector<TouchState_enum> touchStates;
  std::vector<TouchEvent_enum> touchEvents;
};

#endif // TOUCHBOARDGROUP_HPP
