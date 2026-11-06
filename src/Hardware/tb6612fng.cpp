#pragma once

#include "./Hardware/tb6612fng.hpp"

Ponte_h::Ponte_h(uint8_t pin_pwm, uint8_t pin_in1, uint8_t pin_in2){
    this->pwm = pin_pwm;
    this->in1 = pin_in1;
    this->in2 = pin_in2;
    this->stby = static_cast<uint8_t>(PINS::PONTE_H::TB_STBY);
    
    pinMode(this->pwm, OUTPUT);
    pinMode(this->in1, OUTPUT);
    pinMode(this->in2, OUTPUT);
    pinMode(this->stby, OUTPUT);
    digitalWrite(this->stby, HIGH);

    ledcSetup(this->pwm_channel, 10000, 8);
    ledcAttachPin(this->pwm, this->pwm_channel);
};

void Ponte_h::parar(){
    digitalWrite(this->in1, LOW);
    digitalWrite(this->in2, LOW);

    ledcWrite(this->pwm_channel, 0);
};

void Ponte_h::setPower(int pwm){
    pwm = constrain(pwm, -255, 255);
    if(pwm > 0){
        digitalWrite(this->in1, HIGH);
        digitalWrite(this->in2, LOW);
    }else if(pwm < 0){
        digitalWrite(this->in1, LOW);
        digitalWrite(this->in2, HIGH);
        pwm = abs(pwm);
    }else{ 
        this->parar();
        return;
    }

    ledcWrite(this->pwm_channel, pwm);
};

