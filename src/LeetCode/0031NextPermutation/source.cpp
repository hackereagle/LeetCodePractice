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
	
	void nextPermutation(std::vector<int>& nums) {
		int len = nums.size();
		int firstIdx = -1;
		for (int i = len - 2; i >= 0; i--) {
			if (nums[i] < nums[i + 1]) {
				firstIdx = i;
				break;
			}
		}

		if (firstIdx < 0) {
			std::reverse(nums.begin(), nums.end());
		}
		else {
			int secondIdx = -1;
			for (int i = len - 1; i > firstIdx; i--) {
				if (nums[i] > nums[firstIdx]) {
					secondIdx = i;
					break;
				}
			}

			std::swap(nums[firstIdx], nums[secondIdx]);
			std::reverse(nums.begin() + firstIdx + 1, nums.end());
		}
	}
};

class TestNextPermutation
{
public:
	TestNextPermutation()
	{}

	~TestNextPermutation()
	{}

	void Example1()
	{
		// ARRANGE
		std::vector<int> nums({1,2,3});
		std::vector<int> expectedOutput({1, 3, 2});
		std::cout << "===== Test nums = " << Vector2Str(nums) << ", expected output = " << Vector2Str(expectedOutput) << " =====" << std::endl;

		// ACT
		this->mSolution.nextPermutation(nums);

		// ASSERT
		AssertClass::GetInstance().Assert(IsTwoVectorEqual(nums, expectedOutput));
	}

	void Example2()
	{
		// ARRANGE
		std::vector<int> nums({3,2,1});
		std::vector<int> expectedOutput({1,2,3});
		std::cout << "===== Test nums = " << Vector2Str(nums) << ", expected output = " << Vector2Str(expectedOutput) << " =====" << std::endl;

		// ACT
		this->mSolution.nextPermutation(nums);

		// ASSERT
		AssertClass::GetInstance().Assert(IsTwoVectorEqual(nums, expectedOutput));
	}

	void Example3()
	{
		// ARRANGE
		std::vector<int> nums({1,1,5});
		std::vector<int> expectedOutput({1,5,1});
		std::cout << "===== Test nums = " << Vector2Str(nums) << ", expected output = " << Vector2Str(expectedOutput) << " =====" << std::endl;

		// ACT
		this->mSolution.nextPermutation(nums);

		// ASSERT
		AssertClass::GetInstance().Assert(IsTwoVectorEqual(nums, expectedOutput));
	}

private:
	Solution mSolution;
};

int main(int argc, char** argv)
{
	TestNextPermutation test;
	test.Example1();
	test.Example2();
	test.Example3();
	getchar();
	return EXIT_SUCCESS;
}