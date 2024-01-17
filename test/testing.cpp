#include <iostream>
#include <ostream>
#include <string>

void printResult(std::string result)
{
    std::cout << result << std::endl;
}

class VexTest
{
    VexTest()
    {}

    ~VexTest()
    {}
};

bool assertTrue(bool input)
{
    if (input)
    {
        printResult("subtest completed");
        return true;
    }
    printResult("subtest failed");
    return false;
}

bool assertFalse(bool input)
{
    if (!input)
    {
        printResult("subtest completed");
        return true;
    }
    printResult("subtest failed");
    return false;
}