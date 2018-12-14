/*
  MathExtra.cpp - Robot library - A specialized library made by Soviet Robotics to help in their goal of world domination.
  Copyright (c) 2018 Soviet Robotics.  All right reserved.
*/

// include this library's description file as well as Arduino so we can set port modes.
#include "MathExtra.h"
#include <Arduino.h>

int MathExtra::Clamp(int value, int min, int max) {
    if(value > max) return max;
    if (value < min) return min;
    return value;
}