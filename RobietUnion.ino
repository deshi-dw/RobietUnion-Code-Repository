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
  bot.initMotorRight(PMR1, PMR2, PMRE);
  bot.initMotorLeft(PML1, PML2, PMLE);

  // After this we call 'ready' meaning the bot is in idle.
  bot.ready();
}

void loop() {
  bot.update();

  switch(bot.state) {
    case INIT_ROBOT:
      bot.start = INIT_IDLE;
      break;
    case INIT_IDLE:
      initIdle();
      bot.start = LOOP_IDLE;
      break;
    case LOOP_IDLE:
      loopIdle();
      break;
    case INIT_AUTONOMOUS:
      initAutonomous();
      bot.start = LOOP_AUTONOMOUS;
      break;
    case LOOP_AUTONOMOUS:
      loopAutonomous();
      break;
    case INIT_TELEOP:
      initTeleop();
      bot.start = LOOP_TELEOP;
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

void initIdle() {

}

void loopIdle() {

}

void initAutonomous() {

}

void loopAutonomous() {

}

void initTeleop() {

}

void loopTeleop() {

}