/*
  ControllerSender.h - Robot library - A specialized library made by Soviet Robotics to help in their goal of world domination.
  Copyright (c) 2018 Soviet Robotics.  All right reserved.
*/

// Define library. 'ifndef' allows us to check that ControllerSender_h is not already defined.
#ifndef ControllerSender_h
#define ControllerSender_h

class ControllerSender {
    public:
        ControllerSender(int _pinRx, int _pinTx);
        int setX();
        int setY();

    private:
        int pinRx;
        int pinTx;
};

#endif