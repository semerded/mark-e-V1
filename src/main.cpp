/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       {Sem Van Broekhoven}                                      */
/*    Created:      {20/12/2023}                                              */
/*    Description:  Code for the 3rd Graad Team                               */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// Include the V5 Library
#include "screenInfo.cpp"
#include "vex.h"
#include "vex_brain.h"
#include "vex_competition.h"
#include "vex_controller.h"
#include "vex_global.h"
#include "autoCode.cpp"
#include "vex_task.h"
#include "vex_thread.h"
#include "buttonReader.cpp"
#include "vex_units.h"


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
bool topSpeed = true;
bool topSpeedPressed;
bool leftArmExtended = false;
bool rightArmExtended = false;
bool leftArmPressed = false;
bool rightArmPressed = false;

DriveTrain driveTrain = DriveTrain(&fullThrottle, &topSpeed);
Pneumatic pneumaticSystem = Pneumatic(&leftArmExtended, &rightArmExtended);
competition Competition;
Autonomous autonomous = Autonomous();

// ScreenInfo screenInfo = ScreenInfo(0);




void setDriveTrainSpeedMax()
{
  fullThrottle = true;
}

void setDriveTrainSpeedNormal()
{
  fullThrottle = false;
}

void setTopSpeed()
{
  topSpeed = !topSpeed;
}

void leftArm()
{
  leftArmExtended = !leftArmExtended;
}

void rightArm()
{
  rightArmExtended = !rightArmExtended;
}

// ButtonReader test = ButtonReader(Controller1.ButtonA.pressing)
int driveControl()
{
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

    // if (Controller1.ButtonY.pressing())
    // {
    //   if (!topSpeedPressed)
    //   {
    //     topsp
    //   }
    // }
    Controller1.ButtonL2.pressed(setDriveTrainSpeedMax);
    Controller1.ButtonL2.released(setDriveTrainSpeedNormal);

    driveTrain.controllerDriving();

    // screenInfo.clear();
    // screenInfo.print();
  }
  return 0;
}

void drivercontrolTask()
{
  task driverCode(driveControl);
  while (Competition.isDriverControl() && Competition.isEnabled())
  {
    this_thread::sleep_for(10);
  }
  driverCode.stop();
}

int startAutonomous()
{
  autonomous.startAutonomous();
  return 0;
}

void startAutonomousTask()
{
  task autoCode(startAutonomous);
  while(Competition.isAutonomous() && Competition.isEnabled())
  {
    this_thread::sleep_for(10);
  }
  autoCode.stop();
  return;
}

int main()
{
  LeftArm.set(false);
  RightArm.set(false);

  Brain.Screen.setFont(vex::fontType::mono60);
  Brain.Screen.print("Hello World!");
  competition::bStopAllTasksBetweenModes = false;
  Competition.autonomous(startAutonomousTask);
  Competition.drivercontrol(drivercontrolTask);
}