#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Arduino.h>
#include <Servo.h>
#include <DabbleESP32.h>



static const int motor1Pin = 19;
static const int motor4Pin = 16;

Servo motor1;
Servo motor4;

void setup() {
  Serial.begin(115200);
  Dabble.begin("Active Stabilizer");
  motor1.attach(motor1Pin, Servo::CHANNEL_NOT_ATTACHED, 0, 180, 1000, 2000);
  motor4.attach(motor4Pin, Servo::CHANNEL_NOT_ATTACHED, 0, 180, 1000, 2000);
}

void loop() {

  Dabble.processInput();

  if (GamePad.isUpPressed()) {
    motor1.write(35);
    motor4.write(25);
  } else {
    motor1.write(0);
    motor4.write(0);
  }
}