#include <Arduino.h>
#include <ControllerSender.h>
#include <Joystick.h>

// Define controller sender ports.
#define PBRX 9
#define PBTX 8

// Define joystick analog ports.
#define PX 5
#define PY 4
#define PD 7

ControllerSender controllerSender(PBRX, PBTX);
Joystick joystick(PBRX, PBTX);

int x = 0;
int y = 0;

void setup() {
  // Begin Serial so we can print debug info.
  Serial.begin(9600);

}

void loop() {
  joystick.Update();
  controllerSender.Set(joystick.x, joystick.y, 0);
}