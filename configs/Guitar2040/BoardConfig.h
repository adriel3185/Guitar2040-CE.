/*
 * SPDX-License-Identifier: MIT
 * Guitar2040-CE: dedicated nine-button Clone Hero guitar.
 */
#ifndef GUITAR2040_BOARD_CONFIG_H_
#define GUITAR2040_BOARD_CONFIG_H_
#include "enums.pb.h"
#include "class/hid/hid.h"
#define BOARD_CONFIG_LABEL "Guitar2040"
#define DEFAULT_INPUT_MODE INPUT_MODE_KEYBOARD
#define DEFAULT_INPUT_MODE_B1 -1
#define DEFAULT_INPUT_MODE_B2 -1
#define DEFAULT_INPUT_MODE_B3 -1
#define DEFAULT_INPUT_MODE_B4 -1
#define DEFAULT_INPUT_MODE_R2 -1
#define DEFAULT_DEBOUNCE_DELAY 5
#define GPIO_PIN_02 GpioAction::BUTTON_PRESS_B1
#define GPIO_PIN_03 GpioAction::BUTTON_PRESS_B2
#define GPIO_PIN_04 GpioAction::BUTTON_PRESS_B3
#define GPIO_PIN_05 GpioAction::BUTTON_PRESS_B4
#define GPIO_PIN_06 GpioAction::BUTTON_PRESS_L1
#define GPIO_PIN_07 GpioAction::BUTTON_PRESS_UP
#define GPIO_PIN_08 GpioAction::BUTTON_PRESS_DOWN
#define GPIO_PIN_09 GpioAction::BUTTON_PRESS_S2
#define GPIO_PIN_10 GpioAction::BUTTON_PRESS_S1
// These GPIOs are owned by the dedicated five-LED controller.
#define GPIO_PIN_11 GpioAction::ASSIGNED_TO_ADDON
#define GPIO_PIN_12 GpioAction::ASSIGNED_TO_ADDON
#define GPIO_PIN_13 GpioAction::ASSIGNED_TO_ADDON
#define GPIO_PIN_14 GpioAction::ASSIGNED_TO_ADDON
#define GPIO_PIN_15 GpioAction::ASSIGNED_TO_ADDON
#define KEY_BUTTON_B1 HID_KEY_A
#define KEY_BUTTON_B2 HID_KEY_S
#define KEY_BUTTON_B3 HID_KEY_D
#define KEY_BUTTON_B4 HID_KEY_F
#define KEY_BUTTON_L1 HID_KEY_G
#define KEY_DPAD_UP HID_KEY_ARROW_UP
#define KEY_DPAD_DOWN HID_KEY_ARROW_DOWN
#define KEY_DPAD_LEFT HID_KEY_ARROW_LEFT
#define KEY_DPAD_RIGHT HID_KEY_ARROW_RIGHT
#define KEY_BUTTON_S2 HID_KEY_ENTER
#define KEY_BUTTON_S1 HID_KEY_BACKSPACE
#define KEY_BUTTON_R2 HID_KEY_R
#define KEY_BUTTON_L2 HID_KEY_Q
#define KEY_BUTTON_R1 HID_KEY_W
#define KEY_BUTTON_L3 HID_KEY_EQUAL
#define KEY_BUTTON_R3 HID_KEY_MINUS
#define KEY_BUTTON_A1 HID_KEY_9
#define KEY_BUTTON_A2 HID_KEY_F2
// Optional future whammy: 10k potentiometer wiper on GP26 (ADC0).
// Disabled by default; set to 1 only after wiring and switching to a gamepad mode.
#define GUITAR2040_WHAMMY_ENABLED 0
#define GUITAR2040_WHAMMY_PIN 26
#define GUITAR2040_WHAMMY_ADC_MIN 0
#define GUITAR2040_WHAMMY_ADC_MAX 4095
#define GUITAR2040_WHAMMY_INVERT 0
#define GPIO_PIN_26 GpioAction::ASSIGNED_TO_ADDON
#define KEY_BUTTON_FN -1
#endif
