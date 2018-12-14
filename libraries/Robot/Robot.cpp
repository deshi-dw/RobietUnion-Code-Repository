/*
  Robot.cpp - Robot library - A specialized library made by Soviet Robotics to help in their goal of world domination.
  Copyright (c) 2018 Soviet Robotics.  All right reserved.
*/

// include this library's description file as well as Arduino so we can set port modes.
#include "Robot.h"
#include <Arduino.h>

#include <Motor.h>
#include <MathExtra.h>

Robot::Robot() {

  // When initializing, the robot will set it's state to 'INIT_ROBOT'.
  // When it is in this state, the robot will not be to move or do anything else.
  state = INIT_ROBOT;
}

void Robot::Ready() {
  state = INIT_IDLE;
}

void Robot::Update() {

}

void Robot::Drive(int x, int y) {
  int newX = (int)(x * rotationBias);
  int newY = (int)(x * speedBias);
  DriveTank(MathExtra::Clamp(newY + newX, 255, -255), MathExtra::Clamp(newY - newX, -255, 255));
}

void Robot::DriveTank(int right, int left) {
motorRight.SetSpeed(right);
motorLeft.SetSpeed(left);
}

void Robot::AttachMotorRight(int _pin1, int _pin2, int _pinE) {
  motorRight = Motor(_pin1, _pin2, _pinE);
}

void Robot::AttachMotorLeft(int _pin1, int _pin2, int _pinE) {
  motorLeft = Motor(_pin1, _pin2, _pinE);
}