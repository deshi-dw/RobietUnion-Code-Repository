/*
  Joystick.h - Robot library - A specialized library made by Soviet Robotics to help in their goal of world domination.
  Copyright (c) 2018 Soviet Robotics.  All right reserved.
*/

// Define library. 'ifndef' allows us to check that Joystick_h is not already defined.
#ifndef Joystick_h
#define Joystick_h

class Joystick {
    public:
        Joystick(int _pinX, int _pinY);
        int getX();
        int getY();

    private:
        int pinX;
        int pinY;
};

#endif