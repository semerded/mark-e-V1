#include "testing.cpp"
#include <iostream>

class DriveTrain
{
public:
    bool* fullThrottle;

    DriveTrain(bool* fullThrottle)
    {
        this->fullThrottle = fullThrottle;
    }

    ~DriveTrain()
    {}

    bool getFullThrottlevalue()
    {
        return *this->fullThrottle;
    }
};

int main()
{
    bool fullThrottle = false;
    DriveTrain driveTrain = DriveTrain(&fullThrottle);

    assertFalse(driveTrain.getFullThrottlevalue());

    fullThrottle = true;

    assertTrue(driveTrain.getFullThrottlevalue());

    fullThrottle = false;

    assertFalse(driveTrain.getFullThrottlevalue());
}