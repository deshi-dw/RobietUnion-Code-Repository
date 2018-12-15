/*
  ControllerSender.h - Robot library - A specialized library made by Soviet Robotics to help in their goal of world domination.
  Copyright (c) 2018 Soviet Robotics.  All right reserved.
*/

// Define library. 'ifndef' allows us to check that ControllerSender_h is not already defined.
#ifndef ControllerSender_h
#define ControllerSender_h

#include <SoftwareSerial.h>

class ControllerSender {
    public:
        SoftwareSerial *bluetoothSerial;
        ControllerSender(int _pinRx, int _pinTx);
        void Set(uint8_t x, uint8_t y, uint8_t down);
};

#endif