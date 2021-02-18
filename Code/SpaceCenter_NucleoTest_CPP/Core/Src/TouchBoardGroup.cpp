#include "TouchBoardGroup.hpp"

TouchBoardGroup::TouchBoardGroup(uint8_t n, uint8_t touchKeyOffset, TIM_HandleTypeDef &timHandle, 
                                  uint32_t timChannel, DMA_HandleTypeDef &dmaHandle) 
                : ledArray((uint16_t)(n*2), timHandle, timChannel, dmaHandle) {
  numBoards = n;
  myTouchKeyOffset = touchKeyOffset;
}

TouchBoardGroup::~TouchBoardGroup() {
}

void TouchBoardGroup::setPixelColor(uint8_t board_num, uint8_t r, uint8_t g, uint8_t b) {
  ledArray.setPixelColor(board_num*2, r, g, b);
  ledArray.setPixelColor(board_num*2+1, r, g, b);
  ledArray.show();
}

void TouchBoardGroup::setAllPixelColor(uint8_t r, uint8_t g, uint8_t b) {
  for (uint8_t i=0; i < numBoards; i++) {
    ledArray.setPixelColor(i*2, r, g, b);
    ledArray.setPixelColor(i*2+1, r, g, b);
  }
  ledArray.show();
}

void TouchBoardGroup::updateDMA() {
  ledArray.updateDMA();
}

void TouchBoardGroup::updateHalfDMA() {
  ledArray.updateHalfDMA();
}
