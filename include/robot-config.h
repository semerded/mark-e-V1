using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor_group Catapult;
extern digital_out LeftArm;
extern motor_group LeftMainDriveTrain;
extern motor_group RightMainDriveTrain;
extern digital_out RightArm;
extern motor LeftSupportDrive;
extern motor RightSupportDrive;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );