#include "TouchBoardGroup.hpp"

TouchBoardGroup::TouchBoardGroup(uint8_t n, uint8_t touchKeyOffset, TIM_HandleTypeDef &timHandle, 
                                  uint32_t timChannel, DMA_HandleTypeDef &dmaHandle) 
                : ledArray((uint16_t)(n*2), timHandle, timChannel, dmaHandle), touch_states(n) {
  numBoards = n;
  myTouchKeyOffset = touchKeyOffset;
  for (uint8_t ii = 0; ii < numBoards; ii++) {
    touch_states[ii] = TSL_STATEID_RELEASE;
  }
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

void TouchBoardGroup::updateTouchStates() {
  touchDetected = false;
  for (uint8_t ii = 0; ii<numBoards; ii++) {
    if (MyTKeysB[myTouchKeyOffset+ii].p_Data->StateId == TSL_STATEID_DETECT) {
      touchDetected = true;
    }
    touch_states[ii] = MyTKeysB[myTouchKeyOffset+ii].p_Data->StateId;
  }
}

bool TouchBoardGroup::getTouchDetected() {
  return touchDetected;
}

std::vector<TSL_StateId_enum_T> TouchBoardGroup::getTouchStates() {
  return touch_states;
}

void TouchBoardGroup::updatePixelHalfDMA() {
  ledArray.updatePixelHalfDMA();
}
