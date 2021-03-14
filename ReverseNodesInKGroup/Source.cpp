#include "ReverseNodeInKGroupTest.hpp"

int main(int argc, char** argv)
{
    std::unique_ptr<ReverseNodeInKGroupTest> test = std::make_unique<ReverseNodeInKGroupTest>();
    test->Initialize();
    test->Example1Test();
    test->Example2Test();
    test->Example3Test();

    getchar();
    return EXIT_SUCCESS;
}