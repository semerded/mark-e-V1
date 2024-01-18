#include "vex.h"
#include "vex_global.h"
using namespace vex;

class DriveTrain
{
  private:
  int8_t throttle;
  int8_t steering;
  bool* fullThrottle;

  public:
  DriveTrain(bool* fullThrottle)
  {
    this->fullThrottle = fullThrottle;
  }

  ~DriveTrain()
  {}

  void controllerDriving()
  {
    readControllerValue();
    if (this->throttle == 0 && this->steering != 0)
    {
      mainTurning();
      supportTurning();
    }
    else
    {
      mainDriving();
    }
  }

  private:
  void readControllerValue()
  {
    this->throttle = Controller1.Axis3.position();
    this->steering = Controller1.Axis1.position();
  }

  void mainDriving()
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
    setDrivingSpeed(motorSpeedLeft, motorSpeedRight);
    setSupportDriveSpeed(motorSpeedLeft, motorSpeedRight);
  }

  void setDrivingSpeed(int8_t motorSpeedLeft, int8_t motorSpeedRight)
  {
    if (*this->fullThrottle)
    {
      LeftMainDriveTrain.spin(forward, motorSpeedLeft, percent);
      RightMainDriveTrain.spin(forward, motorSpeedRight, percent);
    }
    else
    {
      LeftMainDriveTrain.spin(forward, motorSpeedLeft / 3, percent);
      RightMainDriveTrain.spin(forward, motorSpeedRight / 3, percent);
    }
  }

  void setSupportDriveSpeed(int8_t motorSpeedLeft, int8_t motorSpeedRight)
  {
    if (*this->fullThrottle)
    {
      LeftSupportDrive.spin(forward, motorSpeedLeft, percent);
      RightSupportDrive.spin(forward, motorSpeedRight, percent);
    }
    else
    {
      LeftSupportDrive.spin(forward, motorSpeedLeft / 3, percent);
      RightSupportDrive.spin(forward, motorSpeedRight / 3, percent);
    }
  }

  void mainTurning()
  {
    if (*this->fullThrottle)
    {
      LeftMainDriveTrain.spin(forward, this->steering / 2, percent);
      RightMainDriveTrain.spin(reverse, this->steering / 2, percent);
    }
    else
    {
      LeftMainDriveTrain.spin(forward, this->steering / 4, percent);
      RightMainDriveTrain.spin(reverse, this->steering / 4, percent);
    }
  }

  void supportTurning()
  {
    if (*this->fullThrottle)
    {
      LeftSupportDrive.spin(forward, this->steering / 2, percent);
      RightSupportDrive.spin(reverse, this->steering / 2, percent);
    }
    else
    {
      LeftSupportDrive.spin(forward, this->steering / 4, percent);
      RightSupportDrive.spin(reverse, this->steering / 4, percent);
    }
  }
};