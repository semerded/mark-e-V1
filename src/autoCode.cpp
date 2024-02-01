#include "autonomous.cpp"
#include "vex_global.h"

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
    drive.setFullThrottle(false);
    drive.driveFor(100, 100, 200);
    shoot.shootOnce();
    drive.wait();
    drive.driveFor(100, 100, 1200);
    drive.wait();
    drive.turnFor(right, 100, 600);
    drive.wait();
    drive.driveFor(100, 100, 500);
    vex::wait(2, sec);
  }
};
