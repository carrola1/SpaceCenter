#include "LedButton.hpp"

LedButton::LedButton(GPIO_TypeDef* ledGpioIn, uint16_t ledGpioPinIn, 
                      GPIO_TypeDef* buttonGpioIn, uint16_t buttonGpioPinIn) {
  ledGpio = ledGpioIn;
  ledGpioPin = ledGpioPinIn;
  buttonGpio = buttonGpioIn;
  buttonGpioPin = buttonGpioPinIn;
  buttonState = NOT_PRESSED;
  ledState = OFF;
}

LedButton::~LedButton() {
}

void LedButton::setLedState(LedState_enum state) {
  HAL_GPIO_WritePin(ledGpio, ledGpioPin, state);
  ledState = state;
}

LedState_enum LedButton::getLedState() {
  return ledState;
}

void LedButton::updateButtonState()

void TouchBoard::setTouchGPIO(GPIO_TypeDef *GPIOx, uint16_t GPIOpin) {
  myGpioPort = GPIOx;
  myGpioPin = GPIOpin;
}

void TouchBoard::updateTouchState() {
  if (HAL_GPIO_ReadPin(myGpioPort, myGpioPin) == GPIO_PIN_RESET) {
    myTouchState = TOUCHED;
  } else {
    myTouchState = NOT_TOUCHED;
  }
}

TouchState_enum TouchBoard::getTouchState() {
  return myTouchState;
}
