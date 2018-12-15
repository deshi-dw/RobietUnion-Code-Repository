/*
  // Robot.h - Robot library - A specialized library made by Soviet Robotics to help in their goal of world domination.
  Copyright (c) 2018 Soviet Robotics.  All right reserved.
*/

// Define library. 'ifndef' allows us to check that Robot_h is not already defined.
#ifndef Robot_h
#define Robot_h

// Include type 'RobotState'. This is an enum that holds the robots current state.
#include "RobotState.h"
#include <Motor.h>

class Robot {
  public:
    Robot();
    void Update();
    void Ready();

    void Drive(int x, int y);
    void DriveTank(int right, int left);
    void Stop();

    void AttachMotorRight(int _pin1, int _pin2, int _pinE);
    void AttachMotorLeft(int _pin1, int _pin2, int _pinE);

    Motor motorRight;
    Motor motorLeft;
    RobotState state;

    float rotationBias = 1.0f;
    float speedBias = 1.0f;

    unsigned long time;

    unsigned long autonomousTime;
    unsigned long teleopTime;

  private:
    int speedRight = 0;
    int speedLeft = 0;
    bool stopped = false;
    
    unsigned long timeDifference;
};

#endif
