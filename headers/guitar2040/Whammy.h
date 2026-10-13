/*
 * SPDX-License-Identifier: MIT
 * Optional whammy input for Guitar2040-CE.
 * Exposes a calibrated 0..65535 analog value.
 */
#pragma once
#include "BoardConfig.h"
#include "hardware/adc.h"
#include <cstdint>

namespace guitar2040 {
class Whammy {
public:
    void setup() {
#if GUITAR2040_WHAMMY_ENABLED
        adc_gpio_init(GUITAR2040_WHAMMY_PIN);
#endif
    }
    uint16_t read() const {
#if GUITAR2040_WHAMMY_ENABLED
        adc_select_input(GUITAR2040_WHAMMY_PIN - 26);
        const uint32_t sample = adc_read();
        const uint32_t minVal = GUITAR2040_WHAMMY_ADC_MIN;
        const uint32_t maxVal = GUITAR2040_WHAMMY_ADC_MAX;
        if (maxVal <= minVal || maxVal > 4095) return 32768;
        uint32_t bounded = sample < minVal ? minVal : (sample > maxVal ? maxVal : sample);
        uint32_t scaled = ((bounded - minVal) * 65535u) / (maxVal - minVal);
#if GUITAR2040_WHAMMY_INVERT
        scaled = 65535u - scaled;
#endif
        return static_cast<uint16_t>(scaled);
#else
        return 32768;
#endif
    }
};
}
