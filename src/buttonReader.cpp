#include "vex.h"

using namespace vex;

class ButtonReader
{
  private:
  bool* button;
  bool buttonPressed = false;

  public:
  ButtonReader(bool* button)
  {
    this->button = button;
  }

  ~ButtonReader()
  {}

  bool onPressed()
  {
    if (*this->button)
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