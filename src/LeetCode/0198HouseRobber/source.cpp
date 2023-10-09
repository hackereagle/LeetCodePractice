#include <iostream>
#include <string>
#include <vector>
#include "VectorMiscs.hpp"
#include "AssertClass.hpp"

class Solution
{
public:
	Solution()
	{}

	~Solution()
	{}
	
	int rob(std::vector<int>& nums) {
		std::vector<int> dp(nums.size(), -1);
		return rob(nums, dp, nums.size() - 1);
	}

private:
	int rob(std::vector<int> &nums, std::vector<int> &dp, int n)
	{
		if (n < 0 || n >= nums.size())
			return 0;
		
		if (dp[n] >= 0)
			return dp[n];

		int takeCurHouse = nums[n] + rob(nums, dp, n - 2);
		int dontTakeCurHouse = rob(nums, dp, n - 1);
		dp[n] = std::max(takeCurHouse, dontTakeCurHouse);
		return dp[n];
	}
};

class TestRob
{
public:
	TestRob()
	{}

	~TestRob()
	{}

	void Example1()
	{
		// ARRANGE
		std::vector<int> nums = {1,2,3,1};
		int expectedOutput = 4;
		std::cout << "===== Test nums = " << Vector2Str(nums) << "; output = " << expectedOutput << " =====" << std::endl;

		// ACT
		int result = this->mSolution.rob(nums);

		// ASSERT
		AssertClass::GetInstance().Assert(result = expectedOutput);
	}

	void Example2()
	{
		// ARRANGE
		std::vector<int> nums = {2,7,9,3,1};
		int expectedOutput = 12;
		std::cout << "===== Test nums = " << Vector2Str(nums) << "; output = " << expectedOutput << " =====" << std::endl;

		// ACT
		int result = this->mSolution.rob(nums);

		// ASSERT
		AssertClass::GetInstance().Assert(result = expectedOutput);
	}

	void Example3()
	{
		// ARRANGE
		std::vector<int> nums = {13,100,9,10,1};
		int expectedOutput = 110;
		std::cout << "===== Test nums = " << Vector2Str(nums) << "; output = " << expectedOutput << " =====" << std::endl;

		// ACT
		int result = this->mSolution.rob(nums);

		// ASSERT
		AssertClass::GetInstance().Assert(result = expectedOutput);
	}

	void Example4()
	{
		// ARRANGE
		std::vector<int> nums = {100,2,3,101,2};
		int expectedOutput = 201;
		std::cout << "===== Test nums = " << Vector2Str(nums) << "; output = " << expectedOutput << " =====" << std::endl;

		// ACT
		int result = this->mSolution.rob(nums);

		// ASSERT
		AssertClass::GetInstance().Assert(result = expectedOutput);
	}

private:
	Solution mSolution;
};

int main(int argc, char** argv)
{
	TestRob test;
	test.Example1();
	test.Example2();
	test.Example3();
	test.Example4();
	getchar();
	return EXIT_SUCCESS;
}