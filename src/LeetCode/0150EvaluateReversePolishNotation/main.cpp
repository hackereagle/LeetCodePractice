#include <iostream>
#include <vector>
#include <string>
#include <stack>
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

    typedef long long int int64;
    int evalRPN(std::vector<std::string>& tokens) {
        int64 ret = 0;
        
        std::stack<int64> numbers;
        for(auto t : tokens){
            if (this->isOperator(t)){
                int64 right = numbers.top();
                numbers.pop();
                int64 left = numbers.top();
                numbers.pop();

                int64 result = this->DoOperate(left, t, right);
                //std::cout << left << t << right << " = " << result << std::endl;
                numbers.push(result);
            }
            else {
                numbers.push(std::stoi(t));
            }
        }
        
        ret = numbers.top();
        numbers.pop();
        
        return static_cast<int>(ret);
    }

private:
    bool isOperator(std::string str)
    {
        bool _isOperator = false;

        if ("+" == str ||
            "-" == str ||
            "*" == str ||
            "/" == str)
            _isOperator = true;

        return _isOperator;
    }

    int64 DoOperate(int64 num1, std::string optr, int64 num2)
    {
        int64 ret = 0;

        if ("+" == optr)
            ret = num1 + num2;
        else if ("-" == optr)
            ret = num1 - num2;
        else if ("*" == optr) 
            ret = num1 * num2;
        else if ("/" == optr) 
            ret = num1 / num2;

        return ret;
    }
};

class TestEvalRPN
{
public:
	TestEvalRPN()
	{}

	~TestEvalRPN()
	{}

    void Test_Example1()
    {
        std::cout << "========= Test input [\"2\",\"1\",\"+\",\"3\",\"*\"], output = 9 =========" << std::endl;
        std::vector<std::string> tokens({"2","1","+","3","*"});

        int result = this->mSolution.evalRPN(tokens);
        AssertClass::GetInstance().Assert(result == 9);
    }

    void Test_Example2()
    {
        std::cout << "========= Test input [\"4\",\"13\",\"5\",\"/\",\"+\"], output = 6 =========" << std::endl;
        std::vector<std::string> tokens({"4","13","5","/","+"});

        int result = this->mSolution.evalRPN(tokens);
        AssertClass::GetInstance().Assert(result == 6);
    }

    void Test_Example3()
    {
        std::cout << "========= Test input [\"10\",\"6\",\"9\",\"3\",\"+\",\"-11\",\"*\",\"/\",\"*\",\"17\",\"+\",\"5\",\"+\"], output = 22 =========" << std::endl;
        std::vector<std::string> tokens({"10","6","9","3","+","-11","*","/","*","17","+","5","+"});

        int result = this->mSolution.evalRPN(tokens);
        AssertClass::GetInstance().Assert(result == 22);
    }

    void Test_Example4_EdgeCase()
    {
        std::cout << "========= Test input [\"-128\",\"-128\",\"*\",\"-128\",\"*\",\"-128\",\"*\",\"8\",\"*\",\"-1\",\"*\"], output = -2147483648 =========" << std::endl;
        std::vector<std::string> tokens({"-128","-128","*","-128","*","-128","*","8","*","-1","*"});

        int result = this->mSolution.evalRPN(tokens);
        AssertClass::GetInstance().Assert(result == -2147483648);
    }

private:
	Solution mSolution;

};

int main(int argc, char** argv)
{
	TestEvalRPN test;
    test.Test_Example1();
    test.Test_Example2();
    test.Test_Example3();
    test.Test_Example4_EdgeCase();
	getchar();
	return EXIT_SUCCESS;
}