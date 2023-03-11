#include <iostream>
#include <vector>
#include "AssertClass.hpp"

class Solution
{
public:
	Solution()
	{
		this->mDp = std::vector<int>(45, -1);
		this->mDp[0] = 1;
		this->mDp[1] = 2;
	}

	int climbStairs(int n) {
		return this->Helper(this->mDp, n - 1);
	}

private:
	std::vector<int> mDp;

	int Helper(std::vector<int> &dp, int i)
	{
		if (dp[i] > 0)
			return dp[i];

		dp[i] = this->Helper(dp, i - 1) + this->Helper(dp, i - 2);
		return dp[i];
	}
};

class TestClimbStairs
{
public:
	TestClimbStairs()
	{}

	~TestClimbStairs()
	{}

	void Example1()
	{
		int n = 2;
		int expected = 2;
		std::cout << "===== Test input = " << n << ", output " << expected << " =====" << std::endl;

		int result = this->mSolution.climbStairs(n);

		AssertClass::GetInstance().Assert(result == expected);
	}

	void Example2()
	{
		int n = 3;
		int expected = 3;
		std::cout << "===== Test input = " << n << ", output " << expected << " =====" << std::endl;

		int result = this->mSolution.climbStairs(n);

		AssertClass::GetInstance().Assert(result == expected);
	}

	void Example3()
	{
		int n = 45;
		int expected = 1836311903;
		std::cout << "===== Test input = " << n << ", output " << expected << " =====" << std::endl;

		int result = this->mSolution.climbStairs(n);

		AssertClass::GetInstance().Assert(result == expected);
	}

private:
	Solution mSolution;
};

int main(int argc, char** argv)
{
	TestClimbStairs test;
	test.Example1();
	test.Example2();
	test.Example3();
	getchar();
	return EXIT_SUCCESS;
}