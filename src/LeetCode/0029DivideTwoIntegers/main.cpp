#include <iostream>
#include <vector>
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
        typedef long long int int64; 
        int64 quotient = 0; 
        int64 countBase = 1; 
        int64 _dividend = static_cast<long long int>(dividend); 
        int64 _divisor = static_cast<long long int>(divisor); 
        bool isResultNegtive = false; 
        if(_dividend < 0 ^ _divisor < 0){ 
            isResultNegtive = true; 
        } 
        _dividend = _dividend < 0 ? ((~_dividend) + 1) : _dividend; 
        _divisor = _divisor < 0 ? ((~_divisor) + 1) : _divisor; 

        for(int i = 31; i > -1; i--){ 
            if(_dividend >= (_divisor << i)){ 
                int64 temp = _divisor << i; 
                _dividend = _dividend - temp; 
                quotient = quotient + (1 << i); 
            } 
        } 
         
        if(isResultNegtive & (quotient > 0)){ 
            quotient = ~quotient + 1; 
        } 

        if(!isResultNegtive & (quotient < 0)){ 
            quotient = ~quotient + 1; 
        } 
        if(quotient >= (((int64)1 << 31) - 1)){ 
            quotient = ((int64)1 << 31) - 1; 
        } 
         
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

    void Test_Input_minus_1_1_Output_minus_1()
    {
        std::cout << "========= Test input -1 and 1 output -1 =========" << std::endl;
        int dividend = -1, divisor = 1;

        int result = this->mSolution.divide(dividend, divisor);
        AssertClass::GetInstance().Assert(result == -1);
    }

    void Test_Input_minus_2147483648_1_Output_minus_2147483648()
    {
        std::cout << "========= Test input -2147483648 and 1 output -2147483648 =========" << std::endl;
        int dividend = -2147483648, divisor = 1;

        int result = this->mSolution.divide(dividend, divisor);
        AssertClass::GetInstance().Assert(result == -2147483648);
    }

    void Test_Input_minus_2147483648_minus_1_Output_2147483647()
    {
        std::cout << "========= Test input -2147483648 and -1 output 2147483647 =========" << std::endl;
        int dividend = -2147483647, divisor = -1;

        int result = this->mSolution.divide(dividend, divisor);
        AssertClass::GetInstance().Assert(result == 2147483647);
    }

private:
	Solution mSolution;

};

int main(int argc, char** argv)
{
	TestDivide test;
    test.Test_Input_10_3_Output_3();
    test.Test_Input_7_minus_3_Output_minus_2();
    test.Test_Input_minus_1_1_Output_minus_1();
    test.Test_Input_minus_2147483648_1_Output_minus_2147483648();
    test.Test_Input_minus_2147483648_minus_1_Output_2147483647();
	getchar();
	return EXIT_SUCCESS;
}