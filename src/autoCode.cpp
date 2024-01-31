#include "autonomous.cpp"

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
    shoot.shootOnce();
    drive.setFullThrottle(true);
    drive.driveFor(100, 100, 200);
    drive.turnFor(right, 100, 100);
  }
};
