/*
  Robot.cpp - Robot library - A specialized library made by Soviet Robotics to help in their goal of world domination.
  Copyright (c) 2018 Soviet Robotics.  All right reserved.
*/

// include this library's description file as well as Arduino so we can set port modes.
#include "Robot.h"
#include <Arduino.h>

#include <Motor.h>

Robot::Robot() {
  // When initializing, the robot will set it's state to 'INIT_ROBOT'.
  // When it is in this state, the robot will not be to move or do anything else.
  state = INIT_ROBOT;
}

void Robot::Ready() {
  state = INIT_IDLE;
  DriveTank(0, 0);
  timeDifference = time;
}

void Robot::Update() {
  if(isDisabled) return;

  time = millis() - timeDifference;

  // TODO: Get bluetooth input via ControllerReciever.

  if(!stopped) {
    motorRight.SetSpeed(speedRight);
    motorLeft.SetSpeed(speedLeft);
  }

  if(state == INIT_AUTONOMOUS || state == INIT_TELEOP) timeDifference = time;

  if(state == LOOP_AUTONOMOUS && time > autonomousTime) state = INIT_TELEOP;
  if(state == LOOP_TELEOP && time > teleopTime) state = DISABLED;
  // if(state == LOOP_TELEOP && time > teleopTime) state = INIT_ROBOT;
}

void Robot::Drive(int x, int y) {
  if(stopped) stopped = false;

  int newX = (int)(x * rotationBias);
  int newY = (int)(x * speedBias);
  DriveTank(newY + newX, newY - newX);
}

void Robot::DriveTank(int right, int left) {
  if(stopped) stopped = false;

  speedRight = right;
  speedLeft = left;
}

void Robot::Pause(unsigned long pause) {
  unsigned long pauseTime = time + pause;
  while(pauseTime > time) {
    Update();
  }
}

void Robot::AttachMotorRight(int _pin1, int _pin2, int _pinE) {
  motorRight = Motor(_pin1, _pin2, _pinE);
}

void Robot::AttachMotorLeft(int _pin1, int _pin2, int _pinE) {
  motorLeft = Motor(_pin1, _pin2, _pinE);
}