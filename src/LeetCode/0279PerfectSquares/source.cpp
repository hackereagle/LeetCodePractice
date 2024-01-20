#include <iostream>
#include <sstream>
#include <string>
#include "AssertClass.hpp"

class Solution
{
public:
	Solution()
	{}

	~Solution()
	{}
	
	int numSquares(int n) {
		std::vector<int> dp(n + 1, std::numeric_limits<int>::max());
		dp[0] = 0;

		int square = 0;
		int i = 1;
		do {
			square = i * i;
			UpdateDp(dp, square);
			i = i + 1;
		} while (square <= n);
		//std::cout << Vec2Str(dp) << std::endl;
		
		return dp.back();
	}

private:
	void UpdateDp(std::vector<int> &dp, int square)
	{
		//std::cout << "square = " << square << std::endl;
		size_t len = dp.size();
		int num = 0, mul = 0, remain = 0;
		for (int i = square; i < len; i++) {
			mul = i / square;
			remain = i % square;
			dp[i] = std::min(mul + dp[remain], dp[i]);
			//std::cout << "\tmul = " << mul << ", remain = " << remain << ", dp[" << i << "] = " << dp[i] << std::endl; // debug
		}
	}

	std::string Vec2Str(std::vector<int> &vec)
	{
		std::ostringstream ss;
		ss << "[";
		for (auto &v : vec) {
			ss << v << " ";
		}
		ss << "]";
		return ss.str();
	}
};

class TestNumSquares
{
public:
	TestNumSquares()
	{}

	~TestNumSquares()
	{}

	void Example1()
	{
		// ARRANGE
		int n = 12;
		int expectedOutput = 3;
		std::cout << "===== Test n = " << n << "; output = " << expectedOutput << " =====" << std::endl;

		// ACT
		int result = this->mSolution.numSquares(n);

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example2()
	{
		// ARRANGE
		int n = 13;
		int expectedOutput = 2;
		std::cout << "===== Test n = " << n << "; output = " << expectedOutput << " =====" << std::endl;

		// ACT
		int result = this->mSolution.numSquares(n);

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}
	
	void Example3()
	{
		// ARRANGE
		int n = 10000;
		int expectedOutput = 1;
		std::cout << "===== Test n = " << n << "; output = " << expectedOutput << " =====" << std::endl;

		// ACT
		int result = this->mSolution.numSquares(n);

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

private:
	Solution mSolution;
};

int main(int argc, char** argv)
{
	TestNumSquares test;
	test.Example1();
	test.Example2();
	test.Example3();
	getchar();
	return EXIT_SUCCESS;
}