/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       {Sem Van Broekhoven}                                      */
/*    Created:      {20/12/2023}                                              */
/*    Description:  Code for the 3rd Graad Team                               */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// Include the V5 Library
#include "drivetrain.cpp"
#include "pneumatic.cpp"
#include "vex.h"
#include "vex_controller.h"

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller
// Catapult             motor_group   7, 8
// LeftArm              digital_out   A
// LeftMainDriveTrain   motor_group   1, 3
// RightMainDriveTrain  motor_group   4, 6
// RightArm             digital_out   B
// LeftSupportDrive     motor         2
// RightSupportDrive    motor         5
// ---- END VEXCODE CONFIGURED DEVICES ----

// Allows for easier use of the VEX Library
using namespace vex;

bool fullThrottle = false;
bool leftArmExtended = false;
bool rightArmExtended = false;
bool leftArmPressed = false;
bool rightArmPressed = false;

void setDriveTrainSpeedMax()
{
  fullThrottle = true;
}

void setDriveTrainSpeedNormal()
{
  fullThrottle = false;
}

void leftArm()
{
  leftArmExtended = !leftArmExtended;
}

void rightArm()
{
  rightArmExtended = !rightArmExtended;
}

void doNothing()
{}

int main()
{
  DriveTrain driveTrain = DriveTrain(&fullThrottle);
  Pneumatic pneumaticSystem = Pneumatic(&leftArmExtended, &rightArmExtended);

  LeftArm.set(false);

  // Brain.Screen.print("Hello World!");
  while (true)
  {
    if (Controller1.ButtonR2.pressing())
      Catapult.spin(forward);
    else
      Catapult.stop();

    pneumaticSystem.controller();

    if (Controller1.ButtonL1.pressing())
    {
      if (!leftArmPressed)
      {
        leftArmPressed = true;
        leftArm();
      }
    }
    else
    {
      leftArmPressed = false;
    }
    
    if (Controller1.ButtonR1.pressing())
    {
      if (!rightArmPressed)
      {
        rightArmPressed = true;
        rightArm();
      }
    }
    else
    {
      rightArmPressed = false;
    }
    Controller1.ButtonL2.pressed(setDriveTrainSpeedMax);
    Controller1.ButtonL2.released(setDriveTrainSpeedNormal);

    driveTrain.controllerDriving();
  }
}