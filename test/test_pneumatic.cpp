#include "vex.h"
#include "pneumatic.cpp"
#include <iostream>

bool leftArmExtended = false;
bool rightArmExtended = false;

int main()
{
    Pneumatic pneumaticTest = Pneumatic(&leftArmExtended, &rightArmExtended);

    pneumaticTest.extendAll();

    std::cout << leftArmExtended << rightArmExtended << std::endl;
}