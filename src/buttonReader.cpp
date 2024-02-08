#include "vex.h"

using namespace vex;

class ButtonReader
{
  private:
  bool *buttonStatus;
  bool buttonPressed = false;

  public:
  ButtonReader(bool* buttonStatus)
  {
    this->buttonStatus = buttonStatus;
  }

  ~ButtonReader()
  {}

  bool onPressed()
  {
    if (*this->buttonStatus)
    {
      if (!this->buttonPressed)
      {
        this->buttonPressed = true;
        return true;
      }
    }
    else
    {
      {
        this->buttonPressed = false;
      }
    }
    return false;
  }
};