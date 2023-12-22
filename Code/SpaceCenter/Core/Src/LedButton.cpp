#include "LedButton.hpp"

LedButton::LedButton(GPIO_TypeDef* ledGpioIn, uint16_t ledGpioPinIn, 
                      GPIO_TypeDef* buttonGpioIn, uint16_t buttonGpioPinIn) {
  ledGpio = ledGpioIn;
  ledGpioPin = ledGpioPinIn;
  buttonGpio = buttonGpioIn;
  buttonGpioPin = buttonGpioPinIn;
  buttonState = NOT_PRESSED;
  ledState = OFF;
  timeLast = 0;
  debounceButton = false;
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

void LedButton::updateButtonState() {
  if (debounceButton == false) {
    uint16_t gpioRead = HAL_GPIO_ReadPin(buttonGpio, buttonGpioPin);
    ButtonState_enum newButtonState = gpioRead;
    if (newButtonState != buttonState) {
      debounceButton = true;
      timeLast = HAL_GetTick();
    }
    buttonState = newButtonState;
  } else {
    uint32_t timeNew = HAL_GetTick();
    uint32_t timeDiff = timeNew - timeLast;
    if (timeDiff >= BUTTON_DEBOUNCE_MS) {
      debounceButton = false;
    }
  }
}

ButtonState_enum LedButton::getButtonState() {
  return buttonState;
}


