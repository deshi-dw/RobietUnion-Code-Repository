# RobietUnion-Code-Repository

This is the repository used by the RobietUnion and their ever lasting attempts at world domination. Built from the ground up, this collection of libraries kind of sucks but they all pretty much work.

## How to use it

The repository comes with a premade .ino file. To add logic to the robot you should only edit the methods. The code above manages the state machine and a lot of other junk that isn't worth messing with. If you want to change the pins, those are defined on the top.

&nbsp;

### Control Overview

The robot class has a few methods for controlling.

#### Drive
```cpp
bot.Drive(int x, int y);
```
This will drive the robot via arcade drive. ```y``` will control drive speed and ```x``` will control rotation speed.

&nbsp;

#### Tank Drive
```cpp
bot.DriveTank(int right, int left);
```
This is for if you want to control the robot like a tank. ```right``` and ```left``` obviously corispond to how fast each side of the robot is.

&nbsp;

#### Stop
```cpp
bot.Stop();
```
This just stops the robot from moving. This is different from writing ```bot.Drive(0, 0)``` or ```bot.DriveTank(0, 0)``` because it instead never sends anything to the motors.

&nbsp;

The robot can be adjusted by various variables defined within the Robot class.

#### Drive Speed
```cpp
bot.speedBais = value;
```
This will adjust how much the ```y``` in ```bot.Drive(int x, int y)``` will be used over the ```x```.

&nbsp;

#### Rotation Speed
```cpp
bot.rotationBias = value;
```
This will adjust how much the ```x``` in ```bot.Drive(int x, int y)``` will be used over the ```y```.

&nbsp;

### State Overview

There are 3 different states the robot can be in.
&nbsp;

#### Idle
```cpp
void Idle();
```
Runs continually before the robot can move. This state acts as time outside of the compitiion.

&nbsp;

#### Autonomous
```cpp
void Autonomous();
```
Runs throughout the autonomous part of the compitition. In this stage, controlling the robot is not allowed.

&nbsp;

#### Teleop
```cpp
void Teleop();
```
Runs after atonomous. The bot is now allowed to be controlled by a human.

&nbsp;

Each state has 2 stages:
&nbsp;

#### Init
```Init```
Runs once at the start of the state.

#### Loop
```Loop```
Runs repeatedly until the state changes.

&nbsp;
