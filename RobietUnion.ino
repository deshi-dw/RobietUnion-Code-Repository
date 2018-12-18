// Including Arduino.h is done here as to not break everything.
// This is done everywhere so I will only comment on this one.
#include <Arduino.h>

// Include Robot.h and RobotState.h to use the Robot class.
// The Robot class is the class the runs pretty much everything
// but the state machine. Ideally that would be in the Robot
// Class too but I couldn't find a way to make it work without
// Inheritance and that doesn't work with .ino.
#include <Robot.h>
#include <RobotState.h>

// Define the ports we are using. Normally it isn't great practice
// to define values as this is technically a macro. Basically, as
// it compiles, the program will replace every instance of a defined
// value with the literal value defined. In most cases this isn't
// good but for our purposes it works pretty well.

// Ports are defined as such: PORT : CONTROL : NAME.
// ex. PMR1 is P = PORT, M = MOTOR (CONTROL), R1 = Right1 (NAME)

// Define right motor ports
#define PMR1 13
#define PMR2 12
#define PMRE 11

// Define left motor ports
#define PML1 10
#define PML2 8
#define PMLE 9

// Create our Robot named 'bot'.
Robot bot = Robot();

void setup() {
  // Begin Serial so we can print debug info.
  Serial.begin(9600);

  // Set up the right and left motors on our bot.
  bot.AttachMotorRight(PMR1, PMR2, PMRE);
  bot.AttachMotorLeft(PML1, PML2, PMLE);

  // TODO: Set up bluetooth connection.

  // Ready the state we want to start in. This would ideally be
  // either an INIT state or a finite-runtime state. (ex. DEBUG or DISABLED)
  bot.Ready(DEBUG);
}

void loop() {
  // This is a basic state machine. It will run specific code for
  // each state in the switch loop. Ideally this would be in Robot
  // and just call the methods in this class which could be done
  // with inheritance. Inheritance doesn't work however as that
  // Would require the main sketch (RobietUnion.ino) to inherit
  // from the Robot class which isn't possible.

  /* STATE LABEL LEGEND
  *  INIT - Initialize everything needed for state.
  *  LOOP - Loop over logic for state that needs to be repeatded.
  */
  /* STATE NAME LEGEND
  * IDLE - For out of compitition driving.
  * AUTONOMOUS - For running autonomous code. No user inputs should go here.
  * TELEOP - For human input.
  */
  /* SPECIAL STATE LEGEND
  * INIT_ROBOT - Defualt state of the robot and should in theory should never run.
  * DISABLED - The bot doesn't do anything. Pretty self explanitory.
  * DEBUG - Runs once and then disables. Put debug code here.
  */

  switch(bot.state) {
    case INIT_IDLE:
      initIdle();
      bot.state = LOOP_IDLE;
      break;
    case LOOP_IDLE:
      loopIdle();
      break;
    case INIT_AUTONOMOUS:
      initAutonomous();
      bot.state = LOOP_AUTONOMOUS;
      break;
    case LOOP_AUTONOMOUS:
      loopAutonomous();
      break;
    case INIT_TELEOP:
      initTeleop();
      bot.state = LOOP_TELEOP;
      break;
    case LOOP_TELEOP:
      loopTeleop();
      break;
    case DEBUG:
      debug();
      bot.isDisabled = true;
    // State DISABLED runs once befor disabling the robot.
    case DISABLED:
      Serial.println("Bot is disabled.");
      bot.isDisabled = true;
      Serial.end();
      break;
    case INIT_ROBOT:
      bot.state = INIT_IDLE;
      break;
    // If the robot is stateless we disable the robot.
    default:
      Serial.println("ERROR. Robot is stateless. Shutting down robot...");
      bot.isDisabled = true;
      Serial.end();
      break;
  }

  // Update the robot with all the new data.
  bot.Update();
}

// Run on robot idle initiation state.
void initIdle() {
  Serial.println("Init Idle");
}

// Run on robot idle loop state.
void loopIdle() {
  Serial.println("Init Loop Idle");

  bot.state = INIT_AUTONOMOUS;
}

// Run on robot autonomous initiation state.
void initAutonomous() {
  Serial.println("Init Autonomous");

}

// Run on robot autonomous loop state.
void loopAutonomous() {
  Serial.println("Loop Autonomous");
}

// Run on robot teleop initiation state.
void initTeleop() {
  Serial.println("Init Teleop");

}

// Run on robot teleop loop state.
void loopTeleop() {
  Serial.println("Loop Teleop");
}

// Run on robot debug state.
void debug() {
  // Right Forwards //
  Serial.println("Right forward");
  bot.DriveTank(255, 0);
  bot.Pause(1000);
  bot.DriveTank(0, 0);
  bot.Pause(500);

  Serial.println("Left forward");
  // Left Forwards //
  bot.DriveTank(0, 255);
  bot.Pause(1000);
  bot.DriveTank(0, 0);
  bot.Pause(500);

  Serial.println("Right Backwards");
  // Right Backwards //
  bot.DriveTank(-255, 0);
  bot.Pause(1000);
  bot.DriveTank(0, 0);
  bot.Pause(500);

  Serial.println("Right Backwards");
  // Left Backwards //
  bot.DriveTank(0, -255);
  bot.Pause(1000);
  bot.DriveTank(0, 0);
  bot.Pause(500);

  Serial.println("Both forward");
  // Both Forwards //
  bot.DriveTank(255, 255);
  bot.Pause(1000);
  bot.DriveTank(0, 0);
  bot.Pause(500);

  Serial.println("Both Backwards");
  // Both Backwards //
  bot.DriveTank(-255, -255);
  bot.Pause(1000);
  bot.DriveTank(0, 0);
  bot.Pause(500);

  Serial.println("");
  Serial.println("Debug ended. Disabling robot...");
}