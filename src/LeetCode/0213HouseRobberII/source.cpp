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
		int robMax = 0;
		if (nums.size() < 3) {
			robMax = *std::max_element(nums.begin(), nums.end());
		}
		else {
			std::vector<int> nums1;
			nums1.assign(nums.begin(), nums.begin() + nums.size() - 1);
			//PrintVector(nums1); // debug
			std::vector<int> dp1(nums1.size(), -1);
			int robCase1 = rob(nums1, dp1, nums1.size() - 1);
			//std::cout << robCase1 << std::endl; // debug

			std::vector<int> nums2;
			nums2.assign(nums.begin() + 1, nums.end());
			//PrintVector(nums2); // debug
			std::vector<int> dp2(nums2.size(), -1);
			int robCase2 = rob(nums2, dp2, nums2.size() - 1);
			//std::cout << robCase2 << std::endl; // debug

			robMax = std::max(robCase1, robCase2);
		}
		
		return robMax;
	}

private:
	int rob(std::vector<int> &nums, std::vector<int> &dp, int n)
	{
		if (n < 0 || n >= nums.size())
			return 0;

		if (dp[n] > -1)
			return dp[n];

		int robCurHouse = nums[n] + rob(nums, dp, n - 2);
		//std::cout << "\tn = " << n << ", robCurHouse = " << robCurHouse << std::endl; // debug
		int doNotRobCurHouse = rob(nums, dp, n - 1);
		//std::cout << "\tn = " << n << ", doNotRobCurHouse = " << doNotRobCurHouse << std::endl; // debug
		dp[n] = std::max(robCurHouse, doNotRobCurHouse);
		return dp[n];
	}

	void PrintVector(std::vector<int> &nums)
	{
		std::cout << "[";
		for (auto &n : nums)
			std::cout << n << " ";
		std::cout << "]" << std::endl;
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
		std::vector<int> nums = {2,3,2};
		int expectedOutput = 3;
		std::cout << "===== Test nums = " << Vector2Str(nums) << "; output = " << expectedOutput << " =====" << std::endl;

		// ACT
		int result = this->mSolution.rob(nums);

		// ASSERT
		AssertClass::GetInstance().Assert(result = expectedOutput);
	}

	void Example2()
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

	void Example3()
	{
		// ARRANGE
		std::vector<int> nums = {1,2,3};
		int expectedOutput = 4;
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
	getchar();
	return EXIT_SUCCESS;
}