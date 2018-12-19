/*
  ControllerReceiver.h - Robot library - A specialized library made by Soviet Robotics to help in their goal of world domination.
  Copyright (c) 2018 Soviet Robotics.  All right reserved.
*/

// Define library. 'ifndef' allows us to check that ControllerReceiver_h is not already defined.
#ifndef ControllerReceiver_h
#define ControllerReceiver_h

#include <SoftwareSerial.h>
#include <string.h>

class ControllerReceiver {
    public:
        SoftwareSerial bluetoothSerial;
        ControllerReceiver(int _pinRx, int _pinTx);
        void Update();

        int x;
        int y;
        int down;

    private:
        String input;
        char add;
        int startIndex = 0;
        int endIndex = 0;
};

#endif