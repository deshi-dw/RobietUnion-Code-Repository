/*
  Motor.cpp - Robot library - A specialized library made by Soviet Robotics to help in their goal of world domination.
  Copyright (c) 2018 Soviet Robotics.  All right reserved.
*/

// include this library's description file as well as Arduino so we can set port modes.
#include "Motor.h"
#include <Arduino.h>
#include <MathExtra.h>

Motor::Motor() { }

Motor::Motor(int _pin1, int _pin2, int _pinE) {
  pinMode(_pin1, OUTPUT);
  pinMode(_pin2, OUTPUT);
  pinMode(_pinE, OUTPUT);
  pin1 = _pin1;
  pin2 = _pin2;
  pinE = _pinE;
}

void Motor::SetSpeed(int speed) {
   // TODO: If motors are spinning the wrong way, switch the 1 and 0.
  if(speed > 0) {
    digitalWrite(pin1, 1);
    digitalWrite(pin2, 0);

    analogWrite(pinE, speed);
  }
  else {
    digitalWrite(pin1, 0);
    digitalWrite(pin2, 1);

    analogWrite(pinE, speed*-1);
  }
}