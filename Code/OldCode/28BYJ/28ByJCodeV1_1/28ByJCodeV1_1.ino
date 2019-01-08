#include <AccelStepper.h>
#define HALFSTEP 8

// motor pins
#define motorPin1  4  //In1   
#define motorPin2  5     
#define motorPin3  6     
#define motorPin4  7  //In4

#define motorPin5  10 //In1
#define motorPin6  11 
#define motorPin7  12    
#define motorPin8  13 //In4  

#define MaxSpeed 2000

AccelStepper stepper1(HALFSTEP, motorPin1, motorPin3, motorPin2, motorPin4);
AccelStepper stepper2(HALFSTEP, motorPin5, motorPin7, motorPin6, motorPin8);

// variables
int turnSteps = 2100; 
int lineSteps = -6600; 
int stepperSpeed = 1000; 
int stepCount1 = 0; // Stepper Counter Motor 1
int stepCount2 = 0; // StepCount motor 2

boolean M1pinOn = false; //Button Toggle

boolean turn1 = false; //keep track if we are turning or going straight next
boolean turn2 = false; //keep track if we are turning or going straight next

void setup() {
  delay(3000);
  Serial.begin(9600);
  pinMode(8,INPUT);
  stepper1.setMaxSpeed(MaxSpeed);
  stepper1.move(1);  // I found this necessary
  stepper1.setSpeed(stepperSpeed);

  stepper2.setMaxSpeed(MaxSpeed);
  stepper2.move(-1);  // I found this necessary
  stepper2.setSpeed(stepperSpeed);

}
void loop() {

if (digitalRead(8) == HIGH)
  {
    M1pinOn = !M1pinOn;
    if (M1pinOn == true)
    {
    Serial.println("M1 true");
    }
    else if (M1pinOn == false)
    {
    Serial.println("M1 false");  
    }
    delay(100);
  }

//Code Cut1
}

  //Code Cut1
//    if (M1pinOn == false){
//     if (stepCount1 == 0) {
//       int target = 0;
//          if (turn1 == true) {
//          target = turnSteps;
//    }
//
//    stepper1.move(target);
//    stepper1.setSpeed(stepperSpeed);
//    turn1 = !turn1;
//  }
//    }
//  stepCount1 = stepper1.distanceToGo();
//
//  stepper1.runSpeedToPosition();
