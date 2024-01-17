#include "vex.h"
using namespace vex;

class Pneumatic
{
  private:
  bool* leftArmExtended;
  bool* rightArmExtended;

  public:
  Pneumatic(bool* leftArmExtended, bool* rightArmExtended)
  {
    this->leftArmExtended = leftArmExtended;
    this->rightArmExtended = rightArmExtended;
  }

  ~Pneumatic()
  {}

  void controller()
  {
    LeftArm.set(this->leftArmExtended);
    RightArm.set(this->rightArmExtended);
  }

  void extendAll()
  {
    *this->leftArmExtended = true;
    *this->rightArmExtended = true;
    controller();
  }

  void retractAll()
  {
    *this->leftArmExtended = false;
    *this->rightArmExtended = false;
    controller();
  }
};
