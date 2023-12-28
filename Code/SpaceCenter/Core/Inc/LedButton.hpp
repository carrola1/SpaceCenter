#ifndef LEDBUTTON_HPP
#define LEDBUTTON_HPP

#include <stdint.h>
#include "stm32l0xx_hal.h"

#define BUTTON_DEBOUNCE_MS 100

typedef enum
  {
    NOT_PRESSED  = 0,
    PRESSED
  } ButtonState_enum;

typedef enum
  {
    OFF  = 0U,
    ON
  } LedState_enum;

class LedButton {

public:
  // Constructor
  LedButton(GPIO_TypeDef *ledGpioIn, uint16_t ledGpioPinIn, GPIO_TypeDef *buttonGpioIn, uint16_t buttonGpioPinIn);
  ~LedButton();

  void setLedState(LedState_enum state);
  LedState_enum getLedState();
  ButtonState_enum getButtonState();
  void updateButtonState();

private:
  GPIO_TypeDef* ledGpio;
  uint16_t ledGpioPin;
  GPIO_TypeDef* buttonGpio;
  uint16_t buttonGpioPin;
  ButtonState_enum buttonState;
  LedState_enum ledState;
  uint32_t timeLast;
  bool debounceButton;
};

#endif // LEDBUTTON_HPP
