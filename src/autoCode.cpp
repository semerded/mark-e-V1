#include "autonomous.cpp"

void startAutonomus(Pneumatic* pneumaticSystem, DriveTrain* driveTrain)
{
    AutonomousShooting shoot = AutonomousShooting();
    AutonomousDriving drive = AutonomousDriving(driveTrain);
    AutonomousPneumatic pneumatic = AutonomousPneumatic(pneumaticSystem);

    // start of autonomous code
    shoot.shootOnce();
    drive.drive(100, 100);
}