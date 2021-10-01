#include <stdint.h>
#include "main.h"
#include "stm32l0xx_hal.h"

#define NUM_BOARDS 24

GPIO_TypeDef* touchGpioMap_Port[NUM_BOARDS] =
    {
    	TOUCH_STAR_0_GPIO_Port, // Board 0
    	TOUCH_STAR_1_GPIO_Port, // Board 1
    	TOUCH_STAR_2_GPIO_Port, // Board 2
        TOUCH_STAR_3_GPIO_Port, // Board 3
        TOUCH_STAR_4_GPIO_Port, // Board 4
        TOUCH_STAR_5_GPIO_Port, // Board 5
        TOUCH_STAR_6_GPIO_Port, // Board 6
        TOUCH_STAR_7_GPIO_Port, // Board 7
        TOUCH_STAR_8_GPIO_Port, // Board 8
        TOUCH_STAR_9_GPIO_Port, // Board 9
        TOUCH_STAR_10_GPIO_Port, // Board 10
        TOUCH_STAR_11_GPIO_Port, // Board 11
        TOUCH_STAR_12_GPIO_Port, // Board 12
        TOUCH_STAR_13_GPIO_Port, // Board 13
        TOUCH_STAR_14_GPIO_Port, // Board 14
        TOUCH_STAR_15_GPIO_Port, // Board 15
        TOUCH_STAR_16_GPIO_Port, // Board 16
        TOUCH_STAR_17_GPIO_Port, // Board 17
        TOUCH_STAR_18_GPIO_Port, // Board 18
        TOUCH_STAR_19_GPIO_Port, // Board 19
        TOUCH_STAR_20_GPIO_Port, // Board 20
        TOUCH_STAR_21_GPIO_Port, // Board 21
        TOUCH_STAR_22_GPIO_Port, // Board 22
        TOUCH_STAR_23_GPIO_Port  // Board 23
    };

uint16_t touchGpioMap_Pin[NUM_BOARDS] =
    {
        TOUCH_STAR_0_Pin, // Board 0
        TOUCH_STAR_1_Pin, // Board 1
        TOUCH_STAR_2_Pin, // Board 2
        TOUCH_STAR_3_Pin, // Board 3
        TOUCH_STAR_4_Pin, // Board 4
        TOUCH_STAR_5_Pin, // Board 5
        TOUCH_STAR_6_Pin, // Board 6
        TOUCH_STAR_7_Pin, // Board 7
        TOUCH_STAR_8_Pin, // Board 8
        TOUCH_STAR_9_Pin, // Board 9
        TOUCH_STAR_10_Pin, // Board 10
        TOUCH_STAR_11_Pin, // Board 11
        TOUCH_STAR_12_Pin, // Board 12
        TOUCH_STAR_13_Pin, // Board 13
        TOUCH_STAR_14_Pin, // Board 14
        TOUCH_STAR_15_Pin, // Board 15
        TOUCH_STAR_16_Pin, // Board 16
        TOUCH_STAR_17_Pin, // Board 17
        TOUCH_STAR_18_Pin, // Board 18
        TOUCH_STAR_19_Pin, // Board 19
        TOUCH_STAR_20_Pin, // Board 20
        TOUCH_STAR_21_Pin, // Board 21
        TOUCH_STAR_22_Pin, // Board 22
        TOUCH_STAR_23_Pin  // Board 23
    };
