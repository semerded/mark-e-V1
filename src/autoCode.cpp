#include "autonomous.cpp"
#include "vex_global.h"

using namespace vex;

struct Autonomous
{
  Autonomous()
  {}

  void startAutonomous()
  {
    AutonomousShooting shoot = AutonomousShooting();
    AutonomousDriving drive = AutonomousDriving();
    AutonomousPneumatic pneumatic = AutonomousPneumatic();

    // start of autonomous code
    // drive.setFullThrottle(false);
    drive.driveFor(40, 40, 750);
    drive.wait();
    drive.wait();
    drive.driveFor(-40, -40, 250);
    drive.wait();

    // vex::wait(20, sec);
  }
};
