#pragma once

#include <Arduino.h>
#include <cstdint>

namespace PINS{
    enum class PONTE_H : std::uint8_t {
        TB_PWMA = 16,
        TB_AIN2 = 15,
        TB_AIN1 = 9,
        TB_STBY = 13,
        TB_BIN1 = 3,
        TB_BIN2 = 11,
        TB_PWMB = 10
    };
}