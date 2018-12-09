/*
  ControllerReceiver.cpp - Robot library - A specialized library made by Soviet Robotics to help in their goal of world domination.
  Copyright (c) 2018 Soviet Robotics.  All right reserved.
*/

// include this library's description file as well as Arduino so we can set port modes.
#include "ControllerReceiver.h"
#include <Arduino.h>

#include <SoftwareSerial.h>

ControllerReceiver::ControllerReceiver(int _pinRx, int _pinTx) {
  bluetoothSerial = new SoftwareSerial(_pinRx, _pinTx); // Set SoftwareSerial to RX and TX
  bluetoothSerial->begin(34000); // FIXME: Find correct number.
}

void ControllerReceiver::Update() {
  if(!bluetoothSerial->available) return; // If there is no serial too read we should break out of Update.

  char add = (char)bluetoothSerial->read(); // Read char if there is one.
  input += add; // Add the char to input.

  if(add != '>') return; // If the char is not a closing tag then we break out of Update.

  input = input.substring(input.indexOf('<')).substring(input.indexOf('>')); // Input should look like this: "<x,y,down>" If it doesn't, this will make sure it does.

  int startIndex = 0; // Set the start index. This should be the last comma or, like here at the start, 0.
  int endIndex = input.indexOf(','); // Set the end of the value to the next comma.
  x = input.substring(startIndex, endIndex).toInt(); // Set the x to what is between 0 and the first comma. Repeat.

  startIndex = endIndex;
  endIndex = input.indexOf(',');
  y = input.substring(startIndex, endIndex).toInt();

  startIndex = endIndex;
  endIndex = input.indexOf('>'); // Get the '>' because this should be the last char.
  down = input.substring(startIndex, endIndex).toInt();

  input = String::String();
}

