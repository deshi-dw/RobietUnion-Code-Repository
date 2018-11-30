#include <Arduino.h>

#include <Robot.h>
#include <RobotState.h>

// Define the ports we are using. Normally it isn't great practice to define values as this is technically a macro.
// Basically, as it compiles, the program will replace every instance of a defined value with the literal value defined.
// In most cases this isn't good but for our purposes it works pretty well.
#define PMR1 2
#define PMR2 3

#define PML1 4
#define PML2 5

// Create our Robot named 'bot'.
Robot bot = Robot();

void setup() {
  // Set up the right and left motors on our bot. After this we call ready meaning the bot is in idle.
  bot.initMotorRight(PMR1, PMR2);
  bot.initMotorLeft(PML1, PML2);
  bot.ready();
}

void loop() {

}