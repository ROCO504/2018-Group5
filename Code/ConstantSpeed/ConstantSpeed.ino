/*
   StepperCodeIteration1
   Written by DjTilley for ROCO504
   Used to control a soft robotic gripper
*/

#include <AccelStepper.h>

#define PotPos1 (A0)

AccelStepper NemStp1(AccelStepper::DRIVER, 3, 4);
AccelStepper NemStp2(AccelStepper::DRIVER, 5, 6);
AccelStepper NemStp3(AccelStepper::DRIVER, 7, 8);
AccelStepper NemStp4(AccelStepper::DRIVER, 9, 10);

void setup()
{
  Serial.begin(9600);
  NemStp1.setMaxSpeed(1000);
  NemStp1.setSpeed(200);
  NemStp2.setMaxSpeed(1000);
  NemStp2.setSpeed(200);
  NemStp3.setMaxSpeed(1000);
  NemStp3.setSpeed(200);
  NemStp4.setMaxSpeed(1000);
  NemStp4.setSpeed(200);
}

void loop()
{
  NemStp1.runSpeed();
  NemStp2.runSpeed();
  NemStp3.runSpeed();
  NemStp4.runSpeed();
}
