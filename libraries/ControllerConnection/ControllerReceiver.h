/*
  ControllerReceiver.h - Robot library - A specialized library made by Soviet Robotics to help in their goal of world domination.
  Copyright (c) 2018 Soviet Robotics.  All right reserved.
*/

// Define library. 'ifndef' allows us to check that ControllerReceiver_h is not already defined.
#ifndef ControllerReceiver_h
#define ControllerReceiver_h

class ControllerReceiver {
    public:
        ControllerReceiver(int _pinRx, int _pinTx);
        int getX();
        int getY();

    private:
        int pinRx;
        int pinTx;
};

#endif