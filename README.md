# RobietUnion-Code-Repository

## Files
```
RobietUnion.ino - The main robot file. Edit this to edit robot logic.

Joystick.cpp/h - Should be self explanitory. This is a joystick library to tidy up unessasery code. This might get replaced.
		
RobotState.cpp/h - This is just an enum for state checking the robot. Used for state in Robot.cpp/h.
		
Robot.cpp/h - This is the main logic class for the robot. This library does state handeling, driving, and holding data. This class could have probably been split up but whatever.
```

## Usage
The robot loops, state handling, motors, ect. should all be contained in the **robot.cpp/h** file. Any additions like range finders would be added to that class/header.

The Logic of the robot like atuonomous, driving, etc. should all be kept in the **RobietUnion.ino** file.
