#pragma once

#include "../Configs/configs.hpp"
class Ponte_h{
    private:
        uint8_t pwm, in1, in2, stby, pwm_channel = 0;
    public:
        Ponte_h(uint8_t pin_pwm, uint8_t pin_in1, uint8_t pin_in2);
        void setPower(int pwm);
        void parar();
    };