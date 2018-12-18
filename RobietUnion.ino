#include <Arduino.h>
#include <HardwareSerial.h>

#include <Robot.h>
#include <RobotState.h>

// Define the ports we are using. Normally it isn't great practice to define values as this is technically a macro.
// Basically, as it compiles, the program will replace every instance of a defined value with the literal value defined.
// In most cases this isn't good but for our purposes it works pretty well.
#define PMR1 13
#define PMR2 12
#define PMRE 11

#define PML1 10
#define PML2 8
#define PMLE 9

// Create our Robot named 'bot'.
Robot bot = Robot();

void setup() {
  Serial.begin(9600);

  // Set up the right and left motors on our bot.
  bot.AttachMotorRight(PMR1, PMR2, PMRE);
  bot.AttachMotorLeft(PML1, PML2, PMLE);

  // Set up bluetooth connection.

  // After this we call 'ready' meaning the bot is in idle.
  bot.Ready();
  bot.state = DEBUG;
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
    case DEBUG:
      debug();
      bot.isDisabled = true;
    case DISABLED:
      Serial.println("Bot is disabled.");
      bot.isDisabled = true;
      Serial.end();
      break;
    default:
      Serial.println("ERROR. Robot is stateless. Shutting down robot...");
      bot.isDisabled = true;
      Serial.end();
      break;
  }

  // Update the robot with all the new data.
  bot.Update();
}

void initIdle() {
  Serial.println("Init Idle");
}

void loopIdle() {
  Serial.println("Init Loop Idle");

  bot.state = INIT_AUTONOMOUS;
}

void initAutonomous() {
  Serial.println("Init Autonomous");

}

void loopAutonomous() {
  Serial.println("Loop Autonomous");
}

void initTeleop() {
  Serial.println("Init Teleop");

}

void loopTeleop() {
  Serial.println("Loop Teleop");
}

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