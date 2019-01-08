/*
 * StepperCodeIteration1
 * Written by DjTilley for ROCO504
 * Used to control a soft robotic gripper 
 */

#include <AccelStepper.h>

#define PotPos1 (A0)
#define MOTOR_SCALING 2

int Pval1 = 0;
int previous1 = 0;
int long Pnewval1 = 0;   

AccelStepper NemStp1(AccelStepper::DRIVER, 3, 4);

void setup() {
  Serial.begin(9600);
  NemStp1.setMaxSpeed(4800);
  NemStp1.setAcceleration(4800);
  pinMode(PotPos1, INPUT);
}

void loop() {
  Pval1 = analogRead(PotPos1);  
  if ((Pval1 > previous1+6) || (Pval1 < previous1-6)) { 
    Pnewval1 = map(Pval1, 0, 1023, 0, ( 200* MOTOR_SCALING)); 
    NemStp1.runToNewPosition(-Pnewval1); 
    previous1 = Pval1;
  }
}
