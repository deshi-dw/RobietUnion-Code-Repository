/*
  Robot.h - Robot library - A specialized library made by Soviet Robotics to help in their goal of world domination.
  Copyright (c) 2018 Soviet Robotics.  All right reserved.
*/

// Define library. 'ifndef' allows us to check that Robot_h is not already defined.
#ifndef Robot_h
#define Robot_h

// Include type 'RobotState'. This is an enum that holds the robots current state.
#include "RobotState.h"

class Robot {
  public:
    Robot();
    
     /**
     * \brief Update the robots state and executes tasked based on state.
     **/
    void update();

     /**
     * Ready the robot for idle. If the robot is already passed idle we don't need to call ready.
     **/
    void ready();

     /**
     * Starts the robot into the autonomous phase. This would be the start of the competition.
     **/
    void start();

     /**
     * Stops the robot. Note that this marks the end of the competition and is not meant for stopping the robot from moving.
     **/
    void stop();

     /**
     * Initialize the right motor by giving it two pins. (in1 and in2)
     **/
    void initMotorRight(int _pin1, int _pin2);

     /**
     * Initialize the left motor by giving it two pins. (in1 and in2)
     **/
    void initMotorLeft(int _pin1, int _pin2);

     /**
     * Drive the robot via arcade controls. (x = rotation, y = speed)
     **/
    void drive(int x, int y);

     /**
     * Stop the robot from moving. This method is safe to call if you want to stop the robot from moving.
     **/
    void driveStopped(bool value); // TODO: Consider making this method a one call thing. Or in other words: Call once and then not have to enable it again next update.

    /**
     * Stops or starts the right motor from moving. 0 is off, 1 is on.
     **/
    void motorRightStopped(bool value);

    /**
     * Stops or starts the left motor from moving. 0 is off, 1 is on.
     **/
    void motorRightStopped(bool value);

     /**
     * The state of the robot. There are not going to be many time you want to change this dynamically so it might become private later on.
     **/
    RobotState state = DISABLED;

  private:

     /**
     * When the robot is ready, this method will be call once.
     **/
    void initIdle();

     /**
     * When the robot is ready, this method will call every update after 'initIdle'.
     **/
    void loopIdle();

     /**
     * When the robot has started, this method will be called once.
     **/
    void initAutonomous();

     /**
     * When the robot has started, this method will call every update after 'initAutonomous'.
     **/
    void loopAutonomous();

     /**
     * When the robot has finished autonomous, this method will be called once.
     **/
    void initTeleop();

     /**
     * When the robot has finished autonomous, this method will call every update after 'initTeleop'.
     **/
    void loopTeleop();

    int motorRight1;
    int motorRight2;
    int motorRightEnabled;
    int motorLeft1;
    int motorLeft2;
    int motorLeftEnabled;
};

#endif
