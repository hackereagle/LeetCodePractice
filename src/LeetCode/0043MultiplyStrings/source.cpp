#include <iostream>
#include <string>
#include "AssertClass.hpp"

class Solution
{
public:
	Solution()
	{}

	~Solution()
	{}
	
	std::string multiply(std::string num1, std::string num2) {
		std::string res;

		size_t len = (num1.size() - 1) + (num2.size() - 1);
		if (len == 0) {
			len = 1;
			res = std::string(1, '0');
		}
		else
			res = std::string(len, '0');

		int multiplierDig = num2.size() - 1;
		int num2Dig = 0;
		int curResPos;
		while (multiplierDig >= 0) {
			num2Dig = static_cast<int>(num2[multiplierDig] - '0');
			curResPos = res.size() - 1 - (num2.size() - 1 - multiplierDig);
			//std::cout << "multiplier digit = " << multiplierDig << ", result start position = " << curResPos << std::endl; // debug
			MultiplyNum1WithNum2Dig(num1, num2Dig, res, curResPos);

			multiplierDig = multiplierDig - 1;
		}

		EliminateLeadingZero(res);
		
		return res;
	}

private:
	void MultiplyNum1WithNum2Dig(std::string &num1, int num2Dig, std::string &res, int curResPos)
	{
		int carrier = 0;
		int multiplicandMaxDig = num1.size() - 1;
		int num1Dig = 0;
		int digMultRes = 0;
		for (int i = multiplicandMaxDig; i >= 0; i--, curResPos--) {
			if (curResPos < 0) {
				res.insert(res.begin(), '0');
				curResPos = curResPos + 1;
			}

			num1Dig = static_cast<int>(num1[i] - '0');
			digMultRes = num1Dig * num2Dig;
			digMultRes = digMultRes + static_cast<int>(res[curResPos] - '0') + carrier;
			//std::cout << "\tnum1[" << i << "] = " << num1Dig << ", multiplierDig = " << num2Dig << ", carrier = " << carrier << ", res[" << curResPos << "] = " << (int)(res[curResPos] - '0') << ", digit multiple result = " << digMultRes; // debug
			carrier = 0;

			if (digMultRes > 9) {
				carrier = digMultRes / 10;
				digMultRes = digMultRes % 10;
			}
			res[curResPos] = digMultRes + '0';
			//std::cout << ", res = " << res << std::endl; // debug
		}

		if (carrier > 0) {
			if (curResPos < 0)
				res.insert(res.begin(), carrier + '0');
			else
				res[curResPos] = (char)((int)(res[curResPos] - '0') + carrier) + '0';
			
			carrier = 0;
			//std::cout << "\tcarry: res = " << res << std::endl;
		}
	}

	void EliminateLeadingZero(std::string &res)
	{
		size_t len = res.size();
		while(len > 1 && res[0] == '0')
		{
			res.erase(res.begin());
			len = len - 1;
		}
	}
};

class TestMultiply
{
public:
	TestMultiply()
	{}

	~TestMultiply()
	{}

	void Example1()
	{
		// ARRANGE
		std::string num1 = "2";
		std::string num2 = "3";
		std::string expectedOutput = "6";
		std::cout << "===== Test num1 = " << num1 << ", num2 = " << num2 << "; expected output = " << expectedOutput << " =====" << std::endl;

		// ACT
		std::string result = this->mSolution.multiply(num1, num2);

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example2()
	{
		// ARRANGE
		std::string num1 = "123";
		std::string num2 = "456";
		std::string expectedOutput = "56088";
		std::cout << "===== Test num1 = " << num1 << ", num2 = " << num2 << "; expected output = " << expectedOutput << " =====" << std::endl;

		// ACT
		std::string result = this->mSolution.multiply(num1, num2);

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example3()
	{
		// ARRANGE
		std::string num1 = "999";
		std::string num2 = "0";
		std::string expectedOutput = "0";
		std::cout << "===== Test num1 = " << num1 << ", num2 = " << num2 << "; expected output = " << expectedOutput << " =====" << std::endl;

		// ACT
		std::string result = this->mSolution.multiply(num1, num2);

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example4()
	{
		// ARRANGE
		std::string num1 = "999";
		std::string num2 = "1";
		std::string expectedOutput = "999";
		std::cout << "===== Test num1 = " << num1 << ", num2 = " << num2 << "; expected output = " << expectedOutput << " =====" << std::endl;

		// ACT
		std::string result = this->mSolution.multiply(num1, num2);

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example5()
	{
		// ARRANGE
		std::string num1 = "6";
		std::string num2 = "3";
		std::string expectedOutput = "18";
		std::cout << "===== Test num1 = " << num1 << ", num2 = " << num2 << "; expected output = " << expectedOutput << " =====" << std::endl;

		// ACT
		std::string result = this->mSolution.multiply(num1, num2);

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example6()
	{
		// ARRANGE
		std::string num1 = "999";
		std::string num2 = "999";
		std::string expectedOutput = "998001";
		std::cout << "===== Test num1 = " << num1 << ", num2 = " << num2 << "; expected output = " << expectedOutput << " =====" << std::endl;

		// ACT
		std::string result = this->mSolution.multiply(num1, num2);

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

private:
	Solution mSolution;
};

int main(int argc, char** argv)
{
	TestMultiply test;
	test.Example1();
	test.Example2();
	test.Example3();
	test.Example4();
	test.Example5();
	test.Example6();
	getchar();
	return EXIT_SUCCESS;
}