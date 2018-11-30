/*
  Robot.h - Robot library - A specialized libriary made by Soviet Robotics to help in their goal of world domination.
  Copyright (c) 2018 Soviet Robotics.  All right reserved.
*/

// ensure this library description is only included once
#ifndef Robot_h
#define Robot_h

#define INIT_ROBOT 0

#define INIT_IDLE 1
#define lOOP_IDLE 2
#define INIT_ATONOMOUS 3
#define LOOP_ATONOMOUS 4
#define INIT_TELEOP 6
#define LOOP_TELEOP 7

#include <inttypes.h>

class Robot {
  public:
    Robot();
    void update();
    void initMotorRight(int _pin1, int _pin2);
    void initMotorLeft(int _pin1, int _pin2);

    void drive(int x, int y);
    void stop();

    uint8_t state;

  private:
    int motorRight1;
    int motorRight2;
    int motorLeft1;
    int motorLeft2;
};

#endif
