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

    Controller1.ButtonL1.pressed(leftArm);
    Controller1.ButtonR1.pressed(rightArm);
    Controller1.ButtonL2.pressed(setDriveTrainSpeedMax);
    Controller1.ButtonL2.released(setDriveTrainSpeedNormal);

    driveTrain.controllerDriving();
  }
}