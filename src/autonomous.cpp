#include "drivetrain.cpp"
#include "pneumatic.cpp"
#include "vex_global.h"
#include "vex_motorgroup.h"
#include "vex_units.h"
#include <cstdint>
#include <sys/types.h>

class AutonomousPneumatic: Pneumatic
{
  private:
  bool leftArm = false;
  bool rightArm = false;

  public:
  AutonomousPneumatic(): Pneumatic(&leftArm, &rightArm)
  {}

  void changeLeft(bool extended)
  {
    setLeft(extended);
  }

  void changeRight(bool extended)
  {
    setRight(extended);
  }

  void extendAll()
  {
    Pneumatic::extendAll();
  }

  void retractAll()
  {
    Pneumatic::retractAll();
  }
};

class AutonomousDriving : DriveTrain
{
  private:
  bool fullThrottle;
  bool topSpeed;

  public:
  AutonomousDriving()
      : DriveTrain(&fullThrottle, &topSpeed)
  {}

  void setFullThrottle(bool status)
  {
    this->fullThrottle = status;
  }

  void drive(int8_t speedLeft, int8_t speedRight)
  {
    setDriveSpeed(speedLeft, speedRight);
  }

  void driveFor(int8_t speedLeft, int8_t speedRight, int millisec)
  {
    drive(speedLeft, speedRight);
    vex::wait(millisec, msec);
    stop();
  }

  void turn(turnType direction, uint8_t turningSpeed)
  {
    if (direction == vex::turnType::left)
    {
      turningSpeed *= -1;
    }
    setTurningSpeed(turningSpeed);
  }

  void turnFor(turnType direction, uint8_t turningSpeed, int millisec)
  {
    turn(direction, turningSpeed);
    vex::wait(millisec, msec);
    stop();
  }

  void stop()
  {
    drive(0, 0);
  }

  void wait()
  {
    stop();
    vex::wait(1, sec);
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