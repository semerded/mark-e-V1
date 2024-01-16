#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor CatapultMotorA = motor(PORT7, ratio36_1, true);
motor CatapultMotorB = motor(PORT8, ratio36_1, false);
motor_group Catapult = motor_group(CatapultMotorA, CatapultMotorB);
digital_out LeftArm = digital_out(Brain.ThreeWirePort.A);
motor LeftMainDriveTrainMotorA = motor(PORT1, ratio6_1, false);
motor LeftMainDriveTrainMotorB = motor(PORT3, ratio6_1, false);
motor_group LeftMainDriveTrain = motor_group(LeftMainDriveTrainMotorA, LeftMainDriveTrainMotorB);
motor RightMainDriveTrainMotorA = motor(PORT4, ratio6_1, true);
motor RightMainDriveTrainMotorB = motor(PORT6, ratio6_1, true);
motor_group RightMainDriveTrain = motor_group(RightMainDriveTrainMotorA, RightMainDriveTrainMotorB);
digital_out RightArm = digital_out(Brain.ThreeWirePort.B);
motor LeftSupportDrive = motor(PORT2, ratio6_1, false);
motor RightSupportDrive = motor(PORT5, ratio6_1, true);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}