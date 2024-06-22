#include <iostream>
#include <string>
#include <vector>
#include "VectorMiscs.hpp"
#include "StopWatch.hpp"
#include "AssertClass.hpp"

class Solution
{
public:
	Solution()
	{}

	~Solution()
	{}
	
	int maxRotateFunction(std::vector<int>& nums) {
		int len = nums.size();
		int sum = 0;
		std::vector<int> dp(len, 0);
		for (int i = 0; i < len; i++) {
			sum = sum + nums[i];
			dp[0] = dp[0] + (i * nums[i]);
		}
		int max = dp[0];
		for (int i = 1, idx = len - 1; i < len; i++, idx--) {
			dp[i] = dp[i - 1] + sum - (len * nums[idx]);
			max = std::max(max, dp[i]);
		}
		return max;
	}
};

class TestMaxRotateFunction
{
public:
	TestMaxRotateFunction()
	{}

	~TestMaxRotateFunction()
	{}

	void Example1()
	{
		// ARRANGE
		std::vector<int> nums({4,3,2,6});
		int expectedOutput = 26;
		std::cout << "===== Test nums = " << Vector2Str(nums) << "; output = " << expectedOutput << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		int result = this->mSolution.maxRotateFunction(nums);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example2()
	{
		// ARRANGE
		std::vector<int> nums({100});
		int expectedOutput = 0;
		std::cout << "===== Test nums = " << Vector2Str(nums) << "; output = " << expectedOutput << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		int result = this->mSolution.maxRotateFunction(nums);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

private:
	Solution mSolution;
};

int main(int argc, char** argv)
{
	TestMaxRotateFunction test;
	test.Example1();
	test.Example2();
	getchar();
	return EXIT_SUCCESS;
}