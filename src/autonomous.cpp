#include "pneumatic.cpp"
#include "drivetrain.cpp"
#include "vex_global.h"
#include "vex_motorgroup.h"
#include <cstdint>

class AutonomousPneumatic
{
    private:
    Pneumatic* pneumatic;
    public:
    AutonomousPneumatic(Pneumatic* pneumaticSystem)
    {
        this->pneumatic = pneumaticSystem;
    }

    void changeLeft(bool extended)
    {
        this->pneumatic->setLeft(extended);
    }

    void changeRight(bool extended)
    {
        this->pneumatic->setRight(extended);
    }

    void extendAll()
    {
        this->pneumatic->extendAll();
    }

    void retractAll()
    {
        this->pneumatic->retractAll();
    }
};

class AutonomousDriving
{
    private:
    DriveTrain* driveTrain;
    public:
    AutonomousDriving(DriveTrain* driveTrain)
    {
        this->driveTrain = driveTrain;
    }

    void drive(int8_t speedLeft, int8_t speedRight)
    {
        this->driveTrain->setDrivingSpeed(speedLeft, speedRight);
        this->driveTrain->setSupportDriveSpeed(speedLeft, speedRight);
    }

    void stop()
    {
        drive(0, 0);
    }
};

class AutonomousShooting
{
    private:
    motor_group catapult = Catapult;
    public:
    AutonomousShooting()
    {}

    void shootOnce()
    {
        this->catapult.spinFor(forward, 360, degrees);
    }

    void startShooting()
    {
        this->catapult.spin(forward);
    }

    void stopShooting()
    {
        this->catapult.stop();
    }
};