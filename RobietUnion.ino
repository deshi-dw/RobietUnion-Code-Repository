#include <Arduino.h>

#include <Robot.h>
#include <RobotState.h>

// Define the ports we are using. Normally it isn't great practice to define values as this is technically a macro.
// Basically, as it compiles, the program will replace every instance of a defined value with the literal value defined.
// In most cases this isn't good but for our purposes it works pretty well.
#define PMR1 13
#define PMR2 12
#define PMRE 11

#define PML1 10
#define PML2 9
#define PMLE 8

// Create our Robot named 'bot'.
Robot bot = Robot();

void setup() {
  // Set up the right and left motors on our bot.
  bot.AttachMotorRight(PMR1, PMR2, PMRE);
  bot.AttachMotorLeft(PML1, PML2, PMLE);

  // After this we call 'ready' meaning the bot is in idle.
  bot.Ready();
}

void loop() {
  // This is a basic state machine. It will run specific code for each state in the switch loop.
  switch(bot.state) {
    case INIT_ROBOT:
      bot.state = INIT_IDLE;
      break;
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
    case DISABLED:
      //TODO: Add shutdown functionality.
      break;
    default:
      //TODO: Add shutdown functionality.
      break;
  }

  // Update the robot with all the new data.
  bot.Update();
}

void initIdle() {

}

void loopIdle() {

  bot.state = INIT_AUTONOMOUS;
}

void initAutonomous() {

}

void loopAutonomous() {

  bot.state = INIT_TELEOP;
}

void initTeleop() {

}

void loopTeleop() {
  bot.Drive(0, 200);
}