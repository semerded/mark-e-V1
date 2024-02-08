/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       {Sem Van Broekhoven}                                      */
/*    Created:      {20/12/2023}                                              */
/*    Description:  Code for the 3rd Graad Team                               */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// Include the V5 Library
#include "../include/vex.h"
#include "autoCode.cpp"
#include "buttonReader.cpp"
#include "vex_brain.h"
#include "vex_competition.h"
#include "vex_controller.h"
#include "vex_global.h"
#include "vex_task.h"
#include "vex_thread.h"
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
bool supportDriveActive = true;
bool leftArmExtended = false;
bool rightArmExtended = false;
bool changeAllArm = false;

bool buttonAstatus = false;
bool buttonL1status = false;
bool buttonR1status = false;
bool buttonYstatus = false;

DriveTrain driveTrain = DriveTrain(&fullThrottle, &supportDriveActive);
Pneumatic pneumaticSystem = Pneumatic(&leftArmExtended, &rightArmExtended);
competition Competition;
Autonomous autonomous = Autonomous();
ButtonReader Abutton = ButtonReader(&buttonAstatus);
ButtonReader L1button = ButtonReader(&buttonL1status);
ButtonReader R1button = ButtonReader(&buttonR1status);
ButtonReader Ybutton = ButtonReader(&buttonYstatus);

// ScreenInfo screenInfo = ScreenInfo(0);

void setDriveTrainSpeedMax()
{
  fullThrottle = true;
}

void setDriveTrainSpeedNormal()
{
  fullThrottle = false;
}

// ButtonReader test = ButtonReader(Controller1.ButtonA.pressing)
int driveControl()
{
  while (true)
  {
    // read buttons
    buttonAstatus = Controller1.ButtonA.pressing();
    if (Abutton.onPressed())
    {
      if (leftArmExtended || rightArmExtended)
      {
        pneumaticSystem.retractAll();
      }
      else
      {
        pneumaticSystem.extendAll();
      }
    }
    buttonL1status = Controller1.ButtonL1.pressing();
    if (L1button.onPressed())
    {
      leftArmExtended = !leftArmExtended;
    }
    buttonR1status = Controller1.ButtonR1.pressing();
    if (R1button.onPressed())
    {
      rightArmExtended = !rightArmExtended;
    }

    buttonYstatus = Controller1.ButtonY.pressing();
    if (Ybutton.onPressed())
    {
      supportDriveActive = !supportDriveActive;
    }

    if (Controller1.ButtonR2.pressing())
      Catapult.spin(forward);
    else
      Catapult.stop();

    pneumaticSystem.controller();

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
  while (Competition.isAutonomous() && Competition.isEnabled())
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

  Brain.Screen.setFont(vex::fontType::mono20);
  Brain.Screen.setPenColor(green);
  Brain.Screen.print("if (Mark_e.isWinningMatch()) {");
  Brain.Screen.print("System.Console.WriteLine('Hello World');");
  Brain.Screen.print("print('Hello World!')");
  Brain.Screen.newLcine();
  Brain.Screen.print("console.log('Hello World!')");
  Brain.Screen.newLine();
  Brain.Screen.print("std::cout << 'Hello World!'");
  Brain.Screen.newLine();
  Brain.Screen.print("System.out.println('Hello World!')");
  Brain.Screen.newLine();
  Brain.Screen.print("printf('Hello World!')");
  Brain.Screen.newLine();
  Brain.Screen.print("System.Console.WriteLine('Hello World');");
  Brain.Screen.newLine();
  Brain.Screen.print("System.Console.WriteLine('Hello World');");
  Brain.Screen.newLine();
  Brain.Screen.print("} else {");
  Brain.Screen.newLine();
  Brain.Screen.print("Mark_e.enableSuperpowers(superpowers.all);");
  Brain.Screen.newLine();
  Brain.Screen.print("};");



  competition::bStopAllTasksBetweenModes = false;
  Competition.autonomous(startAutonomousTask);
  Competition.drivercontrol(drivercontrolTask);
}