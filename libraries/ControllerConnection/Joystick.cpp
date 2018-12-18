/*
  Joystick.cpp - Robot library - A specialized library made by Soviet Robotics to help in their goal of world domination.
  Copyright (c) 2018 Soviet Robotics.  All right reserved.
*/

// include this library's description file as well as Arduino so we can set port modes.
#include "Joystick.h"
#include <Arduino.h>

Joystick::Joystick(int _apinX, int _apinY) {
  apinX = _apinX;
  apinY = _apinY;
}

void Joystick::Update() {
  x = map(analogRead(apinX), -1024, 1024, -255, 255);
  y = map(analogRead(apinY), -1024, 1024, -255, 255);
}