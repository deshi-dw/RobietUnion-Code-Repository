/*
  Joystick.cpp - Robot library - A specialized library made by Soviet Robotics to help in their goal of world domination.
  Copyright (c) 2018 Soviet Robotics.  All right reserved.
*/

// include this library's description file as well as Arduino so we can set port modes.
#include "Joysitck.h"
#include <Arduino.h>

Joystick::Joystick(int _pinX, int _pinY) {
    pinX = _pinX;
    pinY = _pinY;
}

Joystick::getX() {
    return map(analogRead(pinX), 0, 1023, -255, 255);
}

Joystick::getY() {
    // FIXME: arduino's 'map' function works with longs (int64) which is quite coslty. Consider creating a map that works with int.
    // FIXME: Calling 'analogRead' every update is not great. Consider only getting the x and y every 'x' amount of updates. This of course would come at the cost of precision.
    return map(analogRead(pinY), 0, 1023, -255, 255);
}

