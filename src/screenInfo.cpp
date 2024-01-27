#include "vex.h"

class ScreenInfo
{
private:
int* motorSpeed;
uint8_t batteryPercentage;

public:
ScreenInfo(int* motorSpeed)
{
this->motorSpeed = motorSpeed;
}

~ScreenInfo()
{}

void print()
{

}

void clear()
{
brain.screen.clear();
}
}