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
	
	bool canJump(std::vector<int>& nums) {
		bool _canJump = false;

		int further = 0;
		int lastStep = 0;
		int len = nums.size();
		for (int i = 0; i < len; i++) {
			further = std::max(further, i + nums[i]);
			if (i == lastStep) {
				lastStep = further;
			}
		}

		if (lastStep >= len - 1) {
			_canJump = true;
		}

		return _canJump;
	}
};

class TestCanJump
{
public:
	TestCanJump()
	{}

	~TestCanJump()
	{}

	void Example1()
	{
		// ARRANGE
		std::vector<int> nums({2,3,1,1,4});
		bool expectedOutput = true;
		std::cout << "===== Test nums = " << nums << "; output = "<< BOOL_TO_STR(expectedOutput) << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		bool result = this->mSolution.canJump(nums);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example2()
	{
		// ARRANGE
		std::vector<int> nums({3,2,1,0,4});
		bool expectedOutput = false;
		std::cout << "===== Test nums = " << nums << "; output = "<< BOOL_TO_STR(expectedOutput) << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		bool result = this->mSolution.canJump(nums);
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
	TestCanJump test;
	test.Example1();
	test.Example2();
	getchar();
	return EXIT_SUCCESS;
}