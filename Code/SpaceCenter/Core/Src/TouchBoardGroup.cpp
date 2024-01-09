#include "TouchBoardGroup.hpp"
#include "TouchGpioMap.h"
#include "stm32l0xx_hal.h"

TouchBoardGroup::TouchBoardGroup(uint8_t n, TIM_HandleTypeDef &timHandle,
                                  uint32_t timChannel, DMA_HandleTypeDef &dmaHandle) 
                : ledArray((uint16_t)(n*NUM_PIXELS_PER_BOARD), timHandle, timChannel, dmaHandle),
                  touchStates(n), touchEvents(n), touchBoards(n) {
  numBoards = n;
  numPixels = n*NUM_PIXELS_PER_BOARD;
  for (int i=0; i<numBoards; i++) {
    touchBoards[i].setTouchGPIO(touchGpioMap_Port[i], touchGpioMap_Pin[i]);
    touchStates[i] = NOT_TOUCHED;
    touchEvents[i] = TOUCH_NO_CHANGE;
  }
}

TouchBoardGroup::~TouchBoardGroup() {
}

void TouchBoardGroup::setPixelColor(uint8_t board_num, uint8_t pixel_ind, uint8_t r, uint8_t g, uint8_t b) {
  touchBoards[board_num].setPixelColor(pixel_ind, r, g, b);
}

void TouchBoardGroup::setAllPixelColor(uint8_t r, uint8_t g, uint8_t b) {
  for (int i=0; i<numBoards; i++) {
    touchBoards[i].setAllPixelColor(r, g, b);
  }
}

void TouchBoardGroup::setBoardColor(uint8_t board_num, uint8_t r, uint8_t g, uint8_t b) {
  touchBoards[board_num].setAllPixelColor(r, g, b);
}

void TouchBoardGroup::twinkleBoard(uint8_t board_num) {
  PixelColor_s color = touchBoards[board_num].getPixelColor(0);
  touchBoards[board_num].setAllPixelColor(color.r/10, color.g/10, color.b/10);
  showPixels();
  HAL_Delay(40);
  touchBoards[board_num].setAllPixelColor(color.r/2, color.g/2, color.b/2);
  showPixels();
  HAL_Delay(40);
  touchBoards[board_num].setAllPixelColor(color.r/5, color.g/5, color.b/5);
  showPixels();
  HAL_Delay(40);
  touchBoards[board_num].setAllPixelColor(color.r/10, color.g/10, color.b/10);
  showPixels();
  HAL_Delay(40);
  touchBoards[board_num].setAllPixelColor(color.r/5, color.g/5, color.b/5);
  showPixels();
  HAL_Delay(40);
  touchBoards[board_num].setAllPixelColor(color.r/2, color.g/2, color.b/2);
  showPixels();
  HAL_Delay(40);
  touchBoards[board_num].setAllPixelColor(color.r, color.g, color.b);
  showPixels();
  HAL_Delay(40);
}

void TouchBoardGroup::showPixels() {
  for (int i=0; i<numBoards; i++) {
    for (int j=0; j<NUM_PIXELS_PER_BOARD; j++) {
      PixelColor_s tempColor = touchBoards[i].getPixelColor(j);
      ledArray.setPixelColor(i*NUM_PIXELS_PER_BOARD+j, tempColor.r, tempColor.g, tempColor.b);
    }
  }
  ledArray.show();
}

PixelColor_s TouchBoardGroup::getPixelColor(uint8_t board_num, uint8_t pixel_ind) {
  return touchBoards[board_num].getPixelColor(pixel_ind);
}

void TouchBoardGroup::updateTouchStates() {
  for (int i=0; i<numBoards; i++) {
    touchBoards[i].updateTouchState();
  }
}

std::vector<TouchState_enum> TouchBoardGroup::getTouchStates() {
  for (int i=0; i<numBoards; i++) {
    touchStates[i] = touchBoards[i].getTouchState();
  }
  return touchStates;
}

std::vector<TouchEvent_enum> TouchBoardGroup::getTouchEvents() {
  for (int i=0; i<numBoards; i++) {
    touchEvents[i] = touchBoards[i].getTouchEvent();
  }
  return touchEvents;
}
