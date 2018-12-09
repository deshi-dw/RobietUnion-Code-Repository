/*
  Robot.cpp - Robot library - A specialized library made by Soviet Robotics to help in their goal of world domination.
  Copyright (c) 2018 Soviet Robotics.  All right reserved.
*/

// include this library's description file as well as Arduino so we can set port modes.
#include "Robot.h"
#include <Joystick.h>
#include <Arduino.h>

Robot::Robot() {
  // When initializing, the robot will set it's state to 'INIT_ROBOT'.
  // When it is in this state, the robot will not be to move or do anything else.
  state = INIT_ROBOT;
}

void Robot::update() {
  // This switch statement acts as a state machine. Depending on what state the robot is in will determine what it can do.
  switch (state) {
    case INIT_ROBOT:
      break;
    case INIT_IDLE:
      initIdle();
      break;
    case LOOP_IDLE:
      loopIdle();
      break;
    case INIT_AUTONOMOUS:
      initAutonomous();
      break;
    case LOOP_AUTONOMOUS:
      loopAutonomous();
      break;
    case INIT_TELEOP:
      initTeleop();
      break;
    case LOOP_TELEOP:
      loopTeleop();
      break;
    case DISABLED:
      //TODO: Add shutdown functionality.
      break;
    default:
      //TODO: Add shutdown functionality.
      break;
  }
}

void Robot::ready() {
  driveStop();
  state = INIT_IDLE;
}

void Robot::start() {

  state = INIT_AUTONOMOUS;
}

void Robot::stop() {

}

void Robot::initIdle() {

  state = LOOP_IDLE;
}

void Robot::loopIdle() {

}

void Robot::initAutonomous() {

  state = LOOP_AUTONOMOUS;
}

void Robot::loopAutonomous() {

}

void Robot::initTeleop() {

  state = LOOP_TELEOP;
}

void Robot::loopTeleop() {
  
}

void Robot::initJoystick(int _pinX, int _pinY) {
  joystick = new Joystick(_pinX, _pinY);
}

void Robot::initMotorRight(int _pin1, int _pin2, int _pinEn) {
  motorRight1 = _pin1;
  motorRight2 = _pin2;
  motorRightEnabled = _pinEn;

  pinMode(motorRight1, OUTPUT);
  pinMode(motorRight2, OUTPUT);
  pinMode(motorRightEnabled, OUTPUT);
}

void Robot::initMotorLeft(int _pin1, int _pin2, int _pinEn) {
  motorLeft1 = _pin1;
  motorLeft2 = _pin2;
  motorLeftEnabled = _pinEn;

  pinMode(motorLeft1, OUTPUT);
  pinMode(motorLeft2, OUTPUT);
  pinMode(motorLeftEnabled, OUTPUT);
}

void Robot::drive(int x, int y) {

}

void Robot::driveStopped(bool value) {
  digitalWrite(motorRightEnabled, value);
  digitalWrite(motorLeftEnabled, value);
}

void Robot::motorRightStopped(bool value) {
  digitalWrite(motorRightEnabled, value);
}

void Robot::motorLeftStopped(bool value) {
  digitalWrite(motorLeftEnabled, value);
}