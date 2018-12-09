/*
  ControllerSender.cpp - Robot library - A specialized library made by Soviet Robotics to help in their goal of world domination.
  Copyright (c) 2018 Soviet Robotics.  All right reserved.
*/

// include this library's description file as well as Arduino so we can set port modes.
#include "ControllerSender.h"
#include <Arduino.h>
#include <SoftwareSerial.h>
#include <inttypes.h>;

ControllerSender::ControllerSender(int _pinRx, int _pinTx) {
  bluetoothSerial = new SoftwareSerial(_pinRx, _pinTx); // Set SoftwareSerial to RX and TX
  bluetoothSerial->begin(34000); // FIXME: Find correct number.
}

void ControllerSender::Set(uint8_t x, uint8_t y, uint8_t down) {
  bluetoothSerial->write('<');
  bluetoothSerial->write(x);
  bluetoothSerial->write(',');
  bluetoothSerial->write(y);
  bluetoothSerial->write(',');
  bluetoothSerial->write(down);
  bluetoothSerial->write('>');
}

