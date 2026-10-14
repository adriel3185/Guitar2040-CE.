/*
 * SPDX-License-Identifier: MIT
 * Guitar2040-CE: discrete indicator LEDs, active-high outputs.
 * GPIO 11..15 are reserved for the five fret LEDs.
 */
#pragma once
#include "pico/stdlib.h"

namespace guitar2040 {
enum class LedMode { AlwaysOn, Reactive };
class GuitarLeds {
public:
    static constexpr uint FRET_COUNT = 5;
    void setup() {
        for (uint i = 0; i < FRET_COUNT; ++i) {
            gpio_init(ledPins[i]);
            gpio_set_dir(ledPins[i], GPIO_OUT);
            gpio_put(ledPins[i], 0);
        }
    }
    void update(uint64_t debouncedPressedPins) {
        for (uint i = 0; i < FRET_COUNT; ++i) {
            bool pressed = (debouncedPressedPins & (uint64_t{1} << fretPins[i])) != 0;
            gpio_put(ledPins[i], mode == LedMode::AlwaysOn || pressed);
        }
    }
    void toggle() {
        mode = mode == LedMode::AlwaysOn ? LedMode::Reactive : LedMode::AlwaysOn;
    }
    LedMode currentMode() const { return mode; }
private:
    LedMode mode = LedMode::Reactive;
    static constexpr uint fretPins[5] = {2, 3, 4, 5, 6};
    static constexpr uint ledPins[5] = {11, 12, 13, 14, 15};
};
} // namespace guitar2040
