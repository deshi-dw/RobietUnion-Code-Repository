
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
#include <ControllerReceiver.h>

class Robot {
  public:
    Robot();
    void Update();
    void Ready(RobotState newState);

    void Drive(int x, int y);
    void DriveTank(int right, int left);
    void Stop();

    void Pause(unsigned long time);

    void AttachMotorRight(int _pin1, int _pin2, int _pinE);
    void AttachMotorLeft(int _pin1, int _pin2, int _pinE);

    void AttachControllerReciver(int _pinRx, int _pinTx);

    Motor motorRight;
    Motor motorLeft;
    ControllerReceiver controllerReceiver;

    RobotState state;

    float rotationBias = 1.0f;
    float speedBias = 1.0f;

    unsigned long time;

    const unsigned long autonomousTime = 15000;
    const unsigned long teleopTime = 45000;

    bool isDisabled = false;

  private:
    int speedRight = 0;
    int speedLeft = 0;
    bool stopped = false;

    unsigned long timeDifference;

    float newX = 0;
    int newY = 0;
};

#endif
