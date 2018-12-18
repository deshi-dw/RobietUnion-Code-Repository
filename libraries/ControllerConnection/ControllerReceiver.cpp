/*
  ControllerReceiver.cpp - Robot library - A specialized library made by Soviet Robotics to help in their goal of world domination.
  Copyright (c) 2018 Soviet Robotics.  All right reserved.
*/

// include this library's description file as well as Arduino so we can set port modes.
#include "ControllerReceiver.h"
#include <Arduino.h>

#include <SoftwareSerial.h>

ControllerReceiver::ControllerReceiver(int _pinRx, int _pinTx) {
  // Set SoftwareSerial to RX and TX
  bluetoothSerial = new SoftwareSerial(_pinRx, _pinTx);
  // FIXME: Find correct number.
  bluetoothSerial->begin(34000);
}

void ControllerReceiver::Update() {
  // If there is no serial too read we should break out of Update.
  if(!bluetoothSerial->available) return;

  // Read char if there is one.
  add = (char)bluetoothSerial->read();
  // Add the char to input.
  input += add;

// If the char is not a closing tag then we break out of Update.
  if(add != '>') return;
  // Input should look like this: "<x,y,down>" If it doesn't, this will make sure it does.
  input = input.substring(input.indexOf('<')).substring(input.indexOf('>'));

  // Set the start index. This should be the last comma or, like here at the start, 0.
  startIndex = 0;
  // Set the end of the value to the next comma.
  endIndex = input.indexOf(',');
  // Set the x to what is between 0 and the first comma. Repeat.
  x = input.substring(startIndex, endIndex).toInt();

  startIndex = endIndex;
  endIndex = input.indexOf(',');
  y = input.substring(startIndex, endIndex).toInt();

  startIndex = endIndex;
  // Get the '>' because this should be the last char.
  endIndex = input.indexOf('>');
  down = input.substring(startIndex, endIndex).toInt();

  input = String::String();
}

