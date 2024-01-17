// #include "vex.h"
// #include "pneumatic.cpp"
#include "testing.cpp"
#include <iostream>


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

    void extendAll()
    {
        *this->leftArmExtended = true;
        *this->rightArmExtended = true;
    }

    void retractAll()
    {
        *this->leftArmExtended = false;
        *this->rightArmExtended = false;
    }
};

int main()
{
    bool leftArmExtended = false;
    bool rightArmExtended = false;

    std::cout << "test started" << std::endl;
    Pneumatic pneumaticTest = Pneumatic(&leftArmExtended, &rightArmExtended);

    assertFalse(leftArmExtended);
    assertFalse(rightArmExtended);

    pneumaticTest.extendAll();

    assertTrue(leftArmExtended);
    assertTrue(rightArmExtended);

    pneumaticTest.retractAll();

    assertFalse(leftArmExtended);
    assertFalse(rightArmExtended);
}