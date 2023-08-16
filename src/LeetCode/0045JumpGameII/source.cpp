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
	
	int jump(std::vector<int>& nums) {
		int minStep = 0;
		int furthest = 0;
		int lastStepDest = 0;
		for (int i = 0; i < nums.size(); i++) {
			furthest = std::max(furthest, nums[i] + i);
			if (lastStepDest == i && lastStepDest < nums.size() - 1) {
				lastStepDest = furthest;
				minStep = minStep + 1;
			}
			//std::cout << "i = " << i << ", furthest = " << furthest << ", lastStepDest = " << lastStepDest << ", minStep = " << minStep << std::endl; // debug
		}
		return minStep;
	}
};

class TestJump
{
public:
	TestJump()
	{}

	~TestJump()
	{}

	void Example1()
	{
		std::vector<int> nums({2,3,1,1,4});
		int expectedOutput = 2;
		std::cout << "===== Test nums = " << Vector2Str(nums) << ", output = " << expectedOutput <<" =====" << std::endl;

		int result = this->mSolution.jump(nums);

		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example2()
	{
		std::vector<int> nums({2,3,0,1,4});
		int expectedOutput = 2;
		std::cout << "===== Test nums = " << Vector2Str(nums) << ", output = " << expectedOutput <<" =====" << std::endl;

		int result = this->mSolution.jump(nums);

		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example3()
	{
		std::vector<int> nums({10, 1, 4,5});
		int expectedOutput = 1;
		std::cout << "===== Test nums = " << Vector2Str(nums) << ", output = " << expectedOutput <<" =====" << std::endl;

		int result = this->mSolution.jump(nums);

		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example4()
	{
		std::vector<int> nums({0});
		int expectedOutput = 0;
		std::cout << "===== Test nums = " << Vector2Str(nums) << ", output = " << expectedOutput <<" =====" << std::endl;

		int result = this->mSolution.jump(nums);

		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example5()
	{
		std::vector<int> nums({1});
		int expectedOutput = 0;
		std::cout << "===== Test nums = " << Vector2Str(nums) << ", output = " << expectedOutput <<" =====" << std::endl;

		int result = this->mSolution.jump(nums);

		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example6()
	{
		std::vector<int> nums({5,6,4,4,6,9,4,4,7,4,4,8,2,6,8,1,5,9,6,5,2,7,9,7,9,6,9,4,1,6,8,8,4,4,2,0,3,8,5});
		int expectedOutput = 5;
		std::cout << "===== Test nums = " << Vector2Str(nums) << ", output = " << expectedOutput <<" =====" << std::endl;

		int result = this->mSolution.jump(nums);

		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example7()
	{
		std::vector<int> nums({8,2,4,4,4,9,5,2,5,8,8,0,8,6,9,1,1,6,3,5,1,2,6,6,0,4,8,6,0,3,2,8,7,6,5,1,7,0,3,4,8,3,5,9,0,4,0,1,0,5,9,2,0,7,0,2,1,0,8,2,5,1,2,3,9,7,4,7,0,0,1,8,5,6,7,5,1,9,9,3,5,0,7,5});
		int expectedOutput = 13;
		std::cout << "===== Test nums = " << Vector2Str(nums) << ", output = " << expectedOutput <<" =====" << std::endl;

		int result = this->mSolution.jump(nums);

		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

private:
	Solution mSolution;
};

int main(int argc, char** argv)
{
	TestJump test;
	test.Example1();
	test.Example2();
	test.Example3();
	test.Example4();
	test.Example5();
	test.Example6();
	test.Example7();
	getchar();
	return EXIT_SUCCESS;
}