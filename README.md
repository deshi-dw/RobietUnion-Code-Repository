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
This just stops the robot from moving.

&nbsp;

The robot can be adjusted by various variables defined within the Robot class.
