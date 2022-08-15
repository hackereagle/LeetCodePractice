#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "AssertClass.hpp"
#include "VectorMiscs.hpp"


class Solution
{
public:
	~Solution()
	{}

	Solution()
    {
    }

    int divide(int dividend, int divisor) {
        int quotient = 0;
        return quotient;
    }

private:
};

class TestDivide
{
public:
	TestDivide()
	{}

	~TestDivide()
	{}

    void Test_Input_10_3_Output_3()
    {
        std::cout << "========= Test input 10 and 3 output 3 =========" << std::endl;
        int dividend = 10, divisor = 3;

        int result = this->mSolution.divide(dividend, divisor);
        AssertClass::GetInstance().Assert(result == 3);
    }

    void Test_Input_7_minus_3_Output_minus_2()
    {
        std::cout << "========= Test input 7 and -3 output -2 =========" << std::endl;
        int dividend = 7, divisor = -3;

        int result = this->mSolution.divide(dividend, divisor);
        AssertClass::GetInstance().Assert(result == -2);
    }

private:
	Solution mSolution;

};

int main(int argc, char** argv)
{
	TestDivide test;
    test.Test_Input_10_3_Output_3();
    test.Test_Input_7_minus_3_Output_minus_2();
	getchar();
	return EXIT_SUCCESS;
}