#include "v5_api.h"
#include "vex.h"
#include "vex_controller.h"

class ScreenInfo
{
  private:
  int* motorSpeed;

  public:
  ScreenInfo(int* motorSpeed)
  {
    this->motorSpeed = motorSpeed;
  }

  ~ScreenInfo()
  {}

  void print()
  {
    // Controller1.Screen.setCursor(0, 0);
    // Controller1.Screen.print("Bat");
    Controller1.Screen.setCursor(0, 0);
    Controller1.Screen.print(vexBatteryCurrentGet());
    Controller1.Screen.setCursor(0, 1);
    Controller1.Screen.print("12345678901234567890");


  }

  void clear()
  {
    Controller1.Screen.clearScreen();
  }
};