#include <iostream>
#include <string>
#include <map>
#include "AssertClass.hpp"

class Solution
{
public:
	Solution()
	{}

	~Solution()
	{}
	
	std::string fractionToDecimal(int numerator, int denominator) {
		std::string ret;
		int flag = 0;
		int64 num = (int64)numerator, den = (int64)denominator;
		if (num < 0) {
			num = ~num + 1;
			flag = flag ^ 1;
		}
		if (den< 0) {
			den = ~den + 1;
			flag = flag ^ 1;
		}
		if (flag && (num !=0 && den != 0)) {
			ret = "-";
		}
		int64 intPart = num / den;
		int64 remain = num - (den * intPart);
		// std::cout << "intPart = " << intPart << ", remain = " << remain << std::endl;
		ret.append(std::to_string(intPart));
		if (remain != 0) {
			ret = ret.append(".");
			remain = remain * 10;
			ComputeFractionsPart(remain, den, ret);
		}
		return ret;
	}
private:
	typedef long long int int64;
	void ComputeFractionsPart(int64 remain, int64 denominator, std::string &ret)
	{
		int64 num = 0;
		int totalSize = ret.size();
		std::string fraction;
		std::map<int64, size_t> remainIndexTable;
		while (remain != 0 && totalSize < 10000) {
			if (remainIndexTable.find(remain) != remainIndexTable.end()) {
				int idx = remainIndexTable[remain];
				fraction.insert(idx, "(");
				fraction.append(")");
				break;
			}
			else {
				remainIndexTable.insert(std::pair<int, int>(remain, fraction.size()));
			}
			num = remain / denominator;
			remain = remain - (denominator * num);
			remain = remain * 10;
			fraction.append(std::to_string(num));
			totalSize = totalSize + 1;
		}
		ret.append(fraction);
	}
};

class TestFractionToDecimal
{
public:
	TestFractionToDecimal()
	{}

	~TestFractionToDecimal()
	{}

	void Example1()
	{
		// ARRANGE
		int numerator = 1;
		int denominator = 2;
		std::string expectedOutput = "0.5";
		std::cout << "===== Test numerator = " << numerator << ", denominator = " << denominator << "; output " << expectedOutput << " =====" << std::endl;

		// ACT
		std::string result = this->mSolution.fractionToDecimal(numerator, denominator);

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example2()
	{
		// ARRANGE
		int numerator = 2;
		int denominator = 1;
		std::string expectedOutput = "2";
		std::cout << "===== Test numerator = " << numerator << ", denominator = " << denominator << "; output " << expectedOutput << " =====" << std::endl;

		// ACT
		std::string result = this->mSolution.fractionToDecimal(numerator, denominator);

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example3()
	{
		// ARRANGE
		int numerator = 4;
		int denominator = 333;
		std::string expectedOutput = "0.(012)";
		std::cout << "===== Test numerator = " << numerator << ", denominator = " << denominator << "; output " << expectedOutput << " =====" << std::endl;

		// ACT
		std::string result = this->mSolution.fractionToDecimal(numerator, denominator);

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example4()
	{
		// ARRANGE
		int numerator = 1;
		int denominator = 3;
		std::string expectedOutput = "0.(3)";
		std::cout << "===== Test numerator = " << numerator << ", denominator = " << denominator << "; output " << expectedOutput << " =====" << std::endl;

		// ACT
		std::string result = this->mSolution.fractionToDecimal(numerator, denominator);

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example5()
	{
		// ARRANGE
		int numerator = -2147483647;
		int denominator = 7;
		std::string expectedOutput = "-306783378.(142857)";
		std::cout << "===== Test numerator = " << numerator << ", denominator = " << denominator << "; output " << expectedOutput << " =====" << std::endl;

		// ACT
		std::string result = this->mSolution.fractionToDecimal(numerator, denominator);

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example6()
	{
		// ARRANGE
		int numerator = 1;
		int denominator = 6;
		std::string expectedOutput = "0.1(6)";
		std::cout << "===== Test numerator = " << numerator << ", denominator = " << denominator << "; output " << expectedOutput << " =====" << std::endl;

		// ACT
		std::string result = this->mSolution.fractionToDecimal(numerator, denominator);

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example7()
	{
		// ARRANGE
		int numerator = 1;
		int denominator = 99;
		std::string expectedOutput = "0.(01)";
		std::cout << "===== Test numerator = " << numerator << ", denominator = " << denominator << "; output " << expectedOutput << " =====" << std::endl;

		// ACT
		std::string result = this->mSolution.fractionToDecimal(numerator, denominator);

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example8()
	{
		// ARRANGE
		int numerator = -1;
		int denominator = 99;
		std::string expectedOutput = "-0.(01)";
		std::cout << "===== Test numerator = " << numerator << ", denominator = " << denominator << "; output " << expectedOutput << " =====" << std::endl;

		// ACT
		std::string result = this->mSolution.fractionToDecimal(numerator, denominator);

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example9()
	{
		// ARRANGE
		int numerator = 0;
		int denominator = -5;
		std::string expectedOutput = "0";
		std::cout << "===== Test numerator = " << numerator << ", denominator = " << denominator << "; output " << expectedOutput << " =====" << std::endl;

		// ACT
		std::string result = this->mSolution.fractionToDecimal(numerator, denominator);

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example10()
	{
		// ARRANGE
		int numerator = -1;
		int denominator = -2147483648;
		std::string expectedOutput = "0.0000000004656612873077392578125";
		std::cout << "===== Test numerator = " << numerator << ", denominator = " << denominator << "; output " << expectedOutput << " =====" << std::endl;

		// ACT
		std::string result = this->mSolution.fractionToDecimal(numerator, denominator);

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

private:
	Solution mSolution;
};

int main(int argc, char** argv)
{
	TestFractionToDecimal test;
	test.Example1();
	test.Example2();
	test.Example3();
	test.Example4();
	test.Example5();
	test.Example6();
	test.Example7();
	test.Example8();
	test.Example9();
	test.Example10();
	getchar();
	return EXIT_SUCCESS;
}