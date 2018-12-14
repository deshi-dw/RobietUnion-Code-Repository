/*
  Motor.h - Robot library - A specialized library made by Soviet Robotics to help in their goal of world domination.
  Copyright (c) 2018 Soviet Robotics.  All right reserved.
*/

// Define library. 'ifndef' allows us to check the class is not already defined.
#ifndef Motor_h
#define Motor_h

class Motor {
    public:
        Motor();
        Motor(int _pin1, int _pin2, int _pinE);
        void SetSpeed(int speed);
        void Stop();
    private:
        int pin1;
        int pin2;
        int pinE;
};

#endif