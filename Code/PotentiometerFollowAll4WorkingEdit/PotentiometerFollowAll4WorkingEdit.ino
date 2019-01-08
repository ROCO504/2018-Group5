/*
   StepperCodeIteration1
   Written by DjTilley for ROCO504
   Used to control a soft robotic gripper
*/

#include <AccelStepper.h>

#define PotPos1 (A0)
#define PotPos2 (A1)
#define PotPos3 (A2)
#define PotPos4 (A3)

#define MOTOR_SCALING 2                                                                       8

AccelStepper NemStp1(AccelStepper::DRIVER, 3, 4);
AccelStepper NemStp2(AccelStepper::DRIVER, 5, 6);
AccelStepper NemStp3(AccelStepper::DRIVER, 7, 8);
AccelStepper NemStp4(AccelStepper::DRIVER, 9, 10);

int Pval1 = 0;
int previous1 = 0;
int long Pnewval1 = 0;

int Pval2 = 0;
int previous2 = 0;
int long Pnewval2 = 0;

int Pval3 = 0;
int previous3 = 0;
int long Pnewval3 = 0;

int Pval4 = 0;
int previous4 = 0;
int long Pnewval4 = 0;

void setup()
{
  Serial.begin(9600);
  NemStp1.setMaxSpeed(3500);
  NemStp1.setAcceleration(3500);
  NemStp2.setMaxSpeed(3500);
  NemStp2.setAcceleration(3500);
  NemStp3.setMaxSpeed(3500);
  NemStp3.setAcceleration(3500);
  NemStp4.setMaxSpeed(3500);
  NemStp4.setAcceleration(3500);
  pinMode(PotPos1, INPUT);
  pinMode(PotPos2, INPUT);
  pinMode(PotPos3, INPUT);
  pinMode(PotPos4, INPUT);
}

void loop()
{
  Pval1 = analogRead(PotPos1);
  if ((Pval1 > previous1 + 6) || (Pval1 < previous1 - 6)) {
    Pnewval1 = map(Pval1, 0, 1023, 0, ( 200 * MOTOR_SCALING));
    NemStp1.runToNewPosition(-Pnewval1);
    previous1 = Pval1;
  }

  Pval2 = analogRead(PotPos2);
  if ((Pval2 > previous2 + 6) || (Pval2 < previous2 - 6)) {
    Pnewval2 = map(Pval2, 0, 1023, 0, ( 200 * MOTOR_SCALING));
    NemStp2.runToNewPosition(-Pnewval2);
    previous2 = Pval2;
  }

  Pval3 = analogRead(PotPos3);
  if ((Pval3 > previous3 + 6) || (Pval3 < previous3 - 6)) {
    Pnewval3 = map(Pval3, 0, 1023, 0, ( 200 * MOTOR_SCALING));
    NemStp3.runToNewPosition(-Pnewval3);
    previous3 = Pval3;
  }

  Pval4 = analogRead(PotPos4);
  if ((Pval4 > previous4 + 6) || (Pval4 < previous4 - 6)) {
    Pnewval4 = map(Pval4, 0, 1023, 0, ( 200 * MOTOR_SCALING));
    NemStp4.runToNewPosition(-Pnewval4);
    previous4 = Pval4;
  }

}
