#include "vex.h"
#include "vex_global.h"
#include <cstdint>
using namespace vex;

class DriveTrain
{
  private:
  int8_t throttle;
  int8_t steering;
  bool* fullThrottle;
  bool* topSpeed;

  public:
  DriveTrain(bool* fullThrottle, bool* topSpeed)
  {
    this->fullThrottle = fullThrottle;
    this->topSpeed = topSpeed;
  }

  ~DriveTrain()
  {}

  void controllerDriving()
  {
    readControllerValue();
    if ((this->throttle < 5 && this->throttle > -5) && this->steering != 0)
    {
      if (*this->fullThrottle)
      {
        setTurningSpeed(this->steering / 2);
      }
      else
      {
        setTurningSpeed(this->steering / 4);
      }
    }
    else
    {
      calculateMotorSpeed(); // drive
    }
  }

  private:
  void readControllerValue()
  {
    this->throttle = Controller1.Axis3.position();
    this->steering = Controller1.Axis1.position();
  }

  void calculateMotorSpeed()
  {
    int8_t motorSpeedLeft = this->throttle;
    int8_t motorSpeedRight = this->throttle;
    if (this->steering < 0)
    {
      motorSpeedLeft = abs(this->throttle) - abs(this->steering);
      if (this->throttle < 0)
      {
        motorSpeedLeft *= -1;
      }
    }
    else if (this->steering > 0)
    {
      motorSpeedRight = abs(this->throttle) - this->steering;
      if (this->throttle < 0)
      {
        motorSpeedRight *= -1;
      }
    }
    if (*this->fullThrottle)
    {
      setDriveSpeed(motorSpeedLeft, motorSpeedRight);
    }
    else
    {
      setDriveSpeed(motorSpeedLeft / 2.5, motorSpeedRight / 2.5);
    }
  }

  public:
  void setDriveSpeed(int8_t motorSpeedLeft, int8_t motorSpeedRight)
  {
    LeftMainDriveTrain.spin(forward, motorSpeedLeft, percent);
    LeftSupportDrive.spin(forward, motorSpeedLeft, percent);
    RightMainDriveTrain.spin(forward, motorSpeedRight, percent);
    RightSupportDrive.spin(forward, motorSpeedRight, percent);
  }

  void setTurningSpeed(int8_t turningSpeed)
  {
    LeftMainDriveTrain.spin(forward, turningSpeed, percent);
    RightMainDriveTrain.spin(reverse, turningSpeed, percent);

    LeftSupportDrive.spin(forward, turningSpeed, percent);
    RightSupportDrive.spin(reverse, turningSpeed, percent);
  }

  void overwriteFullThrottle(bool status)
  {
    *this->fullThrottle = status;
  }
};