#include "TouchBoardGroup.hpp"

TouchBoardGroup::TouchBoardGroup(uint8_t n, TSL_TouchKeyB_T &touchKeysRef, uint8_t touchKeyOffset,
                                  TIM_HandleTypeDef *timHandle, uint32_t timChannel, DMA_HandleTypeDef *dmaHandle) {
  numBoards = n;
  ledArray = NeoPixel((uint16_t)n*2, timHandle, timChannel, dmaHandle);
  touchKeys = touchKeysRef;
  myTouchKeyOffset = touchKeyOffset;
}

TouchBoardGroup::~TouchBoardGroup() {
}

void TouchBoardGroup::setPixelColor(uint8_t board_num, uint8_t r, uint8_t g, uint8_t b) {
  ledArray.setPixelColor(board_num, r, g, b);
  ledArray.show();
}
